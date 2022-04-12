#ifndef TRANSLATION_EXERCISE_H_
#define TRANSLATION_EXERCISE_H_

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "exercise_widget.h"

class TranslationExercise : public ExerciseWidget {
  Q_OBJECT
 public:
  explicit TranslationExercise(QWidget* parent);
  void GenerateNewSentence() final;

 private:
  QVBoxLayout* layout_;

  QLabel* task_label_;
  QLabel* sentence_label_;
  QTextEdit* answer_;
  QPushButton* submit_button_;
};

#endif  // TRANSLATION_EXERCISE_H_
