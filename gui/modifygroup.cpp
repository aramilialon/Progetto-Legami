#include "modifygroup.h"

#include <QFormLayout>
#include <QMessageBox>
#include <QStandardItem>
#include <QStandardItemModel>

modifygroup::modifygroup(group* grp, legami* boss, QWidget *parent) :
    QDialog(parent), Boss(boss), groupToModify(grp)
{
    userVector= groupToModify->members();
    adminVector= groupToModify->admins();

    removeuserRow=QString();
    removeadminRow=QString();
    newadminRow=QString();

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

    userremoveModel= new QStandardItemModel(this);
    QStandardItem* userremoveParentItem= userremoveModel->invisibleRootItem();

    newadminModel= new QStandardItemModel(this);
    QStandardItem* newadminParentItem= newadminModel->invisibleRootItem();

    QVector<account*>::iterator it= userVector.begin();
    for(;it!=userVector.end();++it){
	QStandardItem* temp= new QStandardItem((*it)->user()->user());
	userremoveParentItem->appendRow(temp);

    }
    userremoveList->setModel(userremoveModel);
    connect(userremoveList, SIGNAL(clicked(QModelIndex)), this, SLOT(setRemoveUser(QModelIndex)));

    it=userVector.begin();
    for(;it!=userVector.end();++it){
	if(!groupToModify->getadmin(**(it))){
	    QStandardItem* temp= new QStandardItem((*it)->user()->user());
	    newadminParentItem->appendRow(temp);
	}
    }
    newadminList->setModel(newadminModel);
    connect(newadminList, SIGNAL(clicked(QModelIndex)), this, SLOT(setNewAdmin(QModelIndex)));

    adminremoveModel= new QStandardItemModel(this);
    QStandardItem* adminremoveParentItem= adminremoveModel->invisibleRootItem();

    it= adminVector.begin();
    for(;it!=adminVector.end();++it){
	QStandardItem* temp= new QStandardItem((*it)->user()->user());
	adminremoveParentItem->appendRow(temp);
    }
    connect(adminremoveList, SIGNAL(clicked(QModelIndex)), this, SLOT(setRemoveAdmin(QModelIndex)));
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
	else QMessageBox::warning(this, tr("Error"), tr("User not found"), QMessageBox::Ok, QMessageBox::Ok);
    }
    if(!removeuserRow.isEmpty()){
	groupToModify->removemember(removeuserRow);
    }
    if(!removeadminRow.isEmpty()){
	groupToModify->removeadmin(removeadminRow);
    }
    if(!newadminRow.isEmpty()){
	groupToModify->addadmin(newadminRow);
    }
    close();
    emit modified(groupToModify);
}

void modifygroup::setRemoveAdmin(const QModelIndex ind){
    QStandardItem* temp= adminremoveModel->item(ind.row());
    removeadminRow=temp->text();
}

void modifygroup::setRemoveUser(const QModelIndex ind){
    QStandardItem* temp= userremoveModel->item(ind.row());
    removeuserRow=temp->text();
}

void modifygroup::setNewAdmin(const QModelIndex ind){
    QStandardItem* temp= newadminModel->item(ind.row());
    newadminRow=temp->text();
}
