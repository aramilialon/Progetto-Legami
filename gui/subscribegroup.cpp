#include "subscribegroup.h"

subscribegroup::subscribegroup(account* acc, legami* boss, QWidget *parent) :
    QDialog(parent), accToAdd(acc), Boss(boss)
{
    QVector<group*> groupVectorTemp= Boss->groupDb();
    QVector<group*> groupUser= Boss->groupSearchbyUsern(accToAdd->user()->user());

    QVector<group*>::iterator it1=groupVectorTemp.begin();
    QVector<group*>::iterator it2=groupUser.begin();

    groupsListView= new QListView(this);
    groupModel= new QStandardItemModel(this);

    QStandardItem* groupParentItem= groupModel->invisibleRootItem();

    for(;it1<groupVectorTemp.end();++it1){
	bool found=false;
	for(;!found && it2<groupUser.end();++it2) if(*it1==*it2) found=true;
	if(!found){
	    QStandardItem temp= new QStandardItem((*it1)->name());
	    groupParentItem->appendRow(temp);
	}
	else found=false;
    }
    groupsListView->setModel(groupModel);
    connect(groupsListView, SIGNAL(clicked(QModelIndex)), this, SLOT(setGroup(QModelIndex)));

    textLabel= new QLabel(tr("Select the group with you want to subscrive."), this);

    okButton= new QPushButton(tr("Subscribe"), this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(subscribe()));

    cancelButton= new QPushButton(tr("Cancel"), this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

    layout= new QGridLayout(this);
    layout->addWidget(textLabel, 0, 0);
    layout->addWidget(groupsListView, 1, 0);
    layout->addWidget(okButton, 2, 0);
    layout->addWidget(cancelButton, 2, 1);

    setLayout(layout);

}

void subscribegroup::subscribe(){}

void subscribegroup::setGroup(const QModelIndex ind){}
