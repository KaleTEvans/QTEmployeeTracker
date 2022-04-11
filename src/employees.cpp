#include "headers/employees.h"
#include "ui_employees.h"

Employees::Employees(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Employees)
{
    ui->setupUi(this);
    employeeQuery = new QSqlQuery();
    cellClicked = false;
    rowSelected = 1000;
}

Employees::~Employees()
{
    delete ui;
}

void Employees::displayTable()
{
    // clear table and refresh when updating values
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QString str = "SELECT * FROM employees";
    if (!employeeQuery->exec(str)) {
        qDebug() << "Query execution failed";
        return;
    }

    // set table headers
    ui->tableWidget->setColumnCount(5);
    QStringList labels;
    labels << " " << "First Name" << "Last Name" << "Role ID" << "Manager ID";
    ui->tableWidget->setHorizontalHeaderLabels(labels);

    // now loop over database seeds and add to the table
    int rowCount = 0;

    while (employeeQuery->next()) {
        ui->tableWidget->insertRow(rowCount);
        QTableWidgetItem *firstName = new QTableWidgetItem;
        QTableWidgetItem *lastName = new QTableWidgetItem;
        QTableWidgetItem *roleId = new QTableWidgetItem;
        QTableWidgetItem *departmentId = new QTableWidgetItem;

        firstName->setText(employeeQuery->value(1).toString());
        lastName->setText(employeeQuery->value(2).toString());
        roleId->setText(employeeQuery->value(3).toString());
        departmentId->setText(employeeQuery->value(4).toString());

        ui->tableWidget->setItem(rowCount,1,firstName);
        ui->tableWidget->setItem(rowCount,2,lastName);
        ui->tableWidget->setItem(rowCount,3,roleId);
        ui->tableWidget->setItem(rowCount,4,departmentId);

        rowCount++;
    }
}
