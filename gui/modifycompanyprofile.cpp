#include "modifycompanyprofile.h"

#include <QMessageBox>

modifycompanyprofile::modifycompanyprofile(companyaccount* acc, legami* boss, QWidget *parent) :
    QWidget(parent), accToModify(acc), Boss(boss)
{
    layout= new QVBoxLayout(this);

    usernModify= new modifyusern(*accToModify, Boss, this);
    connect(usernModify, SIGNAL(modified(bool)), this, SLOT(modified(bool)));
    layout->addWidget(usernModify);

    infosModify= new modifycompanyinfos(accToModify, this);
    connect(infosModify, SIGNAL(modified(bool)), this, SLOT(modified(bool)));
    layout->addWidget(infosModify);

    setLayout(layout);
}

void modifycompanyprofile::modified(bool mod){
    if(mod){
	QMessageBox::information(this, tr("Data Modified!"), tr("The data has been modified successfully."), QMessageBox::Ok, QMessageBox::Ok);
    }
}
