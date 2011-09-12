#include "../lib/username.h"
#include "showusern.h"


showusern::showusern(account* acc, legami* Boss, QWidget *parent) :
    QGroupBox(tr("Account Data"), parent), boss(Boss)
{
    usernToShow= acc->user();
    usernLineEdit= new QLineEdit(usernToShow->user());
    usernLineEdit->setReadOnly(true);
    if(Boss->accountlogged()==acc){
        passwLineEdit= new QLineEdit(usernToShow->pass());
        passwLineEdit->setEchoMode(QLineEdit::Password);
        passwLineEdit->setReadOnly(true);
    }
    else passwLineEdit = 0;
    layout= new QFormLayout(this);
    layout->addRow(tr("Username:"), usernLineEdit);
    if(passwLineEdit) layout->addRow(tr("Password:"), passwLineEdit);
    typeLineEdit= new QLineEdit(this);
    if(acc->type()==0) typeLineEdit->setText(tr("Basic Account"));
    else if(acc->type()==1) typeLineEdit->setText(tr("Business Account"));
    else typeLineEdit->setText(tr("Executive Account"));
    typeLineEdit->setReadOnly(true);
    layout->addRow(tr("Account type:"), typeLineEdit);
    setLayout(layout);
}
