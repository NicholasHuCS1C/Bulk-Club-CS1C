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
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    if(mydb.open())
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }



    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/Users/SeanVHatfield/SeanHatfield/Documents/CS 1C Projects/databases/test.db");

    //    QString fileName = QFileDialog::getOpenFileName(this,
    //     tr("Open Database"), "", tr("Database Files (*.db)"));
    //    mydb.setDatabaseName(fileName);


        if (!mydb.open())
        {
            qDebug() << ("Failed to open the database");

        }
        else
        {
            qDebug() << ("Database Connected");

        }


}

Menu::~Menu()
{
    delete ui;
}


//Button to load the customer list
// QSqlDatabasePrivate::removeDatabase: connection 'qt_sql_default_connection'
//is still in use, all queries will cease to work.


void Menu::on_load_all_clicked()
{


//    Format of the data
//    Date of purchase
//    Customer number who bought the product
//    Product description
//    Price of product
//    Quantity
//    ******************************

    //Customer Name
    //Member #
    //Customer Type
    //Membership Expiration Date

    QString tempName;
    QString tempMemberNumber;
    QString tempCustomerType;
    QString tempMembershipExp;

    QFile file("/Users/SeanVHatfield/SeanHatfield/Downloads/Bulk Club Project-1/warehouse shoppers.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "title", "file not open");
    }
    QTextStream in(&file);




    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery(this->mydb);

    qry->prepare("delete from customerTable");
    qry->exec();

    for (int i = 0; !in.atEnd(); i++)
    {
        tempName = in.readLine();
        tempMemberNumber = in.readLine();
        tempCustomerType = in.readLine();
        tempMembershipExp = in.readLine();

        qDebug() << "Name: " << tempName;
        qDebug() << "Membership Number: " << tempMemberNumber;
        qDebug() << "Customer Type: " << tempCustomerType;
        qDebug() << "Membership Expiration Date: " << tempMembershipExp;

        qry->prepare("insert into customerTable (Name,Number,Type,Expiration)" "VALUES ('"+tempName+"', '"+tempMemberNumber+"', '"+tempCustomerType+"', '"+tempMembershipExp+"')");
        qry->exec();

    }

    qry->prepare("select * from customerTable");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableViewDisplayMember->setModel(modal);
    ui->tableViewDisplayMember->resizeColumnsToContents();

    qDebug() << (modal->rowCount());

}


void Menu::on_comboBoxDays_activated(const QString &arg1)
{
    QString argVar;
    argVar = arg1;

    qDebug() << "ArgVar: " << argVar;

    QString textName;

    int tempIndex = 0;
    tempIndex = ui->comboBoxDays->currentIndex() + 1;
    textName = "day" + textName + QString::number(tempIndex) + ".txt";

    qDebug() << "Text name: " << textName;



    //    Date of purchase
    //    Customer number who bought the product
    //    Product description
    //    Price of product
    //    Quantity

        QString tempDate;
        QString tempCustomerNum;
        QString tempDescription;
        QString tempPrice;
        QString tempQuantity;

        QFile file("/Users/SeanVHatfield/SeanHatfield/Downloads/Bulk Club Project-1/" + textName);

        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this, "title", "file not open");
        }
        QTextStream in(&file);




        QSqlQueryModel * modal = new QSqlQueryModel();

        QSqlQuery* qry = new QSqlQuery(this->mydb);

        qry->prepare("delete from '"+argVar+"'");
        qry->exec();

        for (int i = 0; !in.atEnd(); i++)
        {
            tempDate = in.readLine();
            tempCustomerNum = in.readLine();
            tempDescription = in.readLine();
            tempPrice = in.readLine();
            tempQuantity = in.readLine();

            qDebug() << "Date: " << tempDate;
            qDebug() << "Customer Number: " << tempCustomerNum;
            qDebug() << "Description: " << tempDescription;
            qDebug() << "Price: " << tempPrice;
            qDebug() << "Quantity: " << tempQuantity;

            qry->prepare("insert into '"+argVar+"' (Date,Number,Description,Price,Quantity)" "VALUES ('"+tempDate+"', '"+tempCustomerNum+"', '"+tempDescription+"', '"+tempPrice+"', '"+tempQuantity+"')");
            if(qry->exec())
            {
                qDebug() << "Success!";

            }
            else {
                qDebug() << qry->lastError().text();
            }

        }

        qry->prepare("select * from '"+argVar+"'");

        qry->exec();
        modal->setQuery(*qry);
        ui->salesReportTableView->setModel(modal);
        ui->salesReportTableView->resizeColumnsToContents();

        qDebug() << (modal->rowCount());

}
