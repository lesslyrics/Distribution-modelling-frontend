#pragma once
#include <QDialog>
#include <Model/Model.h>
#include <Model/PType.h>

namespace Ui {
class PWindow;
}

class PWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PWindow(int width, QColor color, QWidget *parent = nullptr);

    QColor &getRectColor() { return rect_color; }

    int &getSampleSize() { return sample_size; }

    void activateModel(double &chi_tmp, std::vector<double> &expr_freq,
            std::vector<double> &actu_freq, std::vector<double> &p_dist, std::vector<double> &p_dist_alt) {
        p = model(trials, sample_size, chi_tmp, expr_freq, actu_freq, p_dist, p_dist_alt, a, b, k);
        chi = chi_tmp;
    }

    double &getP() { return p;}

    double &getChi() { return chi;}

    int &getTrials() { return trials;}

    PType &getPType() { return p_type; }


    ~PWindow();

protected:
    void done(int r) override;

private slots:


private:
    int a;
    int b;
    int k;
    std::vector<double> exp_freq;
    std::vector<double> act_freq;
    std::vector<double> p_dist;
    std::vector<double> p_dist_alt;

    PType p_type;


    double p = 0;
    double chi = 0;
    int trials;

    int sample_size;
    QColor rect_color;
    Ui::PWindow *ui;
};

