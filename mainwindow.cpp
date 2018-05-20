#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "massageerror.h"
#include "qstandarditemmodel.h"

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
    QStandardItemModel* name=new QStandardItemModel(200,3,this);
    ui->tableView->setModel(name);
    int row=0;
    int id=User.get_list_size()-200;
    if (id>0)
        id=0;
    while(id!=User.get_list_size()){
        name->setData(name->index(row,0),user_info->get_message(id).);                                     //имя
        name->setData(name->index(row,1),user_info->get_message(id).get_text());
        name->setData(name->index(row,2),user_info->get_message(id).get_time());
        name->setData(name->index(row,3),user_info->get_message(id).get_date());
        id++;
        row++;
    }


//    if (row_now!=200){
//    for(int row = 0; row < (l_model->rowCount()); row++){ }
//       name->setData(name->index(row_now,0),user_info->get_message(12).);                                     //имя
//       name->setData(name->index(row_now,1),user_info->get_message(12).get_text());
//       name->setData(name->index(row_now,2),user_info->get_message(12).get_time());
//       name->setData(name->index(row_now,3),user_info->get_message(12).get_date());
//    }
// else{
//    for(int row = 0; row < (l_model->row_now()); row++){
//        name->setData(name->index(row,0),name->data(name->index(row+1,0)));                                     //имя
//        name->setData(name->index(row,1),name->data(name->index(row+1,1)));
//        name->setData(name->index(row,2),name->data(name->index(row+1,2)));
//        name->setData(name->index(row,3),name->data(name->index(row+1,3)));
//    }
//    name->setData(name->index(row_now,0),user_info->get_message(12).);                                     //имя
//    name->setData(name->index(row_now,1),user_info->get_message(12).get_text());
//    name->setData(name->index(row_now,2),user_info->get_message(12).get_time());
//    name->setData(name->index(row_now,3),user_info->get_message(12).get_date());
//  }
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_quitPushButton_clicked(){

}

void MainWindow::on_sendPushButton_clicked(){

}
