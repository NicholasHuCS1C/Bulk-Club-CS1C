#ifndef MENUSALESMANAGER_H
#define MENUSALESMANAGER_H

#include <QMainWindow>
#include "menu.h"

namespace Ui {
class MenuSalesManager;
}

class MenuSalesManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuSalesManager(QWidget *parent = nullptr);
    ~MenuSalesManager();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MenuSalesManager *ui;
};

#endif // MENUSALESMANAGER_H
