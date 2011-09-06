#include "viewgroupiscrived.h"

#include <QModelIndex>
#include <QStandardItem>
#include <QStandardItemModel>

viewGroupIscrived::viewGroupIscrived(account* acc, legami* boss, QWidget *parent) :
    QWidget(parent), accToShow(acc), Boss(boss)
{
    groupList=Boss->groupSearchbyUsern(accToShow->user()->user());

    layout= new QGridLayout(this);

    groupsListView= new QListView(this);
    layout->addWidget(groupsListView, 0, 0);

    scrollRightArea= new QScrollArea(this);
    layout->addWidget(scrollRightArea, 0, 1);

    QStandardItemModel* model= new QStandardItemModel(this);
    QStandardItem* parentItem= model->invisibleRootItem();

    QVector<group*>::iterator it=groupList.begin();
    for(;it!=groupList.end();++it){
	QStandardItem* item= new QStandardItem((*it)->name());
	parentItem->appendRow(item);
    }

    groupsListView->setModel(model);
    connect(groupsListView, SIGNAL(clicked(QModelIndex)), this, SLOT(showGroup(QModelIndex)));

    setLayout(layout);
}

void viewGroupIscrived::showGroup(const QModelIndex ind)
{
    group* temp=groupList.at(ind.row());
    showgroup* showTemp= new showgroup(temp, this);


}
