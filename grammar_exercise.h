#ifndef GRAMMAR_EXERCISE_H_
#define GRAMMAR_EXERCISE_H_

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>

#include "exercise_widget.h"

class GrammarExercise : public ExerciseWidget {
 Q_OBJECT
 public:
  explicit GrammarExercise(QWidget* parent);
  void GenerateNewSentence();

 private:
  QVBoxLayout* layout_;

  QLabel* task_label_;
  QLabel* sentence_label_;
  QGroupBox* radio_box_;

  QRadioButton* variant_1_;
  QRadioButton* variant_2_;
  QRadioButton* variant_3_;

  QPushButton* submit_button_;
 private:
};

#endif  // GRAMMAR_EXERCISE_H_
