#include "modifycompanyprofile.h"

#include <QMessageBox>

modifycompanyprofile::modifycompanyprofile(companyaccount* acc, QWidget *parent) :
    QWidget(parent), accToModify(acc)
{
    layout= new QVBoxLayout(this);

    usernModify= new modifyusern(*accToModify, this);
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
