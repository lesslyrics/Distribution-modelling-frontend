//
// Created by lesslyrics on 13.04.2020.
//

#pragma once

#include <QtGui/QPainter>
#include <Model/Model.h>
#include <renderarea.h>

/**
 * Draw histogram box
 */
void createBox(float, float, float, float, QPainter &painter, QColor color);

/**
 * Draw histogram
 */
void createHistogram(int sample_size, ModellingType type, int win_w, int win_h, double chi, double p, std::vector<double> &exp_freq, std::vector<double> &act_freq, QPainter &painter);

/**
 * Draw histogram parameters
 */
void printHistParams(int sample_size, ModellingType type, int win_w, double chi, double p,
                     std::vector<double> &exp_freq, std::vector<double> &act_freq, QPainter &painter);