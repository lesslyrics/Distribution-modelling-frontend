#include "renderarea.h"
#include <QPainter>
#include <GL/glut.h>
#include <GL/gl.h>// or glew header, gl3w header,...
#include <array>
#include <iostream>
#include <UI/Plot.h>
#include <Model/PType.h>

#include "UI/Histogram.h"

RenderArea::RenderArea(QWidget *parent)
        : QWidget(parent) {}


void RenderArea::paintEventModel(QPainter &painter) {

    auto x = this->width();
    auto y = this->height();

    createHistogram(sample_size, model_type, x, y, chi, p, exp_freq, act_freq, painter);

}


void RenderArea::paintEventPval(QPainter &painter, PType p_type) {
    auto x = this->width();
    auto y = this->height();
    QString color = "palegreen";

    drawParams(sample_size, x, trials, painter, p_type );
    createPlot(sample_size, p_dist, p_dist_alt, x, y, trials, painter, p_type, color);

}

/*Color - rectangle drawing*/
void RenderArea::paintEventCustom(QPainter &painter) {
    auto x = this->width();
    auto y = this->height();
    QString color = "palegreen";
    drawParamsCustom(a, b, k, sample_size_min, sample_size_med, sample_size_max, x, trials, painter);
    createCustom(sample_size, p_dist, p_dist_alt, x, y, trials, painter, p_type, color);
    drawAlpha(alpha, x, y, painter);

}



void RenderArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    switch (menu) {
        case Menu::Model:
            paintEventModel(painter);
            break;
        case Menu::Pval:
            paintEventPval(painter, p_type);
            break;
        case Menu::Custom:
            paintEventCustom(painter);
            break;
    }

    this->update();
}
