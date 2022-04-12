#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtGui>
#include <QInputDialog>
#include "headers/tablestartup.h"
#include "headers/employeeinput.h"

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

private slots:
    void onOkButtonClicked();
    void on_addEmployee_clicked();
    void on_removeEmployee_clicked();
    void on_editManager_clicked();

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

    EmployeeInput *employeeInput;
};

#endif // EMPLOYEES_H
