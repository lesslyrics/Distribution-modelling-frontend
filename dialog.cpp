#include "dialog.h"
#include "ui_dialog.h"
#include <QIntValidator>
#include <QMessageBox>
#include <iostream>


Dialog::Dialog(int width, QColor color, QWidget *parent)
        : QDialog(parent), ui(new Ui::Dialog), sample_size(width), rect_color(color) {
    ui->setupUi(this);

    this->ui->lineEditSize->setText(QString::number(100));
    this->ui->lineEdit_A->setText(QString::number(30));
    this->ui->lineEdit_B->setText(QString::number(25));
    this->ui->lineEdit_K->setText(QString::number(20));



    if (color == Qt::red)
        ui->radioButtonBern->setChecked(true);
    else if (color == Qt::green)
        ui->radioButtonInverse->setChecked(true);
    else
        ui->radioButtonBern->setChecked(true);

}

void Dialog::on_radioButtonBern_toggled(bool checked) {
}

/* parameters setting */
void Dialog::done(int r) {
    if (ui->radioButtonBern->isChecked())
        rect_color = Qt::red;
    else if (ui->radioButtonInverse->isChecked())
        rect_color = Qt::green;

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
           std::cout << " type= bern"  << std::endl;

    }

    else if (ui->radioButtonInverse->isChecked()){
        std::cout << " type=inv"  << std::endl;

        modelType = ModelType::Inv;

    }


//    std::cout << " type= " << modelType << std::endl;
    QDialog::done(r);
}

Dialog::~Dialog() {
    delete ui;
}


