#include <iostream>
#include "BernoulliMethodModel.h"
#include "InverseFunctionMethodModel.h"
#include <vector>
#include <iomanip>
#include "probdist.h"
#include "Model.h"
#include "ChiSquared.h"
#include "PType.h"

/**
 * hyperparameters
 * */

const int FREQ = 5;

/**
 * method to perform sample merging based on pivot
 * @param h_freq
 * @param h
 * @param h1
 * @param h2
 */
void
merge_sample(std::vector<double> &h_freq, std::vector<double> &h, std::vector<double> &h1) {

    if (!h_freq.empty()) {
        if (h_freq[0] < FREQ) {
            h_freq[1] += h_freq[0];
            h[1] += h[0];
            h1[1] += h1[0];
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
                h_freq[j] = -1;
            }
            if (h_freq[i] < FREQ) {
                h_freq[i + 1] += h_freq[i];
                h[i + 1] += h[i];
                h1[i + 1] += h1[i];
                h_freq[i] = -1;
            }
        }
        if (h_freq[j] < FREQ) {
            h_freq[j - 1] += h_freq[j];
            h[j - 1] += h[j];
            h1[j - 1] += h1[j];
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
 * Method to find Chi-Squared statistics
 */
void findChiStat(ChiSquared &chiStat, HypogeomModel *model, double &chi, int nt, std::vector<double> &p, int trials, std::vector<double>
expected_freq, std::vector<double> expected, std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist){

    chiStat.computeStatistics(*model, trials, nt, expected_freq, expected);
    p.push_back(chiStat.getPValue());

    chi = chiStat.getChiSq();
    exp_freq = chiStat.getExpFreq();
    act_freq = chiStat.getActFreq();
    p_dist = chiStat.getPDist();

}


/**
 * Mthod for distribution generation
 */
double modelDistribution(ModelType type, int trials, int nt, double &chi, std::vector<double> &exp_freq,
                         std::vector<double> &act_freq, std::vector<double> &p_dist, int a, int b,
                         int k) {

    std::vector<double> p;
    std::vector<double> expected_freq;
    std::vector<double> expected;

    std::cout << "hello";
    ChiSquared chiStat;
    HypogeomModel *model;
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

    int len = a;
    for (int l = 0; l < trials; l++) {
        HyperGeomTheoretical dist;

        dist.setA(a);
        dist.setB(b);
        dist.setK(k);
        dist.modelTheoreticalDist(nt, expected_freq, expected);

        model->createDist(trials, a, b, k, nt, len);
        std::vector<double> act_freq_temp = model->getActualFreq();

        merge_sample(expected_freq, expected, act_freq_temp);
        model->setActualFreq(act_freq_temp);

        findChiStat(chiStat, model, chi, nt, p, 1, expected_freq, expected, exp_freq, act_freq, p_dist);

    }

    auto hist_p = std::vector<int>(11, 0); // histograms

    /* for p_value*/
    build_p_dist(hist_p, p, trials);
    p_dist.clear();
    for (int i = 1; i < hist_p.size(); i++)
        p_dist.push_back(((double) hist_p[i - 1]) / trials);

    chiStat.setPDist(p_dist);

    delete (model);
    return chiStat.getPValue();


}

/**
 * Method for the p-distriburion modelling
 */
double modelPVal(int trials, int nt, double &chi, std::vector<double> &exp_freq,
                 std::vector<double> &act_freq, std::vector<double> &p_dist, int a, int b,
                 int k, int a_alt, int b_alt, int k_alt, PType p_type) {

    std::vector<double> p;
    std::vector<double> expected_freq;
    std::vector<double> expected;


    HypogeomModel *model;
    ChiSquared chiStat;
    model = new BernoulliMethodModel(a);


    int len = a;
    for (int l = 0; l < trials; l++) {
        HyperGeomTheoretical dist;

        dist.setA(a);
        dist.setB(b);
        dist.setK(k);
        dist.modelTheoreticalDist(nt, expected_freq, expected);
        std::vector<double> act_freq_temp;

        if (p_type == PType::Power){
            model->createDist(trials, a_alt, b_alt, k_alt, nt, len);
            act_freq_temp = model->getActualFreq();
        }
        else{
            model->createDist(trials, a, b, k, nt, len);
            act_freq_temp = model->getActualFreq();
        }


        merge_sample(expected_freq, expected, act_freq_temp);

        model->setActualFreq(act_freq_temp);

        findChiStat(chiStat, model, chi, nt, p, 1, expected_freq, expected, exp_freq, act_freq, p_dist);

    }

//------------------------------------------------
    auto hist_p = std::vector<int>(11, 0); // histograms

    /* for p_value*/
    build_p_dist(hist_p, p, trials);
    p_dist.clear();
    for (int i = 1; i < hist_p.size(); i++)
        p_dist.push_back(((double) hist_p[i - 1]) / trials);

    chiStat.setPDist(p_dist);

    delete (model);
    return chiStat.getPValue();

}