//
// Created by lesslyrics on 23.02.2020.
//

#include <iostream>
#include "BernoulliMethodModel.h"
#include "probdist.h"
#include "Model.h"


/**
 * method to generate random values using Bernoulli distribution
 * @param a - number of white balls
 * @param b - number of black balls
 * @param k - number of taken balls
 * @return random number
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
 * Generate model with Bernoulli Method
 * @param a - number of white balls
 * @param b - number of black balls
 * @param k - number of taken balls
 * @param nt - number of trials
 * @param h - number of columns in histogram
 */
void BernoulliMethodModel::createDist(int a, int b, int k, int nt, int h) {

    int q;
    std::vector<double> hist(h + 1, 0); // histograms
    for (int j = 0; j != nt; ++j) {
        q = generateRandomValue(a, b, k);
        hist[q]++;
    }
    actual_freq.clear();

    for (int i = 0; i != h + 1; i++)
        actual_freq.push_back(hist[i]);

}

