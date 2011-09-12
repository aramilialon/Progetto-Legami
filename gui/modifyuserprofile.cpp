#include "modifyuserprofile.h"


#include <QMessageBox>

modifyuserprofile::modifyuserprofile(const useraccount & acc, legami* boss, QWidget *parent):
    QWidget(parent), accToModify(const_cast<useraccount*>(&acc)), Boss(boss)
{
    layout= new QVBoxLayout(this);

    usernModify= new modifyusern(acc, Boss, this);
    layout->addWidget(usernModify);
    connect(usernModify, SIGNAL(modified(bool)), this, SLOT(modified(bool)));

    infosModify= new modifyuserinfos(acc, Boss, this);
    connect(infosModify, SIGNAL(modified(bool)), this, SLOT(modified(bool)));
    layout->addWidget(infosModify);

    expsModify= new modifyuserexperiences(acc, Boss, this);
    connect(expsModify, SIGNAL(modifiedlist()), this, SLOT(modexp()));
    layout->addWidget(expsModify);

    setLayout(layout);

    parent->setWindowTitle(tr("Legami - Modify Profile Page"));
}

void modifyuserprofile::modified(bool mod){
    if(mod){
	QMessageBox::information(this, tr("Data Modified!"), tr("The data has been modified successfully."), QMessageBox::Ok, QMessageBox::Ok);
    }
    else{
	QMessageBox::warning(this, tr("Error"), tr("Are you sure you are enabled to modify those data?"), QMessageBox::Ok, QMessageBox::Ok);
    }
}

void modifyuserprofile::modexp(){
    emit modifiedlist();
}
