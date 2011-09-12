#include "showlistpayments.h"

#include <QStandardItem>
#include <QList>

showlistpayments::showlistpayments(account* acc, QWidget *parent) :
    QWidget(parent), accToShow(acc)
{
    selected=-1;

    QVector<payment*> temp= accToShow->payments();
    paymentsTable= new QTableView(this);

    paymentsModel= new QStandardItemModel(this);
    QStandardItem* paymentsRootItem= paymentsModel->invisibleRootItem();

    QList<QStandardItem*> dateList;
    QList<QStandardItem*> requestList;
    QList<QStandardItem*> apprList;

    QVector<payment*>::iterator it=temp.begin();
    for(;it<temp.end();++it){
	payment* payTemp=*it;
	QStandardItem* dateTemp= new QStandardItem(QString(payTemp->date().day())+QString("/")+QString(payTemp->date().month())+QString("/")+QString(payTemp->date().year()));

	QStandardItem* requestTemp=0;
	if(payTemp->request()==1) requestTemp= new QStandardItem(tr("Business"));
	else requestTemp= new QStandardItem(tr("Executive"));

	QStandardItem* apprTemp=0;
	if(payTemp->approved()) apprTemp= new QStandardItem(tr("Approved)"));
	else apprTemp= new QStandardItem(tr("Not Approved"));

	dateList.push_back(dateTemp);
	requestList.push_back(requestTemp);
	apprList.push_back(apprTemp);
    }
    paymentsRootItem->appendColumn(dateList);
    paymentsRootItem->appendColumn(requestList);
    paymentsRootItem->appendColumn(apprList);

    paymentsTable->setModel(paymentsModel);
    connect(paymentsTable, SIGNAL(clicked(QModelIndex)), this, SLOT(modSelected(QModelIndex)));
}

int showlistpayments::sel(){
    return selected;
}

void showlistpayments::modSelected(QModelIndex ind){
    selected=ind.row();
}
