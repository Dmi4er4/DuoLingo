#ifndef EXERCISE_WIDGET_H_
#define EXERCISE_WIDGET_H_

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class ExerciseWidget : public QWidget {
  Q_OBJECT
 public:
  explicit ExerciseWidget(QWidget* parent = nullptr);
  virtual ~ExerciseWidget() = default;
};

#endif  // EXERCISE_WIDGET_H_
