#include "difficulty_dialog.h"

DifficultyDialog::DifficultyDialog(QWidget* parent) :
    buttons_(new QGroupBox(this)),
    layout_(new QVBoxLayout(this)),
    accept_button_(new QDialogButtonBox(QDialogButtonBox::Ok,
                                        Qt::Horizontal,
                                        this)),
    easy_button_(new QRadioButton(tr("Easy"))),
    medium_button_(new QRadioButton(tr("Medium"))),
    hard_button_(new QRadioButton(tr("Hard"))) {
  setParent(parent);

  auto* vert_box(new QVBoxLayout);
  vert_box->addWidget(easy_button_);
  vert_box->addWidget(medium_button_);
  vert_box->addWidget(hard_button_);

  buttons_->setLayout(vert_box);

  layout_->addWidget(buttons_);
  layout_->addWidget(accept_button_);
}