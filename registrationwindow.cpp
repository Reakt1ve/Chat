#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include "database.h"
#include "mainwindow.h"
#include "massageerror.h"
#include "user.h"

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    this->setFixedHeight(209);
    this->setFixedWidth(254);
}

RegistrationWindow::~RegistrationWindow(){
    delete ui;
}

void RegistrationWindow::on_confirmRegPushButton_clicked(){       
    if(ui->regPassLineEdit->text() != ui->regRepPassLineEdit->text()){
        MassageError *msg = new MassageError(1);
        msg->show();
        return;
    }else{
        DataBase *db = new DataBase;
        db->connectToLocalDataBase("main_threat", "chat", "root", "root");

        QList<DataBase_cell*>c_list;
        DataBase_cell *cell_1 = new DataBase_cell;
        cell_1->set_name("login");
        cell_1->set_value(ui->regLoginLineEdit->text());
        c_list.append(cell_1);
        DataBase_cell *cell_2 = new DataBase_cell;
        cell_2->set_name("password");
        cell_2->set_value(ui->regPassLineEdit->text());
        c_list.append(cell_2);

        if(db->setInformation(c_list) == true){
            User *usr = new User;
            usr->load_info(ui->regLoginLineEdit->text());

            this->close();
            MainWindow *mw = new MainWindow(usr);
            mw->show();

            delete db;
            delete usr;
        }else{
            delete db;
            MassageError *msg = new MassageError(2);
            msg->show();
            return;
        }
    }
}
