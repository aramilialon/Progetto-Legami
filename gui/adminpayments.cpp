#include "../lib/account.h"

#include "adminpayments.h"

#include <QList>
#include <QMessageBox>
#include <QStandardItem>

adminpayments::adminpayments(legami* boss, QWidget *parent) :
    QWidget(parent), Boss(boss)
{
    paySelected=-1;

    QVector<account*> tempAcc=Boss->userDb();

    for(QVector<account*>::iterator it=tempAcc.begin();it<tempAcc.end();++it){
	QVector<payment*> payTempo= (*it)->payments();
	for(QVector<payment*>::iterator it1=payTempo.begin();it1<payTempo.end();++it1){
	    payment* temp=(*it1);
	    if(temp->approved()==0){
		payVector.push_back(temp);
	    }
	}
    }

    layout= new QGridLayout(this);

    payTable= new QTableView(this);
    payModel= new QStandardItemModel(this);
    QStandardItem* payRootItem= payModel->invisibleRootItem();


    QList<QStandardItem*> dateList;
    QList<QStandardItem*> userList;
    QList<QStandardItem*> requestList;
    QList<QStandardItem*> apprList;

    QVector<payment*>::iterator it=payVector.begin();
    for(;it<payVector.end();++it){
	payment* payTemp=*it;
	QString day, month, year;
	QStandardItem* dateTemp= new QStandardItem(day.setNum(payTemp->date().day())+QString("/")+month.setNum(payTemp->date().month())+QString("/")+year.setNum(payTemp->date().year()));

	account* accTemp=payTemp->requester();

	QStandardItem* requesterTemp= new QStandardItem(accTemp->user()->user());

	QStandardItem* requestTemp=0;
	if(payTemp->request()==1) requestTemp= new QStandardItem(tr("Business"));
	else requestTemp= new QStandardItem(tr("Executive"));

	QStandardItem* apprTemp=0;
	if(payTemp->approved()) apprTemp= new QStandardItem(tr("Approved)"));
	else apprTemp= new QStandardItem(tr("Not Approved"));

	dateList.push_back(dateTemp);
	userList.push_back(requesterTemp);
	requestList.push_back(requestTemp);
	apprList.push_back(apprTemp);
    }
    payRootItem->appendColumn(dateList);
    payRootItem->appendColumn(userList);
    payRootItem->appendColumn(requestList);
    payRootItem->appendColumn(apprList);

    payTable->setModel(payModel);
    connect(payTable, SIGNAL(clicked(QModelIndex)), this, SLOT(modSelected(QModelIndex)));

    acceptButton= new QPushButton(tr("Accept"), this);
    rejectButton= new QPushButton(tr("Reject"), this);

    connect(acceptButton, SIGNAL(clicked()), this, SLOT(acceptPay()));
    connect(rejectButton, SIGNAL(clicked()), this, SLOT(rejectPay()));

    layout->addWidget(payTable, 0, 0);
    layout->addWidget(acceptButton, 1, 0);
    layout->addWidget(rejectButton, 1, 1);

    setLayout(layout);
}

void adminpayments::modSelected(QModelIndex ind){
    paySelected=ind.row();
}

void adminpayments::acceptPay(){
    if(paySelected>-1){
	payment* temp=payVector[paySelected];
	temp->setApproved(Boss->accountlogged());
    }
    else QMessageBox::warning(this, tr("Error"), tr("Payment not selected.\n Please select a upgrade request"), QMessageBox::Ok, QMessageBox::Ok);
}

void adminpayments::rejectPay(){
    if(paySelected>-1){
	payment* temp=payVector[paySelected];
	temp->setRejected(Boss->accountlogged());
    }
    else QMessageBox::warning(this, tr("Error"), tr("Payment not selected.\n Please select a upgrade request"), QMessageBox::Ok, QMessageBox::Ok);
}
