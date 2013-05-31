/* ======================================================================
**  main.cpp
** ======================================================================
**
** ======================================================================
**  Copyright (c) 2007 by Max Schlee
** ======================================================================
*/
#include <QtWidgets>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QTableWidget  tbl(10,3);
    QStringList  lst;

    lst << "Folders" << "Used Space" << "321";
    //tbl.setHeaderLabels(lst);
    tbl.setHorizontalHeaderLabels(lst);

    tbl.setColumnWidth(0, 200);
    //tbl.setSortingEnabled(true);

    QTableWidgetItem *ptwgItem = new QTableWidgetItem;
//    ptwgItem->setText(2, "Local Disk(C)");
//    ptwgItem->setIcon(2, QPixmap("drive.bmp"));
    ptwgItem->setText("Local Disk(C)");
    ptwgItem->setIcon(QPixmap("drive.bmp"));
    tbl.setItem(0,0,ptwgItem);

    for (int i = 1; i < 10; ++i) {
//        QTableWidgetItem *ptwgItemDir;
//        QTableWidgetItem *ptwgItemDir2;
//        ptwgItemDir->setText(2, "Directory" + QString::number(i));
//        ptwgItemDir->setText(1, QString::number(i) + "MB");
//        ptwgItemDir->setIcon(2, QPixmap("folder.bmp"));
        //ptwgItemDir->setIcon(QPixmap("folder.bmp"));
        //tbl.setItem(i,0,new QTableWidgetItem(QPixmap("folder.bmp")));
//        ptwgItemDir->setText("Directory" + QString::number(i));
        tbl.setItem(i,0,new QTableWidgetItem("Directory" + QString::number(i)));
//        ptwgItemDir2->setText(QString::number(i) + "MB");
        tbl.setItem(i,1,new QTableWidgetItem(QString::number(i) + "MB"));
    }
    //tbl.setItemExpanded(ptwgItem, true);
    tbl.resize(500, 700);
    tbl.show();

    return app.exec();
}
