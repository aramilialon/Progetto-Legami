#ifndef PAYMENT_H
#define PAYMENT_H

#include "account.h"
#include "error.h"

#include <QDate>
#include <QString>

class payment
{
    account* _requester;
    int _request;
    QDate _dateOfRequest;
	int _approved;

public:
	payment(account*, int, QDate, int) throw(error);
    account* requester() const;
    int request() const;
    QDate date() const;
	int approved() const;
    void setApproved(account*);
	void setRejected(account*);

};

#endif // PAYMENT_H
