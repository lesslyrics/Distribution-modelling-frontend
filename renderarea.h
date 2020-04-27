#pragma once

#include <QWidget>
#include <Model/PType.h>

enum class Menu {
    Model,
    Pval,
    Custom
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

    PType &getPType() { return p_type; }

    QColor &getRectColor() { return rect_color; }

    std::vector<double> &getExpFreq() { return exp_freq; }

    std::vector<double> &getActFreq() { return act_freq; }

    std::vector<double> &getPDist() { return p_dist; }

    std::vector<double> &getPDistAlt() { return p_dist_alt; }

    int &getTrials() { return trials; }

    int &getSampleSizeMin() { return sample_size_min; }
    int &getSampleSizeMed() { return sample_size_med; }
    int &getSampleSizeMax() { return sample_size_max; }

    double &getAlpha() { return alpha; }
    int &getA() { return a; }
    int &getB() { return b; }
    int &getK() { return k; }


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Menu menu;
    QColor rect_color = Qt::white;
    int sample_size = 1;
    int a;
    int b;
    int k;

    int sample_size_min = 0;
    int sample_size_med = 100;
    int sample_size_max = 1000;

    int line_width;

    double chi = 0;

    double p = 0;

    ModellingType model_type;

    PType p_type;

    int trials;

    double alpha;

    std::vector<double> exp_freq;
    std::vector<double> act_freq;
    std::vector<double> p_dist;
    std::vector<double> p_dist_alt;


    void paintEventPval(QPainter &painter, PType p_type);

    void paintEventModel(QPainter &painter);

    void paintEventCustom(QPainter &painter);

    void paintEventHello(QPainter &painter);


};
