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

    /**
     * Acquire parameters for drawing
     * @param chi_tmp
     * @param expr_freq
     * @param actu_freq
     * @param p_dist
     * @param p_dist_alt
     */
//    void activateModel(double &chi_tmp, std::vector<double> &expr_freq,
//                       std::vector<double> &actu_freq, std::vector<double> &p_dist, std::vector<double> &p_dist_alt) {
//        p = model(trials, sample_size, chi_tmp, expr_freq, actu_freq, p_dist, p_dist_alt, a, b, k);
//        chi = chi_tmp;
//    }

    void activateModel_tester(double &chi_tmp, std::vector<double> &expr_freq, std::vector<double> &actu_freq,
                       std::vector<double> &p_distr, PType p_type){

        p = model_tester(trials, sample_size, chi_tmp, expr_freq, actu_freq, p_distr,  a,  b, k, p_type);
        chi = chi_tmp;

    }
    /**
     * Getters
     * @return
     */
    QColor &getRectColor() { return rect_color; }

    int &getSampleSize() { return sample_size; }

    double &getP() { return p;}

    double &getChi() { return chi;}

    int &getTrials() { return trials;}

    PType &getPType() { return p_type; }

    /**
     * Destructor
     */
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

