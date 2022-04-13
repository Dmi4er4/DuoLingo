#ifndef GRAMMAR_QUESTION_H_
#define GRAMMAR_QUESTION_H_

#include <QVector>
#include <QString>

struct GrammarQuestion {
  QString question;
  QVector<QString> variants;
  QString answer;
};

#endif  // GRAMMAR_QUESTION_H_