
#include <QMessageBox>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(slotB1Clicked()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openDocument()));
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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "./",
                                                    " XML (*.xml)");
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,
                            tr("File error"),
                            tr("Failed to open\n%1").arg(fileName));
        return;
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
}
