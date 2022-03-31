#include "departments.h"
#include "ui_departments.h"

Departments::Departments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Departments)
{
    ui->setupUi(this);
    dptQuery = new QSqlQuery();
    cellClicked = false;
    rowSelected = 1000;
}

Departments::~Departments()
{
    delete ui;
}

void Departments::displayTable()
{
    //clear table and refresh when updating values
    ui->tableWidget->setRowCount(0);

    QString str = "SELECT * FROM department";
    if (!dptQuery->exec(str)) {
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

    while(dptQuery->next()) {
        ui->tableWidget->insertRow(rowCount);
        QTableWidgetItem *department = new QTableWidgetItem;

        department->setText(dptQuery->value(1).toString());

        ui->tableWidget->setItem(rowCount,1,department);

        rowCount++;
    }
}

void Departments::on_addDept_clicked()
{
    // open dialog box to input department name
    bool ok;
    QString text = QInputDialog::getText(this, tr("Add Department"), tr("Department:"),
                                         QLineEdit::Normal, QDir::home().dirName(), &ok);

    if (ok && !text.isEmpty()) {
        QSqlQuery query;
        query.prepare("INSERT INTO department (name) values (?)");
        query.addBindValue(text);
        if (!query.exec()) {
            qDebug() << "Query execution failed";
            return;
        }

        displayTable();
    }
}

void Departments::on_removeDept_clicked()
{
    if (cellClicked) {
        QSqlQuery query;
        query.prepare("DELETE FROM department WHERE department_id = ?");
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

void Departments::on_editDept_clicked()
{
    if (cellClicked) {
        // open dialog box to input department name
        bool ok;
        QString text = QInputDialog::getText(this, tr("Update Department"), tr("Department:"),
                                             QLineEdit::Normal, QDir::home().dirName(), &ok);

        if (ok && !text.isEmpty()) {
            QSqlQuery query;
            query.prepare("UPDATE department SET name = ? WHERE department_id = ?");
            query.addBindValue(text);
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

void Departments::on_tableWidget_cellClicked(int row, int column)
{
    // set these values to send to button functions when clicked
    cellClicked = true;
    rowSelected = row+1;
}




