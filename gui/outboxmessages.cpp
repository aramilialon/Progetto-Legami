#include "outboxmessages.h"

#include <QStringList>
#include <QStandardItem>

outboxMessages::outboxMessages(account* acc, legami* boss, QWidget *parent) :
    QWidget(parent), accToShow(acc), Boss(boss)
{
    layout= new QVBoxLayout(this);

    messVector=Boss->messageSent(accToShow->user()->user());

    showMess=0;

    outboxList= new QTableView(this);

    QStringList stringList;

    stringList<<tr("Sender")<<tr("Object");

    outboxModel= new QStandardItemModel(this);

    QStandardItem* outboxRoot= outboxModel->invisibleRootItem();

    QList<QStandardItem*> receverList;
    QList<QStandardItem*> objList;

    QVector<message*>::iterator it=messVector.begin();
    for(;it<messVector.end();++it){
	QStandardItem* receverItem= new QStandardItem((*it)->recever()->user()->user());
	QStandardItem* objItem= new QStandardItem((*it)->object());

	receverItem->setEnabled(false);

	receverList.push_back(receverItem);
	objList.push_back(objItem);
    }

    outboxRoot->appendColumn(receverList);
    outboxRoot->appendColumn(objList);

    outboxList->setModel(outboxModel);
    outboxList->resizeColumnsToContents();
    connect(outboxList, SIGNAL(clicked(QModelIndex)), this, SLOT(selected(QModelIndex)));

    layout->addWidget(outboxList);

    setLayout(layout);
}

void outboxMessages::selected(const QModelIndex ind){
    message* temp= messVector[ind.row()];
    if(showMess) delete showMess;
    showMess= new showMessage(temp, this);
    layout->addWidget(showMess);
    showMess->show();
}
