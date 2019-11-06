#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menumanager.h"
#include <QString>
#include <QMessageBox>
#include "menu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Menu * m1 = new Menu;
    menuManager * managerMenu = new menuManager;

    const QString ADMIN_USERNAME = "A";
    const QString ADMIN_PASSWORD = "A";
    const QString MANAGER_USERNAME = "M";
    const QString MANAGER_PASSWORD = "M";

    if ((ui->lineEditUsername->text() != ADMIN_USERNAME || ui->lineEditPassword->text() != ADMIN_PASSWORD)
            && (ui->lineEditUsername->text() != MANAGER_USERNAME || ui->lineEditPassword->text() != MANAGER_PASSWORD))
    {
        QMessageBox::warning(this, "Invalid", "Invalid credentials. Try again.");
        ui->lineEditUsername->setText("");
        ui->lineEditPassword->setText("");
    }
    else if (ui->lineEditUsername->text() == ADMIN_USERNAME || ui->lineEditPassword->text() == ADMIN_PASSWORD)
    {
        m1->show();
        this->close();
    }
    else if (ui->lineEditUsername->text() == MANAGER_USERNAME || ui->lineEditPassword->text() == MANAGER_PASSWORD)
    {
       managerMenu->show();
       this->close();
    }

}
