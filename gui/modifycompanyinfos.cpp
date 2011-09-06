#include "../lib/companyinfo.h"
#include "modifycompanyinfos.h"

modifycompanyinfos::modifycompanyinfos(companyaccount* acc, QWidget *parent) :
    QGroupBox(parent), accToModify(acc)
{
    companyinfo* temp= accToModify->information();

    layout= new QFormLayout(this);

    nameLineEdit= new QLineEdit(temp->name(), this);
    layout->addRow(tr("Name:"), nameLineEdit);

    addressLineEdit= new QLineEdit(temp->address(), this);
    layout->addRow(tr("Address:"), addressLineEdit);

    cotypeLineEdit= new QLineEdit(temp->cotype(), this);
    layout->addRow(tr("Company types:"), cotypeLineEdit);

    okButton= new QPushButton(tr("Modify"), this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(modify()));
    cancelButton= new QPushButton(tr("Reset"), this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reset()));

    layout->addWidget(okButton);
    layout->addWidget(cancelButton);

    setLayout(layout);
}

void modifycompanyinfos::modify(){
    companyinfo* temp= accToModify->information();

    temp->setName(nameLineEdit->text());
    temp->setAddress(addressLineEdit->text());
    temp->setType(cotypeLineEdit->text());

    emit modified(true);
}

void modifycompanyinfos::reset(){
    companyinfo* temp= accToModify->information();

    nameLineEdit->setText(temp->name());
    addressLineEdit->setText(temp->address());
    cotypeLineEdit->setText(temp->cotype());
}
