#pragma once

#include <QDialog>
#include <Model/Model.h>


namespace Ui {
    class Dialog;
}

class Dialog : public QDialog {
Q_OBJECT

public:
    /**
     * Initialize
     * @param width
     * @param color
     * @param parent
     */
    explicit Dialog(int width, QColor color, QWidget *parent = nullptr);

    QColor &getRectColor() { return rect_color; }

    int &getSampleSize() { return sample_size; }

    /**
     * Acquire parameters for drawing
     * @param chi_tmp
     * @param expr_freq
     * @param actu_freq
     * @param p_dist
     * @param p_dist_alt
     */
    void activateModel(double &chi_tmp, std::vector<double> &expr_freq, std::vector<double> &actu_freq,
            std::vector<double> &p_dist, std::vector<double> &p_dist_alt) {
        p = model(modelType, 1, sample_size, chi_tmp, expr_freq, actu_freq, p_dist, p_dist_alt, a, b, k);
        chi = chi_tmp;
    }

    /**
     * Getters
    **/
    double &getP() { return p;}

    double &getChi() { return chi;}

    ModelType &getModelType() { return modelType; }

    /**
     * Destructor
     */
    ~Dialog();

protected:
    void done(int r) override;

private slots:

private:
    int a;
    int b;
    int k;
    std::vector<double> exp_freq;
    std::vector<double> act_freq;

    double p = 0;
    double chi = 0;
    int trials;
    ModelType modelType;

    int sample_size;
    QColor rect_color;
    Ui::Dialog *ui;

};
