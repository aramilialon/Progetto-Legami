#include "inboxmessages.h"

#include <QStringList>
#include <QStandardItem>

inboxMessages::inboxMessages(account* acc, legami* boss, QWidget *parent) :
    QWidget(parent), accToShow(acc), Boss(boss)
{
    layout= new QVBoxLayout(this);

    messVector=Boss->messageReceved(accToShow->user()->user());

    showMess=0;

    inboxList= new QTableView(this);

    QStringList headerList(tr("Sender"));
    headerList.append(tr("Object"));
    inboxModel= new QStandardItemModel(this);


    QStandardItem* inboxRoot= inboxModel->invisibleRootItem();

    QList<QStandardItem*> senderList;
    QList<QStandardItem*> objList;
    QList<QStandardItem*> readList;

    QVector<message*>::iterator it=messVector.begin();
    for(;it<messVector.end();++it){
	QStandardItem* senderItem= new QStandardItem((*it)->sender()->user()->user());
	QStandardItem* objItem= new QStandardItem((*it)->object());
	QStandardItem* readItem=0;

	if((*it)->read()) readItem= new QStandardItem(tr("Read"));
	else readItem= new QStandardItem(tr("Not Read"));

	senderItem->setEnabled(false);

	senderList.push_back(senderItem);
	objList.push_back(objItem);
	readList.push_back(readItem);
    }

    inboxRoot->appendColumn(senderList);
    inboxRoot->appendColumn(objList);
    inboxRoot->appendColumn(readList);

    inboxList->setModel(inboxModel);
    inboxList->resizeColumnsToContents();
    connect(inboxList, SIGNAL(clicked(QModelIndex)), this, SLOT(selected(QModelIndex)));

    layout->addWidget(inboxList);

    setLayout(layout);
}

void inboxMessages::selected(const QModelIndex ind){
    message* temp= messVector[ind.row()];
    if(showMess) delete showMess;
    if(!temp->read()) temp->readed();
    showMess= new showMessage(temp, this);
    layout->addWidget(showMess);
    showMess->show();
}
