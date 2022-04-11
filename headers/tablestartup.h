#ifndef TABLESTARTUP_H
#define TABLESTARTUP_H

#include <QtSql>
#include <QSqlDatabase>

class TableStartup
{
public:
    TableStartup();
    // Schema and Seed functions
    QSqlDatabase connectToDb();
    void setTableSchema();
    void setTableSeeds();
};

#endif // TABLESTARTUP_H
