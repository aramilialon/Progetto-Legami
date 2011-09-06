#include "modifyuserexperience.h"

modifyuserexperience::modifyuserexperience(experience* exp, useraccount* acc, QWidget *parent) :
    QGroupBox(parent), ouwner(acc)
{
    expToModify=exp;
    if(expToModify->type()==0) QGroupBox::setTitle(tr("Work Experience"));
    else QGroupBox::setTitle(tr("Formative Experience"));

    layout= new QGridLayout(this);

    nameLineEdit= new QLineEdit(expToModify->espname(), this);
    nameLabel= new QLabel(tr("Name:"), this);


    dateDateEdit= new QDateEdit(expToModify->espdate(), this);
    dateLabel= new QLabel(tr("Date exp:"), this);

    descrLineEdit= new QLineEdit(expToModify->descr(), this);
    descrLabel= new QLabel(tr("Descr:"), this);

    modifyButton= new QPushButton(tr("Modify"), this);
    connect(modifyButton, SIGNAL(clicked()), this, SLOT(modifyExp()));

    cancelButton= new QPushButton(tr("Cancel"), this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

    deleteButton= new QPushButton(tr("Delete"), this);
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteExp()));

    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(nameLineEdit, 0, 1, 1, 1);
    layout->addWidget(dateLabel, 1, 0);
    layout->addWidget(dateDateEdit, 1, 1, 1, 1);
    layout->addWidget(descrLabel, 2, 0);
    layout->addWidget(descrLineEdit, 2, 1, 1, 1);
    layout->addWidget(modifyButton, 3, 0);
    layout->addWidget(cancelButton, 3, 1);
    layout->addWidget(deleteButton, 3, 2);

    QGroupBox::setLayout(layout);
}

void modifyuserexperience::modifyExp(){
    expToModify->set_namesp(nameLineEdit->text());
    expToModify->set_datesp(dateDateEdit->date().year(), dateDateEdit->date().month(), dateDateEdit->date().day());
    expToModify->set_descr(descrLineEdit->text());
    emit modifiedExp();
}

void modifyuserexperience::cancel(){
    nameLineEdit->setText(expToModify->espname());
    dateDateEdit->setDate(expToModify->espdate());
    descrLineEdit->setText(expToModify->descr());
}

void modifyuserexperience::deleteExp(){
    ouwner->removeexperience(*expToModify);

    emit modifiedExp();

}
