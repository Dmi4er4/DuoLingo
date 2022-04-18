#ifndef MENU_H_
#define MENU_H_

#include <QMenuBar>
#include <QWidget>
#include <QAction>
#include <QPushButton>
#include <QSizePolicy>

#include <QApplication>
#include <QLabel>

#include "difficulty_dialog.h"
#include "settings_dialog.h"
#include "music_class.h"

class Menu : public QMenuBar {
 Q_OBJECT
 public:
  explicit Menu(QWidget* parent = nullptr);

  static void ShowDialog();
  void ChangeDifficulty();

 private:
  QLabel* score_label_;
  MusicClass* music_class_;
};

#endif  // MENU_H_
