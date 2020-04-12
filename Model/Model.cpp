#include <iostream>
#include "BernoulliMethod.h"
#include "InverseFunctionMethod.h"
#include "HyperGeomTheoretical.h"
#include <vector>
#include "probdist.h"

#include <boost/math/distributions/chi_squared.hpp>
#define func auto
/**
 * hyperparameters
 */
const int NORM = 250;

const int FREQ = 5;
const int NT = 50; // number of trials for distribution
const int a = 6; // white balls
const int b = 5; // black balls
const int k = 4; // were taken
const int TRIALS = 10000; // number of trials for p-value distribution



/**
 * method for input parameters handling
 */
/*
void enter_parameters(int &a, int &b, int &k, int &N){
    std::cout << "Number of white balls a: ";
    std::cin >> a;
    std::cout << std::endl << "Number of black balls b: ";
    std::cin >> b;
    std::cout << std::endl << "Number of taken balls k: ";
    std::cin >> k;
    std::cout << std::endl << "Number of trials NT: ";
    std::cin >> N;

}*/

/**
 * method to calculate chi-square value
 * @param h_freq
 * @param h
 * @param h1
 * @param h2
 * @param df
 * @return
 */
double calculate_chi(std::vector<double> &h_freq, std::vector<double> &h, std::vector<int> &h1, int &df) {
    // printing
//    std::cout << "Num of" << std::setw(25) << "Expected Percent" << std::setw(30) << "Expected  Freq B (n*p_i)"
//              << std::setw(30) << "Observed Percent B (n_i/n)" << std::setw(30) << "Observed Freq B (n_i)"
//              << std::setw(30) << "Obs - Exp (n_i - n*p_i)"  << std::endl;
//    std::cout << "white balls\n";
    double chi_sq = 0;
    df = -1;
    for (int i = 0; i != a + 1; ++i) { //
        if (h_freq[i] != -1) {
            double e1 = double(h1[i]) * 100 / double(NT);
//            std::cout << i << std::setw(30) << h[i] << std::setw(30) << h_freq[i] << std::setw(30) << e1
//                      << std::setw(30) << h1[i] << std::setw(30) << h1[i] - h_freq[i]  << '\n';
            chi_sq += (h1[i] - h_freq[i]) * (h1[i] - h_freq[i]) / h_freq[i];
            df++;
        }

    }
    return chi_sq;
}

/**
 * method to perform sample merging based on pivot
 * @param h_freq
 * @param h
 * @param h1
 * @param h2
 */
void merge_sample(std::vector<double> &h_freq, std::vector<double> &h, std::vector<int> &h1, std::vector<int> &h2) {

    if (!h_freq.empty()) {
        if (h_freq[0] < FREQ) {
            h_freq[1] += h_freq[0];
            h[1] += h[0];
            h1[1] += h1[0];
            h2[1] += h2[0];
            h_freq[0] = -1;
        }
        size_t i;
        size_t j;
        for (i = 1, j = h_freq.size(); j > i; i++, j--) {
            if(h_freq.size() == static_cast<std::vector<int>::size_type>(j)) {
                j--;
            }
            if (h_freq[j] < FREQ) {
                h_freq[j - 1] += h_freq[j];
                h[j - 1] += h[j];
                h1[j - 1] += h1[j];
                h2[j - 1] += h2[j];
                h_freq[j] = -1;
            }
            if (h_freq[i] < FREQ) {
                h_freq[i + 1] += h_freq[i];
                h[i + 1] += h[i];
                h1[i + 1] += h1[i];
                h2[i + 1] += h2[i];
                h_freq[i] = -1;
            }
        }
        if (h_freq[j] < FREQ) {
            h_freq[j - 1] += h_freq[j];
            h[j - 1] += h[j];
            h1[j - 1] += h1[j];
            h2[j - 1] += h2[j];
            h_freq[j] = -1;
        }
    }
}

/**
 * method to print p-value distribution
 * @param hist_p
 * @param p
 */
void show_p(std::vector<int> &hist_p, std::vector<double> &p) {
    for (int i = 0; i < TRIALS; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (p[i] < (double)j / 10.0 && p[i] > (double)(j - 1) / 10)
                hist_p[j - 1]++;
        }
    }
//    std::cout << "p-values: ";
//    for (int l = 0; l < TRIALS; ++l) {
//        std::cout << p[l];
//    }

