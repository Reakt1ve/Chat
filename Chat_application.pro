#-------------------------------------------------
#
# Project created by QtCreator 2018-03-09T16:24:58
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chat_application
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    loginwindow.cpp \
    registrationwindow.cpp \
    database.cpp \
    massageerror.cpp \
    user.cpp \
    network.cpp \
    file.cpp \
    sys.cpp

HEADERS  += mainwindow.h \
    loginwindow.h \
    registrationwindow.h \
    database.h \
    massageerror.h \
    user.h \
    network.h \
    file.h \
    sys.h

FORMS    += mainwindow.ui \
    loginwindow.ui \
    registrationwindow.ui
