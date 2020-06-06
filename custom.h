#pragma once
#include <QDialog>
#include <Model/Model.h>
#include <Model/PType.h>
#include <iostream>


namespace Ui {
    class Custom;
}
/**
	\brief Ui class
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020

	Class for the custom task (power by sample size)
**/
class Custom : public QDialog {
Q_OBJECT

public:
    /**
     * Init
     * @param a_t
     * @param b_t
     * @param k_t
     * @param a_at
     * @param b_at
     * @param k_at
     * @param parent
     */
    explicit Custom(int a_t, int b_t, int k_t, int a_at, int b_at, int k_at, QWidget *parent = nullptr);


    /**
     * Acquire parameters for drawing
     * @param chi_tmp
     * @param expr_freq
     * @param actu_freq
     * @param p_dist
     * @param p_dist_alt
     */
     void activateModel(double &chi_tmp, std::vector<double> &expr_freq, std::vector<double> &actu_freq,
                       std::vector<double> &p_distr, PType p_type, int &a_tmp, int &b_tmp, int &k_tmp, int &a_tmp_alt, int &b_tmp_alt, int &k_tmp_alt){
        std::vector<double> p_alt_temp;
        for (int i = 0; i < 10; i++){
            p = modelPVal(trials, sample_size_min + i * 50, chi_tmp, expr_freq, actu_freq, p_distr, a, b, k, a_alt, b_alt, k_alt, p_type);
            chi = chi_tmp;
            for (int j = 0; j < p_distr.size() + 1; j++){
                if ((double)j / 10  - 0.1 <= alpha && double(j + 1) / 10 - 0.1 >= alpha)
                    p_alt_temp.push_back(p_distr[j]);
            }
        }
        p_distr.clear();
        for (double & i : p_alt_temp)
            if (i > 0){
                p_distr.push_back(i);
            }
        a_tmp = a;
        b_tmp = b;
        k_tmp = k;
        a_tmp_alt = a_alt;
        b_tmp_alt = b_alt;
        k_tmp_alt = k_alt;
    }


    /**
      * Getters
     **/
    int &getSampleSizeMin() { return sample_size_min; }

    double &getAlpha() { return alpha; }

    double &getP() { return p;}

    int &getA() { return a; }
    int &getB() { return b; }
    int &getK() { return k; }

    int &getA_alt() { return a_alt; }
    int &getB_alt() { return b_alt; }
    int &getK_alt() { return k_alt; }

    double &getChi() { return chi;}

    /**
     * Destructor
     */
    ~Custom();

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
    int trials = 1000;

    /**
     * significance level
     */
    double alpha = 0;

    /**
     * minimal sample size
     */
    int sample_size_min  = 50;
    Ui::Custom *ui;

};
