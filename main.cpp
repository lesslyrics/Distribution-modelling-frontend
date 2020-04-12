#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QtWidgets/QMessageBox>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    try
    {
        MainWindow w;
        w.setWindowTitle("Distribution modelling");
        w.setMinimumSize(215, 170);

        w.resize(565, 520);

        w.show();
        return a.exec();

    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
        QMessageBox::warning(
                nullptr,
                QLatin1String("Sample05"),
                QString::fromUtf8(ex.what()));
    }


}
