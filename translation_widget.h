#ifndef TRANSLATION_WIDGET_H_
#define TRANSLATION_WIDGET_H_

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

#include "exercise_widget.h"

class TranslationWidget : public ExerciseWidget {
  Q_OBJECT
 public:
  explicit TranslationWidget(QWidget* parent);
  virtual ~TranslationWidget() = default;
  void GenerateNewSentence() final;

 private:
};

#endif  // TRANSLATION_WIDGET_H_
