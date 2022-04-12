#include "choice_widget.h"

#include <iostream>

ChoiceWidget::ChoiceWidget(QWidget* parent)
    : vert_layout_(new QVBoxLayout(this)),
      hello_label_(new QLabel(tr("Hello!"), this)),
      start_label_(new QLabel(tr("Let's start your lesson"), this)),
      translation_button_(new QPushButton(tr("Translation"), this)),
      grammar_button_(new QPushButton(tr("Grammar"), this)){
  setParent(parent);
  translation_button_->setSizePolicy(QSizePolicy::Expanding,
                                     QSizePolicy::Expanding);
  grammar_button_->setSizePolicy(QSizePolicy::Expanding,
                                 QSizePolicy::Expanding);

  QHBoxLayout* layouts[2];
  layouts[0] = new QHBoxLayout();
  layouts[1] = new QHBoxLayout();

  auto* spacer_item =
      new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Expanding);

  layouts[0]->addSpacerItem(spacer_item);
  layouts[0]->setStretch(0, 2);
  layouts[0]->addWidget(translation_button_);
  layouts[0]->setStretch(1, 2);
  layouts[0]->addSpacerItem(spacer_item);
  layouts[0]->setStretch(2, 2);

  layouts[1]->addSpacerItem(spacer_item);
  layouts[1]->setStretch(0, 2);
  layouts[1]->addWidget(grammar_button_);
  layouts[1]->setStretch(1, 2);
  layouts[1]->addSpacerItem(spacer_item);
  layouts[1]->setStretch(2, 2);

  vert_layout_->addSpacerItem(spacer_item);
  vert_layout_->setStretch(0, 1);
  vert_layout_->addWidget(hello_label_, 0, Qt::AlignCenter);
  vert_layout_->setStretch(1, 1);
  vert_layout_->addSpacerItem(spacer_item);
  vert_layout_->setStretch(2, 3);
  vert_layout_->addWidget(start_label_, 0, Qt::AlignCenter);
  vert_layout_->setStretch(3, 1);
  vert_layout_->addSpacerItem(spacer_item);
  vert_layout_->setStretch(4, 1);

  vert_layout_->addLayout(layouts[0], 2);

  vert_layout_->addSpacerItem(spacer_item);
  vert_layout_->setStretch(6, 0);

  vert_layout_->addLayout(layouts[1], 2);

  vert_layout_->addSpacerItem(spacer_item);
  vert_layout_->setStretch(8, 3);
}

