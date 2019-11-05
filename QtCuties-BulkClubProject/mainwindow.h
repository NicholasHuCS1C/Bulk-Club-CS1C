#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QFileInfo>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    //QSqlDatabase mydb;

public:


//    void connClose()
//    {
//        mydb.close();
//        mydb.removeDatabase(QSqlDatabase::defaultConnection);
//    }


    //QSqlDatabase getDB();


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


};

//QSqlDatabase MainWindow::getDB()
//{
//    return mydb;
//}




#endif // MAINWINDOW_H
