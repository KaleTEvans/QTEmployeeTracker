#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/tablestartup.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // set up window title and icon
    this->setWindowTitle("Employee Database");
    // set up widgets
    departments = new Departments();
    roles = new Roles();
    employees = new Employees();
    // add tabs with the page widgets
    ui->tabWidget->addTab(departments, "Departments");
    ui->tabWidget->addTab(roles, "Roles");
    ui->tabWidget->addTab(employees, "Employees");
    // call member functions to display the tables
    departments->displayTable();
    roles->displayTable();
    employees->displayTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}




