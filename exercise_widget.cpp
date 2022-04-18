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