#include "BernoulliMethodModel.h"
#include "InverseFunctionMethodModel.h"
#include "HyperGeomTheoretical.h"
#include "probdist.h"
#include "ModelType.h"
#include "ChiSquared.h"
#include "PType.h"


class ChiSquared;

/**
 * method to perform sample merging based on pivot
 * @param h_freq
 * @param h
 * @param h1
 * @param h2
 */
void merge_sample(std::vector<double> &h_freq, std::vector<double> &h, std::vector<double> &h1, std::vector<double> &h2);

/**
 * method to print p-value distribution
 * @param hist_p
 * @param p
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
auto model(int trials, int nt, double &chi, std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist,  std::vector<double> &p_dist_alt, int a, int b, int k) -> double;

auto model(ModelType type, int trials, int nt, double &chi, std::vector<double> &exp_freq,
           std::vector<double> &act_freq, std::vector<double> &p_dist, std::vector<double> &p_dist_alt, int a, int b, int k) -> double;


double tester(ModelType type, int trials, int nt, double &chi, std::vector<double> &exp_freq,
              std::vector<double> &act_freq, std::vector<double> &p_dist, int a, int b,
              int k);

void
merge_sample_tester(std::vector<double> &h_freq, std::vector<double> &h, std::vector<double> &h1);



void findChiStat_tester( ChiSquared &chiStat, HypogeomModel *model, double &chi, int nt,  std::vector<double> &p, int trials, std::vector<double>
expected_freq, std::vector<double> expected, std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist);




double tester_p(ModelType type, int trials, int nt, double &chi, std::vector<double> &exp_freq,
                std::vector<double> &act_freq, std::vector<double> &p_dist,  int a, int b,
                int k);

double model_tester(int trials, int nt, double &chi, std::vector<double> &exp_freq,
                    std::vector<double> &act_freq, std::vector<double> &p_dist,  int a, int b,
                    int k, PType type);

double tester_p2(ModelType type, int trials, int nt, double &chi, std::vector<double> &exp_freq,
                 std::vector<double> &act_freq, std::vector<double> &p_dist, int a, int b,
                 int k);