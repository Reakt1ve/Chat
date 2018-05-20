#include "user.h"
#include "database.h"
#include "file.h"

User::User(){
    DataBase *db = new DataBase;
    db->connectToLocalDataBase("side_db","chat","root","root");
    QSqlQuery *query = new QSqlQuery("SELECT * FROM messages", db->sqldb);
    int count = query->size();

    this->msg_list = new User_message[count];
    this->mList_size = count;

    delete db;
    delete query;
}

void User::load_info(QString user_log){
    this->set_log(user_log);
    this->set_message();
}

void User::set_log(QString log){
    this->login = log;
}

void User::set_message(){
    DataBase *setMessageDataBase = new DataBase;
    setMessageDataBase->connectToLocalDataBase("setMsgDataBase","chat","root","root");
    QSqlQuery *query = new QSqlQuery("SELECT * FROM messages", setMessageDataBase->sqldb);
    QSqlQuery *query1 = new QSqlQuery("SELECT * FROM users", setMessageDataBase->sqldb);

    int i = 0;
    while(query->next()){
        if(i < this->mList_size){
            query1->next();
            this->msg_list[i].set_date(query->value(query->record().indexOf("date")).toString());
            this->msg_list[i].set_time(query->value(query->record().indexOf("time")).toString());
            this->msg_list[i].set_text(query->value(query->record().indexOf("text")).toString());
            this->msg_list[i].set_user(query1->value(query1->record().indexOf("login")).toString());
            i++;
        }
    }

    delete setMessageDataBase;
    delete query;
    delete query1;
}

QString User::get_log(){
    return this->login;
}

User_message User::get_message(int id){
    return this->msg_list[id];
}


//**********************************************************************************CLASS_USER_MESSAGE*******************************************************************



void User_message::set_date(QString date){
    this->date = QDate::fromString(date,"dd.MM.yyyy");
}

void User_message::set_time(QString time){
    this->time = QTime::fromString(time,"hh:mm:ss");
}

void User_message::set_text(QString text){
    this->text = text;
}

void User_message::set_user(QString user){
    this->user = user;
}

QDate User_message::get_date(){
    return this->date;
}

QTime User_message::get_time(){
    return this->time;
}

QString User_message::get_text(){
    return this->text;
}

QString User_message::get_user(){
    return this->user;
}
