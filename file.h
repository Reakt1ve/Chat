#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

class File : public QFile{
private:
    int findIndexKeyWord(QString r_text, QString keyWord);
public:
    File();
    void createFile(QString file_name, QString file_text);
    QString getAll(QString file);
    QString getInformativeText(QString file, QString feature);
};

#endif // FILE_H
