#ifndef MENU_H_
#define MENU_H_

#include <QMenuBar>
#include <QWidget>
#include <QAction>
#include <QPushButton>
#include <QSizePolicy>

#include <QApplication>
#include <QLabel>

#include <iostream>

#include "difficulty_dialog.h"
#include "settings_dialog.h"
#include "music_class.h"

class Menu : public QMenuBar {
 Q_OBJECT
 public:
  explicit Menu(QWidget* parent = nullptr);

  void ShowDialog();
  void IncScore();
  void DecTries();

 signals:
  void ChangeDifficultySignal(int level);

 private:
  int cur_level_ = 0;

  int score_ = 0;
  int tries_ = 2;
  QLabel* label_;
  MusicClass* music_class_;
};

#endif  // MENU_H_
