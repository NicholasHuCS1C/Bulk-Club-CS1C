#include "managermenu.h"
#include "ui_managermenu.h"

managerMenu::managerMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::managerMenu)
{
    ui->setupUi(this);

    if(mydb.open())
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

        mydb = QSqlDatabase::addDatabase("QSQLITE");
//        dataPath = QFileDialog::getExistingDirectory(this, tr("Open Data Folder"),
//                                                 "/Users/SeanVHatfield/SeanHatfield/Documents/GitHub/Bulk-Club-CS1C/QtCuties-BulkClubProject",
//                                                 QFileDialog::ShowDirsOnly
//                                                 | QFileDialog::DontResolveSymlinks);


        QFile();
//        dataPath = QFileDialog::getExistingDirectory(this, tr("Open Data Folder"),
//                                                 "C:\\Users\\Sean Hatfield\\Documents\\GitHub\\Bulk-Club-CS1C\\QtCuties-BulkClubProject",
//                                                 QFileDialog::ShowDirsOnly
//                                                 | QFileDialog::DontResolveSymlinks);

        dataPath = "C:/Users/Nicholas/Documents/GitHub/Bulk-Club-CS1C/QtCuties-BulkClubProject/Data";



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

        loadMembersTable();
        createPurchasesTables();
        createCustomerPurchasesDB();

        loadNumberAddCustomer();
        createInventoryTable();

        loadCustomerPurchasesTable();

        loadAllComboBoxes();

        loadNumberAddCustomer();
        loadCustomerPurchasesTable();
}

managerMenu::~managerMenu()
{
    delete ui;
}

void managerMenu::on_load_all_clicked()///Loads all current members
{
    loadMembersTable();
}


