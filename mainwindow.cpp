#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "massageerror.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedHeight(430);
    this->setFixedWidth(519);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_quitPushButton_clicked(){

}

void MainWindow::on_sendPushButton_clicked(){

}
