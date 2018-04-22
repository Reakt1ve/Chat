#ifndef USER_H
#define USER_H

#include <QString>
#include <QDate>
#include <QTime>
#include <QSqlQuery>

class User_message{
private:
    QDate date;
    QTime time;
    QString text;
public:
    void set_date(QString date);
    void set_time(QString time);
    void set_text(QString text);

    QDate get_date();
    QTime get_time();
    QString get_text();
};

class User{
private:
    User_message *msg_list;
    int mList_size;
    QString login;
    QString conf_IP;

    void set_log(QString log);
    void set_message();
public:
    User();
    void load_info(QString user_log);
    QString get_log();
    User_message get_message(int id);
};

#endif // USER_H
