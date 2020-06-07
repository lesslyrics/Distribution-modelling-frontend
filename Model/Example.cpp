
/** \file Example.cpp
 * \brief Example file to test essential methods
**/


#include "BernoulliMethodModel.h"
#include "HyperGeomTheoretical.h"
#include "probdist.h"
#include "ChiSquared.h"

/**
 *  Create theoretical HyperGeometric distribution with parameters (a, b, k)
 *  expected_freq - expected frequencies
 *  expected - expected frequencies in percentage
 */
void testDistribution() {
    int nt = 100;
    int a = 6;
    int b = 5;
    int k = 5;

    auto expected_freq = std::vector<double>(0, 0); // histograms
    auto expected = std::vector<double>(0, 0); // histograms

    HyperGeomTheoretical dist;
    dist.setA(a);
    dist.setB(b);
    dist.setK(k);
    dist.modelTheoreticalDist(nt, expected_freq, expected);
}

/**
 *  Model HyperGeometric distribution with parameters (a, b, k) with Bernoulli/InverseFunction Method
 *  act_freq - actual frequencies
 *  uncomment to run for InverseFunction
 */
void testModelling() {
    HypogeomModel *model;
    model = new BernoulliMethodModel();
//    model = new InverseFunctionMethodModel();

    int nt = 100;
    int a = 6;
    int b = 5;
    int k = 5;
    int len = a;
    std::vector<double> act_freq;
    model->createDist(1, a, b, k, nt, len);
    act_freq = model->getActualFreq();

}


/**
 * comute chi-statistics based on the model, distributin and number of troals
 * @param model - model
 * @param trials  - trials for p-value distributin (if not needed - set to 1 as default)
 * @param nt -  number of trials
 * @param expected_freq - expected frequencies (from distribution)
 * @param exp - expected frequencies in percentage (from distribution)
 */
void testChiStatistics(HypogeomModel model, int trials, int nt, const std::vector<double> &expected_freq,
                       const std::vector<double> &exp) {

    void computeStatistics(HypogeomModel model, int trials, int nt, const std::vector<double> &expected_freq, const std::vector<double> &exp);

}

/**
 *
 * @param p - vector containing calculated p-values
 * @param trials - number of trials for the p-value distribution
 * @param p_dist - resulting value - vector containing accumulated p-values (distribution), ready-to-plot
 */
void testPDistribution(std::vector<double> &p, int trials,  std::vector<double> &p_dist){
    auto hist_p = std::vector<int>(11, 0); // histograms
    /* for p_value*/
    build_p_dist(hist_p, p, trials);
    p_dist.clear();
    for (int i = 1; i < hist_p.size(); i++){
        p_dist.push_back(((double) hist_p[i - 1]) / trials);
    }
}
