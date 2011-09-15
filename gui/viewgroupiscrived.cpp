#include "modifygroup.h"
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
    for(;it<groupList.end();++it){
        QStandardItem* item= new QStandardItem((*it)->name());
        item->setEditable(false);
        parentItem->appendRow(item);
    }

    groupsListView->setModel(model);
    connect(groupsListView, SIGNAL(clicked(QModelIndex)), this, SLOT(showGroup(QModelIndex)));

    setLayout(layout);
}

void viewGroupIscrived::showGroup(const QModelIndex ind)
{
    delete showGr;
    showGr= new showgroup(accToShow, groupList[ind.row()], Boss, this);

    connect(showGr, SIGNAL(adminGr(group*)), this, SLOT(adminGroup(group*)));

    scrollRightArea->ensureWidgetVisible(showGr);
    scrollRightArea->setWidget(showGr);
    showGr->adjustSize();
    scrollRightArea->resize(showGr->sizeHint());
    resize(scrollRightArea->size());
    emit(resized());
}

void viewGroupIscrived::adminGroup(group * grp){
    modifygroup* modgr= new modifygroup(grp, Boss, this);
    connect(modgr, SIGNAL(modified(group*)), this, SLOT(groupModified(group*)));
    connect(modgr, SIGNAL(deletethisgroup()), this, SLOT(groupDeleted()));
    modgr->show();
}

void viewGroupIscrived::groupModified(group* grp){
    delete showGr;
    showGr= new showgroup(accToShow, grp, Boss, this);

    connect(showGr, SIGNAL(adminGr(group*)), this, SLOT(adminGroup(group*)));

    scrollRightArea->ensureWidgetVisible(showGr);
    scrollRightArea->setWidget(showGr);
    showGr->adjustSize();
    scrollRightArea->resize(showGr->sizeHint());
    resize(scrollRightArea->size());
    emit(resized());
}

void viewGroupIscrived::groupDeleted(){
    QMessageBox::information(this, tr("Done"), tr("Group deleted."), QMessageBox::Ok, QMessageBox::Ok);
    delete showGr;
    showGr=0;

    delete groupsListView;

    groupList=Boss->groupSearchbyUsern(accToShow->user()->user());

    groupsListView= new QListView(this);
    layout->addWidget(groupsListView, 0, 0);

    QStandardItemModel* model= new QStandardItemModel(this);
    QStandardItem* parentItem= model->invisibleRootItem();

    QVector<group*>::iterator it=groupList.begin();
    for(;it<groupList.end();++it){
        QStandardItem* item= new QStandardItem((*it)->name());
        parentItem->appendRow(item);
    }

    groupsListView->setModel(model);
    connect(groupsListView, SIGNAL(clicked(QModelIndex)), this, SLOT(showGroup(QModelIndex)));
}
