#ifndef DEPARTMENTS_H
#define DEPARTMENTS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtGui>
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

private:
    Ui::Departments *ui;

};

#endif // DEPARTMENTS_H
