//
// Created by lesslyrics on 23.02.2020.
//

#include <iostream>
#include <iomanip>
#include "BernoulliMethod.h"
#include "InverseFunctionMethod.h"
#include "HyperGeomTheoretical.h"
#include "probdist.h"
#include "Model.h"

//const int NT = 50; // number of trials for distribution

/**
 * method to activateModel random values using Bernoulli distribution
 * @param a
 * @param b
 * @param k
 * @return
 */
int BernoulliMethod::generateRandomValue(int a, int b, int k) {
    int i = 0, j = 0;
    int n = a + b;
    do {
        double alpha = randomRange(0, 1);
        double pivot = double(a - j) / (n - i);
        if (alpha < pivot)
            j++;  //std::cout << " j: " << j << std::endl;
        i++;
    } while (i < k);
    int phi = j;
    return phi;
}

 double BernoulliMethod::createDist(int trials, int a, int b, int k, int nt, double &p_fin,
         std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist) {

    HyperGeomTheoretical model_t;
    double chi_sq;
    double chi_sq_alt;
    int q1, q2;
    int df = 0;

    auto p = std::vector<double>(trials, 0); // histograms
    auto p_alt = std::vector<double>(trials, 0); // histograms

    std::vector<int> h1(a + 1, 0); // histograms
    std::vector<int> h2(a + 1, 0);
    std::vector<double> h(a + 1, 0);
    std::vector<double> h_freq(a + 1, 0);

    std::cout << "here" << std::endl;
    BernoulliMethod model(a);
    for (int l = 0; l < trials; ++l) {
        for (int j = 0; j != nt; ++j) {
            q1 = model.generateRandomValue(a, b, k);
            q2 = model.generateRandomValue(5, 5, 4);
            h1[q1]++; // count
            h2[q2]++;
            //std::cout << "q1 " << q1 << std::endl;
        }
        for (int i = 0; i != a + 1; ++i) {
            h[i] = model_t.hyperGeomTheor(a + b, a, k, i);
            h_freq[i] = h[i] * nt / 100;
        }

        merge_sample(h_freq, h, h1, h2);

        //printing
//        std::cout << "Num of" << std::setw(25) << "Expected Percent" << std::setw(30) << "Expected  Freq B (n*p_i)"
//                  << std::setw(30) << "Observed Percent B (n_i/n)" << std::setw(30) << "Observed Freq B (n_i)" <<
//                  std::setw(30) << "Obs - Exp (n_i - n*p_i)" << std::setw(30) << "Obs - Exp Alt (n_i - n*p_i)"
//                  << std::endl;
//        std::cout << "white balls\n";

        for (int i = 0; i != a + 1; ++i) { //
            double e1 = double(h1[i]) * 100 / double(nt);
            double e2 = double(h2[i]) * 100 / double(nt);
//            std::cout << i << std::setw(30) << h[i] << std::setw(30) << h_freq[i] << std::setw(30) << e1
//                      << std::setw(30) << h1[i] << std::setw(30) << h1[i] - h_freq[i] << std::setw(30)
//                      << h2[i] - h_freq[i] << '\n';
        }

        for (double & i : h_freq)
            if (i > 0){
                exp_freq.push_back(i);
            }

        for (int i = 0; i != a + 1; i++)
            if (h_freq[i] > 0){
                act_freq.push_back(h1[i]);
            }

//        for (int i = 0; i < act_freq.size(); i++)
//            std::cout << std::endl << "act[ " << i << "]: " << act_freq[i] << std::endl;
//
//        for (int i = 0; i < exp_freq.size(); i++)
//        std::cout << std::endl << "exp[ " << i << "]: " << exp_freq[i] << std::endl;
//
//    std::cout << std::endl << "size " << exp_freq.size() << std::endl;


        chi_sq = calculate_chi(h_freq, h, h1, df, a, nt);
        chi_sq_alt = calculate_chi(h_freq, h, h2, df, a, nt);

        double p_val = 0;
        CHI(1, df, chi_sq, p_val);
        p[l] = p_val;
        p_fin = p_val;
        p_val = 0;
        CHI(1, df, chi_sq_alt, p_val);
        p_alt[l] = p_val;

        std::fill(h.begin(), h.end(), 0);
        std::fill(h1.begin(), h1.end(), 0);
        std::fill(h2.begin(), h2.end(), 0);
        std::fill(h_freq.begin(), h_freq.end(), 0);


//        std::cout << std::endl << "size bern " << exp_freq.size() << std::endl;

        for (double & i : p)
            if (i > 0){
                p_dist.push_back(i);
            }

        this->chi_sqrt = chi_sq;
        this->p_value = p_fin;
        this->size = trials;

    }
    return chi_sq;

}
