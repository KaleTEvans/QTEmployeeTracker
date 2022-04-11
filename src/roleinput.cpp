#include "headers/roleinput.h"
#include "ui_roleinput.h"

RoleInput::RoleInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoleInput)
{
    ui->setupUi(this);
    // set window title
    this->setWindowTitle("Add Role");
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

    emit okButton();
}

QString RoleInput::getTitle()
{
    return titleValue;
}

QString RoleInput::getSalary()
{
    return salaryValue;
}

int RoleInput::getDeptValue()
{
    return departmentValue;
}


