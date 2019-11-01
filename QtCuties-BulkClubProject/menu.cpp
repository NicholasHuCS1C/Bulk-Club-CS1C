#include "menu.h"
#include "ui_menu.h"

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
