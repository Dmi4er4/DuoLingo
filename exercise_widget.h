#ifndef EXERCISE_WIDGET_H_
#define EXERCISE_WIDGET_H_

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class ExerciseWidget : public QWidget {
  Q_OBJECT
 public:
  explicit ExerciseWidget(QWidget* parent = nullptr);
  virtual ~ExerciseWidget() {};

  virtual void GenerateNewSentence() {};

 protected:
  QVBoxLayout* layout_;

  QLabel* task_label_;
  QLabel* sentence_label_;
  QWidget* answer_;
  QPushButton* submit_button_;
};

#endif  // EXERCISE_WIDGET_H_
