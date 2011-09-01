#include "modifyuserprofile.h"

#include <QMessageBox>

modifyuserprofile::modifyuserprofile(const useraccount & acc, QWidget *parent):
    QWidget(parent), accToModify(const_cast<useraccount*>(&acc))
{
    layout= new QVBoxLayout(this);

    usernModify= new modifyusern(acc, this);
    layout->addWidget(usernModify);
    connect(usernModify, SIGNAL(modified(bool)), this, SLOT(modified(bool)));

    setLayout(layout);
}

void modifyuserprofile::modified(bool mod){
    if(mod){
	QMessageBox::information(this, tr("Data Modified!"), tr("The data has been modified successfully."), QMessageBox::Ok, QMessageBox::Ok);
    }
}
