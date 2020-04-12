#include "intro.h"
#include "ui_intro.h"
#include <QIntValidator>
#include <QMessageBox>



Intro::Intro(QWidget* parent)
  : QDialog(parent)
  , ui(new Ui::Intro)

{
  ui->setupUi(this);
}

Intro::~Intro(){
  delete ui;
}


