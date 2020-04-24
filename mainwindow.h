#pragma once
#include <QMainWindow>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_actionModel_triggered();

    void on_actionPval_triggered();

    void on_actionHi_triggered();

    void on_actionCustom_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
};

