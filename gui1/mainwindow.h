#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    friend void fu(void);

private slots:
    void on_tableWidget_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
	
public slots:
    void slotB1Clicked();
    void openDocument();
    void slotFu();
};

#endif // MAINWINDOW_H
