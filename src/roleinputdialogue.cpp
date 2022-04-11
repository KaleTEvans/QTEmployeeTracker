#include "roleinputdialogue.h"
#include "ui_roleinputdialogue.h"

RoleInputDialogue::RoleInputDialogue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoleInputDialogue)
{
    ui->setupUi(this);
}

RoleInputDialogue::~RoleInputDialogue()
{
    delete ui;
}
