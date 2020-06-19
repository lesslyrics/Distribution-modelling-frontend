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
Custom::Custom(int a_t, int b_t, int k_t, int a_at, int b_at, int k_at, QWidget *parent)
        : QDialog(parent), ui(new Ui::Custom), a(a_t), b(b_t), k(k_t), a_alt(a_at),b_alt(b_at), k_alt(k_at) {
    ui->setupUi(this);

    this->ui->lineEditSize1->setText(QString::number(50));

    this->ui->lineEdit_A->setText(QString::number(a));
    this->ui->lineEdit_B->setText(QString::number(b));
    this->ui->lineEdit_K->setText(QString::number(k));

    this->ui->lineEdit_A_alt->setText(QString::number(a_alt));
    this->ui->lineEdit_B_alt->setText(QString::number(b_alt));
    this->ui->lineEdit_K_alt->setText(QString::number(k_alt));

}

 /**
  * parameters setting
  * @param r
  */
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

    a_alt = this->ui->lineEdit_A_alt->text().toInt();
    if (a_alt <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid parameter"), QMessageBox::Ok);
        return;
    }

    b_alt = this->ui->lineEdit_B_alt->text().toInt();
    if (b_alt <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid parameter"), QMessageBox::Ok);
        return;
    }

    k_alt = this->ui->lineEdit_K_alt->text().toInt();
    if (k_alt <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid parameter"), QMessageBox::Ok);
        return;
    }


    sample_size_min  = this->ui->lineEditSize1->text().toInt();
    if (sample_size_min  <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid size"), QMessageBox::Ok);
        return;
    }

    alpha = this->ui->sliderAlpha->value() * 0.5 / MAX;

    QDialog::done(r);
}

/**
 * Destructor
 */
Custom::~Custom() {
    delete ui;
}


