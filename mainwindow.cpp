#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

/* If Format was chosen - draw a line */
void MainWindow::on_actionModel_triggered() {
    auto width = this->ui->renderarea->getLineWidth();
    auto color = this->ui->renderarea->getRectColor();
    auto formatDialog = new Dialog(width, color, this);

    if (formatDialog->exec() == QDialog::Accepted) {
        ui->renderarea->getMenu() = Menu::Format;
        ui->renderarea->getLineWidth() = formatDialog->getLineWidth();
        ui->renderarea->getRectColor() = formatDialog->getRectColor();
    }
}

/* If Color was chosen - draw a rectangle */
void MainWindow::on_actionPval_triggered() {
    auto col = ui->renderarea->getRectColor();
    auto color = QColorDialog::getColor(col, this, "Select color", QColorDialog::DontUseNativeDialog);
    if (color.isValid()) {
        ui->renderarea->getRectColor() = color;
        ui->renderarea->getMenu() = Menu::Color;
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
