#pragma once

#include <QWidget>
#include <Model/PType.h>

/**
	\brief Ui class
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020

	Class for the menu elements selection
**/
enum class Menu {
    Model,
    Pval,
    Custom
};
/**
	\brief Enum class
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020

	Class for the modelling type selection
**/
enum class ModellingType{
    Bern,
    Inv
};

/**
	\brief Ui class
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020

	Render area class
**/
class RenderArea : public QWidget {
Q_OBJECT

public:
    /**
     * Initialize
     * @param parent
     */
    explicit RenderArea(QWidget *parent = nullptr);


    /**
    * Getters and setters
    * @param parent
    */

    Menu &getMenu() { return menu; }

    int &getSampleSize() { return sample_size; }

    double &getChi() { return chi; }

    double &getP() { return p; }

    ModellingType &getModelType() { return model_type; }

    PType &getPType() { return p_type; }

    std::vector<double> &getExpFreq() { return exp_freq; }

    std::vector<double> &getActFreq() { return act_freq; }

    std::vector<double> &getPDist() { return p_dist; }

    int &getTrials() { return trials; }

    int &getSampleSizeMin() { return sample_size_min; }

    double &getAlpha() { return alpha; }
    int &getA() { return a; }
    int &getB() { return b; }
    int &getK() { return k; }


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    /**
     * menu
     */
    Menu menu;
    /**
     * sample size
     */
    int sample_size = 1;
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
     * sample size for custom task
     */
    int sample_size_min = 0;

    /**
     * chi-squared statistic
     */
    double chi = 0;

    /**
     * p-value for chi-statistic
     */
    double p = 0;

    /**
     * modelling type
     */
    ModellingType model_type;

    /**
     * p-values distribution types
     */
    PType p_type;

    /**
     * number of trials
     */
    int trials;

    /**
     * alpha-level (significance level)
     */
    double alpha;
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
     * Rendering: P-values
     * @param painter
     * @param p_type
     */
    void paintEventPval(QPainter &painter, PType p_type);

    /**
     * Rendering: Model
     * @param painter
     */
    void paintEventModel(QPainter &painter);

    /**
    * Rendering: Custom task
    * @param painter
    */
    void paintEventCustom(QPainter &painter);

    /**
     * Rendering: Hello
     * @param painter
     */
    void paintEventHello(QPainter &painter);


};
