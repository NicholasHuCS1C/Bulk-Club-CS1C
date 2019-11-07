#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "mainwindow.h"
#include "menusalesmanager.h"
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QFileInfo>
#include <QString>
#include <QFileDialog>
#include <QFile>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

friend class MenuSalesManager;

private:
    Ui::Menu *ui;

    //QSqlDatabase mydb;

public:
    explicit Menu(QWidget *parent = nullptr);
    QSqlDatabase mydb;
    QString dataPath;
    void loadFirstSalesReport();
    //QSqlDatabase getDB();
    ~Menu();

private slots:
    void on_load_all_clicked();


    void on_comboBoxDays_activated(const QString &arg1);
    void on_pushButton_clicked();
};

//QSqlDatabase Menu::getDB()
//{
//    return mydb;
//}

#endif // MENU_H
