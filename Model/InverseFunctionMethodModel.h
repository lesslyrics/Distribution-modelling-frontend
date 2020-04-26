//
// Created by lesslyrics on 23.02.2020.
//

#pragma once

#include <vector>
#include "HypogeomModel.h"

class InverseFunctionMethodModel : public HypogeomModel{

public:
    explicit InverseFunctionMethodModel(int a){ h = std::vector<int>(a, 0 );}

    /**
     * Generate random value
     */
    int generateRandomValue(int a, int b, int k);

    /**
     * Find factorial
     */
    static long long int findFactorial(int num);

    /**
     * Generate distribution
     */
//   void createDist(int trials, int a, int b, int k, int nt, double &p_fin,
//                                             std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist, std::vector<double> &p_dist_alt);

    ~InverseFunctionMethodModel() override = default;

};
