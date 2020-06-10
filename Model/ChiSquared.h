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
      * expected frequencies in percentage
      */
    std::vector<double> expected;

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
     * @param h - expected frequencies in percentage
     * @param h_freq - expected frequencies
     * @param h1  - actual frequencies
     */
    void merge_sample(std::vector<double> &h_freq, std::vector<double> &h, std::vector<double> &h1) ;

     /*
      * compute statistics based on model and distribution (created for better structure)
      * @param model - model
      * @param nt - number of trials for distribution
      * @param expected_freq  -  expected frequencies in percentage
      * @param exp  - expected frequencies in percentage
      */
    void computeStatistics(HypogeomModel model, int nt, std::vector<double> &expected_freq, std::vector<double> &exp) {
        std::vector<double> actual_freq = model.getActualFreq();
        merge_sample(expected_freq, exp, actual_freq);

        setExpected(exp);
        setExpFreq(expected_freq);
        model.setActualFreq(actual_freq);
        setActFreq(actual_freq);

        computeStatistics();
    }
    /*
    * calculate chi-statistics
    * @param h_freq - expected frequencies
    * @param h1  - actual frequencies
    * @param df - degrees of freedom
    * @return chi-squared statistics
    */
    double calculate_chi(std::vector<double> &h_freq, std::vector<double> &h1, int &df);


    /*
     * compute chi-squared statistics and find corresponding p-value
     */
    void computeStatistics() {

        int df = 0;
        double p_val = 0;

        std::vector<double> exp_freq_temp = getExpFreq();
        std::vector<double> exp_temp = getExpected();
        std::vector<double> act_freq_temp = getActFreq();

        setChiSq(calculate_chi(exp_freq_temp, act_freq_temp, df));

        CHI(1, df, chi_sq, p_val);
        setPValue(p_val);

        p_dist.push_back(p_val);

        std::fill(exp_freq_temp.begin(), exp_freq_temp.end(), 0);
        std::fill(exp_temp.begin(), exp_temp.end(), 0);
        std::fill(act_freq_temp.begin(), act_freq_temp.end(), 0);


    }

    /*getters and setters */

    const std::vector<double> &getExpFreq() const;

    void setExpFreq(const std::vector<double> &expFreq);

    const std::vector<double> &getExpected() const;

    void setExpected(const std::vector<double> &expected);

    const std::vector<double> &getActFreq() const;

    void setActFreq(const std::vector<double> &actFreq);

    double getChiSq() const;

    void setChiSq(double chiSq);

    const std::vector<double> &getPDist() const;

    void setPDist(const std::vector<double> &pDist);



};
