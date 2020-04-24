#pragma once
#include <QDialog>
#include <Model/Model.h>
#include <Model/PType.h>
#include <iostream>


namespace Ui {
    class Custom;
}

class Custom : public QDialog {
Q_OBJECT

public:
    explicit Custom(int width, QColor color, QWidget *parent = nullptr);


    /**
     * Acquire parameters for drawing
     * @param chi_tmp
     * @param expr_freq
     * @param actu_freq
     * @param p_dist
     * @param p_dist_alt
     */
    void activateModel(double &chi_tmp, std::vector<double> &expr_freq,
                       std::vector<double> &actu_freq, std::vector<double> &p_dist, std::vector<double> &p_dist_alt) {
        p = model(trials, sample_size_min, chi_tmp, expr_freq, actu_freq, p_dist, p_dist_alt, a, b, k);

        std::vector<double> p_alt_temp;
        for (double & i : p_dist_alt)
            if (i > 0){
                p_alt_temp.push_back(i);
            }

        p = model(trials, sample_size_med, chi_tmp, expr_freq, actu_freq, p_dist, p_dist_alt, a, b, k);

        for (double & i : p_dist_alt)
            if (i > 0){
                p_alt_temp.push_back(i);
            }

        p = model(trials, sample_size_max, chi_tmp, expr_freq, actu_freq, p_dist, p_dist_alt, a, b, k);

        for (double & i : p_dist_alt)
            if (i > 0){
                p_alt_temp.push_back(i);
            }
        chi = chi_tmp;

        p_dist_alt.clear();
        for (double & i : p_alt_temp)
            if (i > 0){
                p_dist_alt.push_back(i);
            }
        chi = chi_tmp;

        for (double & i : p_alt_temp)
            std::cout << "p-dist-alt:" << i << std::endl;
        std::cout << std::endl;

    }

    /**
      * Getters
     **/
    int &getSampleSizeMin() { return sample_size_min; }
    int &getSampleSizeMed() { return sample_size_med; }
    int &getSampleSizeMax() { return sample_size_max; }
    QColor &getRectColor() { return rect_color; }

    double &getAlpha() { return alpha; }

    double &getP() { return p;}

    int &getA() { return a; }
    int &getB() { return b; }
    int &getK() { return k; }

    double &getChi() { return chi;}

    /**
     * Destructor
     */
    ~Custom();

protected:
    void done(int r) override;

private slots:


private:
    int a;
    int b;
    int k;
    double alpha = 0;
    std::vector<double> exp_freq;
    std::vector<double> act_freq;

    double p = 0;
    double chi = 0;
    int trials = 10000;
    ModelType modelType = ModelType::Bern;

    int sample_size  = 50;

    int sample_size_min  = 50;
    int sample_size_med = 100 ;
    int sample_size_max = 1000;

    QColor rect_color;
    Ui::Custom *ui;

};
