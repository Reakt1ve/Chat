#include "sys.h"
#include "file.h"

void Environment::set_host_ip(){
    File *fl = new File;
    this->host_ip = fl->getInformativeText("conf.txt", "Host_IP");
    delete fl;
}

void Environment::set_port(){
    File *fl = new File;
    this->port = fl->getInformativeText("conf.txt", "Port").toInt();
    delete fl;
}

QString Environment::get_host_ip(){
    return this->host_ip;
}

int Environment::get_port(){
    return this->port;
}

QString Environment::host_ip = "0.0.0.0";
int Environment::port = 0;
