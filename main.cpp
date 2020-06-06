#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "UI/Histogram.h"

#include <iostream>
#include <QtWidgets/QMessageBox>


/**
 * Driver fuction
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    try
    {
        MainWindow w;
        w.setWindowTitle("Distribution modelling");
        w.setMinimumSize(215, 170);

        w.resize(800, 620);
        w.setStyleSheet("background-color: rgb(20, 23, 23); color:white;");

        w.show();
        return a.exec();

    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
        QMessageBox::warning(
                nullptr,
                QLatin1String("Sample exception"),
                QString::fromUtf8(ex.what()));
    }
}
