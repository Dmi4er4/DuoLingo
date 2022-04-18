#include "grammar_exercise.h"

GrammarExercise::GrammarExercise(QWidget* parent) : ExerciseWidget(parent) {
  radio_box_ = new QGroupBox(this);

  variant_1_ = new QRadioButton("1");
  variant_2_ = new QRadioButton("2");
  variant_3_ = new QRadioButton("3");

  task_label_->setText("Choose the right answer:");

  sentence_label_->setWordWrap(true);
  submit_button_->setSizePolicy(QSizePolicy::Expanding,
                                QSizePolicy::Expanding);

  auto* radio_layout_ = new QVBoxLayout();
  radio_layout_->addWidget(variant_1_);
  radio_layout_->addWidget(variant_2_);
  radio_layout_->addWidget(variant_3_);

  radio_box_->setLayout(radio_layout_);

  layout_->addWidget(task_label_, 1);

  layout_->addWidget(sentence_label_, 2);

  layout_->addWidget(radio_box_, 3);

  layout_->addWidget(submit_button_, 1);

  layout_->addWidget(progress_bar_, 1);

  progress_bar_->setMaximum(count_questions_);

  setLayout(layout_);
  GGLoadSentences();
  GenerateNextPart();

  connect(submit_button_, &QPushButton::clicked,
          this, &GrammarExercise::CheckAnswerAndToNextPart);
}

void GrammarExercise::GGLoadSentences() {
  GrammarQuestion exercise;
  exercise.question =
      tr("I think that the problem Henry raised is a major ________ for our society today.");
  exercise.variants.push_back("theme");
  exercise.variants.push_back("issue");
  exercise.variants.push_back("point");
  exercise.variants.push_back("major");
  exercise.answer = "issue";
  exercise.tip = "You need write here";
  exercises_.push_back(exercise);
  exercises_.push_back(exercise);
  exercises_.push_back(exercise);
  exercises_.push_back(exercise);
  exercises_.push_back(exercise);
}

void GrammarExercise::GenerateNewExercise() {
  exercises_.clear();
  count_incorrect_ = 0;
  cur_num_question_ = 0;
  GGLoadSentences();
}

void GrammarExercise::CheckAnswerAndToNextPart() {
  CheckAnswer();

  progress_bar_->setValue(cur_num_question_);
  if (cur_num_question_ < count_questions_) {
    GenerateNextPart();
  } else {

  }
}

void GrammarExercise::CheckAnswer() {
  const QRadioButton* selected_variant = nullptr;
  if (variant_1_->isChecked()) {
    selected_variant = variant_1_;
  }
  if (variant_2_->isChecked()) {
    selected_variant = variant_2_;
  }
  if (variant_3_->isChecked()) {
    selected_variant = variant_3_;
  }
  if (exercises_[cur_num_question_ - 1].answer != selected_variant->text()) {
    IncIncorrect();
  }
}

void GrammarExercise::GenerateNextPart() {
  cur_num_question_++;
  sentence_label_->setText(exercises_[cur_num_question_ - 1].question);
  variant_1_->setText(exercises_[cur_num_question_ - 1].variants[0]);
  variant_2_->setText(exercises_[cur_num_question_ - 1].variants[1]);
  variant_3_->setText(exercises_[cur_num_question_ - 1].variants[2]);

  variant_1_->setChecked(true);
}
