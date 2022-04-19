#include "tasks_loader.h"

#include <random>

std::vector<std::pair<QString, QString>>
TasksLoader::LoadTranslation(int cnt, int level) {
  std::ifstream in_eng;
  std::ifstream in_ans;
  switch (level) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    case 2: {
      break;
    }
    default: {
      break;
    }
  }

  std::vector<std::pair<QString, QString>> exercises;
  for (int i = 0; i < 10; ++i) {
    exercises.emplace_back();
    std::string str;
    std::getline(in_eng, str);
    exercises.back().first = QString::fromStdString(str);
    std::getline(in_ans, str);
    exercises.back().second = QString::fromStdString(str);
  }
  std::shuffle(exercises.begin(),
               exercises.end(),
               std::mt19937(std::random_device()()));
  exercises.resize(cnt);
  exercises.shrink_to_fit();
  return exercises;
}

QVector<GrammarQuestion> TasksLoader::LoadGrammar(int cnt) {
  Q_UNUSED(cnt);
  return {};
}