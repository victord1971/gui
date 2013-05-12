#include "mainwindow.h"
#include "main.h"
#include "classxml.h"
#include <QApplication>
#include <QtXml>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    classXML clXML;

    w.show();
    
    return a.exec();
}
