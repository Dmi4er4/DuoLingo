#include "exercise_widget.h"

ExerciseWidget::ExerciseWidget(QWidget* parent, int level) :
    QWidget(parent),
    layout_(new QVBoxLayout(this)),
    task_label_(new QLabel(this)),
    sentence_label_(new QLabel(this)),
    submit_button_(new QPushButton("Submit", this)),
    progress_bar_(new QProgressBar(this)) {
  difficulty_level_ = level;
  task_label_->setWordWrap(true);
  sentence_label_->setWordWrap(true);
}

void ExerciseWidget::CheckAnswerAndToNextPart() {
  bool is_restart = CheckAnswer();
  if (cur_num_question_ < count_questions_) {
    if (!is_restart) {
      GenerateNextPart();
    }
  } else {
    if (count_incorrect_ == 0) {
      emit(IncScoreSignal());
    }
    GenerateNewExercise();
  }
}

bool ExerciseWidget::IncIncorrect() {
  count_incorrect_++;
  if (count_incorrect_ == max_wrong_) {
    RestartFail();
    return true;
  }
  return false;
}

void ExerciseWidget::RestartFail() {
  auto* wrong_dialog(new QDialog(this));
  wrong_dialog->setWindowTitle("Wrong!");
  auto* label(new QLabel(tr("Too many incorrect answers")));
  label->setWordWrap(true);
  auto* button(new QPushButton("Restart"));
  auto* layout(new QVBoxLayout(wrong_dialog));
  label->setSizePolicy(QSizePolicy::Expanding,
                       QSizePolicy::Expanding);
  button->setSizePolicy(QSizePolicy::Expanding,
                        QSizePolicy::Expanding);
  layout->addWidget(label, 3);
  layout->addWidget(button, 1);
  wrong_dialog->resize(300, 100);
  connect(button, &QPushButton::clicked, wrong_dialog, &QDialog::reject);
  connect(wrong_dialog, &QDialog::rejected,
          this, &ExerciseWidget::GenerateNewExercise);
  wrong_dialog->exec();
}

void ExerciseWidget::ChangeDifficulty(int level) {
  difficulty_level_ = level;
  GenerateNewExercise();
}