void managerMenu::on_comboBoxDays_activated(const QString &arg1) ///Pick day in the combobox
{

    loadCustomerAmountLabels();

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

//void managerMenu::loadDeleteComboBox()
//{
//    QSqlQuery query;
//    QString itemName;

//    ui->comboBoxDeleteName->clear();

//    bool firstLine=true;
//    query.prepare("SELECT Name from customerTable");

//    if(query.exec())
//    {
//        qDebug() << "Success for delete";
//        while (query.next())
//        {
//            const QSqlRecord recrd = query.record();
//            if(firstLine)
//            {
//                for(int i = 0;i < recrd.count();++i)
//                {
//                    qDebug() << recrd.field(i); //Headers
//                }
//            }
//            firstLine=false;
//            for(int i = 0;i < recrd.count();++i)
//            {
//                qDebug() << recrd.value(i).toString();
//                itemName = recrd.value(i).toString();
//                ui->comboBoxDeleteName->addItem(itemName);

//            }

//        }
//    }else {
//            qDebug() << query.lastError().text();
//        }
//    query.finish();
//}

//void managerMenu::loadDeleteNumberComboBox()
//{
//    QSqlQuery query;
//    QString itemName;

//    ui->comboBoxDeleteMemberNum->clear();

//    bool firstLine=true;
//    query.prepare("SELECT Number from customerTable");

//    if(query.exec())
//    {
//        qDebug() << "Success for delete by number";
//        while (query.next())
//        {
//            const QSqlRecord recrd = query.record();
//            if(firstLine)
//            {
//                for(int i = 0;i < recrd.count();++i)
//                {
//                    qDebug() << recrd.field(i); //Headers
//                }
//            }
//            firstLine=false;
//            for(int i = 0;i < recrd.count();++i)
//            {
//                qDebug() << recrd.value(i).toString();
//                itemName = recrd.value(i).toString();
//                ui->comboBoxDeleteMemberNum->addItem(itemName);

//            }

//        }
//    }else {
//            qDebug() << query.lastError().text();
//        }
//    query.finish();
//}

void managerMenu::loadFirstSalesReport()/// Loads the sales report
{

        loadCustomerAmountLabels();

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

void managerMenu::on_checkBoxStandard_toggled(bool checked)
{
//    QSqlQueryModel * modal = new QSqlQueryModel();
//    QSqlQuery* qry = new QSqlQuery(this->mydb);

//    qry->prepare("");
//    qry->exec();

//    modal->setQuery(*qry);
//    ui->salesReportTableView->setModel(modal);
//    ui->salesReportTableView->resizeColumnsToContents();

    qDebug() << checked;
}

void managerMenu::on_standardButton_clicked()///Views whether member is standard
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(this->mydb);



    QString daySelected;
    daySelected = ui->comboBoxDays->currentText();




    qry->prepare("SELECT '"+daySelected+"'.date,'"+daySelected+"'.Number,'"+daySelected+"'.Description, '"+daySelected+"'.Price, '"+daySelected+"'.Quantity FROM '"+daySelected+"' INNER JOIN customerTable ON '"+daySelected+"'.Number=customerTable.Number WHERE customerTable.Type=\"Regular\"");
    if(qry->exec())
    {
        qDebug() << "Selected Standard Members Only!";
    }


    modal->setQuery(*qry);
    ui->salesReportTableView->setModel(modal);
    ui->salesReportTableView->resizeColumnsToContents();

    ui->labelStandardCustomerNum->setText(QString::number(modal->rowCount()));

}

//void managerMenu::on_buttonAddCustomer_clicked()
//{
//    QFile file(dataPath + "/warehouse shoppers.txt");
//    if(!file.open(QFile::WriteOnly | QFile::Text | QFile::Append))
//    {
//        qDebug() << "File not open\n";
//    }
//    QString date = "12/31/2021";
//    QTextStream outCustomer(&file);

//    outCustomer << endl;
//    outCustomer << ui->lineEditAddName->text() << endl;
//    outCustomer << ui->lineEditAddMemberNum->text() << endl;
//    QString addMemberStatus;
//    if(ui->addCustomerStatus->currentIndex() == 0)
//    {
//        addMemberStatus = "Executive";
//    }
//    else if(ui->addCustomerStatus->currentIndex() == 1)
//    {
//        addMemberStatus = "Standard";
//    }

//    outCustomer << addMemberStatus << endl;
//    outCustomer << date;

//    ui->lineEditAddName->setText("");
//    ui->lineEditAddMemberNum->setText("");

//    loadDatabaseFromFile();
////    loadDeleteComboBox();
////    loadDeleteNumberComboBox();
//    loadAllComboBoxes();
//    loadAddPurchaseCustomerCombo();


//    QMessageBox::information(this, tr("Customer Info"), tr("Customer Added!"));
//}

void managerMenu::loadDatabaseFromFile()/// loads the database from a file
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

void managerMenu::saveDatabaseTxt()/// Saves the database to a file
{
    QSqlQuery query;
    int totalCount = 0;
    int currentCount = 0;

    query.prepare("SELECT * FROM customerTable");
    if(query.exec())
    {
        while (query.next())
        {
            const QSqlRecord recrd = query.record();

            for(int i = 0;i < recrd.count();++i)
            {
                totalCount++;
            }
        }

        qDebug() << totalCount;
    }

    query.finish();


    QFile file(dataPath + "/warehouse shoppers.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate))
    {
        qDebug() << "File not open\n";
    }

    QTextStream outFile(&file);
    bool firstLine=true;
    query.prepare("SELECT * FROM customerTable");
    if(query.exec())
    {
        while (query.next())
        {
            const QSqlRecord recrd = query.record();
            if(firstLine)
            {
                for(int i = 0;i < recrd.count();++i)
                {
                    qDebug() << recrd.field(i); //Headers
                }
            }
            firstLine=false;
            for(int i = 0;i < recrd.count();++i)
            {
                outFile << recrd.value(i).toString();
                currentCount++;
                if (currentCount < (totalCount))
                {
                    outFile << endl;
                }


            }
        }
    }

    query.finish();

    file.close();
}

//void managerMenu::on_buttonDeleteCustomer_clicked()
//{
//    QSqlQuery query;
//    QString deleteName;

//    deleteName = ui->comboBoxDeleteName->currentText();

//    query.prepare("SELECT Number from customerTable");
//    query.prepare("DELETE FROM customerTable WHERE Name='"+deleteName+"'");


//    if(query.exec())
//    {
//        saveDatabaseTxt();
////        loadDeleteComboBox();
////        loadDeleteNumberComboBox();
//        loadAllComboBoxes();
//        loadMembersTable();
//        QMessageBox::information(this, tr("Customer Info"), tr("Customer: '"+deleteName.toLocal8Bit()+"' was deleted!"));

//        if(ui->comboBoxDeleteName->currentIndex() != 0)
//        {
//            ui->comboBoxDeleteName->setCurrentIndex(0);
//        } else{
//            ui->comboBoxDeleteName->setCurrentIndex(1);
//            ui->comboBoxDeleteName->setCurrentIndex(0);
//        }

//    } else {
//        qDebug() << query.lastError().text();
//    }

//    query.finish();


//}

//void managerMenu::on_buttonDeleteCustomerNum_clicked()
//{
//    QSqlQuery query;
//    QString deleteNum;

//    deleteNum = ui->comboBoxDeleteMemberNum->currentText();

//    query.prepare("SELECT Number from customerTable");
//    query.prepare("DELETE FROM customerTable WHERE Number='"+deleteNum+"'");


//    if(query.exec())
//    {
//        saveDatabaseTxt();

//        loadAllComboBoxes();
//        loadMembersTable();

//        QMessageBox::information(this, tr("Customer Info"), tr("Customer: '"+deleteNum.toLocal8Bit()+"' was deleted!"));

//        if(ui->comboBoxDeleteName->currentIndex() != 0)
//        {
//            ui->comboBoxDeleteName->setCurrentIndex(0);
//        } else{
//            ui->comboBoxDeleteName->setCurrentIndex(1);
//            ui->comboBoxDeleteName->setCurrentIndex(0);
//        }

//    } else {
//        qDebug() << query.lastError().text();
//    }

//    query.finish();
//}

void managerMenu::loadMembersTable()/// Loads all members to a table
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

void managerMenu::displayRevenue(QString day)/// Displays revenue for current day
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

   query.finish();
   query2.finish();

   totalRevenue = totalRevenue * 1.0775;

   ui->labelTotalRevenue->setText("$ " + QString::number(totalRevenue));


}

void managerMenu::loadAddPurchaseCustomerCombo()/// Loads the add a purchase to a customer
{
    QSqlQuery query;
    QString itemName;

    ui->comboBoxNameSearch->clear();

    bool firstLine=true;
    query.prepare("SELECT Name from customerTable");

    if(query.exec())
    {
        while (query.next())
        {
            const QSqlRecord recrd = query.record();
            if(firstLine)
            {
                for(int i = 0;i < recrd.count();++i)
                {
                    qDebug() << recrd.field(i); //Headers
                }
            }
            firstLine=false;
            for(int i = 0;i < recrd.count();++i)
            {
                qDebug() << recrd.value(i).toString();
                itemName = recrd.value(i).toString();
                ui->comboBoxNameSearch->addItem(itemName);

            }

        }
    }else {
            qDebug() << query.lastError().text();
        }

    query.finish();
}

void managerMenu::loadAllComboBoxes()///Loads the combobox with the members
{

    //loadDeleteComboBox();
    //loadDeleteNumberComboBox();
    loadAddPurchaseCustomerCombo();
    loadItemsPurchaseCombo();
    loadInventoryTable();
    //loadDeleteItemComboBox();
    displayTotalCustomerPurchases();


}

void managerMenu::createCustomerPurchasesDB()///Creates purchase database
{
    QSqlQuery query;
    QSqlQuery query2;
    QSqlQuery addPurchases;
    QSqlQuery addPurchases2;
    QSqlRecord recrd;




    QString daysAr[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


    for(int i = 0; i < 7; i++)
    {

        addPurchases.prepare("SELECT Number, Description, Price, Quantity from '"+daysAr[i]+"'");

        if(addPurchases.exec())
        {

            while(addPurchases.next())
            {
                QSqlRecord recrd = addPurchases.record();

                for(int n = 0; n < recrd.count();n += 4)
                {
                    QString tempNumber;


                    tempNumber = recrd.value(n).toString();

                    qDebug() << "Num: " << tempNumber;

                    query.prepare("delete from '"+tempNumber+"'");
                    if(query.exec())
                    {
                        qDebug() << "Table '"+tempNumber+"' was emptied!";
                    } else {
                        qDebug() << query.lastError().text();
                    }


                }
            }


        } else {

            qDebug() << addPurchases.lastError().text();

        }


    }




    for(int i = 0; i < 7; i++)
    {

        addPurchases.prepare("SELECT Number, Description, Price, Quantity from '"+daysAr[i]+"'");

        if(addPurchases.exec())
        {



            while(addPurchases.next())
            {
                QSqlRecord recrd = addPurchases.record();

                for(int n = 0; n < recrd.count();n += 4)
                {
                    QString tempNumber;
                    QString tempDescription;
                    QString tempPrice;
                    QString tempQuantity;

                    tempNumber = recrd.value(n).toString();
                    tempDescription = recrd.value(n + 1).toString();
                    tempPrice = recrd.value(n + 2).toString();
                    tempQuantity = recrd.value(n + 3).toString();

                    qDebug() << "Num: " << tempNumber;
                    qDebug() << "Descr: " << tempDescription;
                    qDebug() << "Price: " << tempPrice;
                    qDebug() << "Quant: " << tempQuantity;


                    addPurchases2.prepare("insert into '"+tempNumber+"' (Description,Quantity,Price)" "VALUES ('"+tempDescription+"', '"+tempQuantity+"', '"+tempPrice+"')");

                    if(addPurchases2.exec())
                    {
                        qDebug() << "Purchase added to customer table!";
                    } else {
                        qDebug() << addPurchases2.lastError().text();
                    }


                }
            }


        } else {

            qDebug() << addPurchases.lastError().text();

        }


    }


}

void managerMenu::createPurchasesTables()///Creates purchase tables
{
    QSqlQuery getIdNum;
    QSqlQuery createTable;
    QString idNum;
    bool firstLine = true;


    getIdNum.prepare("SELECT Number from customerTable");
    if(getIdNum.exec())
    {
        qDebug() << "Number was selected from customerTable!";

        while (getIdNum.next())
        {
            const QSqlRecord recrd = getIdNum.record();
            if(firstLine)
            {
                for(int i = 0;i < recrd.count();++i)
                {
                    qDebug() << recrd.field(i); //Headers
                }
            }
            firstLine = false;

            for(int i = 0;i < recrd.count();++i)
            {
                idNum = recrd.value(i).toString();
                qDebug() << "Temp ID Num: " << idNum;

                createTable.prepare("create table if not exists '"+idNum+"' (\"Description\" TEXT, \"Quantity\" NUMERIC, \"Price\" NUMERIC)");
                if(createTable.exec())
                {
                    qDebug() << "Created table for '"+idNum+"'!";
                }

            }

        }

        getIdNum.finish();
        createTable.finish();

    }





}

void managerMenu::clearAllPurchasesTables()/// Clears the purchases from the tables
{
    QSqlQuery getIdNum;
    QSqlQuery clearTables;


    QString idNum;
    bool firstLine = true;


    getIdNum.prepare("SELECT Number from customerTable");
    if(getIdNum.exec())
    {
        qDebug() << "Number was selected from customerTable!";

        while (getIdNum.next())
        {
            const QSqlRecord recrd = getIdNum.record();
            if(firstLine)
            {
                for(int i = 0;i < recrd.count();++i)
                {
                    qDebug() << recrd.field(i); //Headers
                }
            }
            firstLine = false;

            for(int i = 0;i < recrd.count();++i)
            {
                idNum = recrd.value(i).toString();


//                QString dropString;
//                dropString = "DROP TABLE \""+idNum+"\"";


                clearTables.prepare("delete from '"+idNum+"'");

                if(clearTables.exec())
                {
                    qDebug() << "Table for " << idNum << "has been deleted!";
                } else {
                    qDebug() << clearTables.lastError().text();
                }
            }
        }
    }
    getIdNum.finish();
    clearTables.finish();

}

void managerMenu::on_buttonClearPurchases_clicked()
{
    clearAllPurchasesTables();
}

void managerMenu::on_comboBoxNameSearch_activated(const QString &arg1)/// Loads names to combobox
{
    qDebug() << arg1;
    loadNumberAddCustomer();
    loadCustomerPurchasesTable();
    ui->lineEditQuantityInput->clear();
}

void managerMenu::loadNumberAddCustomer()/// Loads the membership number
{
   QString name = ui->comboBoxNameSearch->currentText();
   QSqlQuery query;


   query.prepare("select Number from customerTable where Name=\"" + name + "\"");
   if(query.exec())
   {
       while (query.next())
       {
           qDebug() << query.value(0).toString();
           ui->labelMemberNum->setText(query.value(0).toString());
       }

   } else {
       qDebug() << query.lastError().text();
   }

   double totalRevenue = 0;
   int tempQuantity;
   double tempPrice;
   QString tempNumber;

   //QSqlQuery query;
   QSqlQuery query2;

   tempNumber = ui->labelMemberNum->text();

   query.prepare("SELECT Quantity FROM '"+tempNumber+"'");
   query2.prepare("SELECT Price FROM '"+tempNumber+"'");


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




                   qDebug() << totalRevenue;
               }


           }
       }

   }
   totalRevenue = totalRevenue * 1.0775;

   double rebate = totalRevenue * .02;

   ui->labelTotalAmountSpent->setText("$ " + QString::number(totalRevenue));
   ui->labelRebateAmount->setText("$ " + QString::number(rebate));



   query.prepare("select * from customerTable where Number=\"" + tempNumber + "\" and Type=\"Executive\"");
   if(query.exec())
   {
       int numberOfRows = 0;
       if(query.last())
       {
           numberOfRows =  query.at() + 1;
           query.first();
           query.previous();
       }

       if(numberOfRows != 1)
       {
           ui->labelRebateAmount->hide();
           ui->labelRebateAmountText->hide();
           ui->labelExecutiveMember->hide();
           if (rebate >= 55)
           {
               qDebug() << "rebate for standard " << rebate;
               ui->labelStatusChange->setText("SET EXECUTIVE");
           }

       } else {
           ui->labelRebateAmount->show();
           ui->labelRebateAmountText->show();
           ui->labelExecutiveMember->show();
           if (rebate < 55)
           {
               qDebug() << "rebate for executive " << rebate;
               ui->labelStatusChange->setText("SET STANDARD");
           }
       }

       qDebug() << "Query Size: " << numberOfRows;

   } else {
       query.lastError().text();
   }
}


