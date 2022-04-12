#include "menu.h"

Menu::Menu(QWidget* parent) : score_label_(new QLabel("Score: 0 ")) {
  setParent(parent);
  auto* menu = new QMenu(tr("Menu"));
  auto* change_difficulty(new QAction(tr("&Change difficulty"), this));
  menu->addAction(change_difficulty);
  connect(change_difficulty, &QAction::triggered, this, &Menu::ShowDialog);
  addMenu(menu);
  this->setCornerWidget(score_label_);
}

void Menu::ShowDialog() {
}

void Menu::ChangeDifficulty() {

}
