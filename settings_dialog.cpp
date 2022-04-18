#include "settings_dialog.h"

SettingsDialog::SettingsDialog(QWidget* parent)
    : QDialog(parent),
      layout_(new QVBoxLayout(this)),
      play_buttons_(new QHBoxLayout()),
      start_(new QPushButton("Play")),
      pause_(new QPushButton("Pause")),
      stop_(new QPushButton("Stop")) {

  start_->setSizePolicy(QSizePolicy::Expanding,
                        QSizePolicy::Expanding);
  pause_->setSizePolicy(QSizePolicy::Expanding,
                        QSizePolicy::Expanding);
  stop_->setSizePolicy(QSizePolicy::Expanding,
                       QSizePolicy::Expanding);

  play_buttons_->addWidget(start_, 1);
  play_buttons_->addWidget(pause_, 1);
  play_buttons_->addWidget(stop_, 1);

  layout_->addLayout(play_buttons_);

  auto* ptr = dynamic_cast<MusicClass*>(parent);
  connect(start_, &QPushButton::clicked,
          ptr->GetPlayer(), &QMediaPlayer::play);
  connect(pause_, &QPushButton::clicked,
          ptr->GetPlayer(), &QMediaPlayer::pause);
  connect(stop_, &QPushButton::clicked,
          ptr->GetPlayer(), &QMediaPlayer::stop);
}