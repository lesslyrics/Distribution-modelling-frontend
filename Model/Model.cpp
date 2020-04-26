#include <iostream>
#include "BernoulliMethodModel.h"
#include "InverseFunctionMethodModel.h"
#include <vector>
#include <iomanip>
#include "probdist.h"
#include "Model.h"
#include "ChiSquared.h"

/**
 * hyperparameters
 * */

const int FREQ = 5;
const int a_alt = 5;
const int b_alt = 5;
const int k_alt = 4;

/**
 * method to perform sample merging based on pivot
 * @param h_freq
 * @param h
 * @param h1
 * @param h2
 */
void merge_sample(std::vector<double> &h_freq, std::vector<double> &h, std::vector<double> &h1, std::vector<double> &h2) {

    if (!h_freq.empty()) {
        if (h_freq[0] < FREQ) {
            h_freq[1] += h_freq[0];
            h[1] += h[0];
            h1[1] += h1[0];
            h2[1] += h2[0];
            h_freq[0] = -1;
        }
        size_t i;
        size_t j;
        for (i = 1, j = h_freq.size(); j > i; i++, j--) {
            if(h_freq.size() == static_cast<std::vector<int>::size_type>(j)) {
                j--;
            }
            if (h_freq[j] < FREQ) {
                h_freq[j - 1] += h_freq[j];
                h[j - 1] += h[j];
                h1[j - 1] += h1[j];
                h2[j - 1] += h2[j];
                h_freq[j] = -1;
            }
            if (h_freq[i] < FREQ) {
                h_freq[i + 1] += h_freq[i];
                h[i + 1] += h[i];
                h1[i + 1] += h1[i];
                h2[i + 1] += h2[i];
                h_freq[i] = -1;
            }
        }
        if (h_freq[j] < FREQ) {
            h_freq[j - 1] += h_freq[j];
            h[j - 1] += h[j];
            h1[j - 1] += h1[j];
            h2[j - 1] += h2[j];
            h_freq[j] = -1;
        }
    }
}

/**
 * method to print p-value distribution
 * @param hist_p
 * @param p
 */
void build_p_dist(std::vector<int> &hist_p, std::vector<double> &p, int trials) {
    for (int i = 0; i < trials; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (p[i] < (double)j / 10.0 && p[i] > (double)(j - 1) / 10)
                hist_p[j - 1]++;
        }
    }

    for (int j = 1; j <= 10; ++j){
        hist_p[j] = (double)(hist_p[j - 1] + hist_p[j]);
    }

    for (int i = 1; i < 11; ++i)
        std::cout << "[" << (double) (i - 1) / 10 << "," << (double) i / 10 << "] : " << ((double)hist_p[i - 1])/ trials << std::endl;

}


/**
 * Main method for distribution generation activation
 */
double model(int trials, int nt, double &chi, std::vector<double> &exp_freq,
           std::vector<double> &act_freq,std::vector<double> &p_dist, std::vector<double> &p_dist_alt, int a, int b, int k) {

    return model(ModelType::Bern, trials, nt, chi, exp_freq,
                 act_freq,p_dist, p_dist_alt, a,  b, k);

}


double model(ModelType type, int trials, int nt, double &chi, std::vector<double> &exp_freq,
             std::vector<double> &act_freq, std::vector<double> &p_dist,  std::vector<double> &p_dist_alt, int a, int b, int k) {

    std::vector<double> p;
    HypogeomModel *model;
    ChiSquared chiStat;
    switch ( type ) {
        case ModelType::Bern : {
            model = new BernoulliMethodModel(a);
            break;
        }
//        case ModelType::Inv : {
//            model = new InverseFunctionMethodModel(a);
//               model->createDist(trials, a, b, k, nt);
//            break;
//        }
        default:
            return 1;
    }

    for(int l = 0; l < trials; l++) {

        model->createDist(trials, a, b, k, nt);
        HyperGeomTheoretical dist;

        dist.setA(a);
        dist.setB(b);
        dist.setK(k);
        dist.modelTheoreticalDist(nt);


        std::vector<double> exp_freq_temp = dist.expected_freq;
        std::vector<double> exp_temp = dist.expected;
        std::vector<double> act_freq_temp = model->actual_freq;
        std::vector<double> act_alt_temp = model->actual_alt_freq;

        merge_sample(exp_freq_temp, exp_temp, act_freq_temp, act_alt_temp);

        int size_temp = act_freq_temp.size();

        int iter = 0;
        while (iter < size_temp) {
            if (exp_freq_temp[iter] == -1) {
                exp_freq_temp.erase(exp_freq_temp.begin() + iter);
                exp_temp.erase(exp_temp.begin() + iter);
                act_freq_temp.erase(act_freq_temp.begin() + iter);
                act_alt_temp.erase(act_alt_temp.begin() + iter);
                iter--;
                size_temp--;
            }
            iter++;
        }

//    for (int i = 0; i < size_temp; ++i) {
//        std::cout << i << std::setw(30) << exp_temp[i] << std::setw(30) << exp_freq_temp[i]
//                  << std::setw(30) << act_freq_temp[i] << std::setw(30) << act_freq_temp[i] - exp_freq_temp[i] << std::setw(30) << act_alt_temp[i] - exp_freq_temp[i]  << '\n';
//    }

        model->setActualFreq(act_freq_temp);
        model->setActualAltFreq(act_alt_temp);
        dist.setExpectedFreq(exp_freq_temp);
        dist.setExpected(exp_temp);

//----------------------------------------------

        chiStat.computeStatistics(*model, dist, trials, nt);
//        std::cout << "p-val main: " << chiStat.getPValue() << '\n';

        p.push_back(chiStat.getPValue());

        chi = chiStat.getChiSq();
//        std::cout << "chi " << chi << std::endl;
        exp_freq = chiStat.getExpFreq();
        act_freq = chiStat.getActFreq();
        p_dist = chiStat.getPDist();
        p_dist_alt = chiStat.getPDistAlt();

    }

    auto hist_p = std::vector<int>(11, 0); // histograms

//    for(int i = 1; i < p.size(); i++)
//        std::cout << "dist " << p[i] << std::endl;

    build_p_dist(hist_p, p, trials);
    std::cout << std::endl << std::endl;

    p_dist.clear();
        for(int i = 1; i < hist_p.size(); i++)
          p_dist.push_back(((double)hist_p[i - 1])/ trials);
     chiStat.setPDist(p_dist);


    delete (model);


    return chiStat.getPValue();

}
