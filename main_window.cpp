#include "main_window.h"

MainWindow::MainWindow(QWidget* parent)
    : central_widget_(this) {
  Q_UNUSED(parent);
  resize(1000, 500);
  central_widget_.setSizePolicy(QSizePolicy::Expanding,
                               QSizePolicy::Expanding);
  setCentralWidget(&central_widget_);
  setMenuBar(&menu_);
  connect(&central_widget_, &CentralWidget::IncScoreSignal,
          &menu_, &Menu::IncScore);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
  int sz = std::min(event->size().height(), event->size().width());
  font_.setPointSizeF(sz / 35.0);
  menu_.setFont(font_);
  central_widget_.setFont(font_);
  QWidget::resizeEvent(event);
}