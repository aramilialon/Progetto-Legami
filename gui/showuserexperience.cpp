#include "showuserexperience.h"

#include <QString>

showuserexperience::showuserexperience(experience* exp, QWidget *parent) :
    QGroupBox(parent), expToShow(const_cast<experience*>(exp))
{
    layout= new QFormLayout(this);

    QString type=QString("");
    if(expToShow->type()==0){
        type=QString("Working");
        setTitle(tr("Working Experience"));
    }
    else{
        type= QString("Formative");
        setTitle(tr("Formative Experience"));
    }

    typeLineEdit= new QLineEdit(type, this);
    layout->addRow(tr("Type:"), typeLineEdit);

    expnameLineEdit= new QLineEdit(exp->espname(), this);
    layout->addRow(tr("Name:"), expnameLineEdit);

    expdateDateEdit= new QDateEdit(exp->espdate(), this);
    layout->addRow(tr("Experience date:"), expdateDateEdit);

    descrLineEdit= new QLineEdit(exp->descr(), this);
    layout->addRow(tr("Description"), descrLineEdit);

    setLayout(layout);
}
