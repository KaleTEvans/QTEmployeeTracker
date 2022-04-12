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
        QTableWidgetItem *managerId = new QTableWidgetItem;

        firstName->setText(employeeQuery->value(1).toString());
        lastName->setText(employeeQuery->value(2).toString());
        roleId->setText(employeeQuery->value(3).toString());
        // if the manager value is null, we should add N/A here
        if (employeeQuery->value(4) != NULL) {
            managerId->setText(employeeQuery->value(4).toString());
        } else {
            managerId->setText("N/A");
        }

        ui->tableWidget->setItem(rowCount,1,firstName);
        ui->tableWidget->setItem(rowCount,2,lastName);
        ui->tableWidget->setItem(rowCount,3,roleId);
        ui->tableWidget->setItem(rowCount,4,managerId);

        rowCount++;
    }
}

void Employees::onOkButtonClicked()
{
    firstName = employeeInput->getFirstName();
    lastName = employeeInput->getLastName();
    roleId = employeeInput->getRole();
    managerId = employeeInput->getManager();
    delete employeeInput;

    if (!firstName.isEmpty() && !lastName.isEmpty()) {
        QSqlQuery query;
        query.prepare("INSERT INTO employees (first_name, last_name, role_id, manager_id) VALUES (?,?,?,?)");
        query.addBindValue(firstName);
        query.addBindValue(lastName);
        query.addBindValue(roleId);
        if (!managerId) {
            // equivalent of adding a null value
            query.addBindValue(QVariant());
        } else {
            query.addBindValue(managerId);
        }

        if (!query.exec()) {
            qDebug() << "Query execution failed";
            return;
        }
        // refresh table
        displayTable();
    }
}

void Employees::on_addEmployee_clicked()
{
    employeeInput = new EmployeeInput(this);
    QObject::connect(employeeInput, SIGNAL(okButton()), this, SLOT(onOkButtonClicked()));
    employeeInput->show();
}

void Employees::on_removeEmployee_clicked()
{
    if (cellClicked) {
        QSqlQuery query;
        query.prepare("DELETE FROM employees WHERE employee_id = ?");
        query.addBindValue(rowSelected);
        if (!query.exec()) {
            qDebug() << "Query execution failed";
            return;
        }

        displayTable();
        cellClicked = false;
    }
}


void Employees::on_editRole_clicked()
{
    if (cellClicked) {
        bool ok;
        int newRole = QInputDialog::getInt(this, tr("Update Employee Role"), tr("Role:"),
                                             0, INT_MIN, INT_MAX, 1, &ok);

        if (ok && newRole) {
            QSqlQuery query;
            query.prepare("UPDATE employees SET role_id = ? WHERE employee_id = ?");
            query.addBindValue(newRole);
            query.addBindValue(rowSelected);
            if (!query.exec()) {
                qDebug() << "Query execution failed";
                return;
            }

            displayTable();

            cellClicked = false;
        }
    }
}


void Employees::on_tableWidget_cellClicked(int row, int column)
{
    cellClicked = true;
    rowSelected = row+1;
}

