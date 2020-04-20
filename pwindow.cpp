#include "pwindow.h"
#include "ui_pwindow.h"
#include <QIntValidator>
#include <QMessageBox>
#include <iostream>


PWindow::PWindow(int width, QColor color, QWidget *parent)
        : QDialog(parent), ui(new Ui::PWindow), sample_size(width), rect_color(color) {
    ui->setupUi(this);

    this->ui->lineEditTrials->setText(QString::number(10000));
    this->ui->lineEditSize->setText(QString::number(50));
    this->ui->lineEdit_A->setText(QString::number(6));
    this->ui->lineEdit_B->setText(QString::number(5));
    this->ui->lineEdit_K->setText(QString::number(4));

}

/* parameters setting */
void PWindow::done(int r) {

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

    trials  = this->ui->lineEditTrials->text().toInt();
    if (trials <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid parameter"), QMessageBox::Ok);
        return;
    }

//    std::cout << " type= " << modelType << std::endl;
    QDialog::done(r);
}

PWindow::~PWindow()
{
    delete ui;
}



