cmake_minimum_required(VERSION 3.15)
project(dialogs)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include_directories(.)


find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)



add_executable(dialogs
        dialog.cpp
        dialog.h
        dialog.ui
        dialogs.pro
        intro.cpp
        intro.h
        intro.ui
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        renderarea.cpp
        renderarea.h
        pwindow.cpp
        pwindow.h
        pwindow.ui
        Model/Model.cpp
        Model/Model.h
        Model/HypogeomModel.cpp
        Model/HypogeomModel.h
        Model/BernoulliMethod.cpp
        Model/BernoulliMethod.h
        Model/InverseFunctionMethod.cpp
        Model/InverseFunctionMethod.h
        Model/HyperGeomTheoretical.cpp
        Model/HyperGeomTheoretical.h
        Model/probdist.cpp
        Model/probdist.h
        UI/Histogram.cpp
        UI/Histogram.h
        UI/Plot.cpp
        UI/Plot.h Model/ModelType.h Model/PType.h)


target_link_libraries(dialogs ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

target_link_libraries(dialogs Qt5::Widgets)
target_link_libraries(dialogs Qt5::Core)