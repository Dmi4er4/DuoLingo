#ifndef EMPTY_EXERCISE_H_
#define EMPTY_EXERCISE_H_

#include <QWidget>

#include "exercise_widget.h"

class EmptyExercise : public ExerciseWidget {
 Q_OBJECT
 public:
  explicit EmptyExercise(QWidget* parent = nullptr);
  void GenerateNewSentence() final {};

 private:
};

#endif  // EMPTY_EXERCISE_H_
