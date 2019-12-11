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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_managerMenu
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tabSalesReport;
    QComboBox *comboBoxDays;
    QLabel *labelTXTTotalRevenue;
    QLabel *labelTotalRevenue;
    QTableView *salesReportTableView;
    QPushButton *standardButton;
    QPushButton *executiveButton;
    QLabel *labelEC;
    QLabel *label_2;
    QLabel *labelExecCustomerNum;
    QLabel *labelSC;
    QLabel *labelStandardCustomerNum;
    QWidget *tabDisplayMembers;
    QLineEdit *lineEditSearchNum;
    QLabel *labelTXTSearchNum;
    QComboBox *comboBoxSearchMonth;
    QLabel *label;
    QPushButton *load_all;
    QTableView *tableViewDisplayMember;
    QPushButton *buttonSearchMemberNumber;
    QPushButton *buttonSearchMemberName;
    QLabel *labelTXTSearchNum_3;
    QLineEdit *lineEditSearchName;
    QPushButton *buttonSearchMonth;
    QWidget *tabDisplayInventory;
    QLabel *labelTXTSearchNum_2;
    QLineEdit *lineEditSearchItem;
    QTableView *tableViewInventory;
    QPushButton *pushButtonSearchInventory;
    QPushButton *pushButtonReloadInventory;
    QWidget *tabAddPurchase;
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
    QTableView *tableViewDisplayPurchases;
    QLabel *labelTotalAmountSpent;
    QLabel *labelTXTTotalPrice_2;
    QLabel *labelRebateAmountText;
    QLabel *labelRebateAmount;
    QLabel *labelExecutiveMember;
    QPushButton *buttonLogout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *managerMenu)
    {
        if (managerMenu->objectName().isEmpty())
            managerMenu->setObjectName(QString::fromUtf8("managerMenu"));
        managerMenu->resize(800, 600);
        managerMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 255, 210);"));
        centralwidget = new QWidget(managerMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 781, 531));
        tabWidget->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(225, 225, 225);"));
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
        comboBoxDays->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        labelTXTTotalRevenue = new QLabel(tabSalesReport);
        labelTXTTotalRevenue->setObjectName(QString::fromUtf8("labelTXTTotalRevenue"));
        labelTXTTotalRevenue->setGeometry(QRect(640, 260, 101, 16));
        labelTotalRevenue = new QLabel(tabSalesReport);
        labelTotalRevenue->setObjectName(QString::fromUtf8("labelTotalRevenue"));
        labelTotalRevenue->setGeometry(QRect(640, 290, 121, 31));
        QFont font;
        font.setPointSize(12);
        labelTotalRevenue->setFont(font);
        labelTotalRevenue->setAutoFillBackground(false);
        labelTotalRevenue->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelTotalRevenue->setFrameShape(QFrame::StyledPanel);
        labelTotalRevenue->setFrameShadow(QFrame::Plain);
        salesReportTableView = new QTableView(tabSalesReport);
        salesReportTableView->setObjectName(QString::fromUtf8("salesReportTableView"));
        salesReportTableView->setGeometry(QRect(10, 20, 601, 461));
        salesReportTableView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        standardButton = new QPushButton(tabSalesReport);
        standardButton->setObjectName(QString::fromUtf8("standardButton"));
        standardButton->setGeometry(QRect(640, 340, 113, 32));
        standardButton->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        executiveButton = new QPushButton(tabSalesReport);
        executiveButton->setObjectName(QString::fromUtf8("executiveButton"));
        executiveButton->setGeometry(QRect(640, 380, 113, 32));
        executiveButton->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        labelEC = new QLabel(tabSalesReport);
        labelEC->setObjectName(QString::fromUtf8("labelEC"));
        labelEC->setGeometry(QRect(640, 80, 121, 31));
        label_2 = new QLabel(tabSalesReport);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(640, 120, 111, 21));
        labelExecCustomerNum = new QLabel(tabSalesReport);
        labelExecCustomerNum->setObjectName(QString::fromUtf8("labelExecCustomerNum"));
        labelExecCustomerNum->setGeometry(QRect(640, 110, 121, 31));
        labelExecCustomerNum->setFont(font);
        labelExecCustomerNum->setAutoFillBackground(false);
        labelExecCustomerNum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        labelExecCustomerNum->setFrameShape(QFrame::StyledPanel);
        labelExecCustomerNum->setFrameShadow(QFrame::Plain);
        labelSC = new QLabel(tabSalesReport);
        labelSC->setObjectName(QString::fromUtf8("labelSC"));
        labelSC->setGeometry(QRect(640, 170, 121, 31));
        labelStandardCustomerNum = new QLabel(tabSalesReport);
        labelStandardCustomerNum->setObjectName(QString::fromUtf8("labelStandardCustomerNum"));
        labelStandardCustomerNum->setGeometry(QRect(640, 200, 121, 31));
        labelStandardCustomerNum->setFont(font);
        labelStandardCustomerNum->setAutoFillBackground(false);
        labelStandardCustomerNum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelStandardCustomerNum->setFrameShape(QFrame::StyledPanel);
        labelStandardCustomerNum->setFrameShadow(QFrame::Plain);
        tabWidget->addTab(tabSalesReport, QString());
        tabDisplayMembers = new QWidget();
        tabDisplayMembers->setObjectName(QString::fromUtf8("tabDisplayMembers"));
        lineEditSearchNum = new QLineEdit(tabDisplayMembers);
        lineEditSearchNum->setObjectName(QString::fromUtf8("lineEditSearchNum"));
        lineEditSearchNum->setGeometry(QRect(660, 30, 113, 22));
        lineEditSearchNum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelTXTSearchNum = new QLabel(tabDisplayMembers);
        labelTXTSearchNum->setObjectName(QString::fromUtf8("labelTXTSearchNum"));
        labelTXTSearchNum->setGeometry(QRect(570, 30, 55, 16));
        comboBoxSearchMonth = new QComboBox(tabDisplayMembers);
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->addItem(QString());
        comboBoxSearchMonth->setObjectName(QString::fromUtf8("comboBoxSearchMonth"));
        comboBoxSearchMonth->setGeometry(QRect(660, 220, 61, 22));
        comboBoxSearchMonth->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        label = new QLabel(tabDisplayMembers);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(560, 210, 81, 31));
        load_all = new QPushButton(tabDisplayMembers);
        load_all->setObjectName(QString::fromUtf8("load_all"));
        load_all->setGeometry(QRect(580, 360, 121, 28));
        load_all->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        tableViewDisplayMember = new QTableView(tabDisplayMembers);
        tableViewDisplayMember->setObjectName(QString::fromUtf8("tableViewDisplayMember"));
        tableViewDisplayMember->setGeometry(QRect(20, 30, 481, 441));
        tableViewDisplayMember->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        buttonSearchMemberNumber = new QPushButton(tabDisplayMembers);
        buttonSearchMemberNumber->setObjectName(QString::fromUtf8("buttonSearchMemberNumber"));
        buttonSearchMemberNumber->setGeometry(QRect(680, 70, 80, 21));
        buttonSearchMemberNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        buttonSearchMemberName = new QPushButton(tabDisplayMembers);
        buttonSearchMemberName->setObjectName(QString::fromUtf8("buttonSearchMemberName"));
        buttonSearchMemberName->setGeometry(QRect(670, 170, 80, 21));
        buttonSearchMemberName->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        labelTXTSearchNum_3 = new QLabel(tabDisplayMembers);
        labelTXTSearchNum_3->setObjectName(QString::fromUtf8("labelTXTSearchNum_3"));
        labelTXTSearchNum_3->setGeometry(QRect(534, 130, 81, 20));
        lineEditSearchName = new QLineEdit(tabDisplayMembers);
        lineEditSearchName->setObjectName(QString::fromUtf8("lineEditSearchName"));
        lineEditSearchName->setGeometry(QRect(650, 130, 113, 22));
        lineEditSearchName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        buttonSearchMonth = new QPushButton(tabDisplayMembers);
        buttonSearchMonth->setObjectName(QString::fromUtf8("buttonSearchMonth"));
        buttonSearchMonth->setGeometry(QRect(600, 290, 93, 28));
        buttonSearchMonth->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        tabWidget->addTab(tabDisplayMembers, QString());
        tabDisplayInventory = new QWidget();
        tabDisplayInventory->setObjectName(QString::fromUtf8("tabDisplayInventory"));
        labelTXTSearchNum_2 = new QLabel(tabDisplayInventory);
        labelTXTSearchNum_2->setObjectName(QString::fromUtf8("labelTXTSearchNum_2"));
        labelTXTSearchNum_2->setGeometry(QRect(560, 30, 55, 16));
        lineEditSearchItem = new QLineEdit(tabDisplayInventory);
        lineEditSearchItem->setObjectName(QString::fromUtf8("lineEditSearchItem"));
        lineEditSearchItem->setGeometry(QRect(612, 30, 151, 22));
        lineEditSearchItem->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableViewInventory = new QTableView(tabDisplayInventory);
        tableViewInventory->setObjectName(QString::fromUtf8("tableViewInventory"));
        tableViewInventory->setGeometry(QRect(10, 10, 511, 491));
        tableViewInventory->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButtonSearchInventory = new QPushButton(tabDisplayInventory);
        pushButtonSearchInventory->setObjectName(QString::fromUtf8("pushButtonSearchInventory"));
        pushButtonSearchInventory->setGeometry(QRect(640, 70, 80, 21));
        pushButtonSearchInventory->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButtonReloadInventory = new QPushButton(tabDisplayInventory);
        pushButtonReloadInventory->setObjectName(QString::fromUtf8("pushButtonReloadInventory"));
        pushButtonReloadInventory->setGeometry(QRect(590, 460, 151, 21));
        pushButtonReloadInventory->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        tabWidget->addTab(tabDisplayInventory, QString());
        tabAddPurchase = new QWidget();
        tabAddPurchase->setObjectName(QString::fromUtf8("tabAddPurchase"));
        labelTXTCustomerSearch = new QLabel(tabAddPurchase);
        labelTXTCustomerSearch->setObjectName(QString::fromUtf8("labelTXTCustomerSearch"));
        labelTXTCustomerSearch->setGeometry(QRect(30, 80, 71, 16));
        comboBoxNameSearch = new QComboBox(tabAddPurchase);
        comboBoxNameSearch->setObjectName(QString::fromUtf8("comboBoxNameSearch"));
        comboBoxNameSearch->setGeometry(QRect(110, 80, 151, 22));
        comboBoxNameSearch->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        labelTXTItemSearch = new QLabel(tabAddPurchase);
        labelTXTItemSearch->setObjectName(QString::fromUtf8("labelTXTItemSearch"));
        labelTXTItemSearch->setGeometry(QRect(500, 80, 51, 16));
        labelTXTMemberNumInput = new QLabel(tabAddPurchase);
        labelTXTMemberNumInput->setObjectName(QString::fromUtf8("labelTXTMemberNumInput"));
        labelTXTMemberNumInput->setGeometry(QRect(30, 130, 71, 16));
        labelMemberNum = new QLabel(tabAddPurchase);
        labelMemberNum->setObjectName(QString::fromUtf8("labelMemberNum"));
        labelMemberNum->setGeometry(QRect(130, 130, 131, 21));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(225, 225, 225, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        labelMemberNum->setPalette(palette);
        labelMemberNum->setFont(font);
        labelMemberNum->setAutoFillBackground(false);
        labelMemberNum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelMemberNum->setFrameShape(QFrame::StyledPanel);
        comboBoxItemSearch = new QComboBox(tabAddPurchase);
        comboBoxItemSearch->setObjectName(QString::fromUtf8("comboBoxItemSearch"));
        comboBoxItemSearch->setGeometry(QRect(550, 80, 191, 22));
        comboBoxItemSearch->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        lineEditQuantityInput = new QLineEdit(tabAddPurchase);
        lineEditQuantityInput->setObjectName(QString::fromUtf8("lineEditQuantityInput"));
        lineEditQuantityInput->setGeometry(QRect(550, 130, 61, 22));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        lineEditQuantityInput->setPalette(palette1);
        lineEditQuantityInput->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelQuantityInput = new QLabel(tabAddPurchase);
        labelQuantityInput->setObjectName(QString::fromUtf8("labelQuantityInput"));
        labelQuantityInput->setGeometry(QRect(480, 130, 51, 16));
        labelTXTPricePerItem = new QLabel(tabAddPurchase);
        labelTXTPricePerItem->setObjectName(QString::fromUtf8("labelTXTPricePerItem"));
        labelTXTPricePerItem->setGeometry(QRect(470, 180, 91, 16));
        labelTXTTotalPrice = new QLabel(tabAddPurchase);
        labelTXTTotalPrice->setObjectName(QString::fromUtf8("labelTXTTotalPrice"));
        labelTXTTotalPrice->setGeometry(QRect(470, 220, 71, 16));
        labelPricePerItem = new QLabel(tabAddPurchase);
        labelPricePerItem->setObjectName(QString::fromUtf8("labelPricePerItem"));
        labelPricePerItem->setGeometry(QRect(550, 180, 131, 21));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        labelPricePerItem->setPalette(palette2);
        labelPricePerItem->setFont(font);
        labelPricePerItem->setAutoFillBackground(false);
        labelPricePerItem->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelPricePerItem->setFrameShape(QFrame::StyledPanel);
        labelTotalPrice = new QLabel(tabAddPurchase);
        labelTotalPrice->setObjectName(QString::fromUtf8("labelTotalPrice"));
        labelTotalPrice->setGeometry(QRect(550, 220, 131, 21));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        labelTotalPrice->setPalette(palette3);
        labelTotalPrice->setFont(font);
        labelTotalPrice->setAutoFillBackground(false);
        labelTotalPrice->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelTotalPrice->setFrameShape(QFrame::StyledPanel);
        tableViewDisplayPurchases = new QTableView(tabAddPurchase);
        tableViewDisplayPurchases->setObjectName(QString::fromUtf8("tableViewDisplayPurchases"));
        tableViewDisplayPurchases->setGeometry(QRect(20, 190, 421, 301));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        tableViewDisplayPurchases->setPalette(palette4);
        tableViewDisplayPurchases->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelTotalAmountSpent = new QLabel(tabAddPurchase);
        labelTotalAmountSpent->setObjectName(QString::fromUtf8("labelTotalAmountSpent"));
        labelTotalAmountSpent->setGeometry(QRect(540, 350, 141, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        labelTotalAmountSpent->setPalette(palette5);
        labelTotalAmountSpent->setFont(font);
        labelTotalAmountSpent->setAutoFillBackground(false);
        labelTotalAmountSpent->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelTotalAmountSpent->setFrameShape(QFrame::StyledPanel);
        labelTXTTotalPrice_2 = new QLabel(tabAddPurchase);
        labelTXTTotalPrice_2->setObjectName(QString::fromUtf8("labelTXTTotalPrice_2"));
        labelTXTTotalPrice_2->setGeometry(QRect(550, 330, 111, 16));
        labelRebateAmountText = new QLabel(tabAddPurchase);
        labelRebateAmountText->setObjectName(QString::fromUtf8("labelRebateAmountText"));
        labelRebateAmountText->setGeometry(QRect(550, 400, 111, 16));
        labelRebateAmount = new QLabel(tabAddPurchase);
        labelRebateAmount->setObjectName(QString::fromUtf8("labelRebateAmount"));
        labelRebateAmount->setGeometry(QRect(540, 420, 141, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        labelRebateAmount->setPalette(palette6);
        labelRebateAmount->setFont(font);
        labelRebateAmount->setAutoFillBackground(false);
        labelRebateAmount->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelRebateAmount->setFrameShape(QFrame::StyledPanel);
        labelExecutiveMember = new QLabel(tabAddPurchase);
        labelExecutiveMember->setObjectName(QString::fromUtf8("labelExecutiveMember"));
        labelExecutiveMember->setGeometry(QRect(540, 460, 181, 21));
        labelExecutiveMember->setFont(font);
        tabWidget->addTab(tabAddPurchase, QString());
        buttonLogout = new QPushButton(centralwidget);
        buttonLogout->setObjectName(QString::fromUtf8("buttonLogout"));
        buttonLogout->setGeometry(QRect(670, 0, 93, 28));
        buttonLogout->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        managerMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(managerMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        managerMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(managerMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        managerMenu->setStatusBar(statusbar);

        retranslateUi(managerMenu);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(managerMenu);
    } // setupUi

    void retranslateUi(QMainWindow *managerMenu)
    {
        managerMenu->setWindowTitle(QCoreApplication::translate("managerMenu", "MainWindow", nullptr));
        comboBoxDays->setItemText(0, QCoreApplication::translate("managerMenu", "Sunday", nullptr));
        comboBoxDays->setItemText(1, QCoreApplication::translate("managerMenu", "Monday", nullptr));
        comboBoxDays->setItemText(2, QCoreApplication::translate("managerMenu", "Tuesday", nullptr));
        comboBoxDays->setItemText(3, QCoreApplication::translate("managerMenu", "Wednesday", nullptr));
        comboBoxDays->setItemText(4, QCoreApplication::translate("managerMenu", "Thursday", nullptr));
        comboBoxDays->setItemText(5, QCoreApplication::translate("managerMenu", "Friday", nullptr));
        comboBoxDays->setItemText(6, QCoreApplication::translate("managerMenu", "Saturday", nullptr));

        labelTXTTotalRevenue->setText(QCoreApplication::translate("managerMenu", "Total Revenue:", nullptr));
        labelTotalRevenue->setText(QString());
        standardButton->setText(QCoreApplication::translate("managerMenu", "Standard Only", nullptr));
        executiveButton->setText(QCoreApplication::translate("managerMenu", "Executive Only", nullptr));
        labelEC->setText(QCoreApplication::translate("managerMenu", "Executive Customers: ", nullptr));
        label_2->setText(QString());
        labelExecCustomerNum->setText(QString());
        labelSC->setText(QCoreApplication::translate("managerMenu", "Standard Customers: ", nullptr));
        labelStandardCustomerNum->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabSalesReport), QCoreApplication::translate("managerMenu", "Sales Report", nullptr));
        labelTXTSearchNum->setText(QCoreApplication::translate("managerMenu", "Search #:", nullptr));
        comboBoxSearchMonth->setItemText(0, QCoreApplication::translate("managerMenu", "01", nullptr));
        comboBoxSearchMonth->setItemText(1, QCoreApplication::translate("managerMenu", "02", nullptr));
        comboBoxSearchMonth->setItemText(2, QCoreApplication::translate("managerMenu", "03", nullptr));
        comboBoxSearchMonth->setItemText(3, QCoreApplication::translate("managerMenu", "04", nullptr));
        comboBoxSearchMonth->setItemText(4, QCoreApplication::translate("managerMenu", "05", nullptr));
        comboBoxSearchMonth->setItemText(5, QCoreApplication::translate("managerMenu", "06", nullptr));
        comboBoxSearchMonth->setItemText(6, QCoreApplication::translate("managerMenu", "07", nullptr));
        comboBoxSearchMonth->setItemText(7, QCoreApplication::translate("managerMenu", "08", nullptr));
        comboBoxSearchMonth->setItemText(8, QCoreApplication::translate("managerMenu", "09", nullptr));
        comboBoxSearchMonth->setItemText(9, QCoreApplication::translate("managerMenu", "10", nullptr));
        comboBoxSearchMonth->setItemText(10, QCoreApplication::translate("managerMenu", "11", nullptr));
        comboBoxSearchMonth->setItemText(11, QCoreApplication::translate("managerMenu", "12", nullptr));
        comboBoxSearchMonth->setItemText(12, QString());

        label->setText(QCoreApplication::translate("managerMenu", "Search month:", nullptr));
        load_all->setText(QCoreApplication::translate("managerMenu", "Load All", nullptr));
        buttonSearchMemberNumber->setText(QCoreApplication::translate("managerMenu", "Search", nullptr));
        buttonSearchMemberName->setText(QCoreApplication::translate("managerMenu", "Search", nullptr));
        labelTXTSearchNum_3->setText(QCoreApplication::translate("managerMenu", "Search Name:", nullptr));
        buttonSearchMonth->setText(QCoreApplication::translate("managerMenu", "Load month", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDisplayMembers), QCoreApplication::translate("managerMenu", "Member Search", nullptr));
        labelTXTSearchNum_2->setText(QCoreApplication::translate("managerMenu", "Search:", nullptr));
        pushButtonSearchInventory->setText(QCoreApplication::translate("managerMenu", "Search", nullptr));
        pushButtonReloadInventory->setText(QCoreApplication::translate("managerMenu", "Reload Inventory", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDisplayInventory), QCoreApplication::translate("managerMenu", "Inventory", nullptr));
        labelTXTCustomerSearch->setText(QCoreApplication::translate("managerMenu", "Customer:", nullptr));
        labelTXTItemSearch->setText(QCoreApplication::translate("managerMenu", "Item:", nullptr));
        labelTXTMemberNumInput->setText(QCoreApplication::translate("managerMenu", "Member #:", nullptr));
        labelMemberNum->setText(QString());
        labelQuantityInput->setText(QCoreApplication::translate("managerMenu", "Quantity:", nullptr));
        labelTXTPricePerItem->setText(QCoreApplication::translate("managerMenu", "Price per item:", nullptr));
        labelTXTTotalPrice->setText(QCoreApplication::translate("managerMenu", "Total Price:", nullptr));
        labelPricePerItem->setText(QString());
        labelTotalPrice->setText(QString());
        labelTotalAmountSpent->setText(QString());
        labelTXTTotalPrice_2->setText(QCoreApplication::translate("managerMenu", "Total Amount Spent: ", nullptr));
        labelRebateAmountText->setText(QCoreApplication::translate("managerMenu", "Rebate Amount:", nullptr));
        labelRebateAmount->setText(QString());
        labelExecutiveMember->setText(QCoreApplication::translate("managerMenu", "Executive Member!", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAddPurchase), QCoreApplication::translate("managerMenu", "Purchases", nullptr));
        buttonLogout->setText(QCoreApplication::translate("managerMenu", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class managerMenu: public Ui_managerMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERMENU_H
