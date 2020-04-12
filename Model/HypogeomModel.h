//
// Created by lesslyrics on 18.02.2020.
//

#pragma once
#include <cstdint>

class HypogeomModel {

protected:
    std::vector<int> h; // histograms

public:
    explicit HypogeomModel(int a) {h = std::vector<int>(a, 0 );}
    double randomRange(int min, int max);
    virtual int generateRandomValue(int a, int b, int k);
    std::vector<int> generateHist(int a, int b, int k);
};
