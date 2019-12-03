#include "menu.h"
#include "ui_menu.h"
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QFileInfo>
#include "mainwindow.h"
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    if(mydb.open())
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }



        mydb = QSqlDatabase::addDatabase("QSQLITE");
        dataPath = QFileDialog::getExistingDirectory(this, tr("Open Data Folder"),
                                                 "/Users/SeanVHatfield/SeanHatfield/Documents/GitHub/Bulk-Club-CS1C/QtCuties-BulkClubProject",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);


//        dataPath = QFileDialog::getExistingDirectory(this, tr("Open Data Folder"),
//                                                 "C:\\Users\\Sean Hatfield\\Documents\\GitHub\\Bulk-Club-CS1C\\QtCuties-BulkClubProject",
//                                                 QFileDialog::ShowDirsOnly
//                                                 | QFileDialog::DontResolveSymlinks);



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

        loadAllComboBoxes();
        loadMembersTable();
        createCustomerPurchasesDB();



}

Menu::~Menu()
{
    delete ui;
}




void Menu::on_load_all_clicked()
{
    loadMembersTable();
}


void Menu::on_comboBoxDays_activated(const QString &arg1)
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

void Menu::loadDeleteComboBox()
{
    QSqlQuery query;
    QString itemName;

    ui->comboBoxDeleteName->clear();

    bool firstLine=true;
    query.prepare("SELECT Name from customerTable");

    if(query.exec())
    {
        qDebug() << "Success for delete";
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
                ui->comboBoxDeleteName->addItem(itemName);

            }

        }
    }else {
            qDebug() << query.lastError().text();
        }
}

void Menu::loadDeleteNumberComboBox()
{
    QSqlQuery query;
    QString itemName;

    ui->comboBoxDeleteMemberNum->clear();

    bool firstLine=true;
    query.prepare("SELECT Number from customerTable");

    if(query.exec())
    {
        qDebug() << "Success for delete by number";
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
                ui->comboBoxDeleteMemberNum->addItem(itemName);

            }

        }
    }else {
            qDebug() << query.lastError().text();
        }
}

void Menu::loadFirstSalesReport()
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

void Menu::on_checkBoxStandard_toggled(bool checked)
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

void Menu::on_standardButton_clicked()
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

void Menu::on_buttonAddCustomer_clicked()
{
    QFile file(dataPath + "/warehouse shoppers.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text | QFile::Append))
    {
        qDebug() << "File not open\n";
    }
    QString date = "12/31/2021";
    QTextStream outCustomer(&file);

    outCustomer << endl;
    outCustomer << ui->lineEditAddName->text() << endl;
    outCustomer << ui->lineEditAddMemberNum->text() << endl;
    QString addMemberStatus;
    if(ui->addCustomerStatus->currentIndex() == 0)
    {
        addMemberStatus = "Executive";
    }
    else if(ui->addCustomerStatus->currentIndex() == 1)
    {
        addMemberStatus = "Standard";
    }

    outCustomer << addMemberStatus << endl;
    outCustomer << date;

    ui->lineEditAddName->setText("");
    ui->lineEditAddMemberNum->setText("");

    loadDatabaseFromFile();
//    loadDeleteComboBox();
//    loadDeleteNumberComboBox();
    loadAllComboBoxes();


    QMessageBox::information(this, tr("Customer Info"), tr("Customer Added!"));
}

void Menu::loadDatabaseFromFile()
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

void Menu::saveDatabaseTxt()
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

    file.close();
}