void managerMenu::createInventoryTable()/// creates the inventory table
{
    QSqlQuery query;
    QSqlQuery query2;

    query.prepare("create table if not exists inventoryTable (\"Description\" TEXT, \"Price\" NUMERIC)");

    if(query.exec())
    {
        qDebug() << "Inventory table created!";
    } else {
        qDebug() << query.lastError().text();
    }

    query.prepare("delete from inventoryTable");
    if(query.exec())
    {
        qDebug() << "Inventory table cleared!";
    } else {
        qDebug() << query.lastError().text();
    }



    QString tempNumber;
    QString tempDescription;
    QString tempPrice;

    query.prepare("create unique index inventoryTable_description_price on inventoryTable (Description, Price)");
    if (query.exec())
    {
        qDebug() << "Created unique index";
    } else {
        qDebug() << query.lastError().text();
    }

    query.prepare("SELECT Number from customerTable");

    if(query.exec())
    {

        while (query.next())
        {
            const QSqlRecord recrd = query.record();

            for(int i = 0;i < recrd.count();++i)
            {
                tempNumber = recrd.value(i).toString();





                query2.prepare("select Description, Price from \"" + tempNumber + "\"");

                if(query2.exec())
                {
                    qDebug() << "Reading in Purchases from" << tempNumber;

                    while(query2.next())
                    {
                        QSqlRecord recrd = query2.record();

                        for(int i = 0;i < recrd.count();i += 2)
                        {
                            tempDescription = recrd.value(i).toString();
                            tempPrice = recrd.value(i + 1).toString();

                            qDebug() << "Description: " << tempDescription;
                            qDebug() << "Price: " << tempPrice;

                            //INSERT ITEM INTO TABLE IF NOT EXISTS
                            QSqlQuery query3;
                            query3.prepare("insert or ignore into inventoryTable values ('"+tempDescription+"','"+tempPrice+"')");
                            if(query3.exec())
                            {
                                qDebug() << "Inserted tempDescription: " << tempDescription << " and tempPrice: " << tempPrice;
                            } else{
                                qDebug() << query3.lastError().text();
                            }

                        }
                    }



                } else{
                    qDebug() << query2.lastError().text();
                }
            }

        }
    }else {
            qDebug() << query.lastError().text();
        }
}


