#include "showcontacts.h"
#include "viewotheruser.h"

#include <QStandardItem>
#include <QVector>

showcontacts::showcontacts(account* acc, legami* boss, QWidget *parent) :
    QWidget(parent), accToShow(acc), Boss(boss)
{
    layout= new QGridLayout(this);

    contactsLabel= new QLabel(tr("Contats"), this);
    layout->addWidget(contactsLabel, 0, 0);

    QVector<account*> listTemp= accToShow->getconnections();

    contactsView= new QListView(this);

    contactsModel= new QStandardItemModel(this);
    QStandardItem* contactsParentItem= contactsModel->invisibleRootItem();

    for(QVector<account*>::iterator it=listTemp.begin();it<listTemp.end();++it){
	QStandardItem* temp= new QStandardItem((*it)->user()->user());
	contactsParentItem->appendRow(temp);
    }
    contactsView->setModel(contactsModel);
    connect(contactsView, SIGNAL(clicked(QModelIndex)), this, SLOT(select(QModelIndex)));

    layout->addWidget(contactsView, 1, 0);

    showButton= new QPushButton(tr("Show profile"), this);
    connect(showButton, SIGNAL(clicked()), this, SLOT(showuser()));

    layout->addWidget(showButton, 2, 0);

    setLayout(layout);

}

void showcontacts::select(QModelIndex ind){
    QStandardItem* temp= contactsModel->item(ind.row());
    selection= temp->text();
}

void showcontacts::showuser(){
    account* usertemp= Boss->basicSearch(selection);
    if(usertemp){
	viewotheruser* temp= new viewotheruser(usertemp, Boss, this);
	temp->show();
    }
}

QString showcontacts::sel(){
    return selection;
}
