#include "departments.h"
#include "ui_departments.h"

Departments::Departments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Departments)
{
    ui->setupUi(this);
}

Departments::~Departments()
{
    delete ui;
}

void Departments::displayTable()
{
    QSqlQuery dptQuery;
    QString str = "SELECT * FROM department";
    if (!dptQuery.exec(str)) {
        qDebug() << "Query execution failed";
        return;
    }
    // set table headers
    ui->tableWidget->setColumnCount(2);
    QStringList labels;
    labels << " " << "Department";
    ui->tableWidget->setHorizontalHeaderLabels(labels);

    // now loop over database seeds and add to the table
    int rowCount = 0;

    while(dptQuery.next()) {
        ui->tableWidget->insertRow(rowCount);
        QTableWidgetItem *department = new QTableWidgetItem;

        department->setText(dptQuery.value(1).toString());

        ui->tableWidget->setItem(rowCount,1,department);

        rowCount++;
    }
}

void Departments::on_addDept_clicked()
{

}


