#include "managermenu.h"
#include "ui_managermenu.h"

ManagerMenu::ManagerMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerMenu)
{
    ui->setupUi(this);

    if(mydb.open())
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

        mydb = QSqlDatabase::addDatabase("QSQLITE");

        dataPath = QFileDialog::getExistingDirectory(this, tr("Open Data Folder"),
                                                 "/Users/Nicholas/Documents/GitHub/Bulk-Club-CS1C/QtCuties-BulkClubProject",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

        mydb.setDatabaseName(dataPath + "/database.db");

        if (!mydb.open())
        {
            qDebug() << ("Failed to open the database");

        }
        else
        {
            qDebug() << ("Database Connected");

        }

        loadFirstSalesReport();
        //loadDeleteComboBox();
        //loadDeleteNumberComboBox();
        loadMembersTable();
}

ManagerMenu::~ManagerMenu()
{
    delete ui;
}

void ManagerMenu::on_load_all_clicked()
{
    loadMembersTable();
}

void ManagerMenu::on_comboBoxDays_activated(const QString &arg1)
{
    QString argVar;
    argVar = arg1;
    daySelected = arg1;

    qDebug() << "ArgVar: " << argVar;

    QString textName;

    int tempIndex = 0;
    tempIndex = ui->comboBoxDays->currentIndex() + 1;
    textName = "day" + textName + QString::number(tempIndex) + ".txt";

    qDebug() << "Text name: " << textName;

    //    Date of purchase
    //    Customer number who bought the product
    //    Product description
    //    Price of product
    //    Quantity

        QString tempDate;
        QString tempCustomerNum;
        QString tempDescription;
        QString tempPrice;
        QString tempQuantity;

        QFile file(dataPath + "/" + textName);

        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this, "title", "file not open");
        }
        QTextStream in(&file);

        QSqlQueryModel * modal = new QSqlQueryModel();

        QSqlQuery* qry = new QSqlQuery(this->mydb);

        qry->prepare("delete from '"+argVar+"'");
        qry->exec();

        for (int i = 0; !in.atEnd(); i++)
        {
            tempDate = in.readLine();
            tempCustomerNum = in.readLine();
            tempDescription = in.readLine();
            tempPrice = in.readLine();
            tempQuantity = in.readLine();

//            qDebug() << "Date: " << tempDate;
//            qDebug() << "Customer Number: " << tempCustomerNum;
//            qDebug() << "Description: " << tempDescription;
//            qDebug() << "Price: " << tempPrice;
//            qDebug() << "Quantity: " << tempQuantity;

            qry->prepare("insert into '"+argVar+"' (Date,Number,Description,Price,Quantity)" "VALUES ('"+tempDate+"', '"+tempCustomerNum+"', '"+tempDescription+"', '"+tempPrice+"', '"+tempQuantity+"')");
            if(qry->exec())
            {
//                qDebug() << "Success!";

            }
            else {
                qDebug() << qry->lastError().text();
            }

        }

        qry->prepare("select * from '"+argVar+"'");

        qry->exec();
        modal->setQuery(*qry);
        ui->salesReportTableView->setModel(modal);
        ui->salesReportTableView->resizeColumnsToContents();

        qDebug() << (modal->rowCount());
        displayRevenue(argVar);

}

void ManagerMenu::loadFirstSalesReport()
{
    //Load Sunday on salesReportTableView when window is opened

    //    Date of purchase
    //    Customer number who bought the product
    //    Product description
    //    Price of product
    //    Quantity

        QString tempDate;
        QString tempCustomerNum;
        QString tempDescription;
        QString tempPrice;
        QString tempQuantity;

        QFile file(dataPath + "/day1.txt");

        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this, "title", "file not open");
        }
        QTextStream in(&file);


        QSqlQueryModel * modal = new QSqlQueryModel();

        QSqlQuery* qry = new QSqlQuery(this->mydb);

        qry->prepare("delete from Sunday");
        qry->exec();
        for (int i = 0; !in.atEnd(); i++)
        {

            tempDate = in.readLine();
            tempCustomerNum = in.readLine();
            tempDescription = in.readLine();
            tempPrice = in.readLine();
            tempQuantity = in.readLine();

            qDebug() << "Date: " << tempDate;
            qDebug() << "Customer Number: " << tempCustomerNum;
            qDebug() << "Description: " << tempDescription;
            qDebug() << "Price: " << tempPrice;
            qDebug() << "Quantity: " << tempQuantity;

            qry->prepare("insert into Sunday (Date,Number,Description,Price,Quantity)" "VALUES ('"+tempDate+"', '"+tempCustomerNum+"', '"+tempDescription+"', '"+tempPrice+"', '"+tempQuantity+"')");
            if(qry->exec())
            {
                qDebug() << "Success!";

            }
            else {
                qDebug() << qry->lastError().text();
            }
        }

        qry->prepare("select * from Sunday");

        qry->exec();
        modal->setQuery(*qry);
        ui->salesReportTableView->setModel(modal);
        ui->salesReportTableView->resizeColumnsToContents();

        qry->prepare("select SUM(Price) from Sunday");

        if(qry->exec())
        {
            qDebug() << "Success!";

        }
        else {
            qDebug() << qry->lastError().text();
        }

        QString totalRevenue = qry->value("Price").toString();

        qDebug() << totalRevenue;

        qDebug() << (modal->rowCount());

        displayRevenue("Sunday");


        //END Load Sunday
}

