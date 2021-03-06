#include "intro.h"
#include "ui_intro.h"
#include <QIntValidator>


/**
 * Initialize
 * @param parent
 */
Intro::Intro(QWidget* parent)
  : QDialog(parent)
  , ui(new Ui::Intro)

{
    ui->setupUi(this);
    this->ui->label->setText("<a style=\"color: white; text-decoration: none\" href=\"https://github.com/AlinaBoshchenko\">Created by @lesslyrics</a>");
    this->ui->label->setTextFormat(Qt::RichText);
    this->ui->label->setTextInteractionFlags(Qt::TextBrowserInteraction);
    this->ui->label->setOpenExternalLinks(true);
    this->ui->label->setStyleSheet("QLabel { text-decoration: none; }");


}

Intro::~Intro(){
  delete ui;
}


