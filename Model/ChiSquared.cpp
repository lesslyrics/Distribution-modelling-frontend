//
// Created by lesslyrics on 26.04.2020.
//
const int FREQ = 5;
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


/**
 * method to perform sample merging based on pivot
 * @param h - expected frequencies in percentage
 * @param h_freq - expected frequencies
 * @param h1  - actual frequencies
 */
void ChiSquared::merge_sample(std::vector<double> &h_freq, std::vector<double> &h, std::vector<double> &h1) {

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
