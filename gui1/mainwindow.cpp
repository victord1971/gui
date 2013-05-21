
#include <QMessageBox>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtXml>

QString fileName;
QFile file(fileName);
QXmlInputSource   source(&file);
int count1;//=0;



// ======================================================================
class AddressBookParser : public QXmlDefaultHandler {
    //Q_OBJECT
signals:
    void doFu();

private:
    QString m_strText;

public:
    friend void fu(void);
    // ------------------------------------------------------------------
    bool startElement(const QString&,
                      const QString&,
                      const QString&,
                      const QXmlAttributes& attrs
                     )
    {
        for(int i = 0; i < attrs.count(); i++) {
            if(attrs.localName(i) == "number") {
                qDebug() << "Attr:" << attrs.value(i);
            }
        }
        return true;
    }

    // ------------------------------------------------------------------
    bool characters(const QString& strText)
    {
        m_strText = strText;
        //qDebug() << "знайдено!";
        //emit doFu();
        return true;
    }

    // ------------------------------------------------------------------
    bool endElement(const QString&, const QString&, const QString& str)
    {

//        if (str != "contact" && str != "addressbook") {
//            qDebug() << "TagName:" << str
//                     << "\tText:"  << m_strText;
//        }
        if (str == "author")
        {
            qDebug() << "знайдено книжок " << ++count1;
            //fu();
            //emit doFu();
        }
        return true;
    }

    // ------------------------------------------------------------------
    bool fatalError(const QXmlParseException& exception)
    {
        qDebug() << "Line:"      << exception.lineNumber()
                 << ", Column:"  << exception.columnNumber()
                 << ", Message:" << exception.message();
        return false;
    }

};
//=====================================================================



AddressBookParser handler;
//QFile             file("xml_0.xml");
//QXmlInputSource   source(&file);
QXmlSimpleReader  reader;


//======================================================================
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

    reader.setContentHandler(&handler);
    reader.parse(source);
    ui->table1->setRowCount(count1-1);
    //ui->table1->show();
}

void MainWindow::slotFu()
{

}



void fu(void)
{
    //table->setItem(k, 0,new QTableWidgetItem(zzzz));
                //Ui_MainWindow.table1->setItem(count1,1,new QTableWidgetItem(count1));
    //Ui_MainWindow.table1->setRowHeight(1,23);
}

