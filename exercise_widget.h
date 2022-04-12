#ifndef EXERCISE_WIDGET_H_
#define EXERCISE_WIDGET_H_

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "translation_widget.h"
#include "grammar_widget.h"

class ExerciseWidget : public QWidget {
  Q_OBJECT
 public:
  explicit ExerciseWidget(QWidget* parent = nullptr);

  void ChangeToTranslation();
  void ChangeToGrammar();

  void GenerateNewSentence();

 protected:
  QWidget* exercise_;
};

#endif  // EXERCISE_WIDGET_H_
