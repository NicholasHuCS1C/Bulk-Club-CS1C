#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_buttonLogout_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
