//
// Created by lesslyrics on 23.02.2020.
//

#include <iostream>
#include "InverseFunctionMethod.h"
#include "HyperGeomTheoretical.h"
#include "Model.h"

/** This function finds factorial of large numbers **/
long long int InverseFunctionMethod::findFactorial(int num){
    int fact = 1, i;
    for(i = 1; i <= num; i++)
        fact = fact * i;
    return fact;
}

/**
 * method to activateModel random values using inverse function method
 * @param a
 * @param b
 * @param k
 * @return
 */
int InverseFunctionMethod::generateRandomValue(int a, int b, int k) {
    int i = 0;
    int n = a + b;

//    std::cout <<"fac1 " << (long double)(findFactorial(b) * findFactorial(n-k)) <<  std::endl ;
//    std::cout <<"fac2 " << (long double)(findFactorial(n - a - k)) << std::endl;
//
//    std::cout <<"fac3 " << (long double)(findFactorial(n)) <<  std::endl ;

    long double p = (long double)(findFactorial(b) * findFactorial(n - k)) / findFactorial(n - a - k) / findFactorial(n);
    long double l = p;
//    std::cout <<"l " << l <<  std::endl ;
    long double  alpha = randomRange(0, 1);
//    std::cout <<"alpha " <<  alpha <<  std::endl ;


    while (alpha >= l){
        p = p * (a - i) * (k - i) / ((i + 1) * (n - a - k + i + 1));
//        std::cout <<"p: "  << p << std::endl ;
        l += p;
        i++;
//        std::cout <<"haloo: "  << i << " " << l  << std::endl ;


    }
//    std::cout << "i: " << i << std::endl;
    return i;
}

/**
 * Generate distribution
 * @param trials
 * @param a
 * @param b
 * @param k
 * @param nt
 * @param p_fin
 * @param exp_freq
 * @param act_freq
 * @param p_dist
 * @param p_dist_alt
 * @return
 */
double InverseFunctionMethod::createDist(int trials, int a, int b, int k, int nt, double &p_fin,
                                   std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist, std::vector<double> &p_dist_alt) {

    HyperGeomTheoretical model_t;
    double chi_sq;
    double chi_sq_alt;
    int q1, q2, q_temp;
    int df = 0;

    auto p = std::vector<double>(trials, 0); // histograms
    auto p_alt = std::vector<double>(trials, 0); // histograms

    std::vector<int> h1(a + 1, 0); // histograms
    std::vector<int> h2(a + 1, 0);
    std::vector<double> h(a + 1, 0);
    std::vector<double> h_freq(a + 1, 0);

    InverseFunctionMethod model(a);
    BernoulliMethod model_temp(a);

    for (int l = 0; l < trials; ++l) {
        for (int j = 0; j != nt; ++j) {
            q1 = model.generateRandomValue(a, b, k);
            q2 = model.generateRandomValue(5, 5, 4);
            q_temp = model_temp.generateRandomValue(a, b, k);
//            std::cout  << j << ": q1 "  << q1 << " q_temp " << q_temp << std::endl;

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

        exp_freq.clear();
        act_freq.clear();


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


        p_dist.clear();
        for (double & i : p)
            if (i > 0){
                p_dist.push_back(i);
            }

        p_dist_alt.clear();
        for (double & i : p_alt)
            if (i > 0) {
                p_dist_alt.push_back(i);
            }

    }
    return chi_sq;

}
