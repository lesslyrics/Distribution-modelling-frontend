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

    std::vector<double> p_dist;
    std::vector<double> p_dist_alt;


public:

    /**
     * compute statistics based on model and distribution
     * @param model
     * @param dist
     * @param trials
     * @param nt
     */
    void computeStatistics(HypogeomModel model, HyperGeomTheoretical dist, int trials, int nt) {
        setExpFreq(dist.getExpectedFreq());
        setActFreq(model.getActualFreq());
        setExpected(dist.getExpected());
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
    double  calculate_chi(std::vector<double> &h_freq, std::vector<double> &h, std::vector<double> &h1, int &df, int a, int nt);


    /**
     * compute statistics
     * @param trials
     * @param nt
     */
    void computeStatistics(int trials, int nt) {

        for (int l = 0; l < trials; ++l) {

//            merge_sample(exp_freq, expected, act_freq, act_alt_freq);

            int df = 0;
            double p_val = 0;
            auto p = std::vector<double>(trials, 0); // p_distibutions
            auto p_alt = std::vector<double>(trials, 0);

            chi_sq = calculate_chi(exp_freq, expected, act_freq, df, exp_freq.size() - 1, nt);
            chi_sq_alt = calculate_chi(exp_freq, expected, act_alt_freq, df, exp_freq.size() - 1, nt);

            CHI(1, df, chi_sq, p_val);
            p[l] = p_val;
            p_val = 0;
            CHI(1, df, chi_sq_alt, p_val);
            p_alt[l] = p_val;



//            std::fill(expected.begin(), expected.end(), 0);


            p_dist.clear();
            for (double &i : p)
                if (i > 0) {
                    p_dist.push_back(i);
                }

            p_dist_alt.clear();
            for (double &i : p_alt)
                if (i > 0) {
                    p_dist_alt.push_back(i);
                }

            for (int i = 0; i < p_dist.size(); ++i) {
                std::cout << "p_dist" << std::setw(30) << p_dist[i] << std::setw(30) << "p_alt"
                 << std::setw(30) << p_dist_alt[i] << std::setw(30)  << '\n';
            }
        }
    }

    /** getters and setters **/

    const std::vector<double> &getExpFreq() const;

    void setExpFreq(const std::vector<double> &expFreq);

    const  std::vector<double> &getExpected() const;

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
