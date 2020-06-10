#pragma once


#include <vector>
#include <iostream>
#include <iomanip>

/**
	\brief Class
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020
    @example Example.cpp


	Class for the theoretical distribution generation
**/
class HyperGeomTheoretical {

protected:
    /**
     * distribution parameter a
     */
    int a;
    /**
     * distribution parameter b
     */
    int b;
    /**
     * distribution parameter k
     */
    int k;

public:
    /**
     * Getters and setters
     * @return
     */
    int getA() const;

    void setA(int a);

    int getB() const;

    void setB(int b);

    int getK() const;

    void setK(int k);


public:
/*
 * Helper method to compute hypergeometric distribution
 * @param N - distribution parameter N ( number of objects)
 * @param K - distribution parameter K (K out of N are "bad")
 * @param n - distribution parameter n (sample size)
 * @param k - distribution parameter k (k out of n are "bad")
 * @return calculated value following hypergeometric distribution
 */
    double hyperGeomTheor(unsigned long N, unsigned long K, unsigned long n, unsigned long k);


    /*
     * method to compute binomial coefficient n!/k!(n-k)!
     * @param n
     * @param k
     * @return binomial coefficient n!/k!(n-k)!
     */
    double computeBinCoef(unsigned long n, unsigned long k);

    /*
     * Destructor
     */
    ~HyperGeomTheoretical() = default;


    /*
     * create theoretical distribution
     * @param nt - number of trials
     * @param expected_freq - expected frequencies
     */
    void modelTheoreticalDist(int nt, std::vector<double> &expected_freq) {

        std::vector<double> h(a + 1, 0);
        std::vector<double> h_freq(a + 1, 0);

        for (int i = 0; i != a + 1; ++i) {
            h[i] = hyperGeomTheor(a + b, a, k, i);
            h_freq[i] = h[i] * nt / 100;
        }

        expected_freq.clear();
        for (double &i : h_freq)
                expected_freq.push_back(i);

    }
};


