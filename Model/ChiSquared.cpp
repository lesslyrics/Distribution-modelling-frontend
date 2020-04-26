//
// Created by lesslyrics on 26.04.2020.
//

#include "ChiSquared.h"

/**
 * method to calculate chi-square value
 * @param h_freq
 * @param h
 * @param h1
 * @param h2
 * @param df
 * @return
 */
double ChiSquared::calculate_chi(std::vector<double> &h_freq, std::vector<double> &h, std::vector<double> &h1, int &df, int a, int nt) {
    double chi_sq = 0;
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

const std::vector<double> &ChiSquared::getActAltFreq() const {
    return act_alt_freq;
}

void ChiSquared::setActAltFreq(const std::vector<double> &actAltFreq) {
    act_alt_freq = actAltFreq;
}

double ChiSquared::getChiSq() const {
    return chi_sq;
}

void ChiSquared::setChiSq(double chiSq) {
    chi_sq = chiSq;
}

double ChiSquared::getChiSqAlt() const {
    return chi_sq_alt;
}

void ChiSquared::setChiSqAlt(double chiSqAlt) {
    chi_sq_alt = chiSqAlt;
}

const std::vector<double> &ChiSquared::getPDist() const {
    return p_dist;
}

void ChiSquared::setPDist(const std::vector<double> &pDist) {
    p_dist = pDist;
}

const std::vector<double> &ChiSquared::getPDistAlt() const {
    return p_dist_alt;
}

void ChiSquared::setPDistAlt(const std::vector<double> &pDistAlt) {
    p_dist_alt = pDistAlt;
}
