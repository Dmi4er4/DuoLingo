#include "central_widget.h"

CentralWidget::CentralWidget(QWidget* parent)
    : QWidget(parent),
      layout_(new QHBoxLayout(this)),
      choice_widget_(new ChoiceWidget(this)),
      exercise_widget_(new EmptyExercise(this)) {

  choice_widget_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  exercise_widget_->setSizePolicy(QSizePolicy::Expanding,
                                  QSizePolicy::Expanding);
  layout_->addWidget(choice_widget_, 1);
  layout_->addWidget(exercise_widget_, 1);
  setLayout(layout_);

  connect(choice_widget_, &ChoiceWidget::ChangeToTranslationSignal, this,
          &CentralWidget::ChangeToTranslation);
  connect(choice_widget_, &ChoiceWidget::ChangeToGrammarSignal, this,
          &CentralWidget::ChangeToGrammar);
}

void CentralWidget::ChangeToTranslation() {
  layout_->removeWidget(exercise_widget_);
  delete exercise_widget_;
  exercise_widget_ = new TranslationExercise(this, difficulty_level_);
  layout_->addWidget(exercise_widget_, 1);

  connect(exercise_widget_,
          &ExerciseWidget::IncScoreSignal,
          this,
          &CentralWidget::IncScore);
}

void CentralWidget::ChangeToGrammar() {
  layout_->removeWidget(exercise_widget_);
  delete exercise_widget_;
  exercise_widget_ = new GrammarExercise(this, difficulty_level_);
  layout_->addWidget(exercise_widget_, 1);

  connect(exercise_widget_,
          &ExerciseWidget::IncScoreSignal,
          this,
          &CentralWidget::IncScore);
}

void CentralWidget::IncScore() {
  emit(IncScoreSignal());
}

void CentralWidget::ChangeDifficulty(int level) {
  difficulty_level_ = level;
  exercise_widget_->ChangeDifficulty(level);
}

void CentralWidget::MyResizeEvent(QResizeEvent* event) {
  choice_widget_->MyResizeEvent(event);
}
