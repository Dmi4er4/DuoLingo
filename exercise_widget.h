#ifndef EXERCISE_WIDGET_H_
#define EXERCISE_WIDGET_H_

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QKeyEvent>
#include <QDialog>
#include <QTimer>

class ExerciseWidget : public QWidget {
 Q_OBJECT
 public:
  explicit ExerciseWidget(QWidget* parent = nullptr);
  ~ExerciseWidget() override = default;

  void keyPressEvent(QKeyEvent* event) override;
  virtual void RestartFail();
  virtual void RestartTimeOut();

 signals:
  void IncScoreSignal();

 protected:
  virtual void GenerateNewExercise() = 0;
  virtual void GenerateNextPart() = 0;
  virtual bool CheckAnswer() = 0;

  void CheckAnswerAndToNextPart();
  bool IncIncorrect();
  void ShowTip();

  int difficulty_level_ = 0;
  int time_to_solve_ = 100000;
  int count_questions_ = 5;
  int max_wrong_ = 2;
  int cur_num_question_ = 0;
  int count_incorrect_ = 0;

  QTimer* exercise_timer_;

  QDialog* dialog_tip_ = nullptr;

  QString cur_tip_;

  QVBoxLayout* layout_;

  QLabel* task_label_;
  QLabel* sentence_label_;

  QPushButton* submit_button_;

  QProgressBar* progress_bar_;

};

#endif  // EXERCISE_WIDGET_H_
