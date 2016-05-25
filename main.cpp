#include <QApplication>
#include "mywidgets.h"
#include <QtGui>

//here you have nothing to add

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    mywidget w;
    w.show();

    return a.exec();
}