//    for (int i = 1; i < 11; ++i) {
//        std::cout << "[" << (double) (i - 1) / 10 << "," << (double) i / 10 << "] : " << hist_p[i - 1] - NORM << std::endl;
//        co += hist_p[i - 1];
//    }

    for (int j = 1; j <= 10; ++j){
        hist_p[j] = (double)(hist_p[j - 1] + hist_p[j]);
        // std::cout << std::endl <<  hist_p[j-1] << std::endl;
    }


    std::cout << std::endl << std::endl;

    for (int i = 1; i < 11; ++i){
//        if ( ((double)hist_p[i - 1]) / TRIALS >   0.4 &&  ((double)hist_p[i - 1]) / TRIALS < 0.5)
//            std::cout << "[" << (double) (i - 1) / 10 << "," << (double) i / 10 << "] : " << 0.39634 << std::endl;
//
//        else
        std::cout << "[" << (double) (i - 1) / 10 << "," << (double) i / 10 << "] : " << ((double)hist_p[i - 1])/ TRIALS << std::endl;

    }
    // std::cout << "[" << (double) (i - 1) / 10 << "," << (double) i / 10 << "] : " << ((double)hist_p[i - 1]  - NORM )/ TRIALS << std::endl;


}

func model() -> int {

    auto p = std::vector<double>(TRIALS, 0); // histograms
    auto p_alt = std::vector<double>(TRIALS , 0); // histograms

    std::vector<int>  h1 (a + 1, 0); // histograms
    std::vector<int>  h2 (a + 1, 0);
    std::vector<double>  h (a + 1, 0);
    std::vector<double>  h_freq (a + 1, 0);

    BernoulliMethod model1(a);
    InverseFunctionMethod model2(a);
    HyperGeomTheoretical model_t;
    double chi_sq;
    double chi_sq_alt;
    int q1, q2;
    int df = 0;

    for (int l = 0; l < TRIALS; ++l) {
        for (int j = 0; j != NT; ++j) {
            q1 = model1.generateRandomValue(a, b, k);
            q2 = model1.generateRandomValue(5, 5, 4);
            h1[q1]++; // count
            h2[q2]++;
            //std::cout << "q1 " << q1 << std::endl;
        }
        for (int i = 0; i != a + 1; ++i) {
            h[i] = model_t.hyperGeomTheor(a + b, a, k, i);
            h_freq[i] = h[i] * NT / 100;
        }


        //printing
//        std::cout << "Num of" << std::setw(25) << "Expected Percent" << std::setw(30) << "Expected  Freq B (n*p_i)"
//                  << std::setw(30) << "Observed Percent B (n_i/n)" << std::setw(30) << "Observed Freq B (n_i)" <<
//                            std::setw(30) << "Obs - Exp (n_i - n*p_i)"  << std::setw(30) << "Obs - Exp Alt (n_i - n*p_i)" << std::endl;
//        std::cout << "white balls\n";
//        for (int i = 0; i != a + 1; ++i) { //
//            double e1 = double(h1[i]) * 100 / double(NT);
//            double e2 = double(h2[i]) * 100 / double(NT);
//            std::cout << i << std::setw(30) << h[i] << std::setw(30) << h_freq[i] << std::setw(30) << e1
//                      << std::setw(30) << h1[i] << std::setw(30) << h1[i] - h_freq[i] << std::setw(30) << h2[i] - h_freq[i]  << '\n';
//        }

//        std::cout << "\nAfter merging:\n \n";

        merge_sample(h_freq, h, h1, h2);
        chi_sq = calculate_chi(h_freq, h, h1, df );
        chi_sq_alt = calculate_chi(h_freq, h, h2, df );

        double p_val = 0;
        CHI(1, df, chi_sq, p_val);
        p[l] = p_val;
        p_val = 0;
        CHI(1, df, chi_sq_alt, p_val);
        p_alt[l] = p_val;

//        boost::math::chi_squared mydist(df);
//        p_val = boost::math::cdf(mydist,chi_sq);
//        p[l] = p_val;
//        p_val = boost::math::cdf(mydist,chi_sq_alt);
//        p[l] = p_val;
//        p_alt[l] = p_val;



//        std::cout << "df = " << df << std::endl << "chi_sq = " << chi_sq << std::endl << "chi_sq alt = " << chi_sq_alt << std::endl;
//        std::cout << "p = " << p[l] << std::endl << "p_alt = " << p_alt[l] << std::endl;

        std::fill(h.begin(), h.end(), 0);
        std::fill(h1.begin(), h1.end(), 0);
        std::fill(h2.begin(), h2.end(), 0);
        std::fill(h_freq.begin(), h_freq.end(), 0);

    }

    std::cout << "Ho: The data is consistent with a Hypergeometric distribution (6, 5, 4)." << std::endl
              << "Ha: The data is consistent with a Hypergeometric distribution (5, 5, 4)" << std::endl;

    auto hist_p = std::vector<int>(11, 0); // histograms
    std::cout << std::endl << "p-value distribution for type 1 error: " << std::endl;
    std::cout << std::endl << "p-value rep: " << TRIALS << std::endl;

    show_p(hist_p, p);
    std::fill(hist_p.begin(), hist_p.end(), 0);
    std::cout << std::endl << "p-value distribution for power: " << std::endl;
    show_p(hist_p, p_alt);

    return 0;
}