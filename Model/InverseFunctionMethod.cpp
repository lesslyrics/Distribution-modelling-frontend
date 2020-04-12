//
// Created by lesslyrics on 23.02.2020.
//

#include <iostream>
#include "InverseFunctionMethod.h"

/** This function finds factorial of large numbers **/
long long int InverseFunctionMethod::findFactorial(int num){
    int fact = 1, i;
    for(i = 1; i <= num; i++)
        fact = fact * i;
    return fact;
}

/**
 * method to generate random values using inverse function method
 * @param a
 * @param b
 * @param k
 * @return
 */
int InverseFunctionMethod::generateRandomValue(int a, int b, int k) {
    int i = 0;
    int n = a + b;

  //  std::cout <<"fac " << findFactorial(b) * findFactorial(t) <<  std::endl ;
    long double p = (long double)(findFactorial(b) * findFactorial(n - k)) / findFactorial(n - a - k) / findFactorial(n);
    long double l = p;
    std::cout <<"l " << l <<  std::endl ;
    long double  alpha = randomRange(0, 1);
    std::cout <<"alpha " <<  alpha <<  std::endl ;


    while (alpha >= l){
        p = p * (a - i) * (k - i) / ((i + 1) * (n - a - k + i + 1));
        std::cout <<"p: "  << p << std::endl ;
        l += p;
        i++;
        std::cout <<"haloo: "  << i << " " << l  << std::endl ;


    }
    std::cout << "i: " << i << std::endl;
    return i;
}

