#include "showgroup.h"

#include <QFormLayout>
#include <QStandardItem>
#include <QStandardItemModel>

showgroup::showgroup(group* grp, QWidget *parent) :
    QWidget(parent), groupToShow(grp)
{
    QFormLayout* layoutData= new QFormLayout(this);
    userVector= groupToShow->members();
    adminVector= groupToShow->admins();

    nameLineEdit= new QLineEdit(groupToShow->name(), this);
    layoutData->addRow(tr("Name:"), nameLineEdit);
    descrLineEdit= new QLineEdit(groupToShow->descr(), this);
    layoutData->addRow(tr("Description:"), descrLineEdit);

    layout= new QGridLayout(this);

    layout->addLayout(layoutData, 0, 0);

    usersList= new QListView(this);
    adminList= new QListView(this);

    QStandardItemModel* userModel= new QStandardItemModel(this);
    QStandardItem* userParentItem= userModel->invisibleRootItem();

    QVector<account*>::iterator it= groupToShow->members().begin();
    for(;it!=groupToShow->members().end();++it){
	QStandardItem* userItem= new QStandardItem((*it)->user()->user());
	userParentItem->appendRow(userItem);
    }
    usersList->setModel(userModel);

    QStandardItemModel* adminModel= new QStandardItemModel(this);
    QStandardItem* adminParentItem= adminModel->invisibleRootItem();

    QVector<account*>::iterator it1= groupToShow->admins().begin();
    for(;it1!=groupToShow->admins().end();++it1){
	QStandardItem* adminItem= new QStandardItem((*it1)->user()->user());
	adminParentItem->appendRow(adminItem);
    }
    adminList->setModel(adminModel);

    layout->addWidget(usersList, 1, 0);
    layout->addWidget(adminList, 1, 1);

    setLayout(layout);
}
