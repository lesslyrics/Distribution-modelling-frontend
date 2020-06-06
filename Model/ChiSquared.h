#pragma once

#include <utility>
#include <vector>
#include "Model.h"


/**
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020

	Class for the Chi-squared statistics
**/
class ChiSquared {

protected:

    /**
      * expected frequencies
      */
    std::vector<double> exp_freq;

    /**
      * expected frequencies (accumulated)
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
    double getPValue() const;
    void setPValue(double pValue);

public:

    /**
     * compute statistics based on model and distribution
     * @param model
     * @param dist
     * @param trials
     * @param nt
     */
    void computeStatistics(HypogeomModel model, int trials, int nt, const std::vector<double> &expected_freq, const std::vector<double> &exp) {
        setExpFreq(expected_freq);
        setActFreq(model.getActualFreq());
        setExpected(exp);
        computeStatistics(trials, nt);
    }
    /**
     * method to calculate chi-square value
     * @param h_freq
     * @param h
     * @param h1
     * @param h2
     * @param df
     * @return
     */
    double
    calculate_chi(std::vector<double> &h_freq, std::vector<double> &h, std::vector<double> &h1, int &df, int a, int nt);


    /**
     * compute statistics
     * @param trials
     * @param nt
     */
    void computeStatistics(int trials, int nt) {

        int df = 0;
        double p_val = 0;

        std::vector<double> exp_freq_temp = getExpFreq();
        std::vector<double> exp_temp = getExpected();
        std::vector<double> act_freq_temp = getActFreq();

        setChiSq(calculate_chi(exp_freq_temp, exp_temp, act_freq_temp, df, exp_freq_temp.size() - 1, nt));

        CHI(1, df, chi_sq, p_val);
        setPValue(p_val);

        p_dist.push_back(p_val);

        std::fill(exp_freq_temp.begin(), exp_freq_temp.end(), 0);
        std::fill(exp_temp.begin(), exp_temp.end(), 0);
        std::fill(act_freq_temp.begin(), act_freq_temp.end(), 0);


    }

    /** getters and setters **/

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
