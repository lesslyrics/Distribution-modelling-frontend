//
// Created by lesslyrics on 23.02.2020.
//

#pragma once

#include <vector>
#include "HypogeomModel.h"

class BernoulliMethodModel : public HypogeomModel {

public:
    explicit BernoulliMethodModel(int a){ h = std::vector<int>(a, 0 );}

    /**
    * Generate random value
    **/
    int generateRandomValue(int a, int b, int k);

    /**
    * Generate distribution
    **/
    void createDist(int trials, int a, int b, int k, int nt);

        /**
         * Destructor
         */
    ~BernoulliMethodModel() override = default;
};
