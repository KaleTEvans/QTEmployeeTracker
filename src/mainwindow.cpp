#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/tablestartup.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // set up widgets
    departments = new Departments();
    roles = new Roles();
    // add tabs with the page widgets
    ui->tabWidget->addTab(departments, "Departments");
    ui->tabWidget->addTab(roles, "Roles");
    // call member functions to display the tables
    departments->displayTable();
    roles->displayTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}




