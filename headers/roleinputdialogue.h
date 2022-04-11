#ifndef ROLEINPUTDIALOGUE_H
#define ROLEINPUTDIALOGUE_H

#include <QWidget>

namespace Ui {
class RoleInputDialogue;
}

class RoleInputDialogue : public QWidget
{
    Q_OBJECT

public:
    explicit RoleInputDialogue(QWidget *parent = nullptr);
    ~RoleInputDialogue();

private:
    Ui::RoleInputDialogue *ui;
};

#endif // ROLEINPUTDIALOGUE_H