void managerMenu::loadItemsPurchaseCombo()/// Load all purchasable items
{
    QSqlQuery query;
    QString itemName;

    ui->comboBoxItemSearch->clear();

    query.prepare("SELECT Description from inventoryTable");

    if(query.exec())
    {
        while (query.next())
        {
            const QSqlRecord recrd = query.record();

            for(int i = 0;i < recrd.count();++i)
            {
                itemName = recrd.value(i).toString();
                ui->comboBoxItemSearch->addItem(itemName);

            }

        }
    }else {
            qDebug() << query.lastError().text();
        }


    itemName = ui->comboBoxItemSearch->currentText();
    query.prepare("select Price from inventoryTable where Description='"+itemName+"'");

    QString tempPrice;
    if(query.exec())
    {
        while (query.next())
        {
            const QSqlRecord recrd = query.record();

            for(int i = 0;i < recrd.count();++i)
            {
                tempPrice = recrd.value(i).toString();
                ui->labelPricePerItem->setText("$" + tempPrice);

            }

        }
    }else {
            qDebug() << query.lastError().text();
        }
}

void managerMenu::on_comboBoxItemSearch_currentIndexChanged(const QString &arg1)/// Searches for item in inventory
{
    qDebug() << arg1;
    QSqlQuery query;
    QString tempPrice;

    query.prepare("select Price from inventoryTable where Description='"+arg1+"'");

    if(query.exec())
    {
        while (query.next())
        {
            const QSqlRecord recrd = query.record();

            for(int i = 0;i < recrd.count();++i)
            {
                tempPrice = recrd.value(i).toString();
                ui->labelPricePerItem->setText("$" + tempPrice);

            }

        }
    }else {
            qDebug() << query.lastError().text();
        }
    ui->labelTotalPrice->clear();
}

