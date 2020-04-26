//
// Created by lesslyrics on 18.02.2020.
//

#pragma once

#include <cstdint>

class HypogeomModel {

public:
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
    virtual void createDist(int trials, int a, int b, int k, int nt);


        virtual ~HypogeomModel() = default;

    const std::vector<double> &getActualFreq();

    void setActualFreq(const std::vector<double> &actualFreq);

    const std::vector<double> &getActualAltFreq();

    void setActualAltFreq(const std::vector<double> &actualAltFreq);
};
