
#include <QtWidgets>

#include "xmlhandler.h"

int count1;
//int *count1 = new int;


//XmlHandler::XmlHandler(QTreeWidget *treeWidget)
//    : treeWidget(treeWidget)
//{
//}


    bool XmlHandler::startElement(const QString&,
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
    bool XmlHandler::characters(const QString& strText)
    {
        //m_strText = strText;

        return true;
    }

    // ------------------------------------------------------------------
    bool XmlHandler::endElement(const QString&, const QString&, const QString& str)
    {

//        if (str != "contact" && str != "addressbook") {
//            qDebug() << "TagName:" << str
//                     << "\tText:"  << m_strText;
//        }
        if (str == "author")
        {
            qDebug() << "знайдено книжок " << ++count1;
            //ui->table1->setRowHeight(0,100);
        }
        return true;
    }

    // ------------------------------------------------------------------
    bool XmlHandler::fatalError(const QXmlParseException& exception)
    {
        qDebug() << "Line:"      << exception.lineNumber()
                 << ", Column:"  << exception.columnNumber()
                 << ", Message:" << exception.message();
        return false;
    }