void managerMenu::on_buttonCalcTotalPrice_clicked()/// Calculates total price
{
    QSqlQuery query;
    QString itemName;
    int quantity;
    float totalValue;

    itemName = ui->comboBoxItemSearch->currentText();
    query.prepare("select Price from inventoryTable where Description='"+itemName+"'");

    float tempPrice;
    if(query.exec())
    {
        while (query.next())
        {
            const QSqlRecord recrd = query.record();

            for(int i = 0;i < recrd.count();++i)
            {
                tempPrice = recrd.value(i).toFloat();
                quantity = ui->lineEditQuantityInput->text().toInt();

                totalValue = tempPrice * quantity;
                QString totalValueString;
                totalValueString.setNum(totalValue);
                ui->labelTotalPrice->setText("$" + totalValueString);
            }

        }
    }
}

void managerMenu::loadCustomerPurchasesTable()/// loads the customer purchase table
{

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(this->mydb);
    QString tempNumber;

    tempNumber = ui->labelMemberNum->text();

    qry->prepare("select * from '"+tempNumber+"'");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableViewDisplayPurchases->setModel(modal);
    ui->tableViewDisplayPurchases->resizeColumnsToContents();
}

void managerMenu::loadInventoryTable()/// loads inventory to screen
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(this->mydb);


    qry->prepare("select * from inventoryTable");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableViewInventory->setModel(modal);
    ui->tableViewInventory->resizeColumnsToContents();
}

