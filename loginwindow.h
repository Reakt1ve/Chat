#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LogInWindow;
}

class LogInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LogInWindow(QWidget *parent = 0);
    ~LogInWindow();

private slots:
    void on_logInPushButton_clicked();
    void on_RegPushButton_clicked();

private:
    Ui::LogInWindow *ui;
};

#endif // LOGINWINDOW_H
