#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);


    // Initializing day1.txt onto sales report on startup.
    QFile file(":/resources/days/day1.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Error", "Unable to open on startup.");
    }
    else
    {
        QTextStream read(&file);
    }

}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_buttonLogout_clicked()
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
