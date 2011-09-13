#include "showcontactsmessage.h"

showcontactsmessage::showcontactsmessage(account* acc, legami* boss, QWidget *parent) :
    QDialog(parent), accToShow(acc), Boss(boss)
{
    layout= new QGridLayout(this);

    contactsShown= new showcontacts(accToShow, Boss, this);
    layout->addWidget(contactsShown, 0, 0);

    okButton= new QPushButton(tr("Select"), this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(okPressed()));
    layout->addWidget(okButton, 1, 0);

    cancelButton= new QPushButton(tr("Cancel"), this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    layout->addWidget(cancelButton, 1, 1);

    setLayout(layout);
}

void showcontactsmessage::okPressed(){
    emit selected(contactsShown->sel());
    close();
}
