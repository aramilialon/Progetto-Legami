#include "modifygroup.h"

#include <QFormLayout>
#include <QStandardItem>
#include <QStandardItemModel>

modifygroup::modifygroup(group* grp, legami* boss, QWidget *parent) :
    QDialog(parent), Boss(boss), groupToModify(grp)
{
    userVector= groupToModify->members();
    adminVector= groupToModify->admins();

    removeuserRow=-1;
    removeadminRow=-1;
    newadminRow=-1;

    layout= new QGridLayout();

    QFormLayout* layoutLineEdit= new QFormLayout();

    nameLineEdit= new QLineEdit(groupToModify->name(), this);
    layoutLineEdit->addRow(tr("Name:"), nameLineEdit);
    descrLineEdit= new QLineEdit(groupToModify->descr(), this);
    layoutLineEdit->addRow(tr("Description:"), descrLineEdit);

    newuserLineEdit= new QLineEdit(this);
    layoutLineEdit->addRow(tr("Add new user:"), newuserLineEdit);

    userremoveList= new QListView(this);
    adminremoveList= new QListView(this);
    newadminList= new QListView(this);

    QStandardItemModel* userremoveModel= new QStandardItemModel(this);
    QStandardItem* userremoveParentItem= userremoveModel->invisibleRootItem();

    QStandardItemModel* newadminModel= new QStandardItemModel(this);
    QStandardItem* newadminParentItem= newadminModel->invisibleRootItem();

    QVector<account*>::iterator it= userVector.begin();
    for(;it!=userVector.end();++it){
	QStandardItem* temp= new QStandardItem((*it)->user()->user());
	userremoveParentItem->appendRow(temp);
	newadminParentItem->appendRow(temp);
    }
    userremoveList->setModel(userremoveModel);
    newadminList->setModel(newadminModel);
    connect(userremoveList, SIGNAL(clicked(QModelIndex)), this, SLOT(setRemoveUser(QModelIndex)));
    connect(newadminList, SIGNAL(clicked(QModelIndex)), this, SLOT(setNewAdmin(QModelIndex)));

    QStandardItemModel* adminremoveModel= new QStandardItemModel(this);
    QStandardItem* adminremoveParentItem= adminremoveModel->invisibleRootItem();

    it= adminVector.begin();
    for(;it!=adminVector.end();++it){
	QStandardItem* temp= new QStandardItem((*it)->user()->user());
	adminremoveParentItem->appendRow(temp);
    }
    adminremoveList->setModel(adminremoveModel);

    layoutLineEdit->addRow(tr("New admin:"), newadminList);
    layoutLineEdit->addRow(tr("Remove user:"), userremoveList);
    layoutLineEdit->addRow(tr("Remove admin:"), adminremoveList);

    okButton= new QPushButton(tr("Modify"), this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(modify()));
    cancelButton= new QPushButton(tr("Cancel"), this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

    layout->addLayout(layoutLineEdit, 0, 0);
    layout->addWidget(okButton, 1, 0);
    layout->addWidget(cancelButton, 1, 1);

    setLayout(layout);

}

void modifygroup::modify() throw(error){
    groupToModify->setname(nameLineEdit->text());
    groupToModify->setdescr(descrLineEdit->text());
    if(!newuserLineEdit->text().isEmpty()){
	account* temp= Boss->basicSearch(newuserLineEdit->text());
	if(temp) groupToModify->addmember(*temp);
	else throw error(Username, QString("New user not found"));
    }
    if(removeuserRow!=-1){
	groupToModify->removemember(userVector[removeuserRow]);
    }
    if(removeadminRow!=-1){
	groupToModify->removeadmin(*(adminVector[removeadminRow]));
    }
    if(newadminRow!=-1){
	groupToModify->addadmin(*(userVector[newadminRow]));
    }
    close();
    emit modified(groupToModify);
}

void modifygroup::setRemoveAdmin(const QModelIndex ind){
    removeadminRow=ind.row();
}

void modifygroup::setRemoveUser(const QModelIndex ind){
    removeuserRow=ind.row();
}

void modifygroup::setNewAdmin(const QModelIndex ind){
    newadminRow=ind.row();
}
