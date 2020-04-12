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
func HyperGeomTheoretical::computeBinCoef(uint64_t n, uint64_t k) -> double {

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
func HyperGeomTheoretical::hyperGeomTheor(uint64_t N, uint64_t K, uint64_t n, uint64_t k) -> double {
    return computeBinCoef(K, k) * 100 * computeBinCoef(N - K, n - k) / computeBinCoef(N, n);
}






