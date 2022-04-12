#ifndef GRAMMAR_WIDGET_H_
#define GRAMMAR_WIDGET_H_

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>

class GrammarWidget : public QWidget {
 Q_OBJECT
 public:
  explicit GrammarWidget(QWidget* parent);
  void GenerateNewSentence();

 private:
  QVBoxLayout* layout_;

  QLabel* task_label_;
  QLabel* sentence_label_;
  QGroupBox* radio_box_;

  QRadioButton* variant_1_;
  QRadioButton* variant_2_;
  QRadioButton* variant_3_;

  QPushButton* submit_button_;
 private:
};

#endif  // GRAMMAR_WIDGET_H_
