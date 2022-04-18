#include <QApplication>

#include "main_window.h"


int main(int argc, char* argv[]) {
  QApplication application(argc, argv);
  CentralWidget win(nullptr);
  win.setWindowTitle("Duolingo");
  win.ChangeToTranslation();
  win.show();

  return QApplication::exec();
}
