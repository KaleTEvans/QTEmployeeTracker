#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tablestartup.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // set up widgets
    departments = new Departments();
    // add tabs with the page widgets
    ui->tabWidget->addTab(departments, "Departments");
    // call member functions to display the tables
    departments->displayTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}




