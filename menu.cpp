#include "menu.h"

Menu::Menu(QWidget* parent) :
    score_label_(new QLabel("Score: 0 ")), music_class_(new MusicClass(this)) {
  setParent(parent);
  auto* menu = new QMenu(tr("Menu"));
  auto* change_difficulty(new QAction(tr("&Change difficulty"), this));
  auto* music_settings(new QAction(tr("&Music settings"), this));
  menu->addAction(music_settings);
  connect(change_difficulty, &QAction::triggered,
          this, &Menu::ShowDialog);
  connect(music_settings, &QAction::triggered,
          music_class_, &MusicClass::CreateDialog);
  menu->addAction("&Change difficulty", this,
                  &Menu::ShowDialog, Qt::CTRL | Qt::Key_C);
  addMenu(menu);
  this->setCornerWidget(score_label_);
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
  score_label_->setText(str);
}