void managerMenu::on_buttonAddPurchase_clicked()/// Allows you to add a purchase
{
    QSqlQuery query;
    int tempNumber;
    QString tempDescription;
    QString tempPrice;
    QString tempQuantity;
    int tempQuantityInt;

    tempNumber = ui->labelMemberNum->text().toInt();

    tempQuantity = ui->lineEditQuantityInput->text();
    tempQuantityInt = tempQuantity.toInt();

    tempDescription = ui->comboBoxItemSearch->currentText();

    QString itemName;

    itemName = ui->comboBoxItemSearch->currentText();
    query.prepare("select Price from inventoryTable where Description='"+itemName+"'");

    if(query.exec())
    {
        while (query.next())
        {
            const QSqlRecord recrd = query.record();

            for(int i = 0;i < recrd.count();++i)
            {
                tempPrice = recrd.value(i).toString();

            }

        }
    }else {
            qDebug() << query.lastError().text();
        }





    if (tempQuantityInt > 0)
    {

        query.prepare("insert into \"" + QString::number(tempNumber) + "\"(Description,Quantity,Price) values('"+tempDescription+"','"+tempQuantity+"','"+tempPrice+"')");
        if(query.exec())
        {
            qDebug() << "Item Added successfully!";
        } else {
            qDebug() << query.lastError().text();
        }

    }


    loadCustomerPurchasesTable();

}

void managerMenu::on_pushButtonReloadInventory_clicked()/// refreshes the inventory
{
    loadInventoryTable();
}

