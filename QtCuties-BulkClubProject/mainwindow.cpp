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
    Menu * m1 = new Menu;
    managerMenu * m2 = new managerMenu;

    const QString ADMIN_USERNAME = "A";
    const QString ADMIN_PASSWORD = "A";
    const QString MANAGER_USERNAME = "M";
    const QString MANAGER_PASSWORD = "M";

    if (ui->lineEditUsername->text() == ADMIN_USERNAME && ui->lineEditPassword->text() == ADMIN_PASSWORD)
    {
        m1->show();
        this->close();
    }
    else if (ui->lineEditUsername->text() == MANAGER_USERNAME && ui->lineEditPassword->text() == MANAGER_PASSWORD)
    {
         m2->show();
         this->close();
    }
    else
    {
         QMessageBox::warning(this, "Invalid", "Invalid credentials. Try again bitch.");
    }


}
