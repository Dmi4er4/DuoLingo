#ifndef GRAMMAR_EXERCISE_H_
#define GRAMMAR_EXERCISE_H_

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>

#include "exercise_widget.h"
#include "grammar_question.h"

class GrammarExercise : public ExerciseWidget {
 Q_OBJECT
 public:
  explicit GrammarExercise(QWidget* parent);

 private:
  void GGLoadSentences();
  void CheckAnswerAndToNextPart() final;
  void GenerateNextPart() final;
  void CheckAnswer() final;

  QVector<GrammarQuestion> exercises_;

  int count_questions_ = 5;
  int cur_num_question_ = 0;
  int count_incorrect_ = 0;

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
