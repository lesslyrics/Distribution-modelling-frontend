//
// Created by lesslyrics on 26.04.2020.
//
const int FREQ = 5;
#include "ChiSquared.h"

 /**
  * calculate chi-statistics
  * @param h_expected - expected frequencies
  * @param h_actual  - actual frequencies
  * @param df - degrees of freedom
  * @return chi-squared statistics
  */
double ChiSquared::calculate_chi(std::vector<double> &h_expected, std::vector<double> &h_actual, int &df) {
    double chi_sq = 0;
    int a = h_expected.size() - 1;
    df = -1;
    for (int i = 0; i != a + 1; ++i) {
        if (h_expected[i] != -1) {
            chi_sq += (h_actual[i] - h_expected[i]) * (h_actual[i] - h_expected[i]) / h_expected[i];
            df++;
        }

    }
    return chi_sq;
}


/**
 * method to perform sample merging based on pivot
 * @param h_expected - expected frequencies
 * @param h_actual  - actual frequencies
 */
void ChiSquared::merge_sample(std::vector<double> &h_expected, std::vector<double> &h_actual) {

    if (!h_expected.empty()) {
        if (h_expected[0] < FREQ) {
            h_expected[1] += h_expected[0];
            h_actual[1] += h_actual[0];
            h_expected[0] = -1;
        }
        size_t i;
        size_t j;
        for (i = 1, j = h_expected.size(); j > i; i++, j--) {
            if (h_expected.size() == static_cast<std::vector<int>::size_type>(j)) {
                j--;
            }
            if (h_expected[j] < FREQ) {
                h_expected[j - 1] += h_expected[j];
                h_actual[j - 1] += h_actual[j];
                h_expected[j] = -1;
            }
            if (h_expected[i] < FREQ) {
                h_expected[i + 1] += h_expected[i];
                h_actual[i + 1] += h_actual[i];
                h_expected[i] = -1;
            }
        }
        if (h_expected[j] < FREQ) {
            h_expected[j - 1] += h_expected[j];
            h_actual[j - 1] += h_actual[j];
            h_expected[j] = -1;
        }
    }

    //delete irrelevant elements
    int size_temp = h_expected.size();
    int iter = 0;
    while (iter < size_temp) {
        if (h_expected[iter] == -1) {
            h_expected.erase(h_expected.begin() + iter);
            h_actual.erase(h_actual.begin() + iter);
            iter--;
            size_temp--;
        }
        iter++;
    }
}

const  std::vector<double>  &ChiSquared::getExpFreq() const {
    return exp_freq;
}

void ChiSquared::setExpFreq(const  std::vector<double> &expFreq) {
    exp_freq = expFreq;
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
