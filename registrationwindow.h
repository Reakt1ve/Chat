#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = 0);
    ~RegistrationWindow();

private slots:
    void on_confirmRegPushButton_clicked();

private:
    Ui::RegistrationWindow *ui;
};

#endif // REGISTRATIONWINDOW_H
