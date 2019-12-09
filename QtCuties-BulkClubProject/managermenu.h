#ifndef MANAGERMENU_H
#define MANAGERMENU_H

#include "mainwindow.h"
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QFileInfo>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class managerMenu;
}

class managerMenu : public QMainWindow
{
    Q_OBJECT

private:
    Ui::managerMenu *ui;

public:
    explicit managerMenu(QWidget *parent = nullptr);
    QSqlDatabase mydb;
    QString dataPath;
    QString daySelected;
    void loadFirstSalesReport();
    void loadDeleteComboBox();
    void loadDeleteNumberComboBox();
    void saveDatabaseTxt();
    void loadDatabaseFromFile();
    void loadMembersTable();
    void displayRevenue(QString day);
    void loadAddPurchaseCustomerCombo();
    void loadItemsPurchaseCombo();
    void loadAllComboBoxes();
    void createCustomerPurchasesDB();
    void createPurchasesTables();
    void clearAllPurchasesTables();
    void loadNumberAddCustomer();
    void createInventoryTable();
    void loadCustomerPurchasesTable();
    void loadInventoryTable();
    void addItemToInventory();
    void loadDeleteItemComboBox();
    void deleteItemFromInventory();
    void loadCustomerAmountLabels();
    void displayTotalCustomerPurchases();
    ~managerMenu();

private slots:
    void on_load_all_clicked();


    void on_comboBoxDays_activated(const QString &arg1);
    void on_checkBoxStandard_toggled(bool checked);
    void on_standardButton_clicked();
    //void on_buttonAddCustomer_clicked();
    //void on_buttonDeleteCustomer_clicked();
    //void on_buttonDeleteCustomerNum_clicked();
    void on_buttonClearPurchases_clicked();
    void on_comboBoxNameSearch_activated(const QString &arg1);
    void on_comboBoxItemSearch_currentIndexChanged(const QString &arg1);
    void on_buttonCalcTotalPrice_clicked();
    void on_buttonAddPurchase_clicked();
    void on_pushButtonReloadInventory_clicked();
    void on_pushButtonSearchInventory_clicked();
    //void on_buttonAddItem_clicked();
    //void on_buttonDeleteItem_clicked();
    void on_lineEditQuantityInput_textChanged(const QString &arg1);
    //void on_pushButton_clicked();
    void on_buttonSearchMemberNumber_clicked();
    void on_executiveButton_clicked();
    void on_buttonSearchMemberName_clicked();

    void on_buttonLogout_clicked();
};

#endif // MANAGERMENU_H
