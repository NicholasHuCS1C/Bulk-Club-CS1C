#include "menumanager.h"
#include "ui_menumanager.h"
#include "mainwindow.h"
#include <QMessageBox>

menuManager::menuManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menuManager)
{
    ui->setupUi(this);
}

menuManager::~menuManager()
{
    delete ui;
}

void menuManager::on_buttonLogout_clicked()
{
    MainWindow * login = new MainWindow;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Logout", "You sure you wanna logout homie?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        this->close();
        login->show();
    }
}
