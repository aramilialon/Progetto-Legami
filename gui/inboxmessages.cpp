#include "inboxmessages.h"

#include <QStandardItem>

inboxMessages::inboxMessages(account* acc, legami* boss, QWidget *parent) :
    QWidget(parent), accToShow(acc), Boss(boss)
{
    layout= new QVBoxLayout(this);

    messVector=Boss->messageReceved(accToShow->user()->user());

    showMess=0;

    inboxList= new QTableView(this);

    inboxModel= new QStandardItemModel(this);
    inboxModel->setHeaderData(0, Qt::Horizontal, tr("Sender"));
    inboxModel->setHeaderData(1, Qt::Horizontal, tr("Object"));

    QStandardItem* inboxRoot= inboxModel->invisibleRootItem();

    QList<QStandardItem*> senderList;
    QList<QStandardItem*> objList;

    QVector<message*>::iterator it=messVector.begin();
    for(;it<messVector.end();++it){
	QStandardItem* senderItem= new QStandardItem((*it)->sender()->user()->user());
	QStandardItem* objItem= new QStandardItem((*it)->object());

	senderItem->setEnabled(false);

	senderList.push_back(senderItem);
	objList.push_back(objItem);
    }

    inboxRoot->appendColumn(senderList);
    inboxRoot->appendColumn(objList);

    inboxList->setModel(inboxModel);
    inboxList->resizeColumnsToContents();
    connect(inboxList, SIGNAL(clicked(QModelIndex)), this, SLOT(selected(QModelIndex)));

    layout->addWidget(inboxList);

    setLayout(layout);
}

void inboxMessages::selected(const QModelIndex ind){
    message* temp= messVector[ind.row()];
    if(showMess) delete showMess;
    showMess= new showMessage(temp, this);
    layout->addWidget(showMess);
    showMess->show();
}
