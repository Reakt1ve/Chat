#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(User *user_info, QWidget *parent = 0);
    void setUserInformation(User *user_info);
    ~MainWindow();

private slots:
    void on_quitPushButton_clicked();
    void on_sendPushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
