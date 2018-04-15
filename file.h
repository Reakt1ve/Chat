#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QTextStream>
#include <QString>

class File{
public:
    File();
    void createFile(QString file_text);
    void update();
};

#endif // FILE_H
