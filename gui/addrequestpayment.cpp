#include "../lib/companyaccount.h"
#include "../lib/error.h"
#include "../lib/useraccount.h"

#include "addrequestpayment.h"

#include <QMessageBox>

addrequestpayment::addrequestpayment(account* acc, legami* boss, QWidget *parent) :
    QDialog(parent), accToModify(acc), Boss(boss)
{
    layout= new QGridLayout(this);

    supLabel= new QLabel(tr("Please read the description and select the request you want to make."), this);
    layout->addWidget(supLabel, 0, 1);

    businessLabel= new QLabel(tr("Business Account:"), this);
    executiveLabel= new QLabel(tr("Executive Account:"), this);

    if(dynamic_cast<useraccount*>(accToModify)){
	businessdescrLabel= new QLabel(tr("The business account allows the user to send message only to people who are in his connection list.\n Only one person per time can be insered in the addressee list."), this);
	businessdescrLabel->setWordWrap(true);
	executivedescrLabel= new QLabel(tr("Executive account can send a message to anyone who's registered to Legami."));
    }
    else{
	businessdescrLabel= new QLabel(tr("The business account can search users only by their username. \n The number of results is restricted to 30."), this);
	businessdescrLabel->setWordWrap(true);
	executivedescrLabel= new QLabel(tr("Executive account can search users by username and a filter of the experience."));
    }
    if(accToModify->type()==0){
	businessButton= new QPushButton(tr("Request Business Upgrade"), this);
	connect(businessButton, SIGNAL(clicked()), this, SLOT(createBusiness()));
    }
    else if(accToModify->type()==1){
	businessButton= 0;
    }

    executiveButton= new QPushButton(tr("Request Executive Upgrade"), this);
    connect(executiveButton, SIGNAL(clicked()), this, SLOT(createExecutive()));

    layout->addWidget(businessLabel, 1, 0);
    layout->addWidget(businessdescrLabel, 1, 1);
    layout->addWidget(businessButton, 1, 2);
    layout->addWidget(executiveLabel, 2, 0);
    layout->addWidget(executivedescrLabel, 2, 1);
    layout->addWidget(executiveButton, 2, 2);

    setLayout(layout);
}

void addrequestpayment::createBusiness(){
    payment* temp= new payment(Boss->accountlogged(), 1, QDate::currentDate(), 0);
    try{
	Boss->accountlogged()->addpayment(*temp);
    }
    catch(error er1){
	QMessageBox::warning(this, tr("Error"), er1.comment(), QMessageBox::Ok, QMessageBox::Ok);
    }
    close();
}

void addrequestpayment::createExecutive(){
    payment* temp= new payment(Boss->accountlogged(), 2, QDate::currentDate(), 0);
    try{
	Boss->accountlogged()->addpayment(*temp);
    }
    catch(error er1){
	QMessageBox::warning(this, tr("Error"), er1.comment(), QMessageBox::Ok, QMessageBox::Ok);
    }
    close();
}
