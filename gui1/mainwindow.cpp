
#include <QMessageBox>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xmlhandler.h"
#include <QtXml>

QString fileName;
//QString* fileName = new QString;
QFile file(fileName);
//QFile* file(fileName) = new QFile
QXmlInputSource   source(&file);


extern int count1;

//QXmlSimpleReader  reader;
QXmlSimpleReader *reader = new QXmlSimpleReader;

//======================================================================
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(slotB1Clicked()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openDocument()));
    //connect(&handler, SIGNAL(doFu()), this, SLOT(slotFu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableWidget_activated(const QModelIndex &index)
{
    qDebug() << "on_tableWidget_activated";
}

void MainWindow::slotB1Clicked()
{
    close();
}

void MainWindow::openDocument()
{
    //AddressBookParser handler;
    XmlHandler *handler = new XmlHandler;

    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "./",
                                                    " XML (*.xml)");
    if (fileName.isEmpty())
        return;

    //file(fileName);
    file.setFileName(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,
                            tr("File error"),
                            tr("Failed to open\n%1").arg(fileName));
        return;
    }
    else
    {
        count1=0;
        ui->table1->setRowCount(10000);
    }
//    QTextStream stream(&file);

//    Document *doc = new Document();
//    if (!doc->load(stream)) {
//        QMessageBox::warning(this,
//                            tr("Parse error"),
//                            tr("Failed to parse\n%1").arg(fileName));
//        delete doc;
//        return;
//    }

//    doc->setFileName(fileName);
//    addDocument(doc);

    reader->setContentHandler(handler);
    reader->parse(source);
    ui->table1->setRowCount(count1-1);
    //ui->table1->setRowHeight(0,100);
}


