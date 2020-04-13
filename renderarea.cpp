#include "renderarea.h"
#include <QPainter>
#include <GL/glut.h>
#include <GL/gl.h>// or glew header, gl3w header,...
#include <array>

#include "Model/Model.h"
#include "UI/Histogram.h"

RenderArea::RenderArea(QWidget *parent)
        : QWidget(parent) {}


void RenderArea::paintEventModel(QPainter &painter) {
//    painter.setPen(QPen(rect_color, sample_size));
//    painter.drawLine(100, 200, 100, 400);

    float value[] = {100.0, 150.0, 130.0, 90.0, 70.0, 100.};
    int len = sizeof(value)/sizeof(*value);
    auto x = this->width();
    auto y = this->height();
    createHistogram(len, value, x, y, painter);

//    createCoordinate();

}



/*Color - rectangle drawing*/
void RenderArea::paintEventColor(QPainter &painter) {
    painter.setBrush(rect_color);
    painter.drawRect(200, 200, 200, 200);
}

/* Heading drawing */
void RenderArea::paintHeadingEvent(QPainter &painter) {
    QFont *font = new QFont("vemana2000bold", 12);
    QPen pen;
    auto x = this->width();
//
//    pen.setColor(Qt::red);
//    painter.setFont(*font);
//    painter.setPen(pen);
   // painter.drawText(x / 4, 40, s);

}

void RenderArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    paintHeadingEvent(painter);
    switch (menu) {
        case Menu::Model:
            paintEventModel(painter);
            break;
        case Menu::Pval:
            paintEventColor(painter);
            break;
    }

    this->update();
}
