#include "grammar_exercise.h"

GrammarExercise::GrammarExercise(QWidget* parent) : ExerciseWidget(parent) {
  layout_ = new QVBoxLayout(this);
  task_label_ = new QLabel("Choose the right answer:", this);
  sentence_label_ = new QLabel("sentence", this);
  radio_box_ = new QGroupBox(this);

  variant_1_ = new QRadioButton("1");
  variant_2_ = new QRadioButton("2");
  variant_3_ = new QRadioButton("3");

  submit_button_ = new QPushButton("Submit", this);

  auto* radio_layout_ = new QVBoxLayout();
  radio_layout_->addWidget(variant_1_);
  radio_layout_->addWidget(variant_2_);
  radio_layout_->addWidget(variant_3_);

  radio_box_->setLayout(radio_layout_);

  layout_->addWidget(task_label_);

  layout_->addWidget(sentence_label_);

  layout_->addWidget(radio_box_);

  layout_->addWidget(submit_button_);

  setLayout(layout_);
  GenerateNewSentence();
}

void GrammarExercise::GenerateNewSentence() {

}
