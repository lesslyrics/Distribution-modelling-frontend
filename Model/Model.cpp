#include <iostream>
#include "BernoulliMethod.h"
#include "InverseFunctionMethod.h"
#include <vector>
#include "probdist.h"
#include "Model.h"

/**
 * hyperparameters
 * */

const int FREQ = 5;

/**
 * method to calculate chi-square value
 * @param h_freq
 * @param h
 * @param h1
 * @param h2
 * @param df
 * @return
 */
double calculate_chi(std::vector<double> &h_freq, std::vector<double> &h, std::vector<int> &h1, int &df, int a, int nt) {
    double chi_sq = 0;
    df = -1;
    for (int i = 0; i != a + 1; ++i) {
        if (h_freq[i] != -1) {
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
void show_p(std::vector<int> &hist_p, std::vector<double> &p, int trials) {
    for (int i = 0; i < trials; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (p[i] < (double)j / 10.0 && p[i] > (double)(j - 1) / 10)
                hist_p[j - 1]++;
        }
    }

    for (int j = 1; j <= 10; ++j){
        hist_p[j] = (double)(hist_p[j - 1] + hist_p[j]);
    }

}

/**
 * Main method for distribution generation activation
 */
auto model(int trials, int nt, double &chi, std::vector<double> &exp_freq,
           std::vector<double> &act_freq,std::vector<double> &p_dist, std::vector<double> &p_dist_alt, int a, int b, int k) -> double {

    return model(ModelType::Bern, trials, nt, chi, exp_freq,
            act_freq,p_dist, p_dist_alt, a,  b, k);

}

auto model(ModelType type, int trials, int nt, double &chi, std::vector<double> &exp_freq,
        std::vector<double> &act_freq, std::vector<double> &p_dist,  std::vector<double> &p_dist_alt, int a, int b, int k) -> double {

    double p = 0;
    switch ( type ) {
        case ModelType::Bern : {
            BernoulliMethod model(a);
            chi = model.createDist(trials, a, b, k, nt, p, exp_freq, act_freq, p_dist, p_dist_alt);
            break;
        }
        case ModelType::Inv : {
            InverseFunctionMethod model(a);
            chi = model.createDist(trials, a, b, k, nt, p, exp_freq, act_freq, p_dist, p_dist_alt);
            break;
        }
        default:
            return 1;
    }

    auto hist_p = std::vector<int>(11, 0); // histograms
    auto hist_p_alt = std::vector<int>(11, 0); // histograms

    show_p(hist_p, p_dist, trials);
    std::cout << std::endl << std::endl;

    p_dist.clear();
    for(int i = 1; i < hist_p.size(); i++)
        p_dist.push_back(((double)hist_p[i - 1])/ trials);

    std::cout << std::endl;

    std::fill(hist_p.begin(), hist_p.end(), 0);
//----------------

    show_p(hist_p_alt, p_dist_alt, trials);
    std::cout << std::endl << std::endl;


    p_dist_alt.clear();
    for(int i = 1; i < hist_p_alt.size(); i++)
        p_dist_alt.push_back(((double)hist_p_alt[i - 1])/ trials);


    std::fill(hist_p_alt.begin(), hist_p_alt.end(), 0);

    return p;
}