#include "mainwindow.h"
#include "dialog.h"
#include "intro.h"
#include "ui_mainwindow.h"
#include "pwindow.h"
#include <QColorDialog>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

/* If Format was chosen - draw a line */
void MainWindow::on_actionModel_triggered() {
    auto width = this->ui->renderarea->getLineWidth();
    auto color = this->ui->renderarea->getRectColor();
    auto modelDialog = new Dialog(width, color, this);
    double chi_tmp = 0;
    auto exp_freq = std::vector<double>(0, 0); // histograms
    auto act_freq = std::vector<double>(0, 0); // histograms
    auto p_dist = std::vector<double>(0, 0); // histograms
    auto p_dist_alt = std::vector<double>(0, 0); // histograms


    modelDialog->setStyleSheet("background-color: rgb(26, 26, 29);");


    if (modelDialog->exec() == QDialog::Accepted) {

        modelDialog->activateModel(chi_tmp, exp_freq, act_freq, p_dist, p_dist_alt);
        ui->renderarea->getMenu() = Menu::Model;
        ui->renderarea->getSampleSize() = modelDialog->getSampleSize();
        ui->renderarea->getRectColor() = modelDialog->getRectColor();
        ui->renderarea->getChi() = modelDialog->getChi();

        ModelType temp  =modelDialog->getModelType();
        if (temp == ModelType::Bern)
            ui->renderarea->getModelType() = ModellingType::Bern;
        else if (temp == ModelType::Inv)
            ui->renderarea->getModelType() = ModellingType::Inv;

//        ui->renderarea->getChi() = modelDialog->activateModel(chi_tmp, 0, exp_freq);
        ui->renderarea->getP() =    modelDialog->getP();
        ui->renderarea->getExpFreq() =  exp_freq;
        ui->renderarea->getActFreq() =  act_freq;

    }
}

/* If Color was chosen - draw a rectangle */
void MainWindow::on_actionPval_triggered() {

    auto width = this->ui->renderarea->getLineWidth();
    auto color = this->ui->renderarea->getRectColor();
    auto pvalDialog = new PWindow(width, color, this);
    double chi_tmp = 0;
    auto exp_freq = std::vector<double>(0, 0); // histograms
    auto act_freq = std::vector<double>(0, 0); // histograms
    auto p_dist = std::vector<double>(0, 0); // histograms
    auto p_dist_alt = std::vector<double>(0, 0); // histograms


    pvalDialog->setStyleSheet("background-color: rgb(26, 26, 29);");


    if (pvalDialog->exec() == QDialog::Accepted) {
        pvalDialog->activateModel(chi_tmp, exp_freq, act_freq, p_dist, p_dist_alt);

        ui->renderarea->getMenu() = Menu::Pval;
        ui->renderarea->getSampleSize() = pvalDialog->getSampleSize();
        ui->renderarea->getRectColor() = pvalDialog->getRectColor();
        ui->renderarea->getChi() = pvalDialog->getChi();
        ui->renderarea->getTrials() = pvalDialog->getTrials();

        ui->renderarea->getP() =    pvalDialog->getP();
        ui->renderarea->getExpFreq() =  exp_freq;
        ui->renderarea->getActFreq() =  act_freq;
        ui->renderarea->getPDist() =  p_dist;
        ui->renderarea->getPDistAlt() =  p_dist_alt;

        ui->renderarea->getPType() =   pvalDialog->getPType();


    }
}


void MainWindow::on_actionHi_triggered() {

      auto dialog = new Intro(this);

      dialog->show();
      dialog->raise();
      dialog->activateWindow();
}

void MainWindow::on_actionExit_triggered(){
    QApplication::exit();
}

MainWindow::~MainWindow() {
    delete ui;
}
