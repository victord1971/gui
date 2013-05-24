
#ifndef XMLHANDLER_H
#define XMLHANDLER_H

#include <QIcon>
#include <QXmlDefaultHandler>

QT_BEGIN_NAMESPACE
class QTreeWidget;
class QTreeWidgetItem;
QT_END_NAMESPACE



class XmlHandler : public QXmlDefaultHandler
{
public:
    //XbelHandler(QTreeWidget *treeWidget);

    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &attributes);
    bool endElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName);
    bool characters(const QString &str);
    bool fatalError(const QXmlParseException &exception);
    //QString errorString() const;

private:
    QString m_strText;
    //QTreeWidgetItem *createChildItem(const QString &tagName);

//    QTreeWidget *treeWidget;
//    QTreeWidgetItem *item;
//    QString currentText;
//    QString errorStr;
//    bool metXbelTag;

//    QIcon folderIcon;
//    QIcon bookmarkIcon;
};

#endif
