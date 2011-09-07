#include "viewgroupiscrived.h"

#include <QMessageBox>
#include <QModelIndex>
#include <QStandardItem>
#include <QStandardItemModel>

viewGroupIscrived::viewGroupIscrived(account* acc, legami* boss, QWidget *parent) :
    QWidget(parent), accToShow(acc), Boss(boss)
{
    showGr=0;
    groupList=Boss->groupSearchbyUsern(accToShow->user()->user());

    layout= new QGridLayout(this);

    groupsListView= new QListView(this);
    layout->addWidget(groupsListView, 0, 0);

    scrollRightArea= new QScrollArea(this);
    layout->addWidget(scrollRightArea, 1, 0);

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
    showGr= new showgroup(groupList[ind.row()], this);

    scrollRightArea->ensureWidgetVisible(showGr);
    scrollRightArea->setWidget(showGr);
    showGr->adjustSize();
    scrollRightArea->resize(showGr->sizeHint());
    resize(scrollRightArea->size());
    emit(resized());
}
