#include "../lib/username.h"
#include "../lib/useraccount.h"
#include "showuserprofile.h"

showuserprofile::showuserprofile(const account& acc, legami* Boss, QWidget *parent) :
        QWidget(parent), boss(Boss), accToShow(const_cast<account*>(&acc))
{
        layout= new QVBoxLayout(this);

        userns= new showusern(accToShow, boss, this);
        layout->addWidget(userns);

        infos=new showuserinfo(*accToShow, this);
        layout->addWidget(infos);

        if(!(dynamic_cast<useraccount*>(accToShow)->getexperiences().isEmpty())){
        exps= new showuserexperieces(*accToShow, this);
        layout->addWidget(exps);
        }
        else exps=0;

        setLayout(layout);

        parent->setWindowTitle(tr("Legami - Profile Page"));
}
