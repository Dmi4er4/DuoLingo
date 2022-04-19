#ifndef CENTRAL_WIDGET_H_
#define CENTRAL_WIDGET_H_

#include <QWidget>
#include <QHBoxLayout>

#include "choice_widget.h"
#include "exercise_widget.h"
#include "translation_exercise.h"
#include "grammar_exercise.h"
#include "empty_exercise.h"

class CentralWidget : public QWidget {
 Q_OBJECT
 public:
  explicit CentralWidget(QWidget* parent = nullptr);

  void ChangeToTranslation();
  void ChangeToGrammar();

  void IncScore();

  void MyResizeEvent(QResizeEvent* event);

  void ChangeDifficulty(int level);

 signals:
  void IncScoreSignal();

 private:
  int difficulty_level_ = 0;

  QHBoxLayout* layout_;

  ChoiceWidget* choice_widget_;
  ExerciseWidget* exercise_widget_;
};

#endif  // CENTRAL_WIDGET_H_
