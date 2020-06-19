#pragma once

#include <vector>
#include "HypogeomModel.h"


/**
	\brief Child class for distribution modelling
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020

	Class for the distribution modelling using Bernoulli Method
**/
class BernoulliMethodModel : public HypogeomModel {

public:
    explicit BernoulliMethodModel(){}

    /*
      * method to generate random values using Bernoulli distribution
      * @param a - number of white balls
      * @param b - number of black balls
      * @param k - number of taken balls
      * @return random number
      */
    int generateRandomValue(int a, int b, int k) override;


    /*
     * Generate model with Bernoulli Method
     * @param a - number of white balls
     * @param b - number of black balls
     * @param k - number of taken balls
     * @param nt - number of trials
     * @param h - number of columns in histogram
     */
    void createDist(int a, int b, int k, int nt, int h) override;

    /*
     * Destructor
      */
    ~BernoulliMethodModel() override = default;
};
