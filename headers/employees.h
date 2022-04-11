#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtGui>
#include <QInputDialog>
#include "headers/tablestartup.h"

namespace Ui {
class Employees;
}

class Employees : public QWidget
{
    Q_OBJECT

public:
    explicit Employees(QWidget *parent = nullptr);
    ~Employees();
    void displayTable();

private:
    Ui::Employees *ui;
    QSqlQuery *employeeQuery;
    bool cellClicked;
    int rowSelected;
    // variables to store input values
    QString firstName;
    QString lastName;
    int roleId;
    int managerId;
};

#endif // EMPLOYEES_H
