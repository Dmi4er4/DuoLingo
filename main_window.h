#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <QMainWindow>

#include "central_widget.h"
#include "menu.h"

class MainWindow : public QMainWindow {
 Q_OBJECT
 public:
  explicit MainWindow(QWidget* parent = nullptr);
  void resizeEvent(QResizeEvent* event) override;
 private:
  CentralWidget* central_widget_;
  Menu* menu_;
  QFont font_;
};

#endif  // MAIN_WINDOW_H_
