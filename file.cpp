#include "file.h"

File::File(){}

void File::createFile(QString file_name,QString file_text){
    QFile n_file(file_name);
    if(n_file.open(QIODevice::WriteOnly)){
        QTextStream in(&n_file);
        in << file_text;
        n_file.close();
    }
}

QString File::getAll(QString file){
    QFile *u_file = new QFile(file);
    QString r_text;
    if(u_file->open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream out(u_file);
        while(!out.atEnd()){
            r_text = r_text + out.readLine();
        }
        u_file->close();
    }
    return r_text;
}

QString File::getInformativeText(QString file, QString feature){
    File *fl = new File;
    QString r_text;

    r_text = fl->getAll(file);
    int keyWord = fl->findIndexKeyWord(r_text, feature) ;

    if(keyWord != -1){
        QString res;
        while(r_text[keyWord] != 59){
            res = res + r_text[keyWord];
            keyWord++;
        }
        return res;
    }else qDebug() << "Слово не найдено! Возвращен NULL";

    return "NULL";
}

int File::findIndexKeyWord(QString r_text, QString keyWord){
    qDebug() << r_text;
    int idx = 0;
    for(int i = 0; i < r_text.size(); i++){
        if(r_text[i] == keyWord[0]){
            for(int j = 1; j < keyWord.size(); j++){
                if(r_text[i+j] != keyWord[j]) break;
                if(j == keyWord.size()-1){
                    idx = i+j+3;
                    return idx;
                }
            }
        }
    }

    return -1;
}
