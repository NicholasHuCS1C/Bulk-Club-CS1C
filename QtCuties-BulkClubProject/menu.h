#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT


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
};

//QSqlDatabase Menu::getDB()
//{
//    return mydb;
//}

#endif // MENU_H
