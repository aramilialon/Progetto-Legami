#include "modifyuserprofile.h"

modifyuserprofile::modifyuserprofile(const useraccount & acc, QWidget *parent):
    QWidget(parent), accToModify(const_cast<useraccount*>(&acc))
{
    layout= new QVBoxLayout(this);

    usernModify= new modifyusern(acc, this);
    layout->addWidget(usernModify);

    setLayout(layout);
}
