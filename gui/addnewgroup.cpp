#include "addnewgroup.h"

#include <QFormLayout>

addnewgroup::addnewgroup(account* acc, legami* boss, QWidget *parent) :
    QDialog(parent), Creator(acc), Boss(boss)
{
    layout= new QGridLayout(this);

    QFormLayout* layoutLineEdit= new QFormLayout();

    nameLineEdit= new QLineEdit(this);
    layoutLineEdit->addRow(tr("Name:"), nameLineEdit);

    descrLineEdit= new QLineEdit(this);
    layoutLineEdit->addRow(tr("Description:"), descrLineEdit);

    layout->addLayout(layoutLineEdit, 0, 0);

    okButton= new QPushButton(tr("Create"), this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(create()));
    layout->addWidget(okButton, 1, 0);

    cancelButton= new QPushButton(tr("Cancel"), this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    layout->addWidget(cancelButton, 1, 1);

    setLayout(layout);
}


void addnewgroup::create(){
    group* temp= new group(nameLineEdit->text(), descrLineEdit->text());
    temp->addmember(*Creator);
    temp->addadmin(Creator->user()->user());

    Boss->addGroup(*temp);

    emit created();

    close();
}
