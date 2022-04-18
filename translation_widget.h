#ifndef TRANSLATION_WIDGET_H_
#define TRANSLATION_WIDGET_H_

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

class TranslationWidget : public QWidget {
 Q_OBJECT
 public:
  explicit TranslationWidget(QWidget* parent);
  void GenerateNewSentence();

 private:
  QVBoxLayout* layout_;

  QLabel* task_label_;
  QLabel* sentence_label_;
  QTextEdit* answer_;
  QPushButton* submit_button_;
};

#endif  // TRANSLATION_WIDGET_H_
