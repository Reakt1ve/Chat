#include <QApplication>
#include "loginwindow.h"
#include "file.h"
#include "sys.h"

void init_app();

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    init_app();

    return a.exec();
}

void init_app(){
    File *n_file = new File;
    n_file->setFileName("conf.txt");
    if(!n_file->exists()) n_file->createFile("conf.txt","Host_IP: 127.0.0.1;\r\nPort: 3306;");
    delete n_file;

    Environment *env = new Environment;
    env->set_host_ip();
    env->set_port();

    LogInWindow *w = new LogInWindow;
    w->show();
}
