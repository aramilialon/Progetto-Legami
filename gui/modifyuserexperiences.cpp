#include "modifyuserexperiences.h"

modifyuserexperiences::modifyuserexperiences(const useraccount& acc, QWidget *parent) :
    QGroupBox(tr("Experiences"), parent)
{
    layout= new QVBoxLayout(this);
    accToModify= const_cast<useraccount*>(&acc);
    loadExpWidget();
    addFormativeExp= new QPushButton(tr("Add Formative Exp"), this);
    layout->addWidget(addFormativeExp);
    connect(addFormativeExp, SIGNAL(clicked()), this, SLOT(pushedForm()));

    addWorkingExp= new QPushButton(tr("Add Working Exp"), this);
    layout->addWidget(addWorkingExp);
    connect(addWorkingExp, SIGNAL(clicked()), this, SLOT(pushedWork()));

    QGroupBox::setLayout(layout);
}

void modifyuserexperiences::loadExpWidget(){
    if(!expWidget.isEmpty()){
	for(QVector<modifyuserexperience*>::iterator it=expWidget.begin();it!=expWidget.end();++it) delete *it;
	expWidget.erase(expWidget.begin(), expWidget.end());
    }
    QVector<experience*> expsToModify= accToModify->getexperiences();
    QVector<experience*>::const_iterator itExps=expsToModify.begin();
    for(;itExps!=expsToModify.end();++itExps){
	modifyuserexperience* temp= new modifyuserexperience(*itExps, this);
	expWidget.push_back(temp);
	layout->addWidget(temp);
    }
}

void modifyuserexperiences::pushedForm(){
    experience* newForm= new experience(1);
    accToModify->addexperience(*newForm);

    delete layout;
    layout= new QVBoxLayout(this);
    loadExpWidget();
    layout->addWidget(addFormativeExp);
    layout->addWidget(addWorkingExp);

    QGroupBox::setLayout(layout);
}

void modifyuserexperiences::pushedWork(){
    experience* newForm= new experience(0);
    accToModify->addexperience(*newForm);

    delete layout;
    layout= new QVBoxLayout(this);
    loadExpWidget();
    layout->addWidget(addFormativeExp);
    layout->addWidget(addWorkingExp);

    QGroupBox::setLayout(layout);
    QGroupBox::resize(parentWidget()->size());
}

void modifyuserexperiences::modifiedExp(){

}
