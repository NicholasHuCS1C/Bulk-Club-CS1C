#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <QMainWindow>

namespace Ui {
class menuManager;
}

class menuManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit menuManager(QWidget *parent = nullptr);
    ~menuManager();

private slots:
    void on_buttonLogout_clicked();

private:
    Ui::menuManager *ui;
};

#endif // MENUMANAGER_H
