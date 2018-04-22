#ifndef SYS_H
#define SYS_H

#include <QString>

class Environment
{
private:
    static QString host_ip;
    static int port;
public:
    void set_host_ip();
    void set_port();

    QString get_host_ip();
    int get_port();
};

#endif // SYS_H
