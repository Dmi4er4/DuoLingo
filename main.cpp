#include <QApplication>
#include <QStyleFactory>

#include <iostream>

#include "main_window.h"

int main(int argc, char* argv[]) {
  srand(time(nullptr));
  QApplication application(argc, argv);
  application.setStyle(QStyleFactory::create("Fusion"));
  MainWindow win;
  win.setWindowTitle("DimaLingo");
  win.show();

  return QApplication::exec();
}
