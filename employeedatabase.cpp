#include "employeedatabase.h"
#include "ui_employeedatabase.h"

EmployeeDatabase::EmployeeDatabase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EmployeeDatabase)
{
    ui->setupUi(this);
}

EmployeeDatabase::~EmployeeDatabase()
{
    delete ui;
}
