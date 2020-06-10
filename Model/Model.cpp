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
 * method to build p-value distribution
 * @param hist_p - prepared values for the histogram
 * @param p - p-values
 * @param trials - number of trials for p-value distribution
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
 * Method to get Chi-Squared statistics from Chi-Squared class (added for more convenient usage)
 * @param chiStat  -  chi-statistics
 * @param model - model
 * @param chi -  chi-statistics to be assigned
 * @param nt - number of trials
 * @param p - p-value
 * @param expected_freq - expected frequencies
 * @param expected - expected frequencies in percentage
 * @param exp_freq - expected frequencies to be assigned
 * @param act_freq - actual frequencies to be assigned
 * @param p_dist - p-values distribution
 */
void findChiStat(ChiSquared &chiStat, HypogeomModel *model, double &chi, int nt, std::vector<double> &p, std::vector<double>
expected_freq, std::vector<double> expected, std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist){

    chiStat.computeStatistics(*model, nt, expected_freq, expected);
    p.push_back(chiStat.getPValue());

    chi = chiStat.getChiSq();
    exp_freq = chiStat.getExpFreq();
    act_freq = chiStat.getActFreq();
    p_dist = chiStat.getPDist();

}

/**
    * Main method for distribution generation activation
    * @param type - type of modelling method
    * @param trials - number of trials for p-values distribution
    * @param nt - number of trials for distribution
    * @param chi - chi-squared statistics
    * @param exp_freq - expected frequencies
    * @param act_freq - actual frequencies
    * @param p_dist - p-value
    * @param a - number of white balls for H_o (used when error 1 mode is selected)
    * @param b - number of black balls for H_o (used when error 1 mode is selected)
    * @param k - number of taken balls for H_o (used when error 1 mode is selected)
    * @return chi-statistics
*/
double modelDistribution(ModelType type, int trials, int nt, double &chi, std::vector<double> &exp_freq,
                         std::vector<double> &act_freq, std::vector<double> &p_dist, int a, int b,
                         int k) {

    std::vector<double> p;
    std::vector<double> expected_freq;
    std::vector<double> expected;

    ChiSquared chiStat;
    HypogeomModel *model;
    switch (type) {
        case ModelType::Bern : {
            model = new BernoulliMethodModel();
            break;
        }
        case ModelType::Inv : {
            model = new InverseFunctionMethodModel();
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

        model->createDist(a, b, k, nt, len);
        std::vector<double> act_freq_temp = model->getActualFreq();

        model->setActualFreq(act_freq_temp);
        findChiStat(chiStat, model, chi, nt, p, expected_freq, expected, exp_freq, act_freq, p_dist);

    }

    auto hist_p = std::vector<int>(11, 0); // histograms

    /* for p_value*/
    build_p_dist(hist_p, p, trials);
    p_dist.clear();
    for (int i = 1; i < hist_p.size(); i++){
        p_dist.push_back(((double) hist_p[i - 1]) / trials);
    }

    chiStat.setPDist(p_dist);

    delete (model);
    return chiStat.getPValue();


}

/**
 * Method for the p-distriburion modelling
 * @param trials - number of trials for p-values distribution
 * @param nt - number of trials for distribution
 * @param chi - chi-squared statistics
 * @param exp_freq - expected frequencies
 * @param act_freq - actual frequencies
 * @param p_dist - p-values distribution
 * @param a - number of white balls for H_o (used when error 1 mode is selected)
 * @param b - number of black balls for H_o (used when error 1 mode is selected)
 * @param k - number of taken balls for H_o (used when error 1 mode is selected)
 * @param a_alt - number of white balls for H_1 (used when power mode is selected)
 * @param b_alt - number of black balls for H_1 (used when power mode is selected)
 * @param k_alt - number of taken balls for H_1 (used when power mode is selected)
 * @param p_type - power or error 1 mode
 * @return chi-statistics
 */
double modelPVal(int trials, int nt, double &chi, std::vector<double> &exp_freq,
                 std::vector<double> &act_freq, std::vector<double> &p_dist, int a, int b,
                 int k, int a_alt, int b_alt, int k_alt, PType p_type) {

    std::vector<double> p;
    std::vector<double> expected_freq;
    std::vector<double> expected;


    HypogeomModel *model;
    ChiSquared chiStat;
    model = new BernoulliMethodModel();


    int len = a;
    for (int l = 0; l < trials; l++) {
        HyperGeomTheoretical dist;

        dist.setA(a);
        dist.setB(b);
        dist.setK(k);
        dist.modelTheoreticalDist(nt, expected_freq, expected);
        std::vector<double> act_freq_temp;

        if (p_type == PType::Power){
            model->createDist(a_alt, b_alt, k_alt, nt, len);
            act_freq_temp = model->getActualFreq();
        }
        else{
            model->createDist(a, b, k, nt, len);
            act_freq_temp = model->getActualFreq();
        }


        model->setActualFreq(act_freq_temp);

        findChiStat(chiStat, model, chi, nt, p, expected_freq, expected, exp_freq, act_freq, p_dist);

    }

//------------------------------------------------
    auto hist_p = std::vector<int>(11, 0); // histograms

    /* for p_value*/
    build_p_dist(hist_p, p, trials);
    p_dist.clear();
    for (int i = 1; i < hist_p.size(); i++){
//        std::cout << ((double) hist_p[i - 1]) / trials << std::endl;
        p_dist.push_back(((double) hist_p[i - 1]) / trials);
    }

    chiStat.setPDist(p_dist);

    delete (model);
    return chiStat.getPValue();

}