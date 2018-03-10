#include "database.h"

DataBase::DataBase(){}

void DataBase::connectToLocalDataBase(QString db_threat, QString db_name, QString db_log, QString db_pass){
    this->db_threat = db_threat;

    sqldb = QSqlDatabase::database(db_threat);
    sqldb = QSqlDatabase::addDatabase("QMYSQL", db_threat);

    sqldb.setDatabaseName(db_name);
    sqldb.setHostName("127.0.0.1");
    sqldb.setUserName(db_log);
    sqldb.setPassword(db_pass);

    if(!sqldb.open()) qDebug() << sqldb.lastError().databaseText();
}

bool DataBase::isThereValueInBase(QString val, QString col){
    QSqlQuery *query = new QSqlQuery("SELECT * FROM users",sqldb);
    while(query->next()){
        if(val == query->value(query->record().indexOf(col))) return 1;
    }

    delete query;
    return 0;
}

bool DataBase::setInformation(QList<DataBase_cell*>c_list){
    if(this->isThereValidValue(c_list) == true){
        for(int i = 0; i < c_list.size(); i++){
            c_list[i]->set_type(this->get_headerType(c_list[i]));
        }

        QString query_val;
        for(int i = 0; i < c_list.size(); i++){
            if(c_list[i]->get_type() == "varchar" || "char" || "text"){
                query_val = query_val + "'" + c_list[i]->get_value() + "'";
                if(i != c_list.size()-1) query_val = query_val + ",";
            }
            else{
                query_val = query_val + c_list[i]->get_value() + ",";
                if(i != c_list.size()-1) query_val = query_val + ",";
            }
        }

        QString query_name;
        for(int i = 0; i < c_list.size(); i++){
            query_name = query_name  + c_list[i]->get_name();
            if(i != c_list.size()-1) query_name = query_name + ",";
        }

        QSqlQuery *query = new QSqlQuery(this->sqldb);
        if(!query->exec("INSERT INTO users (" + query_name + ") VALUES (" + query_val + ")")){
            qDebug() << query->lastError().databaseText();
        }

        delete query;
        return 1;
    }
    else return 0;
}

bool DataBase::deleteInformation(){

}

bool DataBase::updateInformation(){

}

QString DataBase::get_headerType(DataBase_cell *cell){
    DataBase *side_db = new DataBase;
    side_db->connectToLocalDataBase("side_threat", "information_schema", "root", "root");
    QSqlQuery *query = new QSqlQuery("SELECT * FROM COLUMNS",side_db->sqldb);
    QString type;
    while(query->next()){
        if(cell->get_name() == query->value(query->record().indexOf("COLUMN_NAME"))){
            type = query->value(query->record().indexOf("DATA_TYPE")).toString();
            break;
        }
    }

    delete query;
    delete side_db;
    return type;
}

bool DataBase::isThereValidValue(QList<DataBase_cell*>c_list){
    DataBase *check_value = new DataBase;
    check_value->connectToLocalDataBase("check_val","chat","root","root");
    QSqlQuery *query = new QSqlQuery("SELECT * FROM users",check_value->sqldb);
    while(query->next()){
        if(c_list[0]->get_value() == query->value(query->record().indexOf("login"))){
            delete query;
            delete check_value;
            return 0;
        }
    }

    delete query;
    delete check_value;
    return 1;
}

DataBase::~DataBase(){
    sqldb = QSqlDatabase();
    QSqlDatabase::removeDatabase(db_threat);
}



//**********************************************************CLASS DATABASE_CELL**********************************************************************




DataBase_cell::DataBase_cell(){
    this->set_name("0");
    this->set_type("0");
    this->set_value("0");
}

void DataBase_cell::set_name(QString name){
    this->t_name = name;
}

void DataBase_cell::set_value(QString value){
    this->t_val = value;
}

void DataBase_cell::set_type(QString type){
    this->t_type = type;
}

QString DataBase_cell::get_name(){
    return t_name;
}

QString DataBase_cell::get_value(){
    return t_val;
}

QString DataBase_cell::get_type(){
    return t_type;
}
