#pragma once

#include <utility>
#include <vector>
#include "Model.h"
/**
 * hyperparameters for chi-squared assumptions
 * */


/**
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020
	\brief Class for the Chi-squared statistics
     @example Example.cpp

**/

class ChiSquared {

protected:

    /**
      * expected frequencies
      */
    std::vector<double> exp_freq;


    /**
     * actual frequencies
     */
    std::vector<double> act_freq;

    /**
     * chi-squared statistics
     */
    double chi_sq = 0;
    /**
     *  p_value by chi-statistic
     */
    double p_value = 0;
    /**
   *  p_value distribution
   */
    std::vector<double> p_dist;

public:
    /** getter **/
    double getPValue() const;
    /**  setter**/
    void setPValue(double pValue);

public:

    /*
      * method to perform sample merging based on pivot
      * @param h_expected - expected frequencies
      * @param h_actual  - actual frequencies
      */
    void merge_sample(std::vector<double> &h_expected, std::vector<double> &h_actual);

     /*
      * compute statistics based on model and distribution (created for better structure)
      * @param model - model
      * @param nt - number of trials for distribution
      * @param dist  -  distribution
      */
    void computeStatistics(HypogeomModel model, HyperGeomTheoretical &dist, int nt) {
        std::vector<double> actual_freq = model.getActualFreq();
        std::vector<double> expected_freq;
        dist.modelTheoreticalDist(nt, expected_freq);

        merge_sample(expected_freq,  actual_freq);

        setExpFreq(expected_freq);
        setActFreq(actual_freq);
        model.setActualFreq(actual_freq);

        computeStatistics();
    }
    /*
    * calculate chi-statistics
    * @param h_expected - expected frequencies
    * @param h_actual  - actual frequencies
    * @param df - degrees of freedom
    * @return chi-squared statistics
    */
    double calculate_chi(std::vector<double> &h_expected, std::vector<double> &h_actual, int &df);


    /*
     * compute chi-squared statistics and find corresponding p-value
     */
    void computeStatistics() {

        int df = 0;
        double p_val = 0;

        std::vector<double> exp_freq_temp = getExpFreq();
        std::vector<double> act_freq_temp = getActFreq();

        setChiSq(calculate_chi(exp_freq_temp, act_freq_temp, df));

        CHI(1, df, chi_sq, p_val);
        setPValue(p_val);

        p_dist.push_back(p_val);

        std::fill(exp_freq_temp.begin(), exp_freq_temp.end(), 0);
        std::fill(act_freq_temp.begin(), act_freq_temp.end(), 0);


    }

    /*getters and setters */

    const std::vector<double> &getExpFreq() const;

    void setExpFreq(const std::vector<double> &expFreq);


    const std::vector<double> &getActFreq() const;

    void setActFreq(const std::vector<double> &actFreq);

    double getChiSq() const;

    void setChiSq(double chiSq);

    const std::vector<double> &getPDist() const;

    void setPDist(const std::vector<double> &pDist);



};
