#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Lesson 4. Drawer.");
    w.setMinimumSize(215, 170);

    w.resize(565, 520);

    w.show();

    return a.exec();
}
