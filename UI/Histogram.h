//
// Created by lesslyrics on 13.04.2020.
//

#ifndef DIALOGS_HISTOGRAM_H
#define DIALOGS_HISTOGRAM_H


#include <QtGui/QPainter>
#include <Model/Model.h>
#include <renderarea.h>

void createBox(float, float, float, float, QPainter &painter, QColor color);
void createHistogram(int sample_size, ModellingType type, int win_w, int win_h, double chi, double p, std::vector<double> &exp_freq, std::vector<double> &act_freq, QPainter &painter);


#endif //DIALOGS_HISTOGRAM_H
