#include "../lib/userinfo.h"
#include "../lib/useraccount.h"

#include "modifyuserinfos.h"

modifyuserinfos::modifyuserinfos(const useraccount & acc, legami* boss, QWidget *parent) :
    QGroupBox(tr("User Info"), parent), accToModify(const_cast<useraccount*>(&acc)), Boss(boss)
{
    layout= new QFormLayout(this);
    userinfo* infos= accToModify->information();

    nameLineEdit= new QLineEdit(infos->name(), this);
    layout->addRow(tr("First Name:"), nameLineEdit);

    surnameLineEdit= new QLineEdit(infos->surname(), this);
    layout->addRow(tr("Last Name:"), surnameLineEdit);

    dateDateEdit= new QDateEdit(infos->birthdate(), this);
    layout->addRow(tr("Birth Date:"), dateDateEdit);

    placeLineEdit= new QLineEdit(infos->birthplace(), this);
    layout->addRow(tr("Birth Place:"), placeLineEdit);

    telnumLineEdit= new QLineEdit(infos->telnum(), this);
    layout->addRow(tr("Tel. Num.:"), telnumLineEdit);

    emailLineEdit= new QLineEdit(infos->email(), this);
    layout->addRow(tr("Email:"), emailLineEdit);

    okButton= new QPushButton(tr("Modify"), this);
    layout->addWidget(okButton);

    cancelButton= new QPushButton(tr("Reset"), this);
    layout->addWidget(cancelButton);

    connect(okButton, SIGNAL(clicked()), this, SLOT(modify()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reset()));

    QGroupBox::setLayout(layout);
}

void modifyuserinfos::modify(){
    if(Boss->accountlogged()==accToModify || dynamic_cast<useraccount*>(accToModify)->getadmin()){
	accToModify->setinfo(nameLineEdit->text(), surnameLineEdit->text(), dateDateEdit->date().year(), dateDateEdit->date().month(), dateDateEdit->date().day(), placeLineEdit->text(), telnumLineEdit->text(), emailLineEdit->text());
	emit modified(true);
    }
    else emit modified(false);
}

void modifyuserinfos::reset(){
    userinfo* infoTemp= accToModify->information();

    nameLineEdit->setText(infoTemp->name());
    surnameLineEdit->setText(infoTemp->surname());
    dateDateEdit->setDate(infoTemp->birthdate());
    placeLineEdit->setText(infoTemp->birthplace());
    telnumLineEdit->setText(infoTemp->telnum());
    emailLineEdit->setText(infoTemp->email());
}
