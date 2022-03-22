#include "dbconnectdialogue.h"
#include "ui_dbconnectdialogue.h"

DBConnectDialogue::DBConnectDialogue(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DBConnectDialogue)
{
    ui->setupUi(this);
}

DBConnectDialogue::~DBConnectDialogue()
{
    delete ui;
}

void DBConnectDialogue::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    // connection properties
    QString servername = "DESKTOP-FRBUP45\\SQLEXPRESS";
    QString dbname = "employeeDB";

    db.setConnectOptions();

    QString dsn = QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);

    db.setDatabaseName(dsn);

    if (db.open()) {
        TableStartup setTables;

        setTables.setTableSchema();
        setTables.setTableSeeds();
        \
        mainWindow = new MainWindow(this);
        mainWindow->show();
        this->hide();

    } else {
        QMessageBox::information(this, "Not Connected", "Database is NOT Connected");
    }
}

