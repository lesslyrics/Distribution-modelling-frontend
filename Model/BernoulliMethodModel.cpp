//
// Created by lesslyrics on 23.02.2020.
//

#include <iostream>
#include "BernoulliMethodModel.h"
#include "HyperGeomTheoretical.h"
#include "probdist.h"
#include "Model.h"
#include "ChiSquared.h"

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
int BernoulliMethodModel::generateRandomValue(int a, int b, int k) {
    int i = 0, j = 0;
    int n = a + b;
    do {
        double alpha = randomRange(0, 1);
        double pivot = double(a - j) / (n - i);
        if (alpha < pivot)
            j++;
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
void BernoulliMethodModel::createDist(int trials, int a, int b, int k, int nt, int h) {

    int q1, q2;

    std::vector<double> h1(h + 1, 0); // histograms
    std::vector<double> h2(h + 1, 0); // histograms


    for (int j = 0; j != nt; ++j) {
        q1 = generateRandomValue(a, b, k);
        q2 = generateRandomValue(a_alt, b_alt, k_alt);
        h1[q1]++;
        h2[q2]++;
    }


    actual_freq.clear();
    actual_alt_freq.clear();

    for (int i = 0; i != h + 1; i++)
        actual_freq.push_back(h1[i]);


    for (int i = 0; i != h + 1; i++)
        actual_alt_freq.push_back(h2[i]);


}

