//
// Created by lesslyrics on 23.04.2020.
//

#include "custom.h"
#include "ui_custom.h"
#include <QIntValidator>
#include <QMessageBox>
#include <iostream>

const int MAX = 50;

/**
 * Initialize
 * @param width
 * @param color
 * @param parent
 */
Custom::Custom(int width, QColor color, QWidget *parent)
        : QDialog(parent), ui(new Ui::Custom), sample_size(width), rect_color(color) {
    ui->setupUi(this);

    this->ui->lineEditSize1->setText(QString::number(50));
    this->ui->lineEditSize2->setText(QString::number(500));

    this->ui->lineEdit_A->setText(QString::number(6));
    this->ui->lineEdit_B->setText(QString::number(5));
    this->ui->lineEdit_K->setText(QString::number(4));

}
/**
 * parameters setting
 **/
void Custom::done(int r) {

    a = this->ui->lineEdit_A->text().toInt();
    if (a <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid parameter"), QMessageBox::Ok);
        return;
    }

    b = this->ui->lineEdit_B->text().toInt();
    if (b<= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid parameter"), QMessageBox::Ok);
        return;
    }

    k = this->ui->lineEdit_K->text().toInt();
    if (k <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid parameter"), QMessageBox::Ok);
        return;
    }

    sample_size_min  = this->ui->lineEditSize1->text().toInt();
    if (sample_size_min  <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid size"), QMessageBox::Ok);
        return;
    }
    sample_size_max  = this->ui->lineEditSize2->text().toInt();
    if (sample_size_max  <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid size"), QMessageBox::Ok);
        return;
    }

    sample_size_med  = (sample_size_max - sample_size_min) / 2;
    if (sample_size_med  <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid size"), QMessageBox::Ok);
        return;
    }

    sample_size = 2;

    alpha = this->ui->sliderAlpha->value() * 0.5 / MAX;

    std::cout << "alpha: " << alpha << std::endl;

//    std::cout << " type= " << modelType << std::endl;
    QDialog::done(r);
}

/**
 * Destructor
 */
Custom::~Custom() {
    delete ui;
}


