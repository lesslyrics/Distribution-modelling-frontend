//
// Created by lesslyrics on 18.02.2020.
//

#include <iostream>
#include <random>
#include "HypogeomModel.h"
#include "time.h"


/**
 * Version for random numbers, high speed
 * **/
double HypogeomModel::randomRange(int min, int max) {

    return double(rand()) / RAND_MAX * (max - min) + min;
}

/**
 * preferred version for more accurate random numbers, but with lower speed **/

//    std::random_device rd;  //Will be used to obtain a seed for the random number engine
//    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
//    std::uniform_real_distribution<> dis(min, max);
//    return dis(gen);

/**
 * Generate random value
 */
int HypogeomModel::generateRandomValue(int a, int b, int k) {
    return 0;
}

/**
 * Generate distribution
 */
double HypogeomModel::createDist(int trials, int a, int b, int k, int nt,
        double &p_fin, std::vector<double> &exp_freq, std::vector<double> &act_freq, std::vector<double> &p_dist, std::vector<double> &p_dist_alt){
    return 0;
}

const std::vector<double> &HypogeomModel::getActualFreq() const {
    return actual_freq;
}

void HypogeomModel::setActualFreq(const std::vector<double> &actualFreq) {
    actual_freq = actualFreq;
}

const std::vector<double> &HypogeomModel::getActualAltFreq() const {
    return actual_alt_freq;
}

void HypogeomModel::setActualAltFreq(const std::vector<double> &actualAltFreq) {
    actual_alt_freq = actualAltFreq;
}

