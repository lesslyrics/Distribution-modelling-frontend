#include "renderarea.h"
#include <QPainter>
#include "Model/Model.h"
RenderArea::RenderArea(QWidget *parent)
        : QWidget(parent) {}

/*Format - line drawing*/
void RenderArea::paintEventFormat(QPainter &painter) {
    painter.setPen(QPen(rect_color, line_width));
    painter.drawLine(100, 200, 100, 400);
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
            paintEventFormat(painter);
            break;
        case Menu::Pval:
            paintEventColor(painter);
            break;
    }

    this->update();
}
