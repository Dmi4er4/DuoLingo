#include "central_widget.h"

CentralWidget::CentralWidget(QWidget* parent) :
    choice_widget_(new ChoiceWidget(this)),
    exercise_widget_(new ExerciseWidget(this)) {
  setParent(parent);

  choice_widget_->setSizePolicy(QSizePolicy::Expanding,
                                QSizePolicy::Expanding);
  layout_.addWidget(choice_widget_, 1);
  layout_.addWidget(exercise_widget_, 1);
  setLayout(&layout_);

  ChangeToTranslation();
}

void CentralWidget::ChangeToTranslation() {
  layout_.removeWidget(exercise_widget_);
  delete exercise_widget_;
  exercise_widget_ = new TranslationWidget(this);
  layout_.addWidget(exercise_widget_);
}
