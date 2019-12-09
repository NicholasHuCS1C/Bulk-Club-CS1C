/********************************************************************************
** Form generated from reading UI file 'managermenu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERMENU_H
#define UI_MANAGERMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerMenu
{
public:
    QWidget *centralwidget;
    QPushButton *buttonLogout;
    QTabWidget *tabWidget;
    QWidget *tabSalesReport;
    QComboBox *comboBoxDays;
    QCheckBox *checkBoxStandard;
    QCheckBox *checkBoxExecutive;
    QLabel *labelTXTTotalRevenue;
    QLabel *labelTotalRevenue;
    QTableView *salesReportTableView;
    QPushButton *standardButton;
    QPushButton *executiveButton;
    QWidget *tabDisplayMembers;
    QLineEdit *lineEditSearchNum;
    QLabel *labelTXTSearchNum;
    QPushButton *buttonSortRebates;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *load_all;
    QTableView *tableViewDisplayMember;
    QWidget *tabEditMembers;
    QLineEdit *lineEditAddName;
    QLabel *labelTXTName;
    QLabel *labelTXTAddCustomer;
    QLineEdit *lineEditAddMemberNum;
    QLabel *labelTXTMemberNum;
    QLabel *labelTXTStatus;
    QLabel *labelTXTDeleteCustomer;
    QPushButton *buttonAddCustomer;
    QComboBox *comboBoxDeleteName;
    QLabel *labelTXTName_2;
    QLabel *labelTXTMemberNum_2;
    QComboBox *comboBoxDeleteMemberNum;
    QPushButton *buttonDeleteCustomer;
    QComboBox *addCustomerStatus;
    QPushButton *buttonDeleteCustomerNum;
    QWidget *tabDisplayInventory;
    QTableWidget *tableWidgetInventory;
    QLabel *labelTXTSearchNum_2;
    QLineEdit *lineEditSearchItem;
    QLabel *labelTXTAddItem_2;
    QLineEdit *lineEditAddItem;
    QLineEdit *lineEditAddPrice;
    QLabel *labelTXTAddItem;
    QLabel *labelTXTAddPrice;
    QPushButton *buttonAddItem;
    QLabel *labelTXTDeleteItem;
    QComboBox *comboBoxDeleteItem;
    QLabel *labelTXTSearchName;
    QPushButton *buttonDeleteItem;
    QWidget *tabAddPurchase;
    QLabel *labelTXTAddPurchase;
    QLabel *labelTXTCustomerSearch;
    QComboBox *comboBoxNameSearch;
    QLabel *labelTXTItemSearch;
    QLabel *labelTXTMemberNumInput;
    QLabel *labelMemberNum;
    QComboBox *comboBoxItemSearch;
    QLineEdit *lineEditQuantityInput;
    QLabel *labelQuantityInput;
    QLabel *labelTXTPricePerItem;
    QLabel *labelTXTTotalPrice;
    QLabel *labelPricePerItem;
    QLabel *labelTotalPrice;
    QPushButton *buttonAddPurchase;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManagerMenu)
    {
        if (ManagerMenu->objectName().isEmpty())
            ManagerMenu->setObjectName(QString::fromUtf8("ManagerMenu"));
        ManagerMenu->resize(800, 600);
        centralwidget = new QWidget(ManagerMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        buttonLogout = new QPushButton(centralwidget);
        buttonLogout->setObjectName(QString::fromUtf8("buttonLogout"));
        buttonLogout->setGeometry(QRect(680, 10, 111, 21));
        QFont font;
        font.setPointSize(6);
        buttonLogout->setFont(font);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 781, 541));
        tabSalesReport = new QWidget();
        tabSalesReport->setObjectName(QString::fromUtf8("tabSalesReport"));
        comboBoxDays = new QComboBox(tabSalesReport);
        comboBoxDays->addItem(QString());
        comboBoxDays->addItem(QString());
        comboBoxDays->addItem(QString());
        comboBoxDays->addItem(QString());
        comboBoxDays->addItem(QString());
        comboBoxDays->addItem(QString());
        comboBoxDays->addItem(QString());
        comboBoxDays->setObjectName(QString::fromUtf8("comboBoxDays"));
        comboBoxDays->setGeometry(QRect(640, 20, 111, 31));
        checkBoxStandard = new QCheckBox(tabSalesReport);
        checkBoxStandard->setObjectName(QString::fromUtf8("checkBoxStandard"));
        checkBoxStandard->setGeometry(QRect(640, 90, 121, 20));
        checkBoxExecutive = new QCheckBox(tabSalesReport);
        checkBoxExecutive->setObjectName(QString::fromUtf8("checkBoxExecutive"));
        checkBoxExecutive->setGeometry(QRect(640, 130, 111, 20));
        labelTXTTotalRevenue = new QLabel(tabSalesReport);
        labelTXTTotalRevenue->setObjectName(QString::fromUtf8("labelTXTTotalRevenue"));
        labelTXTTotalRevenue->setGeometry(QRect(640, 200, 101, 16));
        labelTotalRevenue = new QLabel(tabSalesReport);
        labelTotalRevenue->setObjectName(QString::fromUtf8("labelTotalRevenue"));
        labelTotalRevenue->setGeometry(QRect(640, 230, 121, 31));
        QFont font1;
        font1.setPointSize(12);
        labelTotalRevenue->setFont(font1);
        labelTotalRevenue->setAutoFillBackground(false);
        labelTotalRevenue->setFrameShape(QFrame::StyledPanel);
        labelTotalRevenue->setFrameShadow(QFrame::Plain);
        salesReportTableView = new QTableView(tabSalesReport);
        salesReportTableView->setObjectName(QString::fromUtf8("salesReportTableView"));
        salesReportTableView->setGeometry(QRect(10, 20, 601, 461));
        standardButton = new QPushButton(tabSalesReport);
        standardButton->setObjectName(QString::fromUtf8("standardButton"));
        standardButton->setGeometry(QRect(640, 340, 113, 32));
        executiveButton = new QPushButton(tabSalesReport);
        executiveButton->setObjectName(QString::fromUtf8("executiveButton"));
        executiveButton->setGeometry(QRect(640, 380, 113, 32));
        tabWidget->addTab(tabSalesReport, QString());
        tabDisplayMembers = new QWidget();
        tabDisplayMembers->setObjectName(QString::fromUtf8("tabDisplayMembers"));
        lineEditSearchNum = new QLineEdit(tabDisplayMembers);
        lineEditSearchNum->setObjectName(QString::fromUtf8("lineEditSearchNum"));
        lineEditSearchNum->setGeometry(QRect(660, 30, 113, 22));
        labelTXTSearchNum = new QLabel(tabDisplayMembers);
        labelTXTSearchNum->setObjectName(QString::fromUtf8("labelTXTSearchNum"));
        labelTXTSearchNum->setGeometry(QRect(570, 30, 55, 16));
        buttonSortRebates = new QPushButton(tabDisplayMembers);
        buttonSortRebates->setObjectName(QString::fromUtf8("buttonSortRebates"));
        buttonSortRebates->setGeometry(QRect(580, 270, 121, 28));
        comboBox = new QComboBox(tabDisplayMembers);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(680, 90, 61, 22));
        label = new QLabel(tabDisplayMembers);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(570, 80, 81, 31));
        load_all = new QPushButton(tabDisplayMembers);
        load_all->setObjectName(QString::fromUtf8("load_all"));
        load_all->setGeometry(QRect(580, 310, 121, 28));
        tableViewDisplayMember = new QTableView(tabDisplayMembers);
        tableViewDisplayMember->setObjectName(QString::fromUtf8("tableViewDisplayMember"));
        tableViewDisplayMember->setGeometry(QRect(20, 30, 481, 441));
        tabWidget->addTab(tabDisplayMembers, QString());
        tabEditMembers = new QWidget();
        tabEditMembers->setObjectName(QString::fromUtf8("tabEditMembers"));
        lineEditAddName = new QLineEdit(tabEditMembers);
        lineEditAddName->setObjectName(QString::fromUtf8("lineEditAddName"));
        lineEditAddName->setGeometry(QRect(90, 80, 161, 22));
        labelTXTName = new QLabel(tabEditMembers);
        labelTXTName->setObjectName(QString::fromUtf8("labelTXTName"));
        labelTXTName->setGeometry(QRect(30, 80, 55, 16));
        labelTXTAddCustomer = new QLabel(tabEditMembers);
        labelTXTAddCustomer->setObjectName(QString::fromUtf8("labelTXTAddCustomer"));
        labelTXTAddCustomer->setGeometry(QRect(30, 30, 91, 16));
        lineEditAddMemberNum = new QLineEdit(tabEditMembers);
        lineEditAddMemberNum->setObjectName(QString::fromUtf8("lineEditAddMemberNum"));
        lineEditAddMemberNum->setGeometry(QRect(90, 130, 161, 22));
        labelTXTMemberNum = new QLabel(tabEditMembers);
        labelTXTMemberNum->setObjectName(QString::fromUtf8("labelTXTMemberNum"));
        labelTXTMemberNum->setGeometry(QRect(20, 130, 55, 16));
        labelTXTStatus = new QLabel(tabEditMembers);
        labelTXTStatus->setObjectName(QString::fromUtf8("labelTXTStatus"));
        labelTXTStatus->setGeometry(QRect(30, 180, 55, 16));
        labelTXTDeleteCustomer = new QLabel(tabEditMembers);
        labelTXTDeleteCustomer->setObjectName(QString::fromUtf8("labelTXTDeleteCustomer"));
        labelTXTDeleteCustomer->setGeometry(QRect(390, 30, 111, 16));
        buttonAddCustomer = new QPushButton(tabEditMembers);
        buttonAddCustomer->setObjectName(QString::fromUtf8("buttonAddCustomer"));
        buttonAddCustomer->setGeometry(QRect(120, 240, 93, 28));
        comboBoxDeleteName = new QComboBox(tabEditMembers);
        comboBoxDeleteName->setObjectName(QString::fromUtf8("comboBoxDeleteName"));
        comboBoxDeleteName->setGeometry(QRect(450, 70, 161, 22));
        labelTXTName_2 = new QLabel(tabEditMembers);
        labelTXTName_2->setObjectName(QString::fromUtf8("labelTXTName_2"));
        labelTXTName_2->setGeometry(QRect(400, 70, 55, 16));
        labelTXTMemberNum_2 = new QLabel(tabEditMembers);
        labelTXTMemberNum_2->setObjectName(QString::fromUtf8("labelTXTMemberNum_2"));
        labelTXTMemberNum_2->setGeometry(QRect(390, 180, 55, 16));
        comboBoxDeleteMemberNum = new QComboBox(tabEditMembers);
        comboBoxDeleteMemberNum->setObjectName(QString::fromUtf8("comboBoxDeleteMemberNum"));
        comboBoxDeleteMemberNum->setGeometry(QRect(450, 180, 161, 22));
        buttonDeleteCustomer = new QPushButton(tabEditMembers);
        buttonDeleteCustomer->setObjectName(QString::fromUtf8("buttonDeleteCustomer"));
        buttonDeleteCustomer->setGeometry(QRect(450, 110, 161, 28));
        addCustomerStatus = new QComboBox(tabEditMembers);
        addCustomerStatus->addItem(QString());
        addCustomerStatus->addItem(QString());
        addCustomerStatus->setObjectName(QString::fromUtf8("addCustomerStatus"));
        addCustomerStatus->setGeometry(QRect(90, 180, 171, 32));
        buttonDeleteCustomerNum = new QPushButton(tabEditMembers);
        buttonDeleteCustomerNum->setObjectName(QString::fromUtf8("buttonDeleteCustomerNum"));
        buttonDeleteCustomerNum->setGeometry(QRect(430, 220, 201, 28));
        tabWidget->addTab(tabEditMembers, QString());
        tabDisplayInventory = new QWidget();
        tabDisplayInventory->setObjectName(QString::fromUtf8("tabDisplayInventory"));
        tableWidgetInventory = new QTableWidget(tabDisplayInventory);
        tableWidgetInventory->setObjectName(QString::fromUtf8("tableWidgetInventory"));
        tableWidgetInventory->setGeometry(QRect(10, 20, 541, 491));
        labelTXTSearchNum_2 = new QLabel(tabDisplayInventory);
        labelTXTSearchNum_2->setObjectName(QString::fromUtf8("labelTXTSearchNum_2"));
        labelTXTSearchNum_2->setGeometry(QRect(560, 30, 55, 16));
        lineEditSearchItem = new QLineEdit(tabDisplayInventory);
        lineEditSearchItem->setObjectName(QString::fromUtf8("lineEditSearchItem"));
        lineEditSearchItem->setGeometry(QRect(612, 30, 151, 22));
        labelTXTAddItem_2 = new QLabel(tabDisplayInventory);
        labelTXTAddItem_2->setObjectName(QString::fromUtf8("labelTXTAddItem_2"));
        labelTXTAddItem_2->setGeometry(QRect(560, 120, 55, 16));
        lineEditAddItem = new QLineEdit(tabDisplayInventory);
        lineEditAddItem->setObjectName(QString::fromUtf8("lineEditAddItem"));
        lineEditAddItem->setGeometry(QRect(600, 150, 161, 22));
        lineEditAddPrice = new QLineEdit(tabDisplayInventory);
        lineEditAddPrice->setObjectName(QString::fromUtf8("lineEditAddPrice"));
        lineEditAddPrice->setGeometry(QRect(670, 190, 91, 22));
        labelTXTAddItem = new QLabel(tabDisplayInventory);
        labelTXTAddItem->setObjectName(QString::fromUtf8("labelTXTAddItem"));
        labelTXTAddItem->setGeometry(QRect(560, 150, 41, 16));
        labelTXTAddPrice = new QLabel(tabDisplayInventory);
        labelTXTAddPrice->setObjectName(QString::fromUtf8("labelTXTAddPrice"));
        labelTXTAddPrice->setGeometry(QRect(560, 190, 55, 16));
        buttonAddItem = new QPushButton(tabDisplayInventory);
        buttonAddItem->setObjectName(QString::fromUtf8("buttonAddItem"));
        buttonAddItem->setGeometry(QRect(670, 230, 41, 28));
        labelTXTDeleteItem = new QLabel(tabDisplayInventory);
        labelTXTDeleteItem->setObjectName(QString::fromUtf8("labelTXTDeleteItem"));
        labelTXTDeleteItem->setGeometry(QRect(560, 290, 71, 16));
        comboBoxDeleteItem = new QComboBox(tabDisplayInventory);
        comboBoxDeleteItem->setObjectName(QString::fromUtf8("comboBoxDeleteItem"));
        comboBoxDeleteItem->setGeometry(QRect(610, 320, 151, 22));
        labelTXTSearchName = new QLabel(tabDisplayInventory);
        labelTXTSearchName->setObjectName(QString::fromUtf8("labelTXTSearchName"));
        labelTXTSearchName->setGeometry(QRect(560, 320, 41, 16));
        buttonDeleteItem = new QPushButton(tabDisplayInventory);
        buttonDeleteItem->setObjectName(QString::fromUtf8("buttonDeleteItem"));
        buttonDeleteItem->setGeometry(QRect(670, 360, 51, 28));
        tabWidget->addTab(tabDisplayInventory, QString());
        tabAddPurchase = new QWidget();
        tabAddPurchase->setObjectName(QString::fromUtf8("tabAddPurchase"));
        labelTXTAddPurchase = new QLabel(tabAddPurchase);
        labelTXTAddPurchase->setObjectName(QString::fromUtf8("labelTXTAddPurchase"));
        labelTXTAddPurchase->setGeometry(QRect(30, 30, 241, 16));
        labelTXTCustomerSearch = new QLabel(tabAddPurchase);
        labelTXTCustomerSearch->setObjectName(QString::fromUtf8("labelTXTCustomerSearch"));
        labelTXTCustomerSearch->setGeometry(QRect(30, 80, 71, 16));
        comboBoxNameSearch = new QComboBox(tabAddPurchase);
        comboBoxNameSearch->setObjectName(QString::fromUtf8("comboBoxNameSearch"));
        comboBoxNameSearch->setGeometry(QRect(110, 80, 151, 22));
        labelTXTItemSearch = new QLabel(tabAddPurchase);
        labelTXTItemSearch->setObjectName(QString::fromUtf8("labelTXTItemSearch"));
        labelTXTItemSearch->setGeometry(QRect(370, 80, 51, 16));
        labelTXTMemberNumInput = new QLabel(tabAddPurchase);
        labelTXTMemberNumInput->setObjectName(QString::fromUtf8("labelTXTMemberNumInput"));
        labelTXTMemberNumInput->setGeometry(QRect(30, 130, 71, 16));
        labelMemberNum = new QLabel(tabAddPurchase);
        labelMemberNum->setObjectName(QString::fromUtf8("labelMemberNum"));
        labelMemberNum->setGeometry(QRect(130, 130, 131, 21));
        labelMemberNum->setFont(font1);
        labelMemberNum->setAutoFillBackground(false);
        labelMemberNum->setFrameShape(QFrame::StyledPanel);
        comboBoxItemSearch = new QComboBox(tabAddPurchase);
        comboBoxItemSearch->setObjectName(QString::fromUtf8("comboBoxItemSearch"));
        comboBoxItemSearch->setGeometry(QRect(420, 80, 191, 22));
        lineEditQuantityInput = new QLineEdit(tabAddPurchase);
        lineEditQuantityInput->setObjectName(QString::fromUtf8("lineEditQuantityInput"));
        lineEditQuantityInput->setGeometry(QRect(420, 130, 61, 22));
        labelQuantityInput = new QLabel(tabAddPurchase);
        labelQuantityInput->setObjectName(QString::fromUtf8("labelQuantityInput"));
        labelQuantityInput->setGeometry(QRect(350, 130, 51, 16));
        labelTXTPricePerItem = new QLabel(tabAddPurchase);
        labelTXTPricePerItem->setObjectName(QString::fromUtf8("labelTXTPricePerItem"));
        labelTXTPricePerItem->setGeometry(QRect(320, 180, 91, 16));
        labelTXTTotalPrice = new QLabel(tabAddPurchase);
        labelTXTTotalPrice->setObjectName(QString::fromUtf8("labelTXTTotalPrice"));
        labelTXTTotalPrice->setGeometry(QRect(340, 220, 71, 16));
        labelPricePerItem = new QLabel(tabAddPurchase);
        labelPricePerItem->setObjectName(QString::fromUtf8("labelPricePerItem"));
        labelPricePerItem->setGeometry(QRect(420, 180, 131, 21));
        labelPricePerItem->setFont(font1);
        labelPricePerItem->setAutoFillBackground(false);
        labelPricePerItem->setFrameShape(QFrame::StyledPanel);
        labelTotalPrice = new QLabel(tabAddPurchase);
        labelTotalPrice->setObjectName(QString::fromUtf8("labelTotalPrice"));
        labelTotalPrice->setGeometry(QRect(420, 220, 131, 21));
        labelTotalPrice->setFont(font1);
        labelTotalPrice->setAutoFillBackground(false);
        labelTotalPrice->setFrameShape(QFrame::StyledPanel);
        buttonAddPurchase = new QPushButton(tabAddPurchase);
        buttonAddPurchase->setObjectName(QString::fromUtf8("buttonAddPurchase"));
        buttonAddPurchase->setGeometry(QRect(420, 290, 93, 28));
        tabWidget->addTab(tabAddPurchase, QString());
        ManagerMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ManagerMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ManagerMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(ManagerMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ManagerMenu->setStatusBar(statusbar);

        retranslateUi(ManagerMenu);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ManagerMenu);
    } // setupUi

    void retranslateUi(QMainWindow *ManagerMenu)
    {
        ManagerMenu->setWindowTitle(QCoreApplication::translate("ManagerMenu", "MainWindow", nullptr));
        buttonLogout->setText(QCoreApplication::translate("ManagerMenu", "LOGOUT", nullptr));
        comboBoxDays->setItemText(0, QCoreApplication::translate("ManagerMenu", "Sunday", nullptr));
        comboBoxDays->setItemText(1, QCoreApplication::translate("ManagerMenu", "Monday", nullptr));
        comboBoxDays->setItemText(2, QCoreApplication::translate("ManagerMenu", "Tuesday", nullptr));
        comboBoxDays->setItemText(3, QCoreApplication::translate("ManagerMenu", "Wednesday", nullptr));
        comboBoxDays->setItemText(4, QCoreApplication::translate("ManagerMenu", "Thursday", nullptr));
        comboBoxDays->setItemText(5, QCoreApplication::translate("ManagerMenu", "Friday", nullptr));
        comboBoxDays->setItemText(6, QCoreApplication::translate("ManagerMenu", "Saturday", nullptr));

        checkBoxStandard->setText(QCoreApplication::translate("ManagerMenu", "Standard Only", nullptr));
        checkBoxExecutive->setText(QCoreApplication::translate("ManagerMenu", "Executive Only", nullptr));
        labelTXTTotalRevenue->setText(QCoreApplication::translate("ManagerMenu", "Total Revenue:", nullptr));
        labelTotalRevenue->setText(QString());
        standardButton->setText(QCoreApplication::translate("ManagerMenu", "Standard Only", nullptr));
        executiveButton->setText(QCoreApplication::translate("ManagerMenu", "Executive Only", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSalesReport), QCoreApplication::translate("ManagerMenu", "Sales Report", nullptr));
        labelTXTSearchNum->setText(QCoreApplication::translate("ManagerMenu", "Search #:", nullptr));
        buttonSortRebates->setText(QCoreApplication::translate("ManagerMenu", "Check Rebates", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ManagerMenu", "01", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ManagerMenu", "02", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("ManagerMenu", "03", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("ManagerMenu", "04", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("ManagerMenu", "05", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("ManagerMenu", "06", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("ManagerMenu", "07", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("ManagerMenu", "08", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("ManagerMenu", "09", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("ManagerMenu", "10", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("ManagerMenu", "11", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("ManagerMenu", "12", nullptr));
        comboBox->setItemText(12, QString());

        label->setText(QCoreApplication::translate("ManagerMenu", "Search month:", nullptr));
        load_all->setText(QCoreApplication::translate("ManagerMenu", "Load All", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDisplayMembers), QCoreApplication::translate("ManagerMenu", "Members", nullptr));
        labelTXTName->setText(QCoreApplication::translate("ManagerMenu", "Name:", nullptr));
        labelTXTAddCustomer->setText(QCoreApplication::translate("ManagerMenu", "Add Customer", nullptr));
        labelTXTMemberNum->setText(QCoreApplication::translate("ManagerMenu", "Mem #:", nullptr));
        labelTXTStatus->setText(QCoreApplication::translate("ManagerMenu", "Status:", nullptr));
        labelTXTDeleteCustomer->setText(QCoreApplication::translate("ManagerMenu", "Delete Customer", nullptr));
        buttonAddCustomer->setText(QCoreApplication::translate("ManagerMenu", "Add", nullptr));
        labelTXTName_2->setText(QCoreApplication::translate("ManagerMenu", "Name:", nullptr));
        labelTXTMemberNum_2->setText(QCoreApplication::translate("ManagerMenu", "Mem #:", nullptr));
        buttonDeleteCustomer->setText(QCoreApplication::translate("ManagerMenu", "Delete By Name", nullptr));
        addCustomerStatus->setItemText(0, QCoreApplication::translate("ManagerMenu", "Executive", nullptr));
        addCustomerStatus->setItemText(1, QCoreApplication::translate("ManagerMenu", "Standard", nullptr));

        buttonDeleteCustomerNum->setText(QCoreApplication::translate("ManagerMenu", "Delete By Member Number", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabEditMembers), QCoreApplication::translate("ManagerMenu", "Edit Members", nullptr));
        labelTXTSearchNum_2->setText(QCoreApplication::translate("ManagerMenu", "Search:", nullptr));
        labelTXTAddItem_2->setText(QCoreApplication::translate("ManagerMenu", "Add item:", nullptr));
        labelTXTAddItem->setText(QCoreApplication::translate("ManagerMenu", "Name", nullptr));
        labelTXTAddPrice->setText(QCoreApplication::translate("ManagerMenu", "Price", nullptr));
        buttonAddItem->setText(QCoreApplication::translate("ManagerMenu", "Add", nullptr));
        labelTXTDeleteItem->setText(QCoreApplication::translate("ManagerMenu", "Delete item:", nullptr));
        labelTXTSearchName->setText(QCoreApplication::translate("ManagerMenu", "Name", nullptr));
        buttonDeleteItem->setText(QCoreApplication::translate("ManagerMenu", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDisplayInventory), QCoreApplication::translate("ManagerMenu", "Inventory", nullptr));
        labelTXTAddPurchase->setText(QCoreApplication::translate("ManagerMenu", "Add a purchase to an existing customer:", nullptr));
        labelTXTCustomerSearch->setText(QCoreApplication::translate("ManagerMenu", "Customer:", nullptr));
        labelTXTItemSearch->setText(QCoreApplication::translate("ManagerMenu", "Item:", nullptr));
        labelTXTMemberNumInput->setText(QCoreApplication::translate("ManagerMenu", "Member #:", nullptr));
        labelMemberNum->setText(QString());
        labelQuantityInput->setText(QCoreApplication::translate("ManagerMenu", "Quantity:", nullptr));
        labelTXTPricePerItem->setText(QCoreApplication::translate("ManagerMenu", "Price per item:", nullptr));
        labelTXTTotalPrice->setText(QCoreApplication::translate("ManagerMenu", "Total Price:", nullptr));
        labelPricePerItem->setText(QString());
        labelTotalPrice->setText(QString());
        buttonAddPurchase->setText(QCoreApplication::translate("ManagerMenu", "Add Purchase", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAddPurchase), QCoreApplication::translate("ManagerMenu", "Purchases", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagerMenu: public Ui_ManagerMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERMENU_H
