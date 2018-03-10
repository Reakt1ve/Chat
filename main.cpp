#include "loginwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogInWindow *w = new LogInWindow;
    w->show();

    return a.exec();
}
