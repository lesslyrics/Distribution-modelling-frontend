//
// Created by lesslyrics on 13.04.2020.
//

#include "Histogram.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>

using namespace std;
#define WIDTH 20.0
#define LIMIT_X 300
#define MOVE 100

void createHistogram(int sample_size, ModellingType type, int win_w, int win_h, double chi, double p,
                     std::vector<double> &exp_freq, std::vector<double> &act_freq, QPainter &painter) {


    double *a = &exp_freq[0];
    double *b = &act_freq[0];

    float win_width = (float) win_w / LIMIT_X;
    float x, width = WIDTH;
    int i;
    QFont *font = new QFont("Courier", 12);
    QPen pen;//
    chi = static_cast<int>(chi * 1000 + (chi >= 0.0 ? 0.5 : -0.5)) / 1000.0;
    p = static_cast<int>(p * 1000 + (p >= 0.0 ? 0.5 : -0.5)) / 1000.0;


    /**Parameters description**/
    int length = exp_freq.size();
    painter.setFont(*font);
    pen.setColor("white");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 40, "Chi-squared:");
    painter.drawText(2 * win_w / 3, 80, "P-value:");
    painter.drawText(2 * win_w / 3, 140, "Sample size:");
    painter.drawText(2 * win_w / 3, 180, "Method:");

    pen.setColor("thistle");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3 + 100, 240, "Expected");


    pen.setColor("darkorange");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3 + 120, 40, QString::number(chi));
    painter.drawText(2 * win_w / 3 + 80, 80, QString::number(p));
    painter.drawText(2 * win_w / 3 + 120, 140, QString::number(sample_size));

    if (type == ModellingType::Bern)
        painter.drawText(2 * win_w / 3 + 80, 180, "Bernoulli");
    else if (type == ModellingType::Inv)
        painter.drawText(2 * win_w / 3 + 80, 180, "Inverse functions");

    painter.drawText(2 * win_w / 3 + 100, 220, "Actual");

    pen.setColor("white");
    pen.setWidthF(4);
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 220, "Legend:");


    vector<double> vect_tmp;
    vect_tmp = exp_freq;
    sort(vect_tmp.begin(), vect_tmp.end());
    double max = vect_tmp[vect_tmp.size() - 1];
    int step = max / 10.0;


    /** draw histogram **/
    for (i = 0; i < 13; i++) {
        painter.drawText(win_w / 18, 10 * win_h / 11 - i * step * 10, QString::number(i * step));
    }
    painter.setPen(pen);
    painter.drawText(3 * win_w / 25, 105 * win_h / 110, QString::number(0));
    QColor col;

    for (i = 0; i < length; i++) {
        x = (i * width * win_width) + i * win_width + MOVE;
        if (i - 1 >= 0)
            painter.drawText(x, 105 * win_h / 110, QString::number(i));

        if (a[i] > b[i]){
            col = "thistle";
            createBox(x, 10 * win_h / 11, width * win_width, a[i], painter, col);
            QColor col = "chocolate";
            createBox(x, 10 * win_h / 11, width * win_width, b[i], painter, col);

        }
        else{
            QColor col = "chocolate";
            createBox(x, 10 * win_h / 11, width * win_width, b[i], painter, col);
            col = "thistle";
            createBox(x, 10 * win_h / 11, width * win_width, a[i], painter, col);
        }


    }
//    col = "chocolate";
//    x = (i * width * win_width) + i * win_width + MOVE;
//    createBox(x, 10 * win_h / 11, width * win_width, a[i], painter, col);
//    col = "thistle";
//    createBox(x, 10 * win_h / 11, width * win_width, b[i], painter, col);
//    painter.drawText(x, 105 * win_h / 110, QString::number(i));


    /** draw x and y axes **/
    pen.setWidth(2);
    pen.setColor("thistle");
    painter.setPen(pen);
    painter.drawLine(win_w / 11, 10 * win_h / 11, win_w / 11, 10 * win_h / 11 - (max + 2) * 10);
    painter.drawLine(win_w / 11, 10 * win_h / 11, (length + 1) * win_w / 11, 10 * win_h / 11);

}

void createBox(float x, float y, float width, float height, QPainter &painter, QColor color) {
    QPen pen;
    pen.setColor(color);
    pen.setWidth(width);
    painter.setPen(pen);
    painter.drawLine(x, y - width / 2, x, y - width / 2 - height * 10);

}
