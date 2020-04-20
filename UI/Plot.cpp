//
// Created by lesslyrics on 20.04.2020.
//

#include <vector>
#include <QtGui/QPainter>
#include <iostream>
#include "Plot.h"
#define WIDTH 20.0
#define LIMIT_X 300
#define MOVE 100


void createPlot(int sample_size, std::vector<double> p_dist, int win_w, int win_h, int trials, QPainter &painter){

    double *p = &p_dist[0];

    float win_width = (float) win_w / LIMIT_X;
    float x, width = WIDTH;
    int i;
    QFont *font = new QFont("Courier", 12);
    QPen pen;//
//
//    for (int i = 0; i < p_dist.size(); i++)
//        std::cout << "hh " << i << " " << p_dist[i] << std::endl;

    /**Parameters description**/
    int length = p_dist.size();
    painter.setFont(*font);
    pen.setColor("white");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 40, "Sample size:");
    painter.drawText(2 * win_w / 3, 80, "P-value trials:");
    painter.drawText(2 * win_w / 3, 120, "Should follow:");

    pen.setColor("palegreen");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3 + 100, 200, "Actual");



    pen.setColor("lightsalmon");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3 + 120, 40, QString::number(sample_size));
    painter.drawText(2 * win_w / 3 + 150, 80, QString::number(trials));
    painter.drawText(2 * win_w / 3 + 140, 120, "Uniform");

    painter.drawText(2 * win_w / 3 + 100, 220, "Expected");

    pen.setColor("white");
    pen.setWidthF(4);
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 200, "Legend:");


    double step_x = 5 * win_w / 110;
    double step_y = 6 * win_h / 110;

    /** draw expected **/
    pen.setWidth(2);
    pen.setColor("lightsalmon");
    painter.setPen(pen);
    painter.drawLine(win_w / 11, 10 * win_h / 11,  win_w / 11 + step_x * 10 , 10 * win_h / 11 - step_y * 10);


    /** draw histogram **/
//    for (i = 0; i < 11; i++) {
//        painter.drawText(win_w / 18, 10 * win_h / 11 - i * step * 10, QString::number(i * step));
//    }
    painter.setPen(pen);
//    painter.drawText(3 * win_w / 25, 105 * win_h / 110, QString::number(0));

    pen.setWidth(2);
    pen.setColor("palegreen");
    painter.setPen(pen);
    for (i = 1; i < length; i++) {
        //numbers on the y-axes
        painter.drawLine( win_w / 11 - 3, 10 * win_h / 11 - (i-1) * step_y,  win_w / 11 + 3, 10 * win_h / 11 - (i-1) * step_y);
        painter.drawText(win_w / 11 - 40, 10 * win_h / 11 - (i-1) * step_y, QString::number((double)(i - 1)/10));
        //numbers on the x-axes
        painter.drawLine( win_w / 11 + (i-1) * step_x, 10 * win_h / 11 + 3,  win_w / 11 + (i-1) * step_x, 10 * win_h / 11 - 3);
        painter.drawText(win_w / 11 + (i-1) * step_x, 10 * win_h / 11 + 20, QString::number((double)(i - 1)/10));

        painter.drawLine( win_w / 11 + (i-1) * step_x, 10 * win_h / 11 - (i-1) * step_y * p[i-1],  win_w / 11 + i * step_x, 10 * win_h / 11 - i * step_y * p[i]);
    }

    //numbers on the y-axes
    painter.drawLine( win_w / 11 - 3, 10 * win_h / 11 - (i-1) * step_y,  win_w / 11 + 3, 10 * win_h / 11 - (i-1) * step_y);
    painter.drawText(win_w / 11 - 40, 10 * win_h / 11 - (i-1) * step_y, QString::number((double)(i - 1)/10));

    //numbers on the y-axes
    painter.drawLine( win_w / 11 - 3, 10 * win_h / 11 - (i) * step_y,  win_w / 11 + 3, 10 * win_h / 11 - (i) * step_y);
    painter.drawText(win_w / 11 - 40, 10 * win_h / 11 - (i) * step_y, QString::number((double)(i)/10));

    painter.drawLine( win_w / 11 + (i-1) * step_x, 10 * win_h / 11 + 3,  win_w / 11 + (i-1) * step_x, 10 * win_h / 11 - 3);
    painter.drawText(win_w / 11 + (i-1) * step_x, 10 * win_h / 11 + 20, QString::number((double)(i - 1)/10));

    painter.drawLine( win_w / 11 + (i) * step_x, 10 * win_h / 11 + 3,  win_w / 11 + (i) * step_x, 10 * win_h / 11 - 3);
    painter.drawText(win_w / 11 + (i) * step_x, 10 * win_h / 11 + 20, QString::number((double)(i)/10));

    painter.drawLine( win_w / 11 + (i-1) * step_x, 10 * win_h / 11 - (i-1) * step_y * p[i-1],  win_w / 11 + i * step_x, 10 * win_h / 11 - i * step_y * 1);




    /** draw x and y axes **/
    pen.setWidth(2);
    pen.setColor("white");
    painter.setPen(pen);
    painter.drawLine(win_w / 11, 10 * win_h / 11, win_w / 11, 10 * win_h / 11 - step_y * 10);
    painter.drawLine(win_w / 11, 10 * win_h / 11, win_w / 11 + step_x * 10 , 10 * win_h / 11);


}
