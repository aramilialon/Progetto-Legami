#include "../lib/account.h"
#include "showgroup.h"

#include <QFormLayout>
#include <QMessageBox>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QVector>


showgroup::showgroup(group* grp, QWidget *parent) :
    QWidget(parent)
{
    groupToShow=grp;

    QFormLayout* layoutData= new QFormLayout(this);
    layout= new QGridLayout(this);
    setLayout(layout);

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
	account* accTemp= *it;
	if(accTemp->user()){
	    QStandardItem* userItemTemp= new QStandardItem(accTemp->user()->user());
	    userParentItem->appendRow(userItemTemp);
	}
	else QMessageBox::information(this, tr(""), tr("manca tutto"), QMessageBox::Ok, QMessageBox::Ok);
    }
    usersList->setModel(userModel);

    QStandardItemModel* adminModel= new QStandardItemModel(this);
    QStandardItem* adminParentItem= adminModel->invisibleRootItem();

    it= adminVector.begin();
    for(;it!=adminVector.end();++it){
	account* admTemp= *it;
	if(admTemp->user()){
	    QStandardItem* adminItemTemp= new QStandardItem(admTemp->user()->user());
	    adminParentItem->appendRow(adminItemTemp);
	}
	else QMessageBox::information(this, tr(""), tr("manca tutto"), QMessageBox::Ok, QMessageBox::Ok);
    }
    adminList->setModel(adminModel);

    layout->addWidget(usersList, 1, 0);
    layout->addWidget(adminList, 1, 1);

}
