#pragma once

#include <cstdint>

/**
	\brief Parent class for distribution modelling
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020
    @example Example.cpp

	Class for the distribution modelling
**/
class HypogeomModel {

protected:
    /**
     * actual frequencies
     */
    std::vector<double> actual_freq;


public:
     /**
      * Generate random numbers, high speed
      * @param min
      * @param max
      * @return
      */
    double randomRange(int min, int max);

    /**
     * Generate value for distribution
     * @param a
     * @param b
     * @param k
     * @return
     */
    virtual int generateRandomValue(int a, int b, int k);

      /**
       * Generate distribution
       * @param trials
       * @param a
       * @param b
       * @param k
       * @param nt
       * @param h
       */
    virtual void createDist(int trials, int a, int b, int k, int nt, int h);

    /**
     * Destructor
     */
    virtual ~HypogeomModel() = default;

    /**
     * Get actual
     * @return
     */
    const std::vector<double> &getActualFreq();

    /**
     * Set actual
     **/
    void setActualFreq(const std::vector<double> &actualFreq);

};
