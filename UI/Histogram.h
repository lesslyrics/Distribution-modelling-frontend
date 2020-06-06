//
// Created by lesslyrics on 13.04.2020.
//
/**
\file
\author @lesslyrics (Alina Boshchenko)
\brief UI header file for the histogram

Contains methods needed for the histogram with parameters construction
**/
#pragma once

#include <QtGui/QPainter>
#include <Model/Model.h>
#include <renderarea.h>


/**
 * UI: Draw histogram box
 * @param x
 * @param y
 * @param width
 * @param height
 * @param painter
 * @param color
 */
void createBox(float, float, float, float, QPainter &painter, QColor color);

/**
 * UI: Function to draw histogram for the distribution
 * @param sample_size
 * @param type
 * @param win_w
 * @param win_h
 * @param chi
 * @param p
 * @param exp_freq
 * @param act_freq
 * @param painter
 */
void createHistogram(int sample_size, ModellingType type, int win_w, int win_h, double chi, double p, std::vector<double> &exp_freq, std::vector<double> &act_freq, QPainter &painter);


/**
 * UI: Draw histogram parameters
 * @param sample_size
 * @param type
 * @param win_w
 * @param chi
 * @param p
 * @param exp_freq
 * @param act_freq
 * @param painter
 */
void printHistParams(int sample_size, ModellingType type, int win_w, double chi, double p,
                     std::vector<double> &exp_freq, std::vector<double> &act_freq, QPainter &painter);