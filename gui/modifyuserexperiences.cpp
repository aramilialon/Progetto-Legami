#include "modifyuserexperiences.h"

modifyuserexperiences::modifyuserexperiences(const useraccount& acc, QWidget *parent) :
    QGroupBox(tr("Experiences"), parent)
{
    layout= new QVBoxLayout(this);
    accToModify= const_cast<useraccount*>(&acc);
    QVector<experience*> expsToModify= accToModify->getexperiences();
    QVector<experience*>::const_iterator itExps=expsToModify.begin();
    for(;itExps!=expsToModify.end();++itExps){
	modifyuserexperience* temp= new modifyuserexperience(*itExps, this);
	expWidget.push_back(temp);
	layout->addWidget(temp);
    }
    addFormativeExp= new QPushButton(tr("Add Formative Exp"), this);
    layout->addWidget(addFormativeExp);
    connect(addFormativeExp, SIGNAL(clicked()), this, SLOT(pushedForm()));

    addWorkingExp= new QPushButton(tr("Add Working Exp"), this);
    layout->addWidget(addWorkingExp);
    connect(addWorkingExp, SIGNAL(clicked()), this, SLOT(pushedWork()));

    QGroupBox::setLayout(layout);
}

void modifyuserexperiences::pushedForm(){
    experience* newForm= new experience(1);
}
