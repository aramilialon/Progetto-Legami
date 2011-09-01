#include "../lib/username.h"
#include "showusern.h"


showusern::showusern(account* acc, legami* Boss, QWidget *parent) :
    QGroupBox(tr("Account Data"), parent), boss(Boss)
{
    usernToShow= acc->user();
    usernLineEdit= new QLineEdit(usernToShow->user());
    usernLineEdit->setReadOnly(true);
    if(boss->accountlogged()==acc){
        passwLineEdit= new QLineEdit(usernToShow->pass());
        passwLineEdit->setEchoMode(QLineEdit::Password);
        passwLineEdit->setReadOnly(true);
    }
    else passwLineEdit = 0;
    layout= new QFormLayout(this);
    layout->addRow(tr("Username:"), usernLineEdit);
    if(passwLineEdit) layout->addRow(tr("Password:"), passwLineEdit);
    setLayout(layout);
}