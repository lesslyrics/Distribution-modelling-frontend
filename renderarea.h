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

    int &getSampleSize() { return sample_size; }

    int &getLineWidth() { return line_width; }


    double &getChi() { return chi; }

    double &getP() { return p; }

    ModellingType &getModelType() { return model_type; }


    QColor &getRectColor() { return rect_color; }

    std::vector<double> &getExpFreq() { return exp_freq; }


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Menu menu;
    QColor rect_color = Qt::white;
    int sample_size = 1;

    int line_width;

    double chi = 0;

    double p = 0;

    ModellingType model_type;

    std::vector<double> exp_freq;


    void paintEventColor(QPainter &painter);

    void paintHeadingEvent(QPainter &painter);

    void paintEventModel(QPainter &painter);
};

#endif // RENDERAREA_H
