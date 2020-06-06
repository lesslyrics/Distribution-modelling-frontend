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
    /**
     * Initialize
     * @param width
     * @param color
     * @param a_t
     * @param b_t
     * @param k_t
     * @param a_at
     * @param b_at
     * @param k_at
     * @param parent
     */
    explicit PWindow(int width, QColor color, int a_t, int b_t, int k_t, int a_at, int b_at, int k_at, QWidget *parent = nullptr);

    /**
     * Acquire parameters for drawing
     * @param chi_tmp
     * @param expr_freq
     * @param actu_freq
     * @param p_dist
     * @param p_dist_alt
     */
    void activateModel(double &chi_tmp, std::vector<double> &expr_freq, std::vector<double> &actu_freq,
                       std::vector<double> &p_distr, PType p_type, int &a_tmp, int &b_tmp, int &k_tmp, int &a_tmp_alt, int &b_tmp_alt, int &k_tmp_alt ){

        p = modelPVal(trials, sample_size, chi_tmp, expr_freq, actu_freq, p_distr, a, b, k, a_alt, b_alt, k_alt, p_type);
        a_tmp = a;
        b_tmp = b;
        k_tmp = k;
        a_tmp_alt = a_alt;
        b_tmp_alt = b_alt;
        k_tmp_alt = k_alt;
        chi = chi_tmp;

    }

    /**
     * Getters
     * @return
     */

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
    int a_alt;
    int b_alt;
    int k_alt;
    std::vector<double> exp_freq;
    std::vector<double> act_freq;
    std::vector<double> p_dist;

    PType p_type;

    double p = 0;
    double chi = 0;
    int trials;

    int sample_size;
    Ui::PWindow *ui;
};

