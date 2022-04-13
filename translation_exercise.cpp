#include "translation_exercise.h"

TranslationExercise::TranslationExercise(QWidget* parent) : ExerciseWidget(
    parent) {
  task_label_ = new QLabel("Translate this sentence", this);
  sentence_label_ = new QLabel("Never gonna give you up", this);
  answer_ = new QTextEdit(this);
  answer_->setPlaceholderText("Write your translation here");
  submit_button_ = new QPushButton("Submit", this);
  layout_ = new QVBoxLayout(this);

  layout_->addWidget(task_label_);

  layout_->addWidget(sentence_label_);

  layout_->addWidget(answer_);

  layout_->addWidget(submit_button_);

  connect(submit_button_, &QPushButton::clicked,
          this, &TranslationExercise::CheckAnswerAndToNextPart);

  setLayout(layout_);
  GGLoadSentences();
  GenerateNextPart();
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

void TranslationExercise::CheckAnswerAndToNextPart() {
  CheckTranslation();

  if (cur_num_question_ < count_questions_) {
    GenerateNextPart();
  } else {
  }
}

void TranslationExercise::CheckTranslation() {
  if (translated_[cur_num_question_ - 1].toLower()
      != answer_->toPlainText().toLower()) {
    count_incorrect_++;
  }
}

void TranslationExercise::GenerateNextPart() {
  sentence_label_->setText(sentences_[cur_num_question_++]);
  answer_->setText(tr(""));
}
