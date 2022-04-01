#ifndef ROLES_H
#define ROLES_H

#include <QWidget>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtGui>
#include <QInputDialog>
#include "tablestartup.h"

namespace Ui {
class Roles;
}

class Roles : public QWidget
{
    Q_OBJECT

public:
    explicit Roles(QWidget *parent = nullptr);
    ~Roles();
    void displayTable();

private:
    Ui::Roles *ui;
    QSqlQuery *roleQuery;
    bool cellClicked;
    int rowSelected;
};

#endif // ROLES_H
