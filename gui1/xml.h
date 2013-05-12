#ifndef XML_H
#define XML_H

#include <QObject>

class xml : public QObject
{
    Q_OBJECT
public:
    explicit xml(QObject *parent = 0);
    
signals:
    
public slots:
    void slotQuit();
    
};

#endif // XML_H
