#ifndef DEPARTMENTS_H
#define DEPARTMENTS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtGui>
#include <QInputDialog>
#include "tablestartup.h"


namespace Ui {
class Departments;
}

class Departments : public QWidget
{
    Q_OBJECT

public:
    explicit Departments(QWidget *parent = nullptr);
    ~Departments();
    void displayTable();

private slots:
    void on_addDept_clicked();
    void on_removeDept_clicked();
    void on_editDept_clicked();
    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::Departments *ui;
    QSqlQuery *dptQuery;
    bool cellClicked;
    int rowSelected;
};

#endif // DEPARTMENTS_H
