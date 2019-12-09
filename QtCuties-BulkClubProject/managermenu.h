#ifndef MANAGERMENU_H
#define MANAGERMENU_H

#include <QMainWindow>
#include "menu.h"

namespace Ui {
class ManagerMenu;
}

class ManagerMenu : public QMainWindow
{
    Q_OBJECT

private:
    Ui::ManagerMenu *ui;

public:
    explicit ManagerMenu(QWidget *parent = nullptr);
    QSqlDatabase mydb;
    QString dataPath;
    QString daySelected;
    void loadFirstSalesReport();
    //void loadDeleteComboBox();
    //void loadDeleteNumberComboBox();
    void saveDatabaseTxt();
    void loadDatabaseFromFile();
    void loadMembersTable();
    void displayRevenue(QString day);
    ~ManagerMenu();

private slots:
    void on_load_all_clicked();
    void on_comboBoxDays_activated(const QString &arg1);
    //void on_checkBoxStandard_toggled(bool checked);
    void on_standardButton_clicked();
    //void on_buttonAddCustomer_clicked();
    //void on_buttonDeleteCustomer_clicked();
    //void on_buttonDeleteCustomerNum_clicked();
    void on_buttonLogout_clicked();
};

#endif // MANAGERMENU_H
