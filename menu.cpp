#include "menu.h"

Menu::Menu(QWidget* parent) :
    label_(new QLabel("Score: 0 Tries left: 2", this)),
    music_class_(new MusicClass(this)){
  setParent(parent);
  auto* menu = new QMenu("Menu", this);
  auto* change_difficulty(new QAction("&Change difficulty", this));
  auto* music_settings(new QAction("&Sound settings", this));
  menu->addAction(music_settings);
  connect(change_difficulty, &QAction::triggered, this, &Menu::ShowDialog);
  connect(music_settings, &QAction::triggered,
          music_class_, &MusicClass::CreateDialog);
  menu->addAction("&Change difficulty",
                  this, &Menu::ShowDialog,
                  Qt::CTRL | Qt::Key_C);
  addMenu(menu);
  this->setCornerWidget(label_);
}

void Menu::ShowDialog() {
  auto* dialog(new DifficultyDialog(this, cur_level_));
  dialog->show();
  if (dialog->exec() == QDialog::Accepted) {
    int new_level = dialog->GetNumChecked();
    if (new_level != cur_level_) {
      cur_level_ = new_level;
      emit(ChangeDifficultySignal(cur_level_));
    }
  }
  delete dialog;
}

void Menu::IncScore() {
  score_++;
  QString str("Score: ");
  str.append(QString::number(score_));
  str.append(" Tries left: ");
  str.append(QString::number(tries_));
  label_->setText(str);
}
void Menu::DecTries() {
  tries_--;
  QString str("Score: ");
  str.append(QString::number(score_));
  str.append(" Tries left: ");
  str.append(QString::number(tries_));
  label_->setText(str);
}
