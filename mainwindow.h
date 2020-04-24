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
};

