#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "massageerror.h"

MainWindow::MainWindow(User *user_info, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedHeight(430);
    this->setFixedWidth(519);
    this->setUserInformation(user_info);
}

void MainWindow::setUserInformation(User *user_info){
    ui->presentName->setText(user_info->get_log());

    // Акифон, отображение сообщения за тобой.
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_quitPushButton_clicked(){

}

void MainWindow::on_sendPushButton_clicked(){

}
