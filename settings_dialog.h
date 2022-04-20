#ifndef SETTINGS_DIALOG_H_
#define SETTINGS_DIALOG_H_

#include <QDialog>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSlider>

#include "music_class.h"

class SettingsDialog : public QDialog {
 Q_OBJECT
 public:
  explicit SettingsDialog(QWidget* parent = nullptr);

 private:
  QHBoxLayout* play_buttons_;

  QPushButton* on_;
  QPushButton* off_;
};

#endif  // SETTINGS_DIALOG_H_
