#include "empty_exercise.h"

EmptyExercise::EmptyExercise(QWidget* parent) : ExerciseWidget(parent) {
  submit_button_->setVisible(false);
  progress_bar_->setVisible(false);
}