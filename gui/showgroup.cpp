#include "../lib/account.h"
#include "showgroup.h"

#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QVector>


showgroup::showgroup(account* acc, group* grp, legami* boss, QWidget *parent) :
    QWidget(parent), Boss(boss)
{
    groupToShow=grp;
    accShown=acc;

    layout= new QGridLayout(this);
    setLayout(layout);

    QFormLayout* layoutData= new QFormLayout();

    userVector= groupToShow->members();
    adminVector= groupToShow->admins();

    nameLineEdit= new QLineEdit(grp->name(), this);
    layoutData->addRow(tr("Name:"), nameLineEdit);
    descrLineEdit= new QLineEdit(grp->descr(), this);
    layoutData->addRow(tr("Description:"), descrLineEdit);

    layout->addLayout(layoutData, 0, 0);

    usersList= new QListView(this);
    adminList= new QListView(this);

    QStandardItemModel* userModel= new QStandardItemModel(this);
    QStandardItem* userParentItem= userModel->invisibleRootItem();


    QVector<account*>::iterator it= userVector.begin();
    for(;it!=userVector.end();++it){
	QStandardItem* userItemTemp= new QStandardItem((*it)->user()->user());
	userParentItem->appendRow(userItemTemp);
    }
    usersList->setModel(userModel);

    QStandardItemModel* adminModel= new QStandardItemModel(this);
    QStandardItem* adminParentItem= adminModel->invisibleRootItem();

    bool admin=false;

    it= adminVector.begin();
    for(;it!=adminVector.end();++it){
	account* admTemp= *it;
	if(admTemp->user()){
	    QStandardItem* adminItemTemp= new QStandardItem(admTemp->user()->user());
	    adminParentItem->appendRow(adminItemTemp);
	}
	if(*it==accShown) admin=true;
	else QMessageBox::information(this, tr(""), tr("manca tutto"), QMessageBox::Ok, QMessageBox::Ok);
    }
    adminList->setModel(adminModel);
    QLabel* usernLabel= new QLabel(tr("Users:"), this);
    QLabel* adminsLabel= new QLabel(tr("Admins:"), this);

    layout->addWidget(usernLabel, 1, 0);
    layout->addWidget(adminsLabel, 1, 1);
    layout->addWidget(usersList, 2, 0);
    layout->addWidget(adminList, 2, 1);

    if(admin){
	adminButton= new QPushButton(tr("Admin Group"), this);
	connect(adminButton, SIGNAL(clicked()), this, SLOT(adminGroup()));
	layout->addWidget(adminButton, 3, 0);
    }

}

void showgroup::adminGroup(){
    emit adminGr(groupToShow);
}
