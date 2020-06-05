#include "mainwindow.h"
#include "dialog.h"
#include "intro.h"
#include "ui_mainwindow.h"
#include "pwindow.h"
#include "custom.h"
#include <QColorDialog>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

/**
 * When this menu component is selected draw a histogram for sample
 */
void MainWindow::on_actionModel_triggered() {


    auto width = this->ui->renderarea->getLineWidth();
    auto color = this->ui->renderarea->getRectColor();
    auto modelDialog = new Dialog(width, color, a, b, k,  this);
    double chi_tmp = 0;
    auto exp_freq = std::vector<double>(0, 0); // histograms
    auto act_freq = std::vector<double>(0, 0); // histograms
    auto p_dist = std::vector<double>(0, 0); // histograms


    modelDialog->setStyleSheet("background-color: rgb(26, 26, 29);");


    if (modelDialog->exec() == QDialog::Accepted) {

        modelDialog->activateModel(chi_tmp, exp_freq, act_freq, p_dist, a, b, k);
        ui->renderarea->getMenu() = Menu::Model;
        ui->renderarea->getSampleSize() = modelDialog->getSampleSize();
        ui->renderarea->getChi() = modelDialog->getChi();

        ModelType temp  =modelDialog->getModelType();
        if (temp == ModelType::Bern)
            ui->renderarea->getModelType() = ModellingType::Bern;
        else if (temp == ModelType::Inv)
            ui->renderarea->getModelType() = ModellingType::Inv;

        ui->renderarea->getP() =    modelDialog->getP();
        ui->renderarea->getExpFreq() =  exp_freq;
        ui->renderarea->getActFreq() =  act_freq;

    }
}

/**
 * When this menu component is selected draw a plot for the p-values distribution
 */
void MainWindow::on_actionPval_triggered() {

    auto width = this->ui->renderarea->getLineWidth();
    auto color = this->ui->renderarea->getRectColor();
    auto pvalDialog = new PWindow(width, color, a, b, k, a_alt, b_alt, k_alt, this);
    double chi_tmp = 0;
    auto exp_freq = std::vector<double>(0, 0); // histograms
    auto act_freq = std::vector<double>(0, 0); // histograms
    auto p_dist = std::vector<double>(0, 0); // histograms


    pvalDialog->setStyleSheet("background-color: rgb(26, 26, 29);");


    if (pvalDialog->exec() == QDialog::Accepted) {
        ui->renderarea->getPType() = pvalDialog->getPType();
        pvalDialog->activateModel(chi_tmp, exp_freq, act_freq, p_dist,ui->renderarea->getPType(), a, b, k, a_alt, b_alt, k_alt);

        ui->renderarea->getMenu() = Menu::Pval;
        ui->renderarea->getSampleSize() = pvalDialog->getSampleSize();
        ui->renderarea->getChi() = pvalDialog->getChi();
        ui->renderarea->getTrials() = pvalDialog->getTrials();

        ui->renderarea->getP() =    pvalDialog->getP();
        ui->renderarea->getExpFreq() =  exp_freq;
        ui->renderarea->getActFreq() =  act_freq;
        ui->renderarea->getPDist() =  p_dist;

    }
}


/**
 * When this menu component is selected draw a plot to show difference
 * for p-values distribution depending on the sample_size and alpha
 */
void MainWindow::on_actionCustom_triggered() {

    auto width = this->ui->renderarea->getLineWidth();
    auto color = this->ui->renderarea->getRectColor();
    auto customDialog = new Custom(width, color, a, b, k, a_alt, b_alt, k_alt, this);
    double chi_tmp = 0;
    auto exp_freq = std::vector<double>(0, 0); // histograms
    auto act_freq = std::vector<double>(0, 0); // histograms
    auto p_dist = std::vector<double>(0, 0); // histograms

    customDialog->setStyleSheet("background-color: rgb(26, 26, 29);");

    if (customDialog->exec() == QDialog::Accepted) {
        customDialog->activateModel(chi_tmp, exp_freq, act_freq, p_dist, PType::Power, a, b, k, a_alt, b_alt, k_alt);
        ui->renderarea->getMenu() = Menu::Custom;
        ui->renderarea->getChi() = customDialog->getChi();

        ui->renderarea->getP() =    customDialog->getP();
        ui->renderarea->getExpFreq() =  exp_freq;
        ui->renderarea->getActFreq() =  act_freq;
        ui->renderarea->getPDist() =  p_dist;

        ui->renderarea->getTrials() = 10000;
        ui->renderarea->getPType() =  PType::Power;
        ui->renderarea->getAlpha() = customDialog->getAlpha();

        ui->renderarea->getSampleSizeMin() = customDialog->getSampleSizeMin();

        ui->renderarea->getA() = customDialog->getA();
        ui->renderarea->getB() = customDialog->getB();
        ui->renderarea->getK() = customDialog->getK();

        ui->renderarea->getA() = customDialog->getA_alt();
        ui->renderarea->getB() = customDialog->getB_alt();
        ui->renderarea->getK() = customDialog->getK_alt();


    }
}

/**
 * When this menu component is selected show hi message
 */
void MainWindow::on_actionHi_triggered() {

      auto dialog = new Intro(this);

      dialog->show();
      dialog->raise();
      dialog->activateWindow();
}

/**
 * When this menu component is selected - exit
 */
void MainWindow::on_actionExit_triggered(){
    QApplication::exit();
}

MainWindow::~MainWindow() {
    delete ui;
}
