#include "exercise_widget.h"

ExerciseWidget::ExerciseWidget(QWidget* parent) : exercise_(nullptr) {
  setParent(parent);
  ChangeToTranslation();
}

void ExerciseWidget::ChangeToTranslation() {
  delete exercise_;
  exercise_ = new TranslationWidget(this);
}

void ExerciseWidget::ChangeToGrammar() {
  delete exercise_;
  exercise_ = new GrammarWidget(this);
}

void ExerciseWidget::GenerateNewSentence() {

}
