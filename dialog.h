#pragma once

#include <QDialog>
#include <Model/Model.h>


namespace Ui {
    class Dialog;
}
/**
	\brief Ui class
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020

	Class for the modelling visualization
**/
class Dialog : public QDialog {
Q_OBJECT

public:
    /**
     * Initialize
     * @param width
     * @param color
     * @param parent
     */
    explicit Dialog(int width, QColor color, int a_t, int b_t, int k_t, QWidget *parent = nullptr);


    /**
     * Acquire parameters for drawing
     * @param chi_tmp
     * @param expr_freq
     * @param actu_freq
     * @param p_dist
     * @param p_dist_alt
     */
    void activateModel(double &chi_tmp, std::vector<double> &expr_freq, std::vector<double> &actu_freq,
            std::vector<double> &p_dist, int &a_tmp, int &b_tmp, int &k_tmp){
        p = modelDistribution(modelType, 1, sample_size, chi_tmp, expr_freq, actu_freq, p_dist, a, b, k);
        a_tmp = a;
        b_tmp = b;
        k_tmp = k;
        chi = chi_tmp;
    }

    /**
     * Getters
    **/

    int &getSampleSize() { return sample_size; }

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
    Ui::Dialog *ui;

};
