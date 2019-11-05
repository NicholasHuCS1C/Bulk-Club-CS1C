#include "menu.h"
#include "ui_menu.h"
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QFileInfo>
#include "mainwindow.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}


//Button to load the customer list
// QSqlDatabasePrivate::removeDatabase: connection 'qt_sql_default_connection'
//is still in use, all queries will cease to work.


/*void Menu::on_load_all_clicked()
{


    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    //conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from customer_list");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableViewDisplayMember->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());

}*/

