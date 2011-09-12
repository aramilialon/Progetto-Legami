/*
  File: payment.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "error.h"
#include "payment.h"
#include "useraccount.h"

payment::payment(account* requester, int requested, QDate date= QDate::currentDate(), int approved=0) throw(error)
{
    QVector<payment*>::const_iterator it=requester->payments().begin();
    for(;it!=requester->payments().end();++it){
	if((*it)->approved()==0)
	    throw error(Payment, QString("There already is a request not accepted yet.\n Please wait until your request is accepted or rejected."));
    }
    _requester=requester;
    _request=requested;
    _dateOfRequest=date;
    _approved=approved;
    if(_approved) _requester->setype(_request);
}

account* payment::requester() const{
    return _requester;
}

int payment::request() const{
    return _request;
}

QDate payment::date() const{
    return _dateOfRequest;
}

int payment::approved() const{
    return _approved;
}

void payment::setApproved(account * admin) throw(error){
    if(dynamic_cast<useraccount*>(admin)->getadmin()==1 && _approved==0){
	_approved=1;
	_requester->setype(_request);
    }
    else throw error(Permission, QString("User not allowed to approve payments"));
}

void payment::setRejected(account * admin){
    if(dynamic_cast<useraccount*>(admin)->getadmin()==1 && _approved==0){
	_approved=-1;
    }
}
