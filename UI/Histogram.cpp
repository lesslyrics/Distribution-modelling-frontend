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
#define LIMIT_Y 1.1
#define MOVE 100

void createHistogram(int len, float *data, int win_w, int win_h, QPainter &painter ){


    float win_width = (float)win_w / LIMIT_X;
    float win_height = (float)win_h / LIMIT_Y;
    float x, y = win_height,  width = WIDTH;
    int i;
    for(i = 0; i < len; i++){
        x = (i * width * win_width) + i * win_width + MOVE;
        createBox(x, y, width * win_width, data[i], painter);
    }
}

void createBox(float x, float y, float width, float height, QPainter &painter ){
    painter.setPen(QPen(Qt::red, width));
    painter.drawLine(x, y - height, x, y);

}
