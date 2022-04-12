#ifndef DIFFICULTY_DIALOG_H_
#define DIFFICULTY_DIALOG_H_

#include <QDialog>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QDialogButtonBox>

class DifficultyDialog : public QDialog {
  Q_OBJECT
 public:
  explicit  DifficultyDialog(QWidget* parent = nullptr);
 private:
  QGroupBox* buttons_;
  QVBoxLayout* layout_;
  QDialogButtonBox* accept_button_;

  QRadioButton* easy_button_;
  QRadioButton* medium_button_;
  QRadioButton* hard_button_;
};

#endif  // DIFFICULTY_DIALOG_H_
