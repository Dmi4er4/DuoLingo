#ifndef TASKS_LOADER_H_
#define TASKS_LOADER_H_

#include <QVector>
#include <QString>
#include <QFile>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "grammar_question.h"

class TasksLoader {
 public:
  static std::vector<std::pair<QString, QString>> LoadTranslation(int cnt,
                                                                  int level);
  static std::vector<GrammarQuestion> LoadGrammar(int cnt, int level);
};

#endif  // TASKS_LOADER_H_