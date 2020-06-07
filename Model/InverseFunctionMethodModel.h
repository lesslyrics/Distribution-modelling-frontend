#pragma once

#include <vector>
#include "HypogeomModel.h"

/**
	\brief Child class for distribution modelling
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020

	Class for the distribution modelling using Inverse Functions Method
**/
class InverseFunctionMethodModel : public HypogeomModel{

public:
    explicit InverseFunctionMethodModel(){}

    /*
        * method to generate random values
        * @param a - number of white balls
        * @param b - number of black balls
        * @param k - number of taken balls
        * @return random number
        */
    int generateRandomValue(int a, int b, int k) override ;

     /*
      *  Find factorial
      * @param num
      * @return factorial of the num
      */
    static long double findFactorial(int num);

    /*
      * Generate model with Inverse Function Method
      * @param a - number of white balls
      * @param b - number of black balls
      * @param k - number of taken balls
      * @param nt - number of trials
      * @param h - number of columns in histogram
      */
    void createDist(int a, int b, int k, int nt, int h) override ;

    ~InverseFunctionMethodModel() override = default;

};

