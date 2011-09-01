#include "../lib/useraccount.h"
#include "../lib/userinfo.h"
#include "showuserinfo.h"

showuserinfo::showuserinfo(const account & _AccToShow, QWidget *parent) :
    QGroupBox(tr("User Info"), parent)
{
	accToShow= dynamic_cast<useraccount*>(const_cast<account*>(&_AccToShow));
	userinfo* infoToShow=accToShow->information();

	nameLineEdit= new QLineEdit(infoToShow->name());
	nameLineEdit->setReadOnly(true);

	surnameLineEdit= new QLineEdit(infoToShow->surname());
	surnameLineEdit->setReadOnly(true);

	dateDateEdit= new QDateEdit(infoToShow->birthdate());
	dateDateEdit->setReadOnly(true);
	dateDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

	placeLineEdit= new QLineEdit(infoToShow->birthplace());
	placeLineEdit->setReadOnly(true);

	telnumLineEdit= new QLineEdit(infoToShow->telnum());
	telnumLineEdit->setReadOnly(true);

	emailLineEdit= new QLineEdit(infoToShow->email());
	emailLineEdit->setReadOnly(true);

	layout= new QFormLayout(this);
	layout->addRow(tr("Name:"), nameLineEdit);
	layout->addRow(tr("Surname:"), surnameLineEdit);
	layout->addRow(tr("Birth Date:"), dateDateEdit);
	layout->addRow(tr("Birth place:"), placeLineEdit);
	layout->addRow(tr("Tel Num:"), telnumLineEdit);
	layout->addRow(tr("Email:"), emailLineEdit);

	setLayout(layout);
}
