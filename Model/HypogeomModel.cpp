//
// Created by lesslyrics on 18.02.2020.
//

#include <iostream>
#include <random>
#include "HypogeomModel.h"
#include "time.h"

const int NT = 100000; // number of trials


double HypogeomModel::randomRange(int min, int max) {

    return double( rand())/RAND_MAX* ( max - min ) + min;

/**
 * preferred version for more accurate random numbers, but with lower speed **/

//    std::random_device rd;  //Will be used to obtain a seed for the random number engine
//    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
//    std::uniform_real_distribution<> dis(min, max);
//    return dis(gen);


}

int HypogeomModel::generateRandomValue(int a, int b, int k) {
    return 0;
}


//std::vector<int> HypogeomModel::generateHist(int a, int b, int k) {
//    int q;
//    for (int j = 0; j != NT; ++j) {
//        q = generateRandomValue(a, b, k);
//        h[q]++; // count
//    }
//}

double HypogeomModel::createDist(int trials, int a, int b, int k, int nt, double &p_fin, std::vector<double> &exp_freq){
    return 0;
}

