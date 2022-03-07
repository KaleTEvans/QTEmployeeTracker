#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    // connection properties
    QString servername = "DESKTOP-FRBUP45\\SQLEXPRESS";
    QString dbname = "employeeDB";

    db.setConnectOptions();

    QString dsn = QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);

    db.setDatabaseName(dsn);

    if (db.open()) {
        QMessageBox::information(this, "Connection", "Database Connected Successfully");
    } else {
        QMessageBox::information(this, "Not Connected", "Database is NOT Connected");
    }
}

