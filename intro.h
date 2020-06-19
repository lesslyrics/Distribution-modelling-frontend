#pragma once
#include <QDialog>



namespace Ui {
class Intro;
}
/**
	\brief Ui class
	\author @lesslyrics (Alina Boshchenko)
	\version 2.0
	\date June 2020

	Class for the acknowledgment
**/
class Intro : public QDialog
{
  Q_OBJECT

public:
    /**
     * Initializing
     * @param parent
     */
  explicit Intro(QWidget* parent = nullptr);

  /**
   * Destructor
   */
   ~Intro();

private:
  Ui::Intro* ui;

};

