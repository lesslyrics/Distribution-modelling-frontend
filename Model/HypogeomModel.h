//
// Created by lesslyrics on 18.02.2020.
//

#pragma once
#include <cstdint>

class HypogeomModel {

protected:
    std::vector<int> h; // histograms
    std::vector<double> exp_frq;
    int size;
    double p_value;
    double chi_sqrt;


public:
    explicit HypogeomModel(int a) {h = std::vector<int>(a, 0 );}

    double randomRange(int min, int max);

    virtual int generateRandomValue(int a, int b, int k);

//    std::vector<int> generateHist(int a, int b, int k);

    virtual double createDist(int trials, int a, int b, int k, int nt, double &p_fin,
                                                std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist, std::vector<double> &p_dist_alt);

};
