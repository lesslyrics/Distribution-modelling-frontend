/** \file Example.h
 * \brief Example header file to test essential methods
**/

#include "BernoulliMethodModel.h"
#include "HyperGeomTheoretical.h"
#include "probdist.h"
#include "ChiSquared.h"
#pragma once


/**
 *  Create theoretical HyperGeometric distribution with parameters (a, b, k)
 *  expected_freq - expected frequencies
 *  expected - expected frequencies in percentage
 */
void testDistribution();
/**
 *  Model HyperGeometric distribution with parameters (a, b, k) with Bernoulli/InverseFunction Method
 *  act_freq - actual frequencies
 *  uncomment to run for InverseFunction
 */
void testModelling();


/**
 * comute chi-statistics based on the model, distributin and number of troals
 * @param model - model
 * @param trials  - trials for p-value distributin (if not needed - set to 1 as default)
 * @param nt -  number of trials
 * @param expected_freq - expected frequencies (from distribution)
 * @param exp - expected frequencies in percentage (from distribution)
 */
void testChiStatistics(HypogeomModel model, int trials, int nt, const std::vector<double> &expected_freq,
                       const std::vector<double> &exp);
/**
 *
 * @param p - vector containing calculated p-values
 * @param trials - number of trials for the p-value distribution
 * @param p_dist - resulting value - vector containing accumulated p-values (distribution), ready-to-plot
 */
void testPDistribution(std::vector<double> &p, int trials,  std::vector<double> &p_dist);