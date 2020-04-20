#include "BernoulliMethod.h"
#include "InverseFunctionMethod.h"
#include "HyperGeomTheoretical.h"
#include "probdist.h"
#include "ModelType.h"


/**
 * method to calculate chi-square value
 * @param h_freq
 * @param h
 * @param h1
 * @param h2
 * @param df
 * @return
 */
double calculate_chi(std::vector<double> &h_freq, std::vector<double> &h, std::vector<int> &h1, int &df, int a, int nt);

/**
 * method to perform sample merging based on pivot
 * @param h_freq
 * @param h
 * @param h1
 * @param h2
 */
void merge_sample(std::vector<double> &h_freq, std::vector<double> &h, std::vector<int> &h1, std::vector<int> &h2);

/**
 * method to print p-value distribution
 * @param hist_p
 * @param p
 */
void show_p(std::vector<int> &hist_p, std::vector<double> &p, int trials);

auto model(int trials, int nt, double &chi, std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist, int a, int b, int k) -> double;

auto model(ModelType type, int trials, int nt, double &chi, std::vector<double> &exp_freq,
        std::vector<double> &act_freq, std::vector<double> &p_dist, int a, int b, int k) -> double;