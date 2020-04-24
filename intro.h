#pragma once
#include <QDialog>



namespace Ui {
class Intro;
}

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

