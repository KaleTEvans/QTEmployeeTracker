#include "headers/roles.h"
#include "ui_roles.h"
#include <QAbstractItemView>

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
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

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

void Roles::onOKButtonClicked()
{
    title = roleInput->getTitle();
    salary = roleInput->getSalary();
    departmentId = roleInput->getDeptValue();
    delete roleInput;
    if (!title.isEmpty() && !salary.isEmpty()) {
         QSqlQuery query;
         query.prepare("INSERT INTO roles (title, salary, department_id) VALUES (?,?,?)");
         query.addBindValue(title);
         query.addBindValue(salary);
         query.addBindValue(departmentId);

         if (!query.exec()) {
             qDebug() << "Query execution failed";
             return;
             }
    }
    // refresh table
    displayTable();
}

void Roles::on_addRole_clicked()
{
    roleInput = new RoleInput(this);
    QObject::connect(roleInput, SIGNAL(okButton()), this, SLOT(onOKButtonClicked()));
    roleInput->show();
}


void Roles::on_deleteRole_clicked()
{
    if (cellClicked) {
        QSqlQuery query;
        query.prepare("DELETE FROM roles WHERE role_id = ?");
        query.addBindValue(rowSelected);
        if (!query.exec()) {
            qDebug() << "Query execution failed";
            return;
        }

        displayTable();
        // set cellClicked back to false
        cellClicked = false;
    }
}

void Roles::on_tableWidget_cellClicked(int row, int column)
{
    // set these values to send to button functions when clicked
    cellClicked = true;
    rowSelected = row+1;
}


