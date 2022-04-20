#include "tasks_loader.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <random>

std::vector<std::pair<QString, QString>> TasksLoader::LoadTranslation(int cnt, int level) {
  QString file_path;
  switch (level) {
    case 0: {
      file_path = ":/exercises/translation_easy.json";
      break;
    }
    case 1: {
      file_path = ":/exercises/translation_medium.json";
      break;
    }
    case 2: {
      file_path = ":/exercises/translation_hard.json";
      break;
    }
    default: {
      break;
    }
  }

  QJsonObject json_exs = LoadJson(file_path);

  std::vector<std::pair<QString, QString>> exercises;

  for (const auto &exercise_val : json_exs.value(QString("exercises")).toArray()) {
    auto exercise_obj = exercise_val.toObject();

    if (!IfJsonContainsFields(exercise_obj, kNeededTranslation)) {
      continue;
    }

    exercises.push_back(GetTranslationFromJson(exercise_obj));
  }

  std::shuffle(exercises.begin(), exercises.end(), std::mt19937(std::random_device()()));
  exercises.resize(cnt);
  exercises.shrink_to_fit();
  return exercises;
}

std::vector<GrammarQuestion> TasksLoader::LoadGrammar(int cnt, int level) {
  QString file_path;
  switch (level) {
    case 0: {
      file_path = ":/exercises/grammar_easy.json";
      break;
    }
    case 1: {
      file_path = ":/exercises/grammar_medium.json";
      break;
    }
    case 2: {
      file_path = ":/exercises/grammar_hard.json";
      break;
    }
    default: {
      break;
    }
  }

  QJsonObject json_exs = LoadJson(file_path);

  std::vector<GrammarQuestion> exercises;
  for (const auto &exercise_val : json_exs.value(QString("exercises")).toArray()) {
    auto exercise_obj = exercise_val.toObject();

    if (!IfJsonContainsFields(exercise_obj, kNeededGrammar)) {
      continue;
    }

    exercises.push_back(GetGrammarFromJson(exercise_obj));
  }

  exercises.shrink_to_fit();
  std::random_shuffle(exercises.begin(), exercises.end());
  exercises.resize(cnt);
  return exercises;
}

QJsonObject TasksLoader::LoadJson(QString file_path) {
  QFile file_tasks(file_path);

  if (!file_tasks.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Can't open " << file_path << '\n';
    return {};
  }

  QString val = file_tasks.readAll();
  file_tasks.close();
  return QJsonDocument::fromJson(val.toUtf8()).object();
}

bool TasksLoader::IfJsonContainsFields(QJsonObject exercise_obj, QSet<QString> needed) {
  auto keys_list = exercise_obj.keys();
  QSet<QString> keys_set(keys_list.begin(), keys_list.end());

  if (!keys_set.contains(needed)) {
    qDebug() << "json hasn't " << QSet(needed).subtract(keys_set) << "fields. "
             << exercise_obj << '\n';
    return false;
  }
  return true;
}
std::pair<QString, QString> TasksLoader::GetTranslationFromJson(QJsonObject exercise_obj) {
  std::pair<QString, QString> question;
  question.first = exercise_obj["text"].toString();
  question.second = exercise_obj["translated"].toString();
  return question;
}

GrammarQuestion TasksLoader::GetGrammarFromJson(QJsonObject exercise_obj) {
  GrammarQuestion question;
  question.question = exercise_obj["question"].toString();

  for (const auto &variant : exercise_obj["variants"].toArray()) {
    question.variants.push_back(variant.toString());
  }

  question.answer = exercise_obj["answer"].toString();
  question.tip = exercise_obj["tip"].toString();
  return question;
}
