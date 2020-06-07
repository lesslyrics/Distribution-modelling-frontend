//
// Created by lesslyrics on 18.02.2020.
//

#include <iostream>
#include <random>
#include "HypogeomModel.h"
#include "time.h"


 /**
  * generate random number from the selected range
  * @param min - left edge
  * @param max - right edge
  * @return
  */
double HypogeomModel::randomRange(int min, int max) {

    return double(rand()) / RAND_MAX * (max - min) + min;
}

/**
 * method to generate random values for model
 * @param a - number of white balls
 * @param b - number of black balls
 * @param k - number of taken balls
 * @return random number
 */
int HypogeomModel::generateRandomValue(int a, int b, int k) {
    return 0;
}

/**
 * Generate distribution
 * @param a - number of white balls
 * @param b - number of black balls
 * @param k - number of taken balls
 * @param nt - number of trials
 * @param h - number of columns in histogram
 */
void HypogeomModel::createDist(int a, int b, int k, int nt, int h){
    return;
}

const std::vector<double> &HypogeomModel::getActualFreq(){
    return actual_freq;
}

void HypogeomModel::setActualFreq(const std::vector<double> &actualFreq) {
    actual_freq = actualFreq;
}

