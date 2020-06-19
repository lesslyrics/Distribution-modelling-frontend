//
// Created by lesslyrics on 18.02.2020.
//

#include <iostream>
#include <random>
#include "HypogeomModel.h"
#include "time.h"
#include <random>


std::random_device rd;
std::mt19937 gen(rd());



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

