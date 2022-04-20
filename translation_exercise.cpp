#include "translation_exercise.h"

TranslationExercise::TranslationExercise(QWidget* parent, int level)
                                        : ExerciseWidget(parent, level) {
  answer_ = new QTextEdit(this);
  answer_->setPlaceholderText("Write your translation here");

  task_label_->setText("Translate this sentence");

  sentence_label_->setWordWrap(true);

  answer_->setSizePolicy(QSizePolicy::Expanding,
                         QSizePolicy::Expanding);

  submit_button_->setSizePolicy(QSizePolicy::Expanding,
                                QSizePolicy::Expanding);

  layout_->addWidget(task_label_, 1);

  layout_->addWidget(sentence_label_, 2);

  layout_->addWidget(answer_, 3);

  layout_->addWidget(submit_button_, 1);

  layout_->addWidget(progress_bar_, 1);

  progress_bar_->setMaximum(count_questions_);

  connect(submit_button_, &QPushButton::clicked,
          this, &TranslationExercise::CheckAnswerAndToNextPart);

  setLayout(layout_);
  GenerateNewExercise();
}

void TranslationExercise::GenerateNewExercise() {
  exercises_.clear();
  count_incorrect_ = 0;
  cur_num_question_ = 0;

  exercises_ =
      TasksLoader::LoadTranslation(count_questions_, difficulty_level_);
  GenerateNextPart();
}

bool TranslationExercise::CheckAnswer() {
  if (exercises_[cur_num_question_ - 1].second.toLower()
      != answer_->toPlainText().toLower()) {
    return IncIncorrect();
  }
  return false;
}

void TranslationExercise::GenerateNextPart() {
  progress_bar_->setValue(cur_num_question_);
  sentence_label_->setText(exercises_[cur_num_question_++].first);
  answer_->setText(tr(""));
}
