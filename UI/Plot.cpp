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


void createPlot(int sample_size, std::vector<double> p_dist, std::vector<double> p_dist_alt,
        int win_w, int win_h, int trials, QPainter &painter, PType p_type, QString color){

    double *p;
    if (p_type == PType::Power)
       p = &p_dist_alt[0];
    else
       p = &p_dist[0];

    int i;
    QFont *font = new QFont("Courier", 12);
    QPen pen;//


    /**Parameters description**/
    int length = 10;

    double step_x = 5 * win_w / 110;
    double step_y = 6 * win_h / 110;

    /** draw expected **/
    if (p_type == PType::Error){
        pen.setWidth(2);
        pen.setStyle(Qt::DashLine);

        pen.setColor("lightsalmon");
        painter.setPen(pen);
        painter.drawLine(win_w / 11, 10 * win_h / 11,  win_w / 11 + step_x * 10 , 10 * win_h / 11 - step_y * 10);
    }

    /*Draw plot*/
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);

    pen.setColor(color);
    painter.setPen(pen);

    if (p_type == PType::Power)
        drawForPower(i, win_w, win_h, step_x, step_y, length, p, painter);
    else
        drawForError(i, win_w, win_h, step_x, step_y, length, p, painter);

    drawMinors(i, win_w, win_h, step_x, step_y, length, painter);

    // draw x and y axes
    pen.setWidth(2);
    pen.setColor("white");

    painter.setPen(pen);
    painter.drawLine(win_w / 11, 10 * win_h / 11, win_w / 11, 10 * win_h / 11 - step_y * 10);
    painter.drawLine(win_w / 11, 10 * win_h / 11, win_w / 11 + step_x * 10 , 10 * win_h / 11);

}

void createPlot_tester(int sample_size, std::vector<double> p_dist,
                int win_w, int win_h, int trials, QPainter &painter, PType p_type, QString color){

    double *p;
    p = &p_dist[0];

    int i;
    QFont *font = new QFont("Courier", 12);
    QPen pen;//


    /**Parameters description**/
    int length = 10;

    double step_x = 5 * win_w / 110;
    double step_y = 6 * win_h / 110;

    /** draw expected **/
    if (p_type == PType::Error){
        pen.setWidth(2);
        pen.setStyle(Qt::DashLine);

        pen.setColor("lightsalmon");
        painter.setPen(pen);
        painter.drawLine(win_w / 11, 10 * win_h / 11,  win_w / 11 + step_x * 10 , 10 * win_h / 11 - step_y * 10);
    }

    /*Draw plot*/
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);

    pen.setColor(color);
    painter.setPen(pen);

    if (p_type == PType::Power)
        drawForPower(i, win_w, win_h, step_x, step_y, length, p, painter);
    else
        drawForError(i, win_w, win_h, step_x, step_y, length, p, painter);

    drawMinors(i, win_w, win_h, step_x, step_y, length, painter);

    // draw x and y axes
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

void drawParams(int sample_size, int win_w, int trials, QPainter &painter, PType p_type ){
    //Parameters description
    QPen pen;//

    int length = 10;
    QFont *font = new QFont("Courier", 12);
    painter.setFont(*font);
    pen.setColor("white");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 40, "Sample size:");
    painter.drawText(2 * win_w / 3, 80, "P-value trials:");
    painter.drawText(2 * win_w / 3, 120, "Alternative:");
    painter.drawText(2 * win_w / 3, 200, "Distibution for:");


    pen.setColor("palegreen");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3 + 100, 240, "Actual");


    pen.setColor("lightsalmon");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3 + 120, 40, QString::number(sample_size));
    painter.drawText(2 * win_w / 3 + 150, 80, QString::number(trials));
    painter.drawText(2 * win_w / 3 , 160, "Hypergeometric (5, 5, 4)");
    if (p_type == PType::Power)
        painter.drawText(2 * win_w / 3 + 160, 200, "Power");
    else
        painter.drawText(2 * win_w / 3 + 160, 200, "T.1 Error");


    painter.drawText(2 * win_w / 3 + 100, 280, "Expected");

    pen.setColor("white");
    pen.setWidthF(4);
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 240, "Legend:");


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


void createCustom(int sample_size, std::vector<double> p_dist, std::vector<double> p_dist_alt,
                    int win_w, int win_h, int trials, QPainter &painter, PType p_type,  QString color) {

    createPlot(sample_size, p_dist, p_dist_alt, win_w, win_h, trials, painter, p_type,  "gold");
    p_dist_alt.erase (p_dist_alt.begin(),p_dist_alt.begin() + 10);

    createPlot(sample_size, p_dist, p_dist_alt, win_w, win_h, trials, painter, p_type,  "lightsalmon");
    p_dist_alt.erase (p_dist_alt.begin(),p_dist_alt.begin() + 10);

    createPlot(sample_size, p_dist, p_dist_alt, win_w, win_h, trials, painter, p_type,  "palegreen");
    p_dist_alt.erase (p_dist_alt.begin(),p_dist_alt.begin() + 10);

}

void drawParamsCustom(int a, int b, int k, int sample_size_min, int sample_size_med, int sample_size_max, int win_w, int trials, QPainter &painter){
    //Parameters description
    QPen pen;//

    QFont *font = new QFont("Courier", 12);
    painter.setFont(*font);
    pen.setColor("gold");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 40, "Min sample size:");
    painter.drawText(2 * win_w / 3 + 160, 40, QString::number(sample_size_min));

    pen.setColor("lightsalmon");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 80, "Med sample size:");
    painter.drawText(2 * win_w / 3 + 160, 80, QString::number(sample_size_med));

    pen.setColor("palegreen");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 120, "Max sample size:");
    painter.drawText(2 * win_w / 3 + 160, 120, QString::number(sample_size_max));

    pen.setColor("white");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 160, "Alternative: ");
    painter.drawText(2 * win_w / 3, 240, "Trials: ");

    pen.setColor("wheat");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3 , 200, "Hypergeometric (" +  QString::number(a) + ", " +
                        QString::number(b) + ", " + QString::number(k) + ")");
    painter.drawText(2 * win_w / 3 + 80 , 240, QString::number(trials));

}

void drawAlpha(double alpha, double win_w, double win_h, QPainter &painter){

    // draw alpha-level
    double y = 5 * win_w / 110 * 10;
    double x = 6 * win_h / 110 * 12;


    QPen pen;
    pen.setWidth(2);
    pen.setColor("red");
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);
    painter.drawLine(win_w / 11, 10 * win_h / 11 - y * alpha, win_w / 11 + x , 10 * win_h / 11 - y * alpha);

    pen.setColor("red");
    painter.setPen(pen);
    painter.drawText(2 * win_w / 3, 280, "Alpha: ");
    painter.drawText(2 * win_w / 3 + 80 , 280, QString::number(alpha));

}
