//
// Created by lesslyrics on 25.02.2020.
//

#include "HyperGeomTheoretical.h"
#include <cstdint>
#include <cmath>
#define func auto

/**
 * method to compute binomial coefficient
 * @param n
 * @param k
 * @return
 */
double HyperGeomTheoretical::computeBinCoef(unsigned long n, unsigned long k){

    if (k > n)
        return 0.0;

    if (k * 2ULL > n)   // unsigned long long int: auto two = 2ULL
        k = n - k;

    if (k == 0.0)
        return 1.0;

    // lgamma is the logarithm of the factorial of arg-1.
    return exp(lgamma(n+1) - (lgamma(k+1) + lgamma(n-k+1)));
}

/**
 * Method to compute hypergeometric distribution
 * @param N
 * @param K
 * @param n
 * @param k
 * @return
 */
double HyperGeomTheoretical::hyperGeomTheor(unsigned long  N, unsigned long  K, unsigned long  n, unsigned long  k) {
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

    const  std::vector<double> &HyperGeomTheoretical::getExpectedFreq() const {
        return expected_freq;
    }

    void HyperGeomTheoretical::setExpectedFreq(const  std::vector<double> &expectedFreq) {
        expected_freq = expectedFreq;
    }

    const  std::vector<double> &HyperGeomTheoretical::getExpected() const {
        return expected;
    }

    void HyperGeomTheoretical::setExpected(const  std::vector<double>  &expect) {
        expected = expect;
    }





