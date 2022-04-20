#include "settings_dialog.h"

SettingsDialog::SettingsDialog(QWidget* parent)
    : QDialog(parent),
      play_buttons_(new QHBoxLayout()),
      on_(new QPushButton("Sound on")),
      off_(new QPushButton("Sound off")) {

  off_->setSizePolicy(QSizePolicy::Expanding,
                        QSizePolicy::Expanding);
  on_->setSizePolicy(QSizePolicy::Expanding,
                        QSizePolicy::Expanding);
  play_buttons_->addWidget(on_, 1);
  play_buttons_->addWidget(off_, 1);

  this->setLayout(play_buttons_);

  auto* ptr = dynamic_cast<MusicClass*>(parent);
  connect(on_, &QPushButton::clicked,
          ptr->GetPlayer(), &QMediaPlayer::play);
  connect(off_, &QPushButton::clicked,
          ptr->GetPlayer(), &QMediaPlayer::pause);
}
