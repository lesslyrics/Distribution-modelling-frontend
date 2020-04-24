#pragma once
#include <QDialog>



namespace Ui {
class Intro;
}

class Intro : public QDialog
{
  Q_OBJECT

public:
  explicit Intro(QWidget* parent = nullptr);
   ~Intro();
private:
  Ui::Intro* ui;

};

