#include <QApplication>

#include "main_window.h"


int main(int argc, char* argv[]) {
  QApplication application(argc, argv);
  MainWindow win;
  win.setWindowTitle("Duolingo");
  win.show();

  return QApplication::exec();
}
