#include "choice_widget.h"

#include <iostream>

ChoiceWidget::ChoiceWidget(QWidget* parent)
    : QWidget(parent),
      vert_layout_(new QVBoxLayout(this)),
      hello_label_(new QLabel("Hello!", this)),
      start_label_(new QLabel("Let's start your lesson", this)),
      translation_button_(new QPushButton("Translation", this)),
      grammar_button_(new QPushButton("Grammar", this)) {
  translation_button_->setSizePolicy(QSizePolicy::Expanding,
                                     QSizePolicy::Expanding);
  grammar_button_->setSizePolicy(QSizePolicy::Expanding,
                                 QSizePolicy::Expanding);

  translation_button_->setStyleSheet("background-color: #50c878");
  grammar_button_->setStyleSheet("background-color: #50c878");

  QHBoxLayout* layouts[2];
  layouts[0] = new QHBoxLayout();
  layouts[1] = new QHBoxLayout();

  layouts[0]->addSpacerItem(
      new QSpacerItem(10, 10,
                      QSizePolicy::Expanding, QSizePolicy::Expanding));
  layouts[0]->setStretch(0, 2);
  layouts[0]->addWidget(translation_button_);
  layouts[0]->setStretch(1, 2);
  layouts[0]->addSpacerItem(
      new QSpacerItem(10, 10,
                      QSizePolicy::Expanding, QSizePolicy::Expanding));
  layouts[0]->setStretch(2, 2);

  layouts[1]->addSpacerItem(
      new QSpacerItem(10, 10,
                      QSizePolicy::Expanding, QSizePolicy::Expanding));
  layouts[1]->setStretch(0, 2);
  layouts[1]->addWidget(grammar_button_);
  layouts[1]->setStretch(1, 2);
  layouts[1]->addSpacerItem(
      new QSpacerItem(10, 10,
                      QSizePolicy::Expanding, QSizePolicy::Expanding));
  layouts[1]->setStretch(2, 2);

  vert_layout_->addSpacerItem(
      new QSpacerItem(10, 10,
                      QSizePolicy::Expanding, QSizePolicy::Expanding));
  vert_layout_->setStretch(0, 1);
  vert_layout_->addWidget(hello_label_, 0, Qt::AlignCenter);
  vert_layout_->setStretch(1, 1);
  vert_layout_->addSpacerItem(
      new QSpacerItem(10, 10,
                      QSizePolicy::Expanding, QSizePolicy::Expanding));
  vert_layout_->setStretch(2, 3);
  vert_layout_->addWidget(start_label_, 0, Qt::AlignCenter);
  vert_layout_->setStretch(3, 1);
  vert_layout_->addSpacerItem(
      new QSpacerItem(10, 10,
                      QSizePolicy::Expanding, QSizePolicy::Expanding));
  vert_layout_->setStretch(4, 1);

  vert_layout_->addLayout(layouts[0], 2);

  vert_layout_->addSpacerItem(
      new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Expanding));
  vert_layout_->setStretch(6, 0);

  vert_layout_->addLayout(layouts[1], 2);

  vert_layout_->addSpacerItem(
      new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Expanding));
  vert_layout_->setStretch(8, 3);

  connect(translation_button_,
          &QPushButton::clicked,
          this,
          &ChoiceWidget::ChangeToTranslation);
  connect(grammar_button_,
          &QPushButton::clicked,
          this,
          &ChoiceWidget::ChangeToGrammar);
}

void ChoiceWidget::ChangeToTranslation() {
  translation_button_->setStyleSheet("background-color: #8b008b");
  grammar_button_->setStyleSheet("background-color: #50c878");
  emit(ChangeToTranslationSignal());
}

void ChoiceWidget::ChangeToGrammar() {
  translation_button_->setStyleSheet("background-color: #50c878");
  grammar_button_->setStyleSheet("background-color: #8b008b");
  emit(ChangeToGrammarSignal());
}

void ChoiceWidget::MyResizeEvent(QResizeEvent* event) {
  int sz = std::min(event->size().width(), event->size().height());
  QFont font;
  font.setPointSizeF(sz / 35.0);
  translation_button_->setFont(font);
  grammar_button_->setFont(font);
}
