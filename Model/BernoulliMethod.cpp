//
// Created by lesslyrics on 23.02.2020.
//

#include <iostream>
#include "BernoulliMethod.h"
#include "HyperGeomTheoretical.h"
#include "probdist.h"
#include "Model.h"

const int a_alt = 5;
const int b_alt = 5;
const int k_alt = 4;

/**
 * method to activateModel random values using Bernoulli distribution
 * @param a
 * @param b
 * @param k
 * @return
 */
int BernoulliMethod::generateRandomValue(int a, int b, int k) {
    int i = 0, j = 0;
    int n = a + b;
    do {
        double alpha = randomRange(0, 1);
        double pivot = double(a - j) / (n - i);
        if (alpha < pivot)
            j++;  //std::cout << " j: " << j << std::endl;
        i++;
    } while (i < k);
    int phi = j;
    return phi;
}

/**
 * Generate distribution
 * @param trials
 * @param a
 * @param b
 * @param k
 * @param nt
 * @param p_fin
 * @param exp_freq
 * @param act_freq
 * @param p_dist
 * @param p_dist_alt
 * @return
 */
 double BernoulliMethod::createDist(int trials, int a, int b, int k, int nt, double &p_fin,
         std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist, std::vector<double> &p_dist_alt) {

    HyperGeomTheoretical model_t;
    double chi_sq;
    double chi_sq_alt;
    int q1, q2;
    int df = 0;

    auto p = std::vector<double>(trials, 0); // histograms
    auto p_alt = std::vector<double>(trials, 0); // histograms

    std::vector<int> h1(a + 1, 0); // histograms
    std::vector<int> h2(a + 1, 0);
    std::vector<double> h(a + 1, 0);
    std::vector<double> h_freq(a + 1, 0);

    std::cout << "here" << std::endl;
    BernoulliMethod model(a);
    for (int l = 0; l < trials; ++l) {
        for (int j = 0; j != nt; ++j) {
            q1 = model.generateRandomValue(a, b, k);
            q2 = model.generateRandomValue(a_alt, b_alt, k_alt);
            h1[q1]++; // count
            h2[q2]++;
            //std::cout << "q1 " << q1 << std::endl;
        }
        for (int i = 0; i != a + 1; ++i) {
            h[i] = model_t.hyperGeomTheor(a + b, a, k, i);
            h_freq[i] = h[i] * nt / 100;
        }

        merge_sample(h_freq, h, h1, h2);


        for (int i = 0; i != a + 1; ++i) { //
            double e1 = double(h1[i]) * 100 / double(nt);
            double e2 = double(h2[i]) * 100 / double(nt);
        }

        exp_freq.clear();
        act_freq.clear();


        for (double & i : h_freq)
            if (i > 0){
                exp_freq.push_back(i);
            }

        for (int i = 0; i != a + 1; i++)
            if (h_freq[i] > 0){
                act_freq.push_back(h1[i]);
            }


        chi_sq = calculate_chi(h_freq, h, h1, df, a, nt);
        chi_sq_alt = calculate_chi(h_freq, h, h2, df, a, nt);

        double p_val = 0;
        CHI(1, df, chi_sq, p_val);
        p[l] = p_val;
        p_fin = p_val;
        p_val = 0;
        CHI(1, df, chi_sq_alt, p_val);
        p_alt[l] = p_val;

        std::fill(h.begin(), h.end(), 0);
        std::fill(h1.begin(), h1.end(), 0);
        std::fill(h2.begin(), h2.end(), 0);
        std::fill(h_freq.begin(), h_freq.end(), 0);


        p_dist.clear();
        for (double & i : p)
            if (i > 0){
                p_dist.push_back(i);
            }

        p_dist_alt.clear();
        for (double & i : p_alt)
            if (i > 0) {
                p_dist_alt.push_back(i);
            }
    }
    return chi_sq;
}

