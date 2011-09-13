#include "../lib/account.h"

#include "showuserlist.h"

#include <QGridLayout>

showuserlist::showuserlist(legami* boss, QWidget *parent) :
    QWidget(parent), Boss(boss)
{
    QGridLayout* layout= new QGridLayout(this);
    usersListView= new QListView(this);

    usersModel= new QStandardItemModel(this);
    QStandardItem* usersRootItem= usersModel->invisibleRootItem();

    QVector<account*> temp= Boss->userDb();
    QVector<account*>::iterator it=temp.begin();
    for(;it<temp.end();++it){
	QStandardItem* userTemp= new QStandardItem((*it)->user()->user());
	usersRootItem->appendRow(userTemp);
    }
    usersListView->setModel(usersModel);
    connect(usersListView, SIGNAL(clicked(QModelIndex)), this, SLOT(modifySelected(QModelIndex)));

    layout->addWidget(usersListView, 0, 0);

    setLayout(layout);
}

QString showuserlist::selected(){
    return userSelected;
}

void showuserlist::modifySelected(QModelIndex ind){
    QStandardItem* temp= usersModel->item(ind.row());
    userSelected= temp->text();
}
