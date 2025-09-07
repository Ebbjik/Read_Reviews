#ifndef REVIEWS_H
#define REVIEWS_H

#include <QMainWindow>
#include <QPushButton>

class Reviews : public QMainWindow {
  Q_OBJECT

public:
  explicit Reviews(QWidget *parent = nullptr);

private slots:
  void handleButton();

private:
  QPushButton *button;
};

#endif // REVIEWS_H
