#include "removecontact.h"

#include <QMessageBox>

removecontact::removecontact(account* acc, legami* boss, QWidget *parent) :
    QDialog(parent), accToModify(acc), Boss(boss)
{
    layout=new QGridLayout(this);

    textLabel= new QLabel(tr("Select the account to remove from your connection list."), this);
    layout->addWidget(textLabel, 0, 0);

    showList= new showcontacts(accToModify, Boss, this);
    layout->addWidget(showList, 1, 0);

    okButton= new QPushButton(tr("Remove"), this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(modify()));
    layout->addWidget(okButton, 2, 0);

    cancelButton= new QPushButton(tr("Cancel"), this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    layout->addWidget(cancelButton, 2, 1);

    setLayout(layout);
}

void removecontact::modify(){
    account* temp=Boss->basicSearch(showList->sel());
    if(!temp){
	QMessageBox::information(this, tr("Error"), tr("Account not found"), QMessageBox::Ok, QMessageBox::Ok);
    }
    else{
	accToModify->removeconnection(*temp);
	QMessageBox::warning(this, tr("Done"), tr("Account remove from your connection list."), QMessageBox::Ok, QMessageBox::Ok);
    }
    close();
}
