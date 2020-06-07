#include "BernoulliMethodModel.h"
#include "InverseFunctionMethodModel.h"
#include "HyperGeomTheoretical.h"
#include "probdist.h"
#include "ModelType.h"
#include "ChiSquared.h"
#include "PType.h"

/*! \file Model.h
    \brief Driver file, connector between frontend and backend
    @example Example.cpp
*/



class ChiSquared;


/*
 * method to perform sample merging based on pivot
 * @param h - expected frequencies in percentage
 * @param h_freq - expected frequencies
 * @param h1  - actual frequencies
 */
void merge_sample(std::vector<double> &h_freq, std::vector<double> &h, std::vector<double> &h1);

/*
 * method to build p-value distribution
 * @param hist_p - prepared values for the histogram
 * @param p - p-values
 * @param trials - number of trials for p-value distribution
 */
void build_p_dist(std::vector<int> &hist_p, std::vector<double> &p, int trials);



/*
    * Main method for distribution generation activation
    * @param type - type of modelling method
    * @param trials - number of trials for p-values distribution
    * @param nt - number of trials for distribution
    * @param chi - chi-squared statistics
    * @param exp_freq - expected frequencies
    * @param act_freq - actual frequencies
    * @param p_dist - p-value
    * @param a - number of white balls for H_o (used when error 1 mode is selected)
    * @param b - number of black balls for H_o (used when error 1 mode is selected)
    * @param k - number of taken balls for H_o (used when error 1 mode is selected)
    * @return chi-statistics
*/
double modelDistribution(ModelType type, int trials, int nt, double &chi, std::vector<double> &exp_freq,
                         std::vector<double> &act_freq, std::vector<double> &p_dist, int a, int b,
                         int k);

/*
 * Method to get Chi-Squared statistics from Chi-Squared class (added for more convenient usage)
 * @param chiStat  -  chi-statistics
 * @param model - model
 * @param chi -  chi-statistics to be assigned
 * @param nt - number of trials
 * @param p - p-value
 * @param expected_freq - expected frequencies
 * @param expected - expected frequencies in percentage
 * @param exp_freq - expected frequencies to be assigned
 * @param act_freq - actual frequencies to be assigned
 * @param p_dist - p-values distribution
 */
void findChiStat(ChiSquared &chiStat, HypogeomModel *model, double &chi, int nt, std::vector<double> &p, std::vector<double>
expected_freq, std::vector<double> expected, std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist);



/*
 * Method for the p-distriburion modelling
 * @param trials - number of trials for p-values distribution
 * @param nt - number of trials for distribution
 * @param chi - chi-squared statistics
 * @param exp_freq - expected frequencies
 * @param act_freq - actual frequencies
 * @param p_dist - p-values distribution
 * @param a - number of white balls for H_o (used when error 1 mode is selected)
 * @param b - number of black balls for H_o (used when error 1 mode is selected)
 * @param k - number of taken balls for H_o (used when error 1 mode is selected)
 * @param a_alt - number of white balls for H_1 (used when power mode is selected)
 * @param b_alt - number of black balls for H_1 (used when power mode is selected)
 * @param k_alt - number of taken balls for H_1 (used when power mode is selected)
 * @param p_type - power or error 1 mode
 * @return chi-statistics
 */
double modelPVal(int trials, int nt, double &chi, std::vector<double> &exp_freq,
                 std::vector<double> &act_freq, std::vector<double> &p_dist, int a, int b,
                 int k, int a_alt, int b_alt, int k_alt, PType p_type);