#include "renderarea.h"
#include <QPainter>
#include <array>
#include <iostream>
#include <UI/Plot.h>
#include <Model/PType.h>
#include <QTimer>
#include "UI/Histogram.h"

RenderArea::RenderArea(QWidget *parent)
        : QWidget(parent) {}


/**
* Rendering:Model
* @param painter
*/
void RenderArea::paintEventModel(QPainter &painter) {

    auto x = this->width();
    auto y = this->height();
    QPen pen;
    pen.setColor("black");
    painter.setPen(pen);
    painter.drawRect(0, 0, x, y);
    if (sample_size != 1)
         createHistogram(sample_size, model_type, x, y, chi, p, exp_freq, act_freq, painter);

}

/**
 * Rendering: P-vals
 * @param painter
 * @param p_type
 */
void RenderArea::paintEventPval(QPainter &painter, PType p_type) {
    auto x = this->width();
    auto y = this->height();
    QString color = "palegreen";

    drawParams(sample_size, x, trials, painter, p_type );
    createPlot(p_dist, x, y, painter, p_type, color);


}

/**
 *  Rendering: Custom task
 * @param painter
 */
void RenderArea::paintEventCustom(QPainter &painter) {
    auto x = this->width();
    auto y = this->height();
    sample_size = sample_size_min;
    QString color = "palegreen";
    drawParamsCustom(a, b, k, sample_size_min, x, trials, painter);
//    createCustom(p_dist, x, y, painter, p_type);
    createCustomPlot(p_dist, x, y, painter, p_type, color, sample_size_min);

    drawAlpha(alpha, x, y, painter);

}

/**
 *  Rendering: Hello
 * @param painter
 */
void RenderArea::paintEventHello(QPainter &painter) {
    auto x = this->width();
    auto y = this->height();
    if (sample_size == 1) {
        QFont *font = new QFont("Courier", 14);
        QPen pen;//
        painter.setFont(*font);
        pen.setColor("white");
        painter.setPen(pen);
        painter.drawText(x / 15, y / 8, "Hello friend");
        painter.drawText(x / 15, y / 5, "Welcome to the tool for distribution modelling");
        painter.drawText(x / 15, 2 * y / 7, "Select menu item to start_");
    }
}

/**
   * Rendering: Overall
   * @param event
   */
void RenderArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    paintEventHello(painter);

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
