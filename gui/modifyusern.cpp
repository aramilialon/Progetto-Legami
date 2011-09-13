#include "../lib/useraccount.h"

#include "modifyusern.h"

#include <QMessageBox>

modifyusern::modifyusern(const account& acc, legami* boss, QWidget *parent) :
    QGroupBox(tr("Account Data"), parent), accToModify(const_cast<account*>(&acc)), Boss(boss)
{
    username* userTemp= accToModify->user();

    layout= new QFormLayout(this);

    usernLineEdit= new QLineEdit(userTemp->user(), this);
    layout->addRow(tr("Username:"), usernLineEdit);

    passwLineEdit= new QLineEdit(userTemp->pass(), this);
    passwLineEdit->setEchoMode(QLineEdit::Password);
    layout->addRow(tr("Password:"), passwLineEdit);

    if(dynamic_cast<useraccount*>(accToModify) && dynamic_cast<useraccount*>(Boss->accountlogged())->getadmin()==1 && accToModify!=Boss->accountlogged()){
        yesadminRadio= new QRadioButton(tr("Yes"), this);
        noadminRadio= new QRadioButton(tr("No"), this);
        layout->addRow(tr("Admin"), yesadminRadio);
        layout->addRow(noadminRadio);
        if(dynamic_cast<useraccount*>(accToModify)->getadmin()==1) yesadminRadio->setChecked(true);
        else noadminRadio->setChecked(true);
    }

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
    if(dynamic_cast<useraccount*>(accToModify) && dynamic_cast<useraccount*>(Boss->accountlogged())->getadmin()==1 && accToModify!=Boss->accountlogged()){
        if(yesadminRadio->isChecked()){
            dynamic_cast<useraccount*>(accToModify)->setadmin(1);
            dynamic_cast<useraccount*>(accToModify)->setype(2);
        }
        else{
            dynamic_cast<useraccount*>(accToModify)->setadmin(0);
            payment* temp= dynamic_cast<useraccount*>(accToModify)->getlastpaymentapproved();
            QMessageBox::information(this, QString(), QString(), QMessageBox::Ok, QMessageBox::Ok);
            if(temp) dynamic_cast<useraccount*>(accToModify)->setype(temp->request());
            else dynamic_cast<useraccount*>(accToModify)->setype(0);
        }
    }
    emit modified(true);
}

void modifyusern::reset(){
    username* userTemp= accToModify->user();
    usernLineEdit->setText(userTemp->user());
    passwLineEdit->setText(userTemp->pass());
    update();
}
