#pragma once
#include <QMainWindow>


namespace Ui {
    class MainWindow;
}

/**
	\brief Ui class
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020

	Main Window class
**/
class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    /**
     * When this menu component is selected draw a histogram for sample
     */
    void on_actionModel_triggered();

    /**
     * When this menu component is selected draw a plot for the p-values distribution
     */
    void on_actionPval_triggered();

    /**
     * When this menu component is selected show hi message
     */
    void on_actionHi_triggered();

    /**
     * When this menu component is selected draw a plot to show difference
     * for p-values distribution depending on the sample_size and alpha
     */
    void on_actionCustom_triggered();

    /**
     * When this menu component is selected - exit
     */
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;

    int a = 30;
    int b = 25;
    int k = 25;

    int a_alt = 29;
    int b_alt = 19;
    int k_alt = 24;
};

