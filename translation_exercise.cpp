#include "translation_exercise.h"

TranslationExercise::TranslationExercise(QWidget* parent) : ExerciseWidget(
    parent) {
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

void TranslationExercise::GGLoadSentences() {
  sentences_.push_back("Why are we here?");
  translated_.push_back("Зачем мы здесь");

  sentences_.push_back("Just to suffer?");
  translated_.push_back("Просто чтобы страдать?");

  sentences_.push_back("I'm gonna make him an offer he can't refuse.");
  translated_.push_back(
      "Я собираюсь сделать ему предложение, от которого он не сможет отказаться.");

  sentences_.push_back("May the force be with you.");
  translated_.push_back("Да прибудет с тобой сила.");

  sentences_.push_back("I love the smell of napalm in the morning.");
  translated_.push_back("Люблю запах напалма по утрам.");
}

void TranslationExercise::GenerateNewExercise() {
  sentences_.clear();
  translated_.clear();
  count_incorrect_ = 0;
  cur_num_question_ = 0;

  exercise_timer_->setSingleShot(true);
  exercise_timer_->setInterval(time_to_solve_);
  exercise_timer_->start();

  GGLoadSentences();
  GenerateNextPart();
}

void TranslationExercise::CheckAnswerAndToNextPart() {
  CheckAnswer();

  progress_bar_->setValue(cur_num_question_);
  if (cur_num_question_ < count_questions_) {
    GenerateNextPart();
  } else {
  }
}

void TranslationExercise::CheckAnswer() {
  if (translated_[cur_num_question_ - 1].toLower()
      != answer_->toPlainText().toLower()) {
    IncIncorrect();
  }
}

void TranslationExercise::GenerateNextPart() {
  sentence_label_->setText(sentences_[cur_num_question_++]);
  answer_->setText(tr(""));
}
