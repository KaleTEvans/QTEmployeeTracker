#ifndef DBCONNECTDIALOGUE_H
#define DBCONNECTDIALOGUE_H

#include <QMainWindow>
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <iostream>
#include "tablestartup.h"
#include "mainwindow.h"

namespace Ui {
class DBConnectDialogue;
}

class DBConnectDialogue : public QMainWindow
{
    Q_OBJECT

public:
    explicit DBConnectDialogue(QWidget *parent = nullptr);
    ~DBConnectDialogue();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DBConnectDialogue *ui;
    MainWindow *mainWindow;
};

#endif // DBCONNECTDIALOGUE_H
