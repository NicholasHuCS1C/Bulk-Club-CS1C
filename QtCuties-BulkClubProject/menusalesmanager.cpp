#include "menusalesmanager.h"
#include "ui_menusalesmanager.h"

MenuSalesManager::MenuSalesManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuSalesManager)
{
    ui->setupUi(this);


}

MenuSalesManager::~MenuSalesManager()
{
    delete ui;
}

void MenuSalesManager::on_pushButton_clicked()
{
    QMessageBox::StandardButton logout = QMessageBox::question(this, "Logout", "Are you sure you want to logout?",
                                                               QMessageBox::Yes | QMessageBox::No);
    if (logout == QMessageBox::Yes)
    {
        MainWindow * loginScreen = new MainWindow;
        loginScreen->show();
        this->close();
    }
}


