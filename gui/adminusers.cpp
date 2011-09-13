#include "adminuser.h"
#include "adminusers.h"


adminusers::adminusers(legami* boss, QWidget *parent) :
    QWidget(parent), Boss(boss)
{
    userList= new showuserlist(Boss, this);

    layout= new QGridLayout(this);

    layout->addWidget(userList, 0, 0);

    modifyButton= new QPushButton(tr("Modify"), this);
    connect(modifyButton, SIGNAL(clicked()), this, SLOT(modify()));
    layout->addWidget(modifyButton, 1, 0);

    setLayout(layout);
}

void adminusers::modify(){
    QString selected= userList->selected();
    account* temp= Boss->basicSearch(selected);
    adminuser* adminUser= new adminuser(temp, Boss, this);
    adminUser->show();
}
