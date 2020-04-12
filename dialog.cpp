#include "dialog.h"
#include "ui_dialog.h"
#include <QIntValidator>
#include <QMessageBox>


Dialog::Dialog(int width, QColor color, QWidget *parent)
        : QDialog(parent), ui(new Ui::Dialog), line_width(width), rect_color(color) {
    ui->setupUi(this);

    this->ui->lineEditSize->setText(QString::number(line_width));

    if (color == Qt::red)
        ui->radioButtonBern->setChecked(true);
    else if (color == Qt::green)
        ui->radioButtonInverse->setChecked(true);
    else
        ui->radioButtonBern->setChecked(true);

}

/* not able to change width if blue is selected */
void Dialog::on_radioButtonBern_toggled(bool checked) {
    this->ui->lineEditSize->setDisabled(checked);
}

/* parameters setting */
void Dialog::done(int r) {
    if (ui->radioButtonBern->isChecked())
        rect_color = Qt::red;
    else if (ui->radioButtonInverse->isChecked())
        rect_color = Qt::green;

    auto input_width = this->ui->lineEditSize->text().toInt();
//    if (!(input_width > 0 && input_width < 4)) {
//        QMessageBox::warning(this, tr(""), tr("Should be from 1 to 3."), QMessageBox::Ok);
//        return;
//    }
    line_width = input_width;

    QDialog::done(r);
    return;
}

Dialog::~Dialog() {
    delete ui;
}


