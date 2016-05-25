#-------------------------------------------------
#
# Project created by QtCreator 2011-06-19T19:43:01
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = plottherm2
TEMPLATE = app


SOURCES += main.cpp \
    mywidgets.cpp

HEADERS  += \
    mywidgets.h

#uncomment this part to display the console window (then you have to recompile all your project)
#CONFIG      += console

#this is the commands you have to add :
#-the port com library :
INCLUDEPATH += /usr/local/qwt-6.1.2/lib/
INCLUDEPATH += /usr/local/qwt-6.1.2/include/
LIBS += -L/usr/local/qwt-6.1.2/lib -lqwt
