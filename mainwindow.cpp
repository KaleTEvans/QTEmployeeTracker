#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::clearValues()
{
    ui->lineEditQuery->clear();
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

        clearValues();

        QString query = "CREATE TABLE department ("
                        "id int identity(1,1) primary key,"
                        "name VARCHAR(30));";

        QSqlQuery databaseQuery;

        if (!databaseQuery.exec(query)) {
            qDebug() << "Error creating table:" << databaseQuery.lastError().text() << "\n";
        }

        databaseQuery.prepare("INSERT INTO department (name) VALUES (:name)");
        databaseQuery.bindValue(":name", "Sales");
        databaseQuery.exec();

//        QSqlQuery qry("SELECT name FROM department");
//        while (qry.next()) {
//            QString name = qry.value(0).toString();
//            qDebug() << "Data: " << name;
//        }
    } else {
        QMessageBox::information(this, "Not Connected", "Database is NOT Connected");
    }

}

