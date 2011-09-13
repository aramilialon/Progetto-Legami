#include "admingroups.h"
#include "modifygroup.h"

#include <QMessageBox>

admingroups::admingroups(legami* boss, QWidget *parent) :
    QWidget(parent), Boss(boss)
{
    layout= new QGridLayout(this);
    QVector<group*> groupVectorTemp= Boss->groupDb();
    QVector<group*>::iterator it1=groupVectorTemp.begin();

    groupsListView= new QListView(this);
    groupModel= new QStandardItemModel(this);

    QStandardItem* groupParentItem= groupModel->invisibleRootItem();

    for(;it1<groupVectorTemp.end();++it1){
	QStandardItem* temp= new QStandardItem((*it1)->name());
	groupParentItem->appendRow(temp);
    }
    groupsListView->setModel(groupModel);
    connect(groupsListView, SIGNAL(clicked(QModelIndex)), this, SLOT(setGroup(QModelIndex)));

    layout->addWidget(groupsListView, 0, 0);

    modifyButton= new QPushButton(tr("Modify"), this);
    connect(modifyButton, SIGNAL(clicked()), this, SLOT(modifyGroup()));

    layout->addWidget(modifyButton, 1, 0);

    setLayout(layout);
}

void admingroups::setGroup(const QModelIndex ind){
    QStandardItem* temp=groupModel->item(ind.row());
    groupSelected= temp->text();
}

void admingroups::modifyGroup(){
    QVector<group*> temp=Boss->groupDb();
    group* temp1=0;
    bool found=false;

    for(QVector<group*>::iterator it=temp.begin();!found && it!=temp.end();++it){
	if((*it)->name()==groupSelected){
	    temp1=(*it);
	    found=true;
	}
    }
    if(temp1){
	modifygroup* x= new modifygroup(temp1, Boss, this);
	connect(x, SIGNAL(deletethisgroup()), this, SLOT(groupdeleted()));
	connect(x, SIGNAL(modified(group*)), this, SLOT(modified()));
	x->show();
    }
}

void admingroups::groupdeleted(){
    QMessageBox::information(this, tr("Done"), tr("Group deleted"), QMessageBox::Ok, QMessageBox::Ok);
}

void admingroups::modified(){
    QMessageBox::information(this, tr("Done"), tr("Group modified"), QMessageBox::Ok, QMessageBox::Ok);
}
