#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QList>

class DataBase_cell{
private:
    QString t_name;
    QString t_val;
    QString t_type;
public:
    DataBase_cell();
    void set_name(QString name);
    void set_value(QString value);
    void set_type(QString type);
    QString get_name();
    QString get_value();
    QString get_type();
};

class DataBase
{
private:
    QString db_threat;
    QString get_headerType(DataBase_cell *cell);
    bool isThereValidValue(QList<DataBase_cell *> c_list);
public:
    QSqlDatabase sqldb;

    DataBase();
    void connectToLocalDataBase(QString db_threat, QString db_name, QString db_log, QString db_pass);
    bool isThereValueInBase(QString val, QString col);
    bool setInformation(QList<DataBase_cell *> c_list);
    bool deleteInformation();
    bool updateInformation();
    ~DataBase();
};

#endif // DATABASE_H
