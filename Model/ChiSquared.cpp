//
// Created by lesslyrics on 26.04.2020.
//

#include "ChiSquared.h"

 /**
  * calculate chi-statistics
  * @param h_freq - expected frequencies
  * @param h1  - actual frequencies
  * @param df - degrees of freedom
  * @return chi-squared statistics
  */
double ChiSquared::calculate_chi(std::vector<double> &h_freq, std::vector<double> &h1, int &df) {
    double chi_sq = 0;
    int a = h_freq.size() - 1;
    df = -1;
    for (int i = 0; i != a + 1; ++i) {
        if (h_freq[i] != -1) {
            chi_sq += (h1[i] - h_freq[i]) * (h1[i] - h_freq[i]) / h_freq[i];
            df++;
        }

    }
    return chi_sq;
}

const  std::vector<double>  &ChiSquared::getExpFreq() const {
    return exp_freq;
}

void ChiSquared::setExpFreq(const  std::vector<double> &expFreq) {
    exp_freq = expFreq;
}

const  std::vector<double> &ChiSquared::getExpected() const {
    return expected;
}

void ChiSquared::setExpected(const  std::vector<double> &expected) {
    ChiSquared::expected = expected;
}

const std::vector<double> &ChiSquared::getActFreq() const {
    return act_freq;
}

void ChiSquared::setActFreq(const std::vector<double> &actFreq) {
    act_freq = actFreq;
}


double ChiSquared::getChiSq() const {
    return chi_sq;
}

void ChiSquared::setChiSq(double chiSq) {
    chi_sq = chiSq;
}


const std::vector<double> &ChiSquared::getPDist() const {
    return p_dist;
}

void ChiSquared::setPDist(const std::vector<double> &pDist) {
    p_dist = pDist;
}

double ChiSquared::getPValue() const {
    return p_value;
}

void ChiSquared::setPValue(double pValue) {
    p_value = pValue;
}
