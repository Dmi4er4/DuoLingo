#include "main_window.h"
#include <QApplication>

#include <QStyleFactory>
#include <iostream>

int main(int argc, char* argv[]) {
  QApplication application(argc, argv);
  QApplication::setStyle(QStyleFactory::create("Fusion"));
  MainWindow win;
  win.setWindowTitle("Duolingo");
  win.show();

  return QApplication::exec();
}
