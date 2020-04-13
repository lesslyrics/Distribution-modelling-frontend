#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>


namespace Ui {
    class Dialog;
}

class Dialog : public QDialog {
Q_OBJECT

public:
    explicit Dialog(int width, QColor color, QWidget *parent = nullptr);

    QColor &getRectColor() { return rect_color; }

    int &getSampleSize() { return sample_size; }

    int &getParamA() { return a; }

    int &getParamB() { return b; }

    int &getParamK() { return k; }


    ~Dialog();

protected:
    void done(int r) override;

private slots:

    void on_radioButtonBern_toggled(bool checked);

private:
    int a;
    int b;
    int k;
    int trials;
    int sample_size;
    QColor rect_color;
    Ui::Dialog *ui;

};

#endif // DIALOG_H
