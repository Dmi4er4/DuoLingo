#ifndef EXERCISE_WIDGET_H_
#define EXERCISE_WIDGET_H_

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QProgressBar>

class ExerciseWidget : public QWidget {
 Q_OBJECT
 public:
  explicit ExerciseWidget(QWidget* parent = nullptr);
  ~ExerciseWidget() override = default;

 protected:
  virtual void GenerateNextPart() = 0;
  virtual void CheckAnswer() = 0;
  virtual void CheckAnswerAndToNextPart() = 0;

  int count_questions_ = 5;
  int cur_num_question_ = 0;
  int count_incorrect_ = 0;

  QVBoxLayout* layout_;

  QLabel* task_label_;
  QLabel* sentence_label_;

  QPushButton* submit_button_;

  QProgressBar* progress_bar_;

};

#endif  // EXERCISE_WIDGET_H_
