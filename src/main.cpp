#include "mainwindow.h"
#include "headers/dbconnectdialogue.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBConnectDialogue w;
    w.show();
    return a.exec();
}