void managerMenu::on_pushButtonSearchInventory_clicked()/// Searches through inventory
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(this->mydb);
    QSqlQuery query;

    QString tempDescription;
    tempDescription = ui->lineEditSearchItem->text();


    qry->prepare("select * from inventoryTable where Description=\"" + tempDescription + "\"");

    if(qry->exec())
    {
        modal->setQuery(*qry);
        ui->tableViewInventory->setModel(modal);
        ui->tableViewInventory->resizeColumnsToContents();

        ui->lineEditSearchItem->clear();

        //loadAllComboBoxes();
    } else {
        QMessageBox::information(this, tr("Search Info"), tr("Member Was Not Found!"));
        ui->lineEditSearchItem->clear();
    }
}


//void managerMenu::addItemToInventory()
//{
//    QSqlQuery query;
//    QString tempDescription;
//    QString tempPrice;

//    tempDescription = ui->lineEditAddItem->text();
//    tempPrice = ui->lineEditAddPrice->text();

//    query.prepare("insert or ignore into inventoryTable values ('"+tempDescription+"','"+tempPrice+"')");
//    if(query.exec())
//    {
//        qDebug() << "Item Added successfully!";
//    } else {
//        qDebug() << query.lastError().text();
//    }




//    loadInventoryTable();
//}

//void managerMenu::on_buttonAddItem_clicked()
//{
//    addItemToInventory();
//    ui->lineEditAddItem->clear();
//    ui->lineEditAddPrice->clear();

//    QMessageBox::information(this, tr("Inventory Info"), tr("Item Added!"));

//    loadAllComboBoxes();
//}

//void managerMenu::loadDeleteItemComboBox()
//{
//    QSqlQuery query;
//    QString itemName;

//    ui->comboBoxDeleteItem->clear();

//    query.prepare("SELECT Description from inventoryTable");

//    if(query.exec())
//    {
//        qDebug() << "Success for delete";
//        while (query.next())
//        {
//            QSqlRecord recrd = query.record();

//            for(int i = 0;i < recrd.count();++i)
//            {
//                itemName = recrd.value(i).toString();
//                ui->comboBoxDeleteItem->addItem(itemName);

//            }

//        }
//    }else {
//            qDebug() << query.lastError().text();
//        }
//}
//void managerMenu::deleteItemFromInventory()
//{
//    QSqlQuery query;
//    QString tempDescription;

//    tempDescription = ui->comboBoxDeleteItem->currentText();

//    query.prepare("delete from inventoryTable where Description=\"" + tempDescription + "\"");

//    if(query.exec())
//    {
//        QMessageBox::information(this, tr("Inventory Info"), tr("Item Deleted!"));
//        qDebug() << "Item Deleted!";
//    } else {
//        qDebug() << query.lastError().text();
//    }


//}

//void managerMenu::on_buttonDeleteItem_clicked()
//{

//    deleteItemFromInventory();
//    loadInventoryTable();
//    loadAllComboBoxes();

//    if(ui->comboBoxDeleteItem->currentIndex() != 0)
//    {
//        ui->comboBoxDeleteItem->setCurrentIndex(0);
//    } else{
//        ui->comboBoxDeleteItem->setCurrentIndex(1);
//        ui->comboBoxDeleteItem->setCurrentIndex(0);
//    }
//}

void managerMenu::on_lineEditQuantityInput_textChanged(const QString &arg1)/// edits quantity of inventory
{
    QSqlQuery query;
    QString itemName;
    int quantity;
    float totalValue;

    qDebug() << arg1;

    itemName = ui->comboBoxItemSearch->currentText();
    query.prepare("select Price from inventoryTable where Description='"+itemName+"'");

    float tempPrice;
    if(query.exec())
    {
        while (query.next())
        {
            const QSqlRecord recrd = query.record();

            for(int i = 0;i < recrd.count();++i)
            {
                tempPrice = recrd.value(i).toFloat();
                quantity = ui->lineEditQuantityInput->text().toInt();

                totalValue = tempPrice * quantity;
                QString totalValueString;
                totalValueString.setNum(totalValue);
                ui->labelTotalPrice->setText("$" + totalValueString);


            }

        }
    }
}



void managerMenu::on_buttonSearchMemberNumber_clicked()/// searches for meembership number
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(this->mydb);
    QSqlQuery query;

    QString tempNumber;
    tempNumber = ui->lineEditSearchNum->text();


    qry->prepare("select * from customerTable where Number=\"" + tempNumber + "\"");

    if(qry->exec())
    {
        modal->setQuery(*qry);
        ui->tableViewDisplayMember->setModel(modal);
        ui->tableViewDisplayMember->resizeColumnsToContents();

        ui->lineEditSearchNum->clear();

        loadAllComboBoxes();
    } else {
        QMessageBox::information(this, tr("Search Info"), tr("Member Was Not Found!"));
    }



}


