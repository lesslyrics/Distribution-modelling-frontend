#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

enum class Menu {
    Model,
    Pval
};

enum class ModellingType{
    Bern,
    Inv
};

class RenderArea : public QWidget {
Q_OBJECT

public:
    explicit RenderArea(QWidget *parent = nullptr);

    Menu &getMenu() { return menu; }

    int &getLineWidth() { return line_width; }

    QColor &getRectColor() { return rect_color; }

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Menu menu;
    QColor rect_color = Qt::white;
    int line_width = 1;

    void paintEventColor(QPainter &painter);

    void paintHeadingEvent(QPainter &painter);

    void paintEventModel(QPainter &painter);
};

#endif // RENDERAREA_H
