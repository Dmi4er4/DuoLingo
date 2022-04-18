#ifndef GRAMMAR_EXERCISE_H_
#define GRAMMAR_EXERCISE_H_

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QProgressBar>

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

  QGroupBox* radio_box_;

  QRadioButton* variant_1_;
  QRadioButton* variant_2_;
  QRadioButton* variant_3_;
 private:
};

#endif  // GRAMMAR_EXERCISE_H_
