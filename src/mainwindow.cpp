#include "mainwindow.h"
#include <QDebug>
#include <QFrame>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  // 创建中央窗口部件
  QWidget *central = new QWidget(this);
  setCentralWidget(central);

  // 布局
  QVBoxLayout *mainLayout = new QVBoxLayout(central);

  // 用户信息区域
  QHBoxLayout *userInfoLayout = new QHBoxLayout;
  QLabel *avatar = new QLabel;
  // 设置头像图片
  QPixmap pixmap(":/resources/image.png"); // 使用资源路径
  if (pixmap.isNull()) {
    qDebug() << "图片加载失败，路径:" << ":/resources/image.png";
  } else {
    avatar->setPixmap(pixmap);
    avatar->setScaledContents(true); // 使图片适应 QLabel 的大小
  }

  QLabel *usernameLabel = new QLabel("你好，xxx/未登录");
  userInfoLayout->addWidget(avatar);
  userInfoLayout->addWidget(usernameLabel);
  mainLayout->addLayout(userInfoLayout);

  // 面包屑导航
  QHBoxLayout *breadcrumbLayout = new QHBoxLayout;
  QLabel *breadcrumbLabel = new QLabel("面包屑");
  breadcrumbLabel->setStyleSheet("background-color: #f0f0f0; padding: 5px;");
  breadcrumbLayout->addWidget(breadcrumbLabel);
  mainLayout->addLayout(breadcrumbLayout);

  // 表格区域
  QFrame *tableFrame = new QFrame;
  tableFrame->setFrameShape(QFrame::Box);
  tableFrame->setFrameShadow(QFrame::Raised);
  tableFrame->setLineWidth(1);
  tableFrame->setMidLineWidth(1);
  tableFrame->setStyleSheet("background-color: #f5f5f5;");
  QVBoxLayout *tableLayout = new QVBoxLayout(tableFrame);

  // 创建表格
  QTableWidget *table = new QTableWidget;
  table->setRowCount(1);
  table->setColumnCount(1);
  table->setItem(0, 0, new QTableWidgetItem("表格"));
  table->setHorizontalHeaderItem(0, new QTableWidgetItem(""));
  table->setVerticalHeaderItem(0, new QTableWidgetItem(""));
  table->horizontalHeader()->hide();
  table->verticalHeader()->hide();
  table->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑
  table->setStyleSheet("font-size: 24px;");

  tableLayout->addWidget(table);

  // 将表格框架添加到主布局
  mainLayout->addWidget(tableFrame);

  // 设置窗口标题
  setWindowTitle("评论列表");
  resize(400, 300);
}

void MainWindow::handleButton() {
  QMessageBox::information(this, "提示", "按钮被点击");
}
