#include "ui_loginwindow.h"
#include "database.h"
#include "mainwindow.h"
#include "registrationwindow.h"
#include "loginwindow.h"
#include "massageerror.h"

LogInWindow::LogInWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInWindow)
{
    ui->setupUi(this);
    this->setFixedHeight(226);
    this->setFixedWidth(225);
}

LogInWindow::~LogInWindow(){
    delete ui;
}

void LogInWindow::on_logInPushButton_clicked(){
    DataBase *db = new DataBase;
    db->connectToLocalDataBase("main_threat", "chat", "root", "root");
    if((db->isThereValueInBase(ui->logLineEdit->text(), "login") && db->isThereValueInBase(ui->passwordLineEdit->text(), "password")) == true){
        delete db;
        MainWindow *mw = new MainWindow;
        this->close();
        mw->show();
    }
    else{
        delete db;
        MassageError *msg = new MassageError(0);
        msg->show();
        return;
    }
}

void LogInWindow::on_RegPushButton_clicked(){
    RegistrationWindow *rw = new RegistrationWindow;
    this->close();
    rw->show();
}
