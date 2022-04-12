#include "headers/employeeinput.h"
#include "ui_employeeinput.h"

EmployeeInput::EmployeeInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeInput)
{
    ui->setupUi(this);
    // set window title
    this->setWindowTitle("Add Employee");
}

EmployeeInput::~EmployeeInput()
{
    delete ui;
}

void EmployeeInput::clearValues()
{
    ui->firstNameEdit->clear();
    ui->lastNameEdit->clear();
    ui->roleBox->clear();
    ui->managerEdit->clear();
}

void EmployeeInput::on_okButton_clicked()
{
    firstNameValue = ui->firstNameEdit->displayText();
    lastNameValue = ui->lastNameEdit->displayText();
    roleValue = ui->roleBox->value();
    managerValue = ui->managerEdit->displayText();

    emit okButton();
}

QString EmployeeInput::getFirstName()
{
    return firstNameValue;
}

QString EmployeeInput::getLastName()
{
    return lastNameValue;
}

int EmployeeInput::getRole()
{
    return roleValue;
}

int EmployeeInput::getManager()
{
    if (managerValue.isEmpty()) {
        return NULL;
    } else {
        int managerNumber = managerValue.toInt();
        return managerNumber;
    }
}

