#include "../lib/error.h"

#include "addnewcontact.h"

#include <QMessageBox>

addnewcontact::addnewcontact(account* acc, legami* boss, QWidget *parent) :
    QDialog(parent), accToModify(acc), Boss(boss)
{
    layout= new QFormLayout(this);

    newuserLineEdit= new QLineEdit(this);
    layout->addRow(tr("Username:"), newuserLineEdit);

    okButton= new QPushButton(tr("Add"), this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(addContact()));
    layout->addWidget(okButton);

    cancelButton= new QPushButton(tr("Cancel"), this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    layout->addWidget(cancelButton);

    setLayout(layout);
}

void addnewcontact::addContact(){
    account* temp= Boss->basicSearch(newuserLineEdit->text());
    if(!temp){
	QMessageBox::warning(this, tr("Error"), tr("User not found"), QMessageBox::Ok, QMessageBox::Ok);
    }
    else{
	try{
	    accToModify->addconnection(*temp);
	    QMessageBox::information(this, tr("Ok!"), tr("User succefully added to your contact list."), QMessageBox::Ok, QMessageBox::Ok);
	}
	catch(error er1){
	    QMessageBox::warning(this, tr("Error"), er1.comment(), QMessageBox::Ok, QMessageBox::Ok);
	}
    }

    close();
}
