//
// Created by lesslyrics on 13.04.2020.
//

#include "Histogram.h"
#include <math.h>


#include <iostream>

using namespace std;
#define WIDTH 20.0
#define LIMIT_X 300
#define MOVE 100

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
void createHistogram(int sample_size, ModellingType type, int win_w, int win_h, double chi, double p,
                     std::vector<double> &exp_freq, std::vector<double> &act_freq, QPainter &painter) {

    double *a = &exp_freq[0];
    double *b = &act_freq[0];

    QPen pen;

    float win_width = (float) win_w / LIMIT_X;
    float x, width = WIDTH;
    int i;
    QFont *font = new QFont("Courier", 12);
    chi = static_cast<int>(chi * 1000 + (chi >= 0.0 ? 0.5 : -0.5)) / 1000.0;
    p = static_cast<int>(p * 1000 + (p >= 0.0 ? 0.5 : -0.5)) / 1000.0;

//--------------------------------------------Print parameters
    /**Parameters description**/
    int length = exp_freq.size();
    painter.setFont(*font);
    pen.setColor("white");
    painter.setPen(pen);

    printHistParams(sample_size, type, win_w, chi, p, exp_freq, act_freq, painter);

    pen.setColor("white");
    pen.setWidthF(4);
    painter.setPen(pen);

//-------------------------------------Find boundaries for the plot
    vector<double> vect_tmp;
    vect_tmp = exp_freq;
    sort(vect_tmp.begin(), vect_tmp.end());
    double max;

    vector<double> vect_tmp_2;
    vect_tmp_2 = act_freq;
    sort(vect_tmp_2.begin(), vect_tmp_2.end());
    if (vect_tmp[vect_tmp.size() - 1] > vect_tmp_2[vect_tmp_2.size() - 1])
         max = vect_tmp[vect_tmp.size() - 1];
    else
        max = vect_tmp_2[vect_tmp_2.size() - 1];
//-------------------------------------Draw histogram
    double step = max / 10.0;
    pen.setWidthF(4);


    /** draw histogram **/
    for (i = 0; i < 13; i++) {
        pen.setWidthF(2);
        painter.setPen(pen);
        double num = i * step;
        num = roundf(num * 10) / 10;
        painter.drawText(win_w / 18 - 20, 10 * win_h / 11 - i * step * 10, QString::number(num));
        painter.drawLine(win_w / 11 - 3, 10 * win_h / 11 - i * step * 10, win_w / 11 + 3, 10 * win_h / 11 - i * step * 10);
    }
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

//------------------------------Draw x and y axes
    pen.setWidth(2);
    pen.setColor("thistle");
    painter.setPen(pen);
    painter.drawLine(win_w / 11, 10 * win_h / 11, win_w / 11, 10 * win_h / 11 - (max + 10) * 10);
    painter.drawLine(win_w / 11, 10 * win_h / 11, (length + 1) * win_w / 11, 10 * win_h / 11);

}

/**
 * UI: Draw histogram box
 * @param x
 * @param y
 * @param width
 * @param height
 * @param painter
 * @param color
 */
void createBox(float x, float y, float width, float height, QPainter &painter, QColor color) {
    QPen pen;
    pen.setColor(color);
    pen.setWidth(width);
    painter.setPen(pen);
    painter.drawLine(x, y - width / 2, x, y - width / 2 - height * 10);

}

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
                     std::vector<double> &exp_freq, std::vector<double> &act_freq, QPainter &painter){
    QPen pen;
    QFont *font = new QFont("Courier", 12);
    painter.setFont(*font);
    /**Parameters description**/
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
}
