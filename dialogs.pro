#-------------------------------------------------
#
# Project created by QtCreator 2020-03-30T10:46:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dialogs
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog.cpp \
    renderarea.cpp \
    intro.cpp \
    pwindow.cpp \
    custom.cpp \
    Model/BernoulliMethod.cpp \
    Model/HyperGeomTheoretical.cpp \
    Model/HypogeomModel.cpp \
    Model/InverseFunctionMethod.cpp \
    Model/Model.cpp \
    Model/probdist.cpp \
    UI/Histogram.cpp \
    UI/Plot.cpp

HEADERS += \
        mainwindow.h \
    dialog.h \
    renderarea.h \
    intro.h \
    pwindow.h \
    custom.h \
    Model/BernoulliMethod.h \
    Model/HyperGeomTheoretical.h \
    Model/HypogeomModel.h \
    Model/InverseFunctionMethod.h \
    Model/Model.h \
    Model/ModelType.h \
    Model/probdist.h \
    Model/PType.h \
    UI/Histogram.h \
    UI/Plot.h

FORMS += \
        mainwindow.ui \
    dialog.ui \
    intro.ui \
    pwindow.ui \
    custom.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
