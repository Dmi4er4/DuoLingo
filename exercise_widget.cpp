#include "exercise_widget.h"

ExerciseWidget::ExerciseWidget(QWidget* parent) :
    QWidget(parent),
    layout_(new QVBoxLayout()),
    task_label_(new QLabel()),
    sentence_label_(new QLabel()),
    submit_button_(new QPushButton("Submit")),
    progress_bar_(new QProgressBar) {}

void ExerciseWidget::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_H) {
    submit_button_->setText(tr("H pressed"));
    submit_button_->repaint();
  }
  QWidget::keyPressEvent(event);
}

void ExerciseWidget::IncIncorrect() {
  ++count_incorrect_;
  if (count_incorrect_ == max_wrong_) {
    RestartFail();
  }
}

void ExerciseWidget::RestartFail() {
  auto* wrong_dialog(new QDialog(this));
  wrong_dialog->setWindowTitle("Wrong!");
  wrong_dialog->setSizePolicy(QSizePolicy::Expanding,
                              QSizePolicy::Expanding);
  auto* label(new QLabel(tr("Too many incorrect answers")));
  auto* button(new QPushButton("Restart"));
  auto* layout(new QVBoxLayout(wrong_dialog));
  layout->addWidget(label);
  layout->addWidget(button);

  connect(button, &QPushButton::clicked, wrong_dialog, &QDialog::reject);
  connect(wrong_dialog, &QDialog::rejected, this, &ExerciseWidget::GenerateNewExercise);
  wrong_dialog->exec();
}