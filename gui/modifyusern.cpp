#include "modifyusern.h"


modifyusern::modifyusern(const useraccount& acc, QWidget *parent) :
    QGroupBox(tr("Account Data"), parent), accToModify(const_cast<useraccount*>(&acc))
{
    username* userTemp= accToModify->user();

    layout= new QFormLayout(this);

    usernLineEdit= new QLineEdit(userTemp->user(), this);
    layout->addRow(tr("Username:"), usernLineEdit);

    passwLineEdit= new QLineEdit(userTemp->pass(), this);
    passwLineEdit->setEchoMode(QLineEdit::Password);
    layout->addRow(tr("Password:"), passwLineEdit);

    okButton= new QPushButton(tr("Modify"), this);
    layout->addWidget(okButton);

    cancelButton= new QPushButton(tr("Reset"), this);
    layout->addWidget(cancelButton);

    connect(okButton, SIGNAL(clicked()), this, SLOT(modify()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reset()));

    QGroupBox::setLayout(layout);
}

void modifyusern::modify(){
    accToModify->setuser(usernLineEdit->text(), passwLineEdit->text());
    emit modified(true);
}

void modifyusern::reset(){
    username* userTemp= accToModify->user();
    usernLineEdit->setText(userTemp->user());
    passwLineEdit->setText(userTemp->pass());
    update();
}