void ManagerMenu::on_standardButton_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(this->mydb);

    qry->prepare("select * from '"+daySelected+"' where customerTable.Number = '"+daySelected+"'.Number and Type = Regular");

    if(qry->exec())
    {
        qDebug() << "Success!";

    }
    else {
        qDebug() << qry->lastError().text();
    }

    modal->setQuery(*qry);
    ui->salesReportTableView->setModel(modal);
    ui->salesReportTableView->resizeColumnsToContents();
}

void ManagerMenu::loadDatabaseFromFile()
{
    QString tempName;
    QString tempMemberNumber;
    QString tempCustomerType;
    QString tempMembershipExp;

    QFile file(dataPath + "/warehouse shoppers.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "title", "file not open");
    }
    QTextStream in(&file);

    QSqlQuery* qry = new QSqlQuery(this->mydb);

    qry->prepare("delete from customerTable");
    qry->exec();

    for (int i = 0; !in.atEnd(); i++)
    {
        tempName = in.readLine();
        tempMemberNumber = in.readLine();
        tempCustomerType = in.readLine();
        tempMembershipExp = in.readLine();

        qDebug() << "Name: " << tempName;
        qDebug() << "Membership Number: " << tempMemberNumber;
        qDebug() << "Customer Type: " << tempCustomerType;
        qDebug() << "Membership Expiration Date: " << tempMembershipExp;

        qry->prepare("insert into customerTable (Name,Number,Type,Expiration)" "VALUES ('"+tempName+"', '"+tempMemberNumber+"', '"+tempCustomerType+"', '"+tempMembershipExp+"')");
        qry->exec();

    }
}

void ManagerMenu::loadMembersTable()
{
    //Customer Name
    //Member #
    //Customer Type
    //Membership Expiration Date

    QString tempName;
    QString tempMemberNumber;
    QString tempCustomerType;
    QString tempMembershipExp;

    QFile file(dataPath + "/warehouse shoppers.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "title", "file not open");
    }
    QTextStream in(&file);

    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery(this->mydb);

    qry->prepare("delete from customerTable");
    qry->exec();

    for (int i = 0; !in.atEnd(); i++)
    {
        tempName = in.readLine();
        tempMemberNumber = in.readLine();
        tempCustomerType = in.readLine();
        tempMembershipExp = in.readLine();

//        qDebug() << "Name: " << tempName;
//        qDebug() << "Membership Number: " << tempMemberNumber;
//        qDebug() << "Customer Type: " << tempCustomerType;
//        qDebug() << "Membership Expiration Date: " << tempMembershipExp;

        qry->prepare("insert into customerTable (Name,Number,Type,Expiration)" "VALUES ('"+tempName+"', '"+tempMemberNumber+"', '"+tempCustomerType+"', '"+tempMembershipExp+"')");
        qry->exec();

    }

    qry->prepare("select * from customerTable");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableViewDisplayMember->setModel(modal);
    ui->tableViewDisplayMember->resizeColumnsToContents();

    qDebug() << (modal->rowCount());
}

void ManagerMenu::displayRevenue(QString day)
{
   double totalRevenue = 0;
   int tempQuantity;
   double tempPrice;

   QSqlQuery query;
   QSqlQuery query2;

   query.prepare("SELECT Quantity FROM '"+day+"'");
   query2.prepare("SELECT Price FROM '"+day+"'");


   if(query.exec())
   {
       if(query2.exec())
       {
           while (query.next() && query2.next())
           {

               const QSqlRecord recrd = query.record();
               const QSqlRecord recrdPrice = query2.record();

               for(int i = 0;i < recrd.count();++i)
               {
                   tempQuantity = recrd.value(i).toInt();
                   tempPrice = recrdPrice.value(i).toDouble();

                   qDebug() << "Temp Quantity: " << tempQuantity;
                   qDebug() << "Temp Price: " << tempPrice;

                   totalRevenue += (tempQuantity*tempPrice);
    //               itemName = recrd.value(i).toString();
    //               ui->comboBoxDeleteName->addItem(itemName);

                   qDebug() << totalRevenue;
               }
           }
       }
   }

   ui->labelTotalRevenue->setText("$ " + QString::number(totalRevenue));

}

void ManagerMenu::on_buttonLogout_clicked()
{
    MainWindow * logoutScreen = new MainWindow;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Logout Confirmation", "Do you want to logout?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        logoutScreen->show();
        this->close();
    }
}
