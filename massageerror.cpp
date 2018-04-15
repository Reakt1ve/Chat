#include "massageerror.h"
#include "QDebug"

MassageError::MassageError(int msg){
    this->num_msg = msg;
}

void MassageError::show(){
    switch(num_msg){
        case 0:{
            QMessageBox *msg_1 = new QMessageBox;
            msg_1->setText("Внимание!");
            msg_1->setInformativeText("Неверно введен логин или пароль!");
            msg_1->setStandardButtons(QMessageBox::Cancel);
            msg_1->exec();
            break;
        }
        case 1:{
            QMessageBox *msg_2 = new QMessageBox;
            msg_2->setText("Внимание!");
            msg_2->setInformativeText("Пароли не совпадают!");
            msg_2->setStandardButtons(QMessageBox::Cancel);
            msg_2->exec();
            break;
        }
        case 2:{
            QMessageBox *msg_3 = new QMessageBox;
            msg_3->setText("Внимание!");
            msg_3->setInformativeText("Логин уже занят!");
            msg_3->setStandardButtons(QMessageBox::Cancel);
            msg_3->exec();
            break;
        }
        default:{
            qDebug() << "Введено неправильное значение. Повторите попытку!";
        }

        //
    }
}
