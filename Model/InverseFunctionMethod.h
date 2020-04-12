//
// Created by lesslyrics on 23.02.2020.
//

#pragma once

#include <vector>
#include "HypogeomModel.h"

class InverseFunctionMethod : public virtual HypogeomModel{

public:
    explicit InverseFunctionMethod(int a): HypogeomModel(a){h = std::vector<int>(a, 0 );}
    int generateRandomValue(int a, int b, int k) override;
    static long long int findFactorial(int num);

};

