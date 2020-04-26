//
// Created by lesslyrics on 25.02.2020.
//

#pragma once


#include <vector>
#include <iostream>
#include <iomanip>

class HyperGeomTheoretical {

protected:
    int a;
    int b;
    int k;
    std::vector<double> expected_freq;
    std::vector<double> expected;

public:
    int getA() const;

    void setA(int a);

    int getB() const;

    void setB(int b);

    int getK() const;

    void setK(int k);

    const std::vector<double> &getExpectedFreq() const;

    void setExpectedFreq(const  std::vector<double> &expectedFreq);

    const  std::vector<double> &getExpected() const;

    void setExpected(const  std::vector<double> &expect);


public:
    double hyperGeomTheor(unsigned long N, unsigned long K, unsigned long n, unsigned long k);

    double computeBinCoef(unsigned long n, unsigned long k);

    ~HyperGeomTheoretical() = default;

    void modelTheoreticalDist(int nt) {

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


