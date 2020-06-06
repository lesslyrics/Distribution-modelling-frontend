#pragma once
#include <QDialog>
#include <Model/Model.h>
#include <Model/PType.h>

namespace Ui {
class PWindow;
}

/**
	\brief Ui class
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020

	Class for the p-values distribution visualization
**/
class PWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * Initialize
     * @param a_t
     * @param b_t
     * @param k_t
     * @param a_at
     * @param b_at
     * @param k_at
     * @param parent
     */
    explicit PWindow(int a_t, int b_t, int k_t, int a_at, int b_at, int k_at, QWidget *parent = nullptr);

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
    /**
       * distribution parameter a
       */
    int a;
    /**
       * distribution parameter b
       */
    int b;
    /**
       * distribution parameter k
       */
    int k;
    /**
       * distribution parameter a_alternative (needed for the parameters in dialog memorization only)
       */
    int a_alt;
    /**
     * distribution parameter b_alternative (needed for the parameters in dialog memorization only)
     */
    int b_alt;
    /**
       * distribution parameter k_alternative (needed for the parameters in dialog memorization only)
       */
    int k_alt;
    /**
    * expected frequencies
    */
    std::vector<double> exp_freq;
    /**
       * actual frequencies
       */
    std::vector<double> act_freq;
    /**
       * p-values distribution
       */
    std::vector<double> p_dist;

    /**
    * p-values distribution types
    */
    PType p_type;

    /**
    * chi-squared statistic
    */
    double chi = 0;

    /**
     * p-value for chi-statistic
     */
    double p = 0;

    /**
     * trials
     */
    int trials;

    /**
     * sample size
     */
    int sample_size;
    Ui::PWindow *ui;
};

