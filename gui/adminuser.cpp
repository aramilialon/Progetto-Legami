#include "../lib/companyaccount.h"
#include "../lib/useraccount.h"

#include "adminuser.h"
#include "modifycompanyprofile.h"
#include "modifyuserprofile.h"

adminuser::adminuser(account* acc, legami* boss, QWidget *parent) :
    QDialog(parent), accToModify(acc), Boss(boss)
{
    layout= new QGridLayout(this);

    if(dynamic_cast<useraccount*>(accToModify)) modifyWidget= new modifyuserprofile(*(dynamic_cast<useraccount*>(accToModify)), Boss, this);
    else modifyWidget= new modifycompanyprofile(dynamic_cast<companyaccount*>(accToModify), Boss, this);

    mainWidget= new QScrollArea(this);
    mainWidget->setWidget(modifyWidget);
    layout->addWidget(mainWidget, 0, 0);

    finishButton= new QPushButton(tr("Finish"), this);
    connect(finishButton, SIGNAL(clicked()), this, SLOT(close()));
    layout->addWidget(finishButton);

}
