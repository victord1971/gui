#include "mainwindow.h"
#include "main.h"

#include <QApplication>
//#include <QtXml>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    MainWindow *w = new MainWindow;

    w->show();
    
    return a.exec();
}
