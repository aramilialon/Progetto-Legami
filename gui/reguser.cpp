/*
  File: reguser.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "../lib/account.h"
#include "../lib/companyaccount.h"
#include "../lib/error.h"
#include "../lib/legami.h"
#include "../lib/useraccount.h"
#include "reguser.h"

#include <QDialogButtonBox>
#include <QMessageBox>

reguser::reguser(legami* boss, QWidget *parent) :
    QDialog(parent), Boss(boss)
{

    layout= new QFormLayout(this);

    QDialogButtonBox* buttonLayout= new QDialogButtonBox(this);
    okButton= new QPushButton(tr("Register"), this);
    cancelButton= new QPushButton(tr("Cancel"), this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(reginto()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    buttonLayout->addButton(okButton, QDialogButtonBox::YesRole);
    buttonLayout->addButton(cancelButton, QDialogButtonBox::RejectRole);

    usernLineEdit= new QLineEdit(this);
    passwLineEdit= new QLineEdit(this);
    passwLineEdit->setEchoMode(QLineEdit::Password);

    userRadio= new QRadioButton(tr("User Account"), this);
    companyRadio= new QRadioButton(tr("Company Account"), this);
    userRadio->setChecked(true);

    layout->addRow(tr("Username:"), usernLineEdit);
    layout->addRow(tr("Password:"), passwLineEdit);
    layout->addRow(userRadio);
    layout->addRow(companyRadio);
    layout->addWidget(buttonLayout);
    setLayout(layout);
}

void reguser::reginto(){
    if(!usernLineEdit->text().isNull() && !passwLineEdit->text().isNull()){
        account* temp=0;
        if(userRadio->isChecked()){
            temp= new useraccount(usernLineEdit->text(), passwLineEdit->text(), 0, *Boss);
            useraccount* temp2=dynamic_cast<useraccount*>(temp);
            temp2->setadmin(0);
        }
        else{
            temp= new companyaccount(usernLineEdit->text(), passwLineEdit->text(), 0, *Boss);
        }
        bool wrong=false;
        try{
            Boss->addAccount(*temp);
        }
        catch(error er1){
            delete temp;
            QMessageBox::warning(this, tr("Duplicate account"), tr("Error! There is an already existing account with the same username."), QMessageBox::Ok, QMessageBox::Ok);
            wrong=true;
        }
        if(wrong) emit registered(false);
        else emit registered(true);
    }
    else{
        emit registered(true);
    }
    close();
}
