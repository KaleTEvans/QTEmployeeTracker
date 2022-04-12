QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/employeeinput.cpp \
    src/dbconnectdialogue.cpp \
    src/departments.cpp \
    src/employees.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/roleinput.cpp \
    src/roles.cpp \
    src/tablestartup.cpp

HEADERS += \
    headers/dbconnectdialogue.h \
    headers/departments.h \
    headers/employeeinput.h \
    headers/mainwindow.h \
    headers/roleinput.h \
    headers/roles.h \
    headers/tablestartup.h \
    headers/employees.h

FORMS += \
    forms/dbconnectdialogue.ui \
    forms/departments.ui \
    forms/mainwindow.ui \
    forms/roleinput.ui \
    forms/roles.ui \
    forms/employees.ui \
    forms/employeeinput.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
