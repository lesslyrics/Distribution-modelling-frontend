#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "UI/Histogram.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


#include <iostream>
#include <QtWidgets/QMessageBox>


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
                QLatin1String("Sample05"),
                QString::fromUtf8(ex.what()));
    }

//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowPosition(200, 100);
//    glutInitWindowSize(400, 300);
//    glutCreateWindow("Hello World");
//    glutDisplayFunc(display);
//
//    setupHist();
//    glutMainLoop();


}
