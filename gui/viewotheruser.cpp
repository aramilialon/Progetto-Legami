#include "../lib/companyaccount.h"
#include "../lib/useraccount.h"
#include "showcompanyprofile.h"
#include "showuserprofile.h"
#include "viewotheruser.h"


viewotheruser::viewotheruser(account* acc, legami* boss, QWidget *parent) :
    QDialog(parent), accToShow(acc), Boss(boss)
{
    layout= new QVBoxLayout(this);
    if(dynamic_cast<useraccount*>(accToShow)) MainWidget= new showuserprofile(*accToShow, Boss, this);
    else MainWidget= new showcompanyprofile(*accToShow, Boss, this);
    layout->addWidget(MainWidget);

    okButton= new QPushButton(tr("Close"), this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(ok()));

    layout->addWidget(okButton);

    setLayout(layout);
}

void viewotheruser::ok(){
    close();
}
