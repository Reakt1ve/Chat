#include "loginwindow.h"
#include "file.h"
#include <QApplication>

void init_app();

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    init_app();

    return a.exec();
}

void init_app(){
    Q

    LogInWindow *w = new LogInWindow;
    w->show();
}
