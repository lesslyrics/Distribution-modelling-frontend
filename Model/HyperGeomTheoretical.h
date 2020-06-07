#pragma once


#include <vector>
#include <iostream>
#include <iomanip>

/**
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020
    \example Example.cpp

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

    /**
     * Method to compute hypergeometric distribution
     * @param N
     * @param K
     * @param n
     * @param k
     * @return
     */
    double hyperGeomTheor(unsigned long N, unsigned long K, unsigned long n, unsigned long k);


    /**
    * method to compute binomial coefficient
    * @param n
    * @param k
    * @return
    */
    double computeBinCoef(unsigned long n, unsigned long k);

    /**
     * Destructor
     */
    ~HyperGeomTheoretical() = default;


    /**
     * create theoretical distribution
     * @param nt
     * @param expected_freq
     * @param expected
     */
    void modelTheoreticalDist(int nt, std::vector<double> &expected_freq, std::vector<double> &expected) {

        std::vector<double> h(a + 1, 0);
        std::vector<double> h_freq(a + 1, 0);

        for (int i = 0; i != a + 1; ++i) {
            h[i] = hyperGeomTheor(a + b, a, k, i);
            h_freq[i] = h[i] * nt / 100;
        }

        expected_freq.clear();
        expected.clear();

        for (double &i : h)
                expected.push_back(i);


        for (double &i : h_freq)
                expected_freq.push_back(i);

    }
};


