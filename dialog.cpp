#include "dialog.h"
#include "ui_dialog.h"
#include <QIntValidator>
#include <QMessageBox>
#include <iostream>

/**
 * Initialize
 * @param width
 * @param color
 * @param parent
 */
Dialog::Dialog(int a_t, int b_t, int k_t, QWidget *parent)
        : QDialog(parent), ui(new Ui::Dialog), a(a_t), b(b_t), k(k_t){
    ui->setupUi(this);


//    this->ui->lineEditSize->setText(QString::number(100));
    this->ui->lineEdit_A->setText(QString::number(a_t));
    this->ui->lineEdit_B->setText(QString::number(b_t));
    this->ui->lineEdit_K->setText(QString::number(k_t));

    ui->radioButtonBern->setChecked(true);

}


 /**
  * parameters setting
  * @param r
  */
void Dialog::done(int r) {

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

    sample_size  = this->ui->lineEditSize->text().toInt();
    if (sample_size  <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid size"), QMessageBox::Ok);
        return;
    }

    if (ui->radioButtonBern->isChecked()){
        modelType = ModelType::Bern;
    }

    else if (ui->radioButtonInverse->isChecked()){
        modelType = ModelType::Inv;
    }

    QDialog::done(r);
}

/**
 * Destructor
 */
Dialog::~Dialog() {
    delete ui;
}


