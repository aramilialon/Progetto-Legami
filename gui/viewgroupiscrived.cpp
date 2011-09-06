#include "viewgroupiscrived.h"

#include <QStandardItem>
#include <QStandardItemModel>

viewGroupIscrived::viewGroupIscrived(account* acc, legami* boss, QWidget *parent) :
    QWidget(parent), accToShow(acc), Boss(boss)
{
    groupList=Boss->groupSearchbyUsern(accToShow->user()->user());

    layout= new QGridLayout(this);

    groupsListView= new QListView(this);
    layout->addWidget(groupsListView, 0, 0);

    QStandardItemModel* model= new QStandardItemModel(this);
    QStandardItem* parentItem= model->invisibleRootItem();

    QVector<group*>::iterator it=groupList.begin();
    for(;it!=groupList.end();++it){
	QStandardItem* item= new QStandardItem((*it)->name());
	parentItem->appendRow(item);
    }

    groupsListView->setModel(model);

    setLayout(layout);
}

void viewGroupIscrived::showgroup(){

}
