/*
  File: legamilogin.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "../lib/account.h"
#include "legamilogin.h"

#include <QDialogButtonBox>
#include <QHBoxLayout>

legamilogin::legamilogin(legami* manager, QWidget* parent) :
	QDialog(parent), boss(manager)
{
    layout= new QGridLayout(this);

    upperLabel= new QLabel(tr("Please enter your account data."), this);

    usernLabel= new QLabel(tr("Username:"), this);
    usernLineEdit= new QLineEdit(this);
    usernLabel->setBuddy(usernLineEdit);

    passwLabel= new QLabel(tr("Password:"), this);
    passwLineEdit= new QLineEdit(this);
    passwLineEdit->setEchoMode(QLineEdit::Password);
    passwLabel->setBuddy(passwLineEdit);

    loginButton= new QPushButton(tr("Login"), this);
    cancelButton= new QPushButton(tr("Cancel"), this);

    connect(loginButton, SIGNAL(clicked()), this, SLOT(tryLogin()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

    QDialogButtonBox* buttonLayout= new QDialogButtonBox(this);
    buttonLayout->addButton(loginButton, QDialogButtonBox::YesRole);
    buttonLayout->addButton(cancelButton, QDialogButtonBox::RejectRole);

    layout->addWidget(upperLabel, 0, 0);
    layout->addWidget(usernLabel, 1, 0);
    layout->addWidget(usernLineEdit, 1, 1);
    layout->addWidget(passwLabel, 2, 0);
    layout->addWidget(passwLineEdit, 2, 1);
    layout->addWidget(buttonLayout, 3, 1);
    setLayout(layout);
}

void legamilogin::tryLogin(){
    bool ok=boss->logAccount(usernLineEdit->text(), passwLineEdit->text());
	close();
    emit(logged(ok));
}
