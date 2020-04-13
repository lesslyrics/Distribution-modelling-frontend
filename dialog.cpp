#include "dialog.h"
#include "ui_dialog.h"
#include <QIntValidator>
#include <QMessageBox>
#include <iostream>


Dialog::Dialog(int width, QColor color, QWidget *parent)
        : QDialog(parent), ui(new Ui::Dialog), sample_size(width), rect_color(color) {
    ui->setupUi(this);

    this->ui->lineEditSize->setText(QString::number(sample_size));

    if (color == Qt::red)
        ui->radioButtonBern->setChecked(true);
    else if (color == Qt::green)
        ui->radioButtonInverse->setChecked(true);
    else
        ui->radioButtonBern->setChecked(true);

}

void Dialog::on_radioButtonBern_toggled(bool checked) {
    this->ui->lineEditSize->setDisabled(checked);
}

/* parameters setting */
void Dialog::done(int r) {
    if (ui->radioButtonBern->isChecked())
        rect_color = Qt::red;
    else if (ui->radioButtonInverse->isChecked())
        rect_color = Qt::green;

    auto input_A = this->ui->lineEdit_A->text().toInt();
    if (input_A <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid parameter"), QMessageBox::Ok);
        return;
    }

    auto input_B = this->ui->lineEdit_B->text().toInt();
    if (input_B <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid parameter"), QMessageBox::Ok);
        return;
    }

    auto input_K = this->ui->lineEdit_K->text().toInt();
    if (input_K <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid parameter"), QMessageBox::Ok);
        return;
    }

    auto input_size = this->ui->lineEditSize->text().toInt();
    if (input_size <= 0){
        QMessageBox::warning(this, tr(""), tr("Invalid size"), QMessageBox::Ok);
        return;
    }
    sample_size = input_size;
    std::cout << "size " << sample_size << " a= " << input_A << " b= " << input_B << " k= " << input_K << std::endl;
    QDialog::done(r);
}

Dialog::~Dialog() {
    delete ui;
}


