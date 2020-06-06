#pragma once

#include <vector>
#include "HypogeomModel.h"

/**
	\brief Child class
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020

	Class for the distribution modelling using Inverse Functions Method
**/
class InverseFunctionMethodModel : public HypogeomModel{

public:
    explicit InverseFunctionMethodModel(){}

     /**
      * Generate random value
      * @param a
      * @param b
      * @param k
      * @return
      */
    int generateRandomValue(int a, int b, int k) override ;

     /**
      *  Find factorial
      * @param num
      * @return
      */
    static long double findFactorial(int num);

     /**
      * Generate distribution
      * @param trials
      * @param a
      * @param b
      * @param k
      * @param nt
      * @param h
      */
    void createDist(int trials, int a, int b, int k, int nt, int h) override ;

    ~InverseFunctionMethodModel() override = default;

};

