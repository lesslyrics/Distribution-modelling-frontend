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


/**
 * method to perform sample merging based on pivot
 * @param h_freq
 * @param h
 * @param h1
 * @param h2
 */
void
merge_sample(std::vector<double> &h_freq, std::vector<double> &h, std::vector<double> &h1);

/**
 * method to build p-value distribution
 * @param hist_p
 * @param p
 * @param trials
 */
void build_p_dist(std::vector<int> &hist_p, std::vector<double> &p, int trials);

/**
 * Main method for distribution generation activation
 * @param trials
 * @param nt
 * @param chi
 * @param exp_freq
 * @param act_freq
 * @param p_dist
 * @param p_dist_alt
 * @param a
 * @param b
 * @param k
 * @return
 */

double modelDistribution(ModelType type, int trials, int nt, double &chi, std::vector<double> &exp_freq,
                         std::vector<double> &act_freq, std::vector<double> &p_dist, int a, int b,
                         int k);


/**
 * Refers to  chi-squared
 * @param chiStat
 * @param model
 * @param chi
 * @param nt
 * @param p
 * @param trials
 * @param expected_freq
 * @param expected
 * @param exp_freq
 * @param act_freq
 * @param p_dist
 */
void findChiStat(ChiSquared &chiStat, HypogeomModel *model, double &chi, int nt, std::vector<double> &p, int trials, std::vector<double>
expected_freq, std::vector<double> expected, std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist);



/**
 * Method for p-values distribution modelling
 * @param trials
 * @param nt
 * @param chi
 * @param exp_freq
 * @param act_freq
 * @param p_dist
 * @param a
 * @param b
 * @param k
 * @param a_alt
 * @param b_alt
 * @param k_alt
 * @param p_type
 * @return
 */
double modelPVal(int trials, int nt, double &chi, std::vector<double> &exp_freq,
                 std::vector<double> &act_freq, std::vector<double> &p_dist, int a, int b,
                 int k, int a_alt, int b_alt, int k_alt, PType p_type);