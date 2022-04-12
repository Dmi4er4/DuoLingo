#include "translation_widget.h"

TranslationWidget::TranslationWidget(QWidget* parent) {
  setParent(parent);
  task_label_ = new QLabel("Translate this sentence", this);
  sentence_label_ = new QLabel("", this);
  answer_ = new QTextEdit("", this);
  submit_button_ = new QPushButton("Submit", this);
  layout_ = new QVBoxLayout(this);

  layout_->addWidget(task_label_);

  layout_->addWidget(sentence_label_);

  layout_->addWidget(answer_);

  layout_->addWidget(submit_button_);

  setLayout(layout_);
  GenerateNewSentence();
}

void TranslationWidget::GenerateNewSentence() {

}
