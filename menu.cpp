#include "menu.h"

Menu::Menu(QWidget* parent) :
    score_label_(new QLabel("Score: 0 ")), music_class_(new MusicClass(this)) {
  setParent(parent);
  auto* menu = new QMenu(tr("Menu"));
  auto* change_difficulty(new QAction(tr("&Change difficulty"), this));
  auto* music_settings(new QAction(tr("&Music settings"), this));
  menu->addAction(change_difficulty);
  menu->addAction(music_settings);
  connect(change_difficulty, &QAction::triggered, this, &Menu::ShowDialog);
  connect(music_settings, &QAction::triggered,
          music_class_, &MusicClass::CreateDialog);
  addMenu(menu);
  this->setCornerWidget(score_label_);
}

void Menu::ShowDialog() {
}

void Menu::ChangeDifficulty() {

}
