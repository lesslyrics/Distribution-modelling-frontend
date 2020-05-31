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
void
merge_sample(std::vector<double> &h_freq, std::vector<double> &h, std::vector<double> &h1, std::vector<double> &h2) {

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
            if (h_freq.size() == static_cast<std::vector<int>::size_type>(j)) {
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


    //delete irrelevant elements
    int size_temp = h_freq.size();
    int iter = 0;
    while (iter < size_temp) {
        if (h_freq[iter] == -1) {
            h_freq.erase(h_freq.begin() + iter);
            h.erase(h.begin() + iter);
            h1.erase(h1.begin() + iter);
            h2.erase(h2.begin() + iter);
            iter--;
            size_temp--;
        }
        iter++;
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
            if (p[i] < (double) j / 10.0 && p[i] > (double) (j - 1) / 10)
                hist_p[j - 1]++;
        }
    }

    for (int j = 1; j <= 10; ++j) {
        hist_p[j] = (double) (hist_p[j - 1] + hist_p[j]);
    }
}


/**
 * Main method for distribution generation activation
 */
double model(int trials, int nt, double &chi, std::vector<double> &exp_freq,
             std::vector<double> &act_freq, std::vector<double> &p_dist, std::vector<double> &p_dist_alt, int a, int b,
             int k) {

    return model(ModelType::Bern, trials, nt, chi, exp_freq,
                 act_freq, p_dist, p_dist_alt, a, b, k);

}


double model(ModelType type, int trials, int nt, double &chi, std::vector<double> &exp_freq,
             std::vector<double> &act_freq, std::vector<double> &p_dist, std::vector<double> &p_dist_alt, int a, int b,
             int k) {

    std::vector<double> p;
    std::vector<double> p_alt;
    std::vector<double> expected_freq;
    std::vector<double> expected;

    std::cout << "hello";

    HypogeomModel *model;
    ChiSquared chiStat;
    switch (type) {
        case ModelType::Bern : {
            model = new BernoulliMethodModel(a);
            break;
        }
        case ModelType::Inv : {
            model = new InverseFunctionMethodModel(a);
            break;
        }
        default:
            return 1;
    }

    for (int l = 0; l < trials; l++) {

        model->createDist(trials, a, b, k, nt);
        HyperGeomTheoretical dist;

        dist.setA(a);
        dist.setB(b);
        dist.setK(k);
        dist.modelTheoreticalDist(nt, expected_freq, expected);

//        std::vector<double> exp_freq_temp = expected_freq;
//        std::vector<double> exp_temp = expected;

        std::vector<double> act_freq_temp = model->getActualFreq();
        std::vector<double> act_alt_temp = model->getActualAltFreq();

        merge_sample(expected_freq, expected, act_freq_temp, act_alt_temp);

        model->setActualFreq(act_freq_temp);
        model->setActualAltFreq(act_alt_temp);
//
//        expected_freq = exp_freq_temp;
//        expected = exp_temp;

//-----------------------------------------------

        chiStat.computeStatistics(*model, dist, trials, nt, expected_freq, expected);
        p.push_back(chiStat.getPValue());
        p_alt.push_back(chiStat.getPValueAlt());

        chi = chiStat.getChiSq();
        exp_freq = chiStat.getExpFreq();
        act_freq = chiStat.getActFreq();
        p_dist = chiStat.getPDist();
        p_dist_alt = chiStat.getPDistAlt();

    }

//------------------------------------------------
    auto hist_p = std::vector<int>(11, 0); // histograms
    auto hist_p_alt = std::vector<int>(11, 0); // histograms

    /* for p_value*/
    build_p_dist(hist_p, p, trials);
    p_dist.clear();
    for (int i = 1; i < hist_p.size(); i++)
        p_dist.push_back(((double) hist_p[i - 1]) / trials);

    chiStat.setPDist(p_dist);

    /* for alternative*/
    build_p_dist(hist_p_alt, p_alt, trials);
    p_dist_alt.clear();
    for (int i = 1; i < hist_p_alt.size(); i++)
        p_dist_alt.push_back(((double) hist_p_alt[i - 1]) / trials);

    chiStat.setPDistAlt(p_dist_alt);


    delete (model);
    return chiStat.getPValue();

}