void managerMenu::loadCustomerAmountLabels()/// loads amount customer spent
{
    on_executiveButton_clicked();
    on_standardButton_clicked();
}

void managerMenu::on_executiveButton_clicked()/// loads executive members only
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(this->mydb);



    QString daySelected;
    daySelected = ui->comboBoxDays->currentText();




    qry->prepare("SELECT '"+daySelected+"'.date,'"+daySelected+"'.Number,'"+daySelected+"'.Description, '"+daySelected+"'.Price, '"+daySelected+"'.Quantity FROM '"+daySelected+"' INNER JOIN customerTable ON '"+daySelected+"'.Number=customerTable.Number WHERE customerTable.Type=\"Executive\"");
    if(qry->exec())
    {
        qDebug() << "Selected Executive Members Only!";
    }



    modal->setQuery(*qry);
    ui->salesReportTableView->setModel(modal);
    ui->salesReportTableView->resizeColumnsToContents();

    ui->labelExecCustomerNum->setText(QString::number(modal->rowCount()));
}

void managerMenu::on_buttonSearchMemberName_clicked()/// Searches for members
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(this->mydb);


    QString tempNumber;
    tempNumber = ui->lineEditSearchName->text();


    qry->prepare("select * from customerTable where Name=\"" + tempNumber + "\"");

    if(qry->exec())
    {
        modal->setQuery(*qry);
        ui->tableViewDisplayMember->setModel(modal);
        ui->tableViewDisplayMember->resizeColumnsToContents();

        ui->lineEditSearchName->clear();

        loadAllComboBoxes();
    } else {
        QMessageBox::information(this, tr("Search Info"), tr("Member Was Not Found!"));
    }
}

void managerMenu::displayTotalCustomerPurchases()
{
//    double totalRevenue = 0;
//    int tempQuantity;
//    double tempPrice;
//    QString tempNumber;

//    QSqlQuery query;
//    QSqlQuery query2;

//    tempNumber = ui->labelMemberNum->text();

//    query.prepare("SELECT Quantity FROM '"+tempNumber+"'");
//    query2.prepare("SELECT Price FROM '"+tempNumber+"'");


//    if(query.exec())
//    {
//        if(query2.exec())
//        {
//            while (query.next() && query2.next())
//            {

//                const QSqlRecord recrd = query.record();
//                const QSqlRecord recrdPrice = query2.record();

//                for(int i = 0;i < recrd.count();++i)
//                {
//                    tempQuantity = recrd.value(i).toInt();
//                    tempPrice = recrdPrice.value(i).toDouble();

//                    qDebug() << "Temp Quantity: " << tempQuantity;
//                    qDebug() << "Temp Price: " << tempPrice;



//                    totalRevenue += (tempQuantity*tempPrice);




//                    qDebug() << totalRevenue;
//                }


//            }
//        }

//    }



//    totalRevenue = totalRevenue * 1.0775;

//    ui->labelTotalAmountSpent->setText("$ " + QString::number(totalRevenue));
}

void managerMenu::on_buttonLogout_clicked()/// logs out to login menu
{
    MainWindow * loginScreen = new MainWindow;
    loginScreen->show();
    this->close();
}

void managerMenu::on_buttonSearchMonth_clicked()/// searches the month of purchases
{
    QSqlQueryModel * modal = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery(this->mydb);



        QString tempDate;
        tempDate = ui->comboBoxSearchMonth->currentText();

        //tempDate = "SELECT * from customerTable WHERE Expiration like '%'"+tempDate+"'/%' AND Expiration NOT like '%/'"+tempDate+"'/%'";
        qDebug() << tempDate;

        qry->prepare("SELECT * from customerTable WHERE Expiration like '%" + tempDate + "/%' AND Expiration NOT like '%/" + tempDate + "/%'");

        if(qry->exec())
        {
            modal->setQuery(*qry);
            ui->tableViewDisplayMember->setModel(modal);
            ui->tableViewDisplayMember->resizeColumnsToContents();

            ui->lineEditSearchName->clear();

            loadAllComboBoxes();
        } else {
            QMessageBox::information(this, tr("Search Info"), tr("Member Was Not Found!"));
        }
}
