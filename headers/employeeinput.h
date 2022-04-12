#ifndef EMPLOYEEINPUT_H
#define EMPLOYEEINPUT_H

#include <QDialog>

namespace Ui {
class EmployeeInput;
}

class EmployeeInput : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeInput(QWidget *parent = nullptr);
    ~EmployeeInput();
    // public methods to retreive input
    QString getFirstName();
    QString getLastName();
    int getRole();
    int getManager();

private slots:
    void on_okButton_clicked();

signals:
    void okButton();

private:
    Ui::EmployeeInput *ui;
    void clearValues();
    // text variables
    QString firstNameValue;
    QString lastNameValue;
    int roleValue;
    QString managerValue;
};

#endif // EMPLOYEEINPUT_H
