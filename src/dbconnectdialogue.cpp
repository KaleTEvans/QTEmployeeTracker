#include "headers/dbconnectdialogue.h"
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
    TableStartup setTables;
    QSqlDatabase db = setTables.connectToDb();


    if (db.open()) {
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

