#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    if(mydb.open())
//    {
//        mydb.close();
//        mydb.removeDatabase(QSqlDatabase::defaultConnection);
//    }


//    mydb=QSqlDatabase::addDatabase("QSQLITE");
//    mydb.setDatabaseName("/Users/SeanVHatfield/SeanHatfield/Documents/CS 1C Projects/databases/test.db");

//        if (!mydb.open())
//        {
//            qDebug() << ("Failed to open the database");

//        }
//        else
//        {
//            qDebug() << ("Database Connected");

//        }

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    const QString ADMIN_USERNAME = "A";
    const QString ADMIN_PASSWORD = "A";
    const QString MANAGER_USERNAME = "S";
    const QString MANAGER_PASSWORD = "S";

    if ((ui->lineEditUsername->text() != ADMIN_USERNAME || ui->lineEditPassword->text() != ADMIN_PASSWORD) &&
            (ui->lineEditUsername->text() != MANAGER_USERNAME || ui->lineEditPassword->text() != MANAGER_PASSWORD))
    {
        QMessageBox::warning(this, "Invalid", "Invalid credentials. Try again bitch.");
    }
    else if (ui->lineEditUsername->text() == ADMIN_USERNAME && ui->lineEditPassword->text() == ADMIN_PASSWORD)
    {
        Menu * adminMenu = new Menu;
        adminMenu->show();
        this->close();
    }
    else if (ui->lineEditUsername->text() == MANAGER_USERNAME && ui->lineEditPassword->text() == MANAGER_PASSWORD)
    {
        MenuSalesManager * managerMenu = new MenuSalesManager;
        managerMenu->show();
        this->close();
    }
}
