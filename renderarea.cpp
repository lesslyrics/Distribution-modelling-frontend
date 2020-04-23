#include "renderarea.h"
#include <QPainter>
#include <GL/glut.h>
#include <GL/gl.h>// or glew header, gl3w header,...
#include <array>
#include <iostream>
#include <UI/Plot.h>

#include "UI/Histogram.h"

RenderArea::RenderArea(QWidget *parent)
        : QWidget(parent) {}


void RenderArea::paintEventModel(QPainter &painter) {
//    painter.setPen(QPen(rect_color, sample_size));
//    painter.drawLine(100, 200, 100, 400);

    auto x = this->width();
    auto y = this->height();

    createHistogram(sample_size, model_type, x, y, chi, p, exp_freq, act_freq, painter);

}



/*Color - rectangle drawing*/
void RenderArea::paintEventPval(QPainter &painter) {
    auto x = this->width();
    auto y = this->height();

    createPlot(sample_size, p_dist, x, y, trials, painter);
}


void RenderArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    switch (menu) {
        case Menu::Model:
            paintEventModel(painter);
            break;
        case Menu::Pval:
            paintEventPval(painter);
            break;
    }

    this->update();
}
