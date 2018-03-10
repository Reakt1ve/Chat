#ifndef MASSAGEERROR_H
#define MASSAGEERROR_H

#include <QMessageBox>

class MassageError
{
private:
    int num_msg;
public:
    MassageError(int msg);
    void show();
};

#endif // MASSAGEERROR_H
