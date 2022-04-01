#include "roles.h"
#include "ui_roles.h"

Roles::Roles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Roles)
{
    ui->setupUi(this);
    roleQuery = new QSqlQuery();
    cellClicked = false;
    rowSelected = 1000;
}

Roles::~Roles()
{
    delete ui;
}

void Roles::displayTable()
{
    //clear table and refresh when updating values
    ui->tableWidget->setRowCount(0);

    QString str = "SELECT * FROM roles";
    if (!roleQuery->exec(str)) {
        qDebug() << "Query execution failed";
        return;
    }
    // set table headers
    ui->tableWidget->setColumnCount(4);
    QStringList labels;
    labels << " " << "Title" << "Salary" << "Department ID";
    ui->tableWidget->setHorizontalHeaderLabels(labels);

    // now loop over database seeds and add to the table
    int rowCount = 0;

    while(roleQuery->next()) {
        ui->tableWidget->insertRow(rowCount);
        QTableWidgetItem *title = new QTableWidgetItem;
        QTableWidgetItem *salary = new QTableWidgetItem;
        QTableWidgetItem *departmentId = new QTableWidgetItem;

        title->setText(roleQuery->value(1).toString());
        salary->setText(roleQuery->value(2).toString());
        departmentId->setText(roleQuery->value(3).toString());

        ui->tableWidget->setItem(rowCount,1,title);
        ui->tableWidget->setItem(rowCount,2,salary);
        ui->tableWidget->setItem(rowCount,3,departmentId);

        rowCount++;
    }
}