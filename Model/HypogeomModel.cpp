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
 * Generate random value
 */
int HypogeomModel::generateRandomValue(int a, int b, int k) {
    return 0;
}

/**
 * Generate distribution
 */
void HypogeomModel::createDist(int trials, int a, int b, int k, int nt, int h){
    return;
}

const std::vector<double> &HypogeomModel::getActualFreq(){
    return actual_freq;
}

void HypogeomModel::setActualFreq(const std::vector<double> &actualFreq) {
    actual_freq = actualFreq;
}

