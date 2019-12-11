#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap logo(":/resources/resources/logo.png");
    int w = ui->labelPic->width();
    int h= ui->labelPic->height();
    ui->labelPic->setPixmap(logo.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap arnold(":/resources/resources/arnold.jpg");
    w = ui->labelArnold->width();
    h = ui->labelArnold->height();
    ui->labelArnold->setPixmap(arnold);

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



    const QString ADMIN_USERNAME = "admin";
    const QString ADMIN_PASSWORD = "password";
    const QString MANAGER_USERNAME = "manager";
    const QString MANAGER_PASSWORD = "password";

    if (ui->lineEditUsername->text() == ADMIN_USERNAME && ui->lineEditPassword->text() == ADMIN_PASSWORD)
    {
        Menu * m1 = new Menu;
        m1->show();
        this->close();
    }
    else if (ui->lineEditUsername->text() == MANAGER_USERNAME && ui->lineEditPassword->text() == MANAGER_PASSWORD)
    {
         managerMenu * m2 = new managerMenu;
         m2->show();
         this->close();
    }
    else
    {
         QMessageBox::warning(this, "Invalid", "Invalid credentials.");
    }


}
