//
// Created by lesslyrics on 23.02.2020.
//

#include "BernoulliMethod.h"
#include "InverseFunctionMethod.h"

/**
 * method to generate random values using Bernoulli distribution
 * @param a
 * @param b
 * @param k
 * @return
 */
int BernoulliMethod::generateRandomValue(int a, int b, int k) {
    int i = 0, j = 0;
    int n = a + b;
    do{
        double  alpha = randomRange(0, 1);
        double pivot = double(a - j) / (n - i);
        if (alpha < pivot)
            j++;  //std::cout << " j: " << j << std::endl;
        i++;
    }
    while (i < k);
    int phi = j;
    return phi;
}

