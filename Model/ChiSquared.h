//
// Created by lesslyrics on 26.04.2020.
//

#pragma once

#include <utility>
#include <vector>
#include "Model.h"

class ChiSquared {

protected:
    std::vector<double> exp_freq;
    std::vector<double> expected;

    std::vector<double> act_freq;
    std::vector<double> act_alt_freq;

    double chi_sq;
    double chi_sq_alt;

    double p_value;
    double p_value_alt;

public:
    double getPValue() const;

    void setPValue(double pValue);

protected:

    std::vector<double> p_dist;
    std::vector<double> p_dist_alt;
public:
    double getPValueAlt() const;

    void setPValueAlt(double pValueAlt);


public:

    /**
     * compute statistics based on model and distribution
     * @param model
     * @param dist
     * @param trials
     * @param nt
     */
    void computeStatistics(HypogeomModel model, HyperGeomTheoretical dist, int trials, int nt, const std::vector<double> &expected_freq, const std::vector<double> &exp) {
        setExpFreq(expected_freq);
        setActFreq(model.getActualFreq());
        setExpected(exp);
        setActAltFreq(model.getActualAltFreq());
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
        std::vector<double> act_alt_temp = getActAltFreq();


        setChiSq(calculate_chi(exp_freq_temp, exp_temp, act_freq_temp, df, exp_freq_temp.size() - 1, nt));
        setChiSqAlt(calculate_chi(exp_freq_temp, exp_temp, act_alt_temp, df, exp_freq_temp.size() - 1, nt));

        CHI(1, df, chi_sq, p_val);
        setPValue(p_val);

        p_dist.push_back(p_val);

        p_val = 0;
        CHI(1, df, chi_sq_alt, p_val);
        setPValueAlt(p_val);

        p_dist_alt.push_back(p_val);

        std::fill(exp_freq_temp.begin(), exp_freq_temp.end(), 0);
        std::fill(exp_temp.begin(), exp_temp.end(), 0);
        std::fill(act_freq_temp.begin(), act_freq_temp.end(), 0);
        std::fill(act_alt_temp.begin(), act_alt_temp.end(), 0);


    }

    /** getters and setters **/

    const std::vector<double> &getExpFreq() const;

    void setExpFreq(const std::vector<double> &expFreq);

    const std::vector<double> &getExpected() const;

    void setExpected(const std::vector<double> &expected);

    const std::vector<double> &getActFreq() const;

    void setActFreq(const std::vector<double> &actFreq);

    const std::vector<double> &getActAltFreq() const;

    void setActAltFreq(const std::vector<double> &actAltFreq);

    double getChiSq() const;

    void setChiSq(double chiSq);

    double getChiSqAlt() const;

    void setChiSqAlt(double chiSqAlt);

    const std::vector<double> &getPDist() const;

    void setPDist(const std::vector<double> &pDist);

    const std::vector<double> &getPDistAlt() const;

    void setPDistAlt(const std::vector<double> &pDistAlt);

};
