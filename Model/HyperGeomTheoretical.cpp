//
// Created by lesslyrics on 25.02.2020.
//

#include "HyperGeomTheoretical.h"
#include <cstdint>
#include <cmath>

#define func auto

/**
   * method to compute binomial coefficient n!/k!(n-k)!
   * @param n
   * @param k
   * @return binomial coefficient n!/k!(n-k)!
   */
double HyperGeomTheoretical::computeBinCoef(unsigned long n, unsigned long k) {

    if (k > n)
        return 0.0;

    if (k * 2ULL > n)   // unsigned long long int: auto two = 2ULL
        k = n - k;

    if (k == 0.0)
        return 1.0;

    // lgamma is the logarithm of the factorial of arg-1.
    return exp(lgamma(n + 1) - (lgamma(k + 1) + lgamma(n - k + 1)));
}

/**
 * Helper method to compute hypergeometric distribution
 * @param N - distribution parameter N ( number of objects)
 * @param K - distribution parameter K (K out of N are "bad")
 * @param n - distribution parameter n (sample size)
 * @param k - distribution parameter k (k out of n are "bad")
 * @return calculated value following hypergeometric distribution
 */
double HyperGeomTheoretical::hyperGeomTheor(unsigned long N, unsigned long K, unsigned long n, unsigned long k) {
    return computeBinCoef(K, k) * 100 * computeBinCoef(N - K, n - k) / computeBinCoef(N, n);
}

int HyperGeomTheoretical::getA() const {
    return a;
}

void HyperGeomTheoretical::setA(int a) {
    HyperGeomTheoretical::a = a;
}

int HyperGeomTheoretical::getB() const {
    return b;
}

void HyperGeomTheoretical::setB(int b) {
    HyperGeomTheoretical::b = b;
}

int HyperGeomTheoretical::getK() const {
    return k;
}

void HyperGeomTheoretical::setK(int k) {
    HyperGeomTheoretical::k = k;
}





