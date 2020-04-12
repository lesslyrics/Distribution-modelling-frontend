#include "mainwindow.h"
#include "dialog.h"
#include "intro.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <iostream>
#include "Model/Model.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

/* If Format was chosen - draw a line */
void MainWindow::on_actionModel_triggered() {
    auto width = this->ui->renderarea->getLineWidth();
    auto color = this->ui->renderarea->getRectColor();
    auto modelDialog = new Dialog(width, color, this);


    if (modelDialog->exec() == QDialog::Accepted) {
        ui->renderarea->getMenu() = Menu::Model;
        ui->renderarea->getLineWidth() = modelDialog->getLineWidth();
        ui->renderarea->getRectColor() = modelDialog->getRectColor();
        auto k = model();
        std::cout << "k = " << k;

    }
}

/* If Color was chosen - draw a rectangle */
void MainWindow::on_actionPval_triggered() {
    auto col = ui->renderarea->getRectColor();
    auto color = QColorDialog::getColor(col, this, "Select color", QColorDialog::DontUseNativeDialog);
    if (color.isValid()) {
        ui->renderarea->getRectColor() = color;
        ui->renderarea->getMenu() = Menu::Pval;
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
