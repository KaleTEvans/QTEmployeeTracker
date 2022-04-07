#include "roleinput.h"
#include "ui_roleinput.h"

RoleInput::RoleInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoleInput)
{
    ui->setupUi(this);
}

RoleInput::~RoleInput()
{
    delete ui;
}

void RoleInput::clearValues()
{
    ui->titleEdit->clear();
    ui->salaryEdit->clear();
    ui->departmentEdit->clear();
}

void RoleInput::on_okButton_clicked()
{
    titleValue = ui->titleEdit->displayText();
    salaryValue = ui->salaryEdit->displayText();
    departmentValue = ui->departmentEdit->value();

    if (!titleValue.isEmpty() && !salaryValue.isEmpty()) {
        QSqlQuery query;
        query.prepare("INSERT INTO roles (title, salary, department_id) VALUES (?,?,?)");
        query.addBindValue(titleValue);
        query.addBindValue(salaryValue);
        query.addBindValue(departmentValue);

        if (!query.exec()) {
            qDebug() << "Query execution failed";
            return;
        }
    }

    emit okButton();
}




