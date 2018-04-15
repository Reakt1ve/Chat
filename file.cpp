#include "file.h"

File::File(){}

void File::createFile(QString file_text){
    QFile *n_file = new QFile("conf.txt");
    if(!n_file->open(QIODevice::WriteOnly)) return;

    QTextStream in(&n_file);
    in << file_text;
    n_file->close();

    // Дописать
}

void File::update(){

}
