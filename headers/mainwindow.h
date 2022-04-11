#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <iostream>
#include <QTabWidget>
#include "headers/departments.h"
#include "headers/roles.h"
#include "headers/employees.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    QTabWidget *tabSelect;
    Departments *departments;
    Roles *roles;
    Employees *employees;
};
#endif // MAINWINDOW_H
