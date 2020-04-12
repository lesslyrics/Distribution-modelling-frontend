cmake_minimum_required(VERSION 3.15)
project(dialogs)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include_directories(.)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(dialogs
        dialog.cpp
        dialog.h
        dialog.ui
        dialogs.pro
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        renderarea.cpp
        renderarea.h)

target_link_libraries(dialogs Qt5::Widgets)
target_link_libraries(dialogs Qt5::Core)