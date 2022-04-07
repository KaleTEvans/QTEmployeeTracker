#ifndef ROLES_H
#define ROLES_H

#include <QWidget>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtGui>
#include <QInputDialog>
#include "tablestartup.h"
#include "roleinputdialogue.h"
#include "roleinput.h"

namespace Ui {
class Roles;
}

class Roles : public QWidget
{
    Q_OBJECT

public:
    explicit Roles(QWidget *parent = nullptr);
    ~Roles();
    void displayTable();

private slots:
    void on_addRole_clicked();
    void onOKButtonClicked();
    void on_deleteRole_clicked();
    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::Roles *ui;
    QSqlQuery *roleQuery;
    bool cellClicked;
    int rowSelected;
    // variables to store input values
    QString title;
    QString salary;
    int departmentId;

    RoleInput *roleInput;
};

#endif // ROLES_H
