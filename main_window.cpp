#include "main_window.h"

MainWindow::MainWindow(QWidget* parent)
    : central_widget(this) {
  Q_UNUSED(parent);
  resize(1000, 500);
  central_widget.setSizePolicy(QSizePolicy::Expanding,
                               QSizePolicy::Expanding);
  setCentralWidget(&central_widget);
  setMenuBar(&menu_);
  // menu_.show();
}

void MainWindow::resizeEvent(QResizeEvent* event) {
  int sz = std::min(event->size().height(), event->size().width());
  font_.setPointSizeF(sz / 35.0);
  menu_.setFont(font_);
  central_widget.setFont(font_);
  QWidget::resizeEvent(event);
}