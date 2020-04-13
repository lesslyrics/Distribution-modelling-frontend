//
// Created by lesslyrics on 13.04.2020.
//

#ifndef DIALOGS_HISTOGRAM_H
#define DIALOGS_HISTOGRAM_H


#include <QtGui/QPainter>

    void createBox(float, float, float, float, QPainter &painter);

    void createHistogram(int len, float *data, int win_w, int win_h, QPainter &painter);


#endif //DIALOGS_HISTOGRAM_H
