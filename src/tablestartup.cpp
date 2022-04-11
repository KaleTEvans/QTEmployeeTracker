#include "headers/tablestartup.h"

TableStartup::TableStartup()
{

}

QSqlDatabase TableStartup::connectToDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    // connection properties
    QString servername = "DESKTOP-FRBUP45\\SQLEXPRESS";
    QString dbname = "employeeDB";

    db.setConnectOptions();

    QString dsn = QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);

    db.setDatabaseName(dsn);

    return db;
}

void TableStartup::setTableSchema()
{
    QSqlQuery dbQuery;
    // Drop the table and create a new one upon program start
    dbQuery.exec("DROP TABLE IF EXISTS employees");
    dbQuery.exec("DROP TABLE IF EXISTS roles");
    dbQuery.exec("DROP TABLE IF EXISTS department");

    QString qDepartment = "CREATE TABLE department ("
                            "department_id INT IDENTITY(1,1) PRIMARY KEY,"
                            "name VARCHAR(30));";

    if (!dbQuery.exec(qDepartment)) {
        qDebug() << "Error creating department table:" << dbQuery.lastError().text() << "\n";
    }

    QString qRoles = "CREATE TABLE roles ("
                        "role_id INT IDENTITY(1,1) PRIMARY KEY,"
                        "title VARCHAR(30) NOT NULL,"
                        "salary DECIMAL(10, 0) NOT NULL,"
                        "department_id INT NOT NULL,"
                        "FOREIGN KEY (department_id) REFERENCES department(department_id) ON DELETE CASCADE ON UPDATE CASCADE);";

    if (!dbQuery.exec(qRoles)) {
        qDebug() << "Error creating role table:" << dbQuery.lastError().text() << "\n";
    }

    QString qEmployees = "CREATE TABLE employees ("
                            "employee_id INT IDENTITY(1,1) NOT NULL PRIMARY KEY,"
                            "first_name VARCHAR(30) NOT NULL,"
                            "last_name VARCHAR(30) NOT NULL,"
                            "role_id int NOT NULL,"
                            "manager_id INT DEFAULT NULL,"
                            "FOREIGN KEY (role_id) REFERENCES roles(role_id) ON DELETE CASCADE ON UPDATE CASCADE,"
                            "FOREIGN KEY (manager_id) REFERENCES employees(employee_id));";

    if (!dbQuery.exec(qEmployees)) {
        qDebug() << "Error creating employee table:" << dbQuery.lastError().text() << "\n";
    }



}

/***** SEEDS *****/
void TableStartup::setTableSeeds()
{
    QSqlQuery dbQuery;

    // department seeds
    dbQuery.exec("INSERT INTO department (name) VALUES ('Accounting'), ('Sales'), ('Executive'), ('Engineering')");

    // role seeds
    dbQuery.exec("INSERT INTO roles (title, salary, department_id) VALUES"
                 "('Software Engineer', '95000', 4),"
                 "('Accountant', '60000', 1),"
                 "('Sales Lead', '120000', 2),"
                 "('Branch Manager', '300000', 3);");
}
