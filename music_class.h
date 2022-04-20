#ifndef MUSIC_CLASS_H_
#define MUSIC_CLASS_H_

#include <QWidget>
#include <QtMultimedia>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMediaPlayer>
#include "settings_dialog.h"

class MusicClass : public QWidget {
 Q_OBJECT
 public:
  explicit MusicClass(QWidget* parent = nullptr);

  QMediaPlayer* GetPlayer();

  void CreateDialog();

 private:
  QMediaPlayer* media_player_;

};

#endif  // MUSIC_CLASS_H_
