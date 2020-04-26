//
// Created by lesslyrics on 18.02.2020.
//

#pragma once

#include <cstdint>

class HypogeomModel {

protected:
    std::vector<int> h; // histograms
    std::vector<double> actual_freq;
    std::vector<double> actual_alt_freq;


public:

    double randomRange(int min, int max);

    /**
      * Generate random value
      **/
    virtual int generateRandomValue(int a, int b, int k);

    /**
      * Generate distribution
      **/
    virtual double createDist(int trials, int a, int b, int k, int nt, double &p_fin,
                              std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist,
                              std::vector<double> &p_dist_alt);

    virtual ~HypogeomModel() = default;

    const std::vector<double> &getActualFreq() const;

    void setActualFreq(const std::vector<double> &actualFreq);

    const std::vector<double> &getActualAltFreq() const;

    void setActualAltFreq(const std::vector<double> &actualAltFreq);
};
