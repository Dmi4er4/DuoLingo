#include "exercise_widget.h"

ExerciseWidget::ExerciseWidget(QWidget* parent) :
    QWidget(parent),
    exercise_timer_(new QTimer(this)),
    layout_(new QVBoxLayout()),
    task_label_(new QLabel()),
    sentence_label_(new QLabel()),
    submit_button_(new QPushButton("Submit")),
    progress_bar_(new QProgressBar) {
  connect(exercise_timer_, &QTimer::timeout,
          this, &ExerciseWidget::RestartTimeOut);
}

void ExerciseWidget::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_H) {
    ShowTip();
  }
}

bool ExerciseWidget::IncIncorrect() {
  ++count_incorrect_;
  if (count_incorrect_ == max_wrong_) {
    RestartFail();
    return true;
  }
  return false;
}

void ExerciseWidget::startTimer() {
  exercise_timer_->setInterval(time_to_solve_);
}

void ExerciseWidget::RestartFail() {
  auto* wrong_dialog(new QDialog(this));
  wrong_dialog->setWindowTitle("Wrong!");
  wrong_dialog->setSizePolicy(QSizePolicy::Expanding,
                              QSizePolicy::Expanding);
  auto* label(new QLabel(tr("Too many incorrect answers")));
  auto* button(new QPushButton("Restart"));
  auto* layout(new QVBoxLayout(wrong_dialog));
  label->setSizePolicy(QSizePolicy::Expanding,
                       QSizePolicy::Expanding);
  button->setSizePolicy(QSizePolicy::Expanding,
                        QSizePolicy::Expanding);
  layout->addWidget(label, 3);
  layout->addWidget(button, 1);

  connect(button, &QPushButton::clicked,
          wrong_dialog, &QDialog::reject);
  connect(wrong_dialog, &QDialog::rejected,
          this, &ExerciseWidget::GenerateNewExercise);
  wrong_dialog->exec();
}

void ExerciseWidget::ShowTip() {
  exercise_timer_->stop();
  dialog_tip_ = new QDialog(this);
  auto* tip_layout(new QVBoxLayout(dialog_tip_));
  auto* label_tip(new QLabel(cur_tip_));
  auto* ok_button(new QPushButton("OK"));
  tip_layout->addWidget(label_tip);
  tip_layout->addWidget(ok_button);
  dialog_tip_->setLayout(tip_layout);
  connect(ok_button, &QPushButton::clicked, dialog_tip_, &QDialog::reject);
  dialog_tip_->exec();
}

void ExerciseWidget::RestartTimeOut() {
  if (dialog_tip_ != nullptr) {
    dialog_tip_->reject();
  }
  auto* wrong_dialog(new QDialog(this));
  wrong_dialog->setWindowTitle("Time Out!");
  wrong_dialog->setSizePolicy(QSizePolicy::Expanding,
                              QSizePolicy::Expanding);
  auto* label(new QLabel(tr("Too slow")));
  auto* button(new QPushButton("Restart"));
  auto* layout(new QVBoxLayout(wrong_dialog));
  label->setSizePolicy(QSizePolicy::Expanding,
                       QSizePolicy::Expanding);
  button->setSizePolicy(QSizePolicy::Expanding,
                        QSizePolicy::Expanding);
  layout->addWidget(label, 3);
  layout->addWidget(button, 1);

  connect(button, &QPushButton::clicked, wrong_dialog, &QDialog::reject);
  connect(wrong_dialog, &QDialog::rejected,
          this, &ExerciseWidget::GenerateNewExercise);
  wrong_dialog->exec();
}