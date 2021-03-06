#include "../lib/experience.h"
#include "showuserexperieces.h"

showuserexperieces::showuserexperieces(const account & acc, QWidget *parent) :
    QGroupBox(tr("Experiences"), parent), accToShow(dynamic_cast<useraccount*>(const_cast<account*>(&acc)))
{
    layout= new QVBoxLayout(this);
    QVector<experience*> expsVector= accToShow->getexperiences();
    for(QVector<experience*>::iterator it=expsVector.begin(); it!=expsVector.end();++it){
        showuserexperience* temp= new showuserexperience(*it, this);
        exps.push_back(temp);
        layout->addWidget(temp);
    }
}
