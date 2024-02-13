#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow() {
  delete ui;
}

// next
void MainWindow::on_pushButton_released() {
  ui->stackedWidget->setCurrentIndex(  ui->stackedWidget->currentIndex() + 1);
}

void MainWindow::on_pushButton_2_released() {
  ui->stackedWidget->setCurrentIndex(  ui->stackedWidget->currentIndex() - 1);
}
