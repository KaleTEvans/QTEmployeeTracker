#ifndef ROLEINPUT_H
#define ROLEINPUT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class RoleInput;
}

class RoleInput : public QDialog
{
    Q_OBJECT

public:
    explicit RoleInput(QWidget *parent = nullptr);
    ~RoleInput();
    // will use public methods to retreive input
    QString getTitle();
    QString getSalary();
    int getDeptValue();

private slots:
    void on_okButton_clicked();

signals:
    void okButton();

private:
    Ui::RoleInput *ui;
    void clearValues();
    // text variables
    QString titleValue;
    QString salaryValue;
    int departmentValue;

};

#endif // ROLEINPUT_H
