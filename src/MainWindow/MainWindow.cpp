#include "MainWindow.h"
#include "../Reviews/Reviews.h" // 新增
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  // 中央窗口
  QWidget *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  // 页面 1：用 Reviews 替换
  QWidget *page1 = new Reviews; // 这里替换为 Reviews 实例

  // 页面 2
  QWidget *page2 = new QWidget;
  QVBoxLayout *layout2 = new QVBoxLayout(page2);
  layout2->addWidget(new QLabel("这是页面 2"));

  // 堆叠窗口
  stackedWidget = new QStackedWidget;
  stackedWidget->addWidget(page1);
  stackedWidget->addWidget(page2);

  // 切换按钮
  QPushButton *btnSwitch = new QPushButton("切换页面");
  connect(btnSwitch, &QPushButton::clicked, this, &MainWindow::switchPage);

  // 布局
  QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
  mainLayout->addWidget(stackedWidget);
  mainLayout->addWidget(btnSwitch);
}

void MainWindow::switchPage() {
  int index = (stackedWidget->currentIndex() + 1) % stackedWidget->count();
  stackedWidget->setCurrentIndex(index);
}
