#include "music_class.h"

MusicClass::MusicClass(QWidget* parent)
    : QWidget(parent),
      media_player_(new QMediaPlayer(this)) {
  media_player_->setLoops(QMediaPlayer::Infinite);
}

QMediaPlayer* MusicClass::GetPlayer() {
  return media_player_;
}

void MusicClass::CreateDialog() {
  auto* dialog(new SettingsDialog(this));
  dialog->exec();
}
