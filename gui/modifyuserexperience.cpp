#include "modifyuserexperience.h"

modifyuserexperience::modifyuserexperience(experience* exp, QWidget *parent) :
    QGroupBox(parent)
{
    expToModify=exp;
    if(expToModify->type()==0) QGroupBox::setTitle(tr("Work Experience"));
    else QGroupBox::setTitle(tr("Formative Experience"));

    layoutEdit= new QFormLayout(this);
    layout= new QGridLayout(this);

    nameLineEdit= new QLineEdit(expToModify->espname(), this);
    layoutEdit->addRow(tr("Name:"), nameLineEdit);

    dateDateEdit= new QDateEdit(expToModify->espdate(), this);
    layoutEdit->addRow(tr("Date exp:"), dateDateEdit);

    descrLineEdit= new QLineEdit(expToModify->descr(), this);
    layoutEdit->addRow(tr("Description:"), descrLineEdit);

    layout->addLayout(layoutEdit, 0, 0);

    modifyButton= new QPushButton(tr("Modify"), this);
    connect(modifyButton, SIGNAL(clicked()), this, SLOT(modifyExp()));
    layout->addWidget(modifyButton, 1, 0);

    cancelButton= new QPushButton(tr("Cancel"), this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    layout->addWidget(cancelButton, 1, 1);

    QGroupBox::setLayout(layout);
}

void modifyuserexperience::modifyExp(){

}

void modifyuserexperience::cancel(){

}
