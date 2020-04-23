//
// Created by lesslyrics on 20.04.2020.
//

#include <vector>
#include <QtGui/QPainter>
#include <iostream>
#include <QPen>
#include <Model/PType.h>
#include "Plot.h"
#define WIDTH 20.0
#define LIMIT_X 300
#define MOVE 100


void createPlot(int sample_size, std::vector<double> p_dist, std::vector<double> p_dist_alt, int win_w, int win_h, int trials, QPainter &painter, PType p_type){

    double *p;
    if (p_type == PType::Power)
       p = &p_dist_alt[0];
    else
       p = &p_dist[0];

    int i;
    QFont *font = new QFont("Courier", 12);
    QPen pen;//

    for (int i = 0; i < p_dist.size(); i++)
        std::cout << "hh " << i << " " << p_dist[i] << std::endl;

    /**Parameters description**/
    int length = p_dist.size();
    painter.setFont(*font);
    pen.setColor("white");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 40, "Sample size:");
    painter.drawText(2 * win_w / 3, 80, "P-value trials:");
    painter.drawText(2 * win_w / 3, 120, "Should follow:");
    painter.drawText(2 * win_w / 3, 160, "Distibution for:");


    pen.setColor("palegreen");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3 + 100, 200, "Actual");


    pen.setColor("lightsalmon");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3 + 120, 40, QString::number(sample_size));
    painter.drawText(2 * win_w / 3 + 150, 80, QString::number(trials));
    painter.drawText(2 * win_w / 3 + 140, 120, "Uniform");
    if (p_type == PType::Power)
        painter.drawText(2 * win_w / 3 + 160, 160, "Power");
    else
        painter.drawText(2 * win_w / 3 + 160, 160, "T.1 Error");


    painter.drawText(2 * win_w / 3 + 100, 220, "Expected");

    pen.setColor("white");
    pen.setWidthF(4);
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 200, "Legend:");


    double step_x = 5 * win_w / 110;
    double step_y = 6 * win_h / 110;

    /** draw expected **/
    pen.setWidth(2);
    pen.setStyle(Qt::DashLine);

    pen.setColor("lightsalmon");
    painter.setPen(pen);
    painter.drawLine(win_w / 11, 10 * win_h / 11,  win_w / 11 + step_x * 10 , 10 * win_h / 11 - step_y * 10);


    /*Draw plot*/
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);

    pen.setColor("palegreen");
    painter.setPen(pen);

    if (p_type == PType::Power)
        drawForPower(i, win_w, win_h, step_x, step_y, length, p, painter);
    else
        drawForError(i, win_w, win_h, step_x, step_y, length, p, painter);

    drawMinors(i, win_w, win_h, step_x, step_y, length, painter);

    /** draw x and y axes **/
    pen.setWidth(2);
    pen.setColor("white");

    painter.setPen(pen);
    painter.drawLine(win_w / 11, 10 * win_h / 11, win_w / 11, 10 * win_h / 11 - step_y * 10);
    painter.drawLine(win_w / 11, 10 * win_h / 11, win_w / 11 + step_x * 10 , 10 * win_h / 11);

}

void drawMinors(int i,int win_w, int win_h, double step_x, double step_y, int length, QPainter &painter){

    for (i = 1; i < length + 2; i++) {
        //numbers on the y-axes
        painter.drawLine( win_w / 11 - 3, 10 * win_h / 11 - (i-1) * step_y,  win_w / 11 + 3, 10 * win_h / 11 - (i-1) * step_y);
        painter.drawText(win_w / 11 - 40, 10 * win_h / 11 - (i-1) * step_y, QString::number((double)(i - 1)/10));
        //numbers on the x-axes
        painter.drawLine( win_w / 11 + (i-1) * step_x, 10 * win_h / 11 + 3,  win_w / 11 + (i-1) * step_x, 10 * win_h / 11 - 3);
        painter.drawText(win_w / 11 + (i-1) * step_x, 10 * win_h / 11 + 20, QString::number((double)(i - 1)/10));
    }
}


void drawForPower(int i, int win_w, int win_h, double step_x, double step_y, int length, const double* p, QPainter &painter){

    double height = 10 * step_y;

    for (i = 0; i < length - 1; i++){
        painter.drawLine( win_w / 11 + step_x * i, 10 * win_h / 11 - height * p[i] ,  win_w / 11 + step_x * (i + 1), 10 * win_h / 11 - height * p[i + 1] );
    }
    painter.drawLine( win_w / 11 + step_x * i, 10 * win_h / 11 - height * p[i] ,  win_w / 11 + step_x * (i + 1), 10 * win_h / 11 - height );


}

void drawForError(int i, int win_w, int win_h, double step_x, double step_y, int length, double* p, QPainter &painter){

    double height = 10 * step_y;
    i = 0;
    painter.drawLine( win_w / 11 , 10 * win_h / 11 ,  win_w / 11 + step_x, 10 * win_h / 11 - height * p[i]);

    for (i = 1; i < length - 1; i++){
        painter.drawLine( win_w / 11 + step_x * i, 10 * win_h / 11 - height * p[i - 1] ,  win_w / 11 + step_x * (i + 1), 10 * win_h / 11 - height * p[i] );
    }
    painter.drawLine( win_w / 11 + step_x * i, 10 * win_h / 11 - height * p[i - 1] ,  win_w / 11 + step_x * (i + 1), 10 * win_h / 11 - height );


}
