#ifndef EMPLOYEEDATABASE_H
#define EMPLOYEEDATABASE_H

#include <QMainWindow>

namespace Ui {
class EmployeeDatabase;
}

class EmployeeDatabase : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeeDatabase(QWidget *parent = nullptr);
    ~EmployeeDatabase();

private:
    Ui::EmployeeDatabase *ui;
};

#endif // EMPLOYEEDATABASE_H