void Menu::on_buttonDeleteCustomer_clicked()
{
    QSqlQuery query;
    QString deleteName;

    deleteName = ui->comboBoxDeleteName->currentText();

    query.prepare("SELECT Number from customerTable");
    query.prepare("DELETE FROM customerTable WHERE Name='"+deleteName+"'");


    if(query.exec())
    {
        saveDatabaseTxt();
//        loadDeleteComboBox();
//        loadDeleteNumberComboBox();
        loadAllComboBoxes();
        loadMembersTable();
        QMessageBox::information(this, tr("Customer Info"), tr("Customer: '"+deleteName.toLocal8Bit()+"' was deleted!"));

        if(ui->comboBoxDeleteName->currentIndex() != 0)
        {
            ui->comboBoxDeleteName->setCurrentIndex(0);
        } else{
            ui->comboBoxDeleteName->setCurrentIndex(1);
            ui->comboBoxDeleteName->setCurrentIndex(0);
        }

    } else {
        qDebug() << query.lastError().text();
    }


}

void Menu::on_buttonDeleteCustomerNum_clicked()
{
    QSqlQuery query;
    QString deleteNum;

    deleteNum = ui->comboBoxDeleteMemberNum->currentText();

    query.prepare("SELECT Number from customerTable");
    query.prepare("DELETE FROM customerTable WHERE Number='"+deleteNum+"'");


    if(query.exec())
    {
        saveDatabaseTxt();

        loadAllComboBoxes();
        loadMembersTable();

        QMessageBox::information(this, tr("Customer Info"), tr("Customer: '"+deleteNum.toLocal8Bit()+"' was deleted!"));

        if(ui->comboBoxDeleteName->currentIndex() != 0)
        {
            ui->comboBoxDeleteName->setCurrentIndex(0);
        } else{
            ui->comboBoxDeleteName->setCurrentIndex(1);
            ui->comboBoxDeleteName->setCurrentIndex(0);
        }

    } else {
        qDebug() << query.lastError().text();
    }
}

void Menu::loadMembersTable()
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

void Menu::displayRevenue(QString day)
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

void Menu::loadAddPurchaseCustomerCombo()
{
    QSqlQuery query;
    QString itemName;

    ui->comboBoxNameSearch->clear();

    bool firstLine=true;
    query.prepare("SELECT Name from customerTable");

    if(query.exec())
    {
        qDebug() << "Success for delete";
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
}

void Menu::loadAllComboBoxes()
{

    loadDeleteComboBox();
    loadDeleteNumberComboBox();
    loadAddPurchaseCustomerCombo();
}

void Menu::createCustomerPurchasesDB()
{
    QSqlQuery query;
    QSqlQuery query2;

    QString daysAr[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    query.prepare("DELETE from allNumbers");
    query.exec();


    for(int i = 0; i < 7; i++)
    {
        //qDebug() << daysAr[i];

        query.prepare("SELECT Number from '"+daysAr[i]+"'");

        if(query.exec())
        {
            //qDebug() << "Success for customer db";
            while (query.next())
            {
                const QSqlRecord recrd = query.record();

                for(int i = 0;i < recrd.count();++i)
                {
                    QString numberToInsert = recrd.value(i).toString();

                    qDebug() << numberToInsert;
                    //Insert number into numbers table if it doesnt exist already
                    //WORKING
//                    query2.prepare("insert into allNumbers (Number) VALUES ('"+numberToInsert+"')");
                    //GET THIS TO WORK
                    query2.prepare("insert into allNumbers (Number) VALUES ('"+numberToInsert+"')");


                    //query2.prepare("INSERT INTO memos(id,text) SELECT 5, 'text to insert' WHERE NOT EXISTS(SELECT 1 FROM memos WHERE id = 5 AND text = 'text to insert');");
                   // qry->prepare("insert into '"+argVar+"' (Date,Number,Description,Price,Quantity)" "VALUES ('"+tempDate+"', '"+tempCustomerNum+"', '"+tempDescription+"', '"+tempPrice+"', '"+tempQuantity+"')");


                    if(query2.exec())
                    {
                        qDebug() << "Number added successfully to numbers table";
                    } else {
                        qDebug() << query2.lastError().text();
                    }

                }

            }
        } else {

            qDebug() << query.lastError().text();

        }
    }

    query.prepare("SELECT * from Sunday WHERE Number=67890");








}
