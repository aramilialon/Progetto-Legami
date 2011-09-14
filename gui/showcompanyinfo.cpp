#include "../lib/companyinfo.h"
#include "showcompanyinfo.h"

showcompanyinfo::showcompanyinfo(const account& acc, QWidget *parent) :
    QGroupBox(tr("Company info"), parent)
{

    accToShow= dynamic_cast<companyaccount*>(const_cast<account*>(&acc));

    layout= new QFormLayout(this);
    companyinfo* infos= accToShow->information();

    nameLineEdit= new QLineEdit(infos->name(), this);
    nameLineEdit->setReadOnly(true);
    layout->addRow(tr("Name:"), nameLineEdit);

    addressLineEdit= new QLineEdit(infos->address(), this);
    addressLineEdit->setReadOnly(true);
    layout->addRow(tr("Address:"), addressLineEdit);

    cotypeLineEdit= new QLineEdit(infos->cotype());
    cotypeLineEdit->setReadOnly(true);
    layout->addRow(tr("Company type(s):"), cotypeLineEdit);

    setLayout(layout);

}
