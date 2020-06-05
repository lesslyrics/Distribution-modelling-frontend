//
// Created by lesslyrics on 23.02.2020.
//

#pragma once

#include <vector>
#include "HypogeomModel.h"

class InverseFunctionMethodModel : public HypogeomModel{

public:
    explicit InverseFunctionMethodModel(int a){}

    /**
     * Generate random value
     */
    int generateRandomValue(int a, int b, int k) override ;

    /**
     * Find factorial
     */
    static long double findFactorial(int num);

    /**
     * Generate distribution
     */
    void createDist(int trials, int a, int b, int k, int nt, int h) override ;

    ~InverseFunctionMethodModel() override = default;

};

