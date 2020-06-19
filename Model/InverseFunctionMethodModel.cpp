//
// Created by lesslyrics on 23.02.2020.
//

#include "InverseFunctionMethodModel.h"
#include "Model.h"

#include <random>

extern std::mt19937 gen;

/**
   *  Find factorial
   * @param num
   * @return factorial of the num
   */
long double InverseFunctionMethodModel::findFactorial(int num) {
    long double fact = 1;
    int i;
    for (i = 1; i <= num; i++)
        fact = fact * (long double)i;
    return fact;
}


/**
    * method to generate random values
    * @param a - number of white balls
    * @param b - number of black balls
    * @param k - number of taken balls
    * @return random number
    */
int InverseFunctionMethodModel::generateRandomValue(int a, int b, int k) {
    int i = 0;
    int n = a + b;

    long double p = (findFactorial(b) * findFactorial(n - k)) / findFactorial(b - k) / findFactorial(n);
    long double l = p;
    std::uniform_real_distribution<> dis(0., 1.);
    double alpha = dis(gen);


    while (alpha >= l) {
        p = (long double)p * (long double)(a - i) * (long double)(k - i) / ((i + 1) * (long double)(n - a - k + i + 1));
        l += p;
        i++;
    }
    return i;
}

/**
  * Generate model with Inverse Function Method
  * @param a - number of white balls
  * @param b - number of black balls
  * @param k - number of taken balls
  * @param nt - number of trials
  * @param h - number of columns in histogram
  */
void InverseFunctionMethodModel::createDist(int a, int b, int k, int nt, int h) {

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