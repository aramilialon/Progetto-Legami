#include "showcompanyprofile.h"

showcompanyprofile::showcompanyprofile(const account & acc, legami* Boss, QWidget *parent) :
    QWidget(parent), boss(Boss), accToShow(const_cast<account*>(&acc))
{
    layout= new QVBoxLayout(this);

    usern= new showusern(accToShow, boss, this);
    layout->addWidget(usern);

    infos= new showcompanyinfo(*accToShow, this);
    layout->addWidget(infos);

    setLayout(layout);
}
