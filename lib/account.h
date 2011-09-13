/*
  File: account.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "error.h"
#include "experience.h"
#include "legami.h"
#include "message.h"
#include "payment.h"
#include "username.h"

#include <QString>
#include <QVector>

class legami;
class payment;

class account
{

    int _type;
    legami* _boss;
    QVector<account*> _connection;
    QVector<payment*> _payments;

    account* getconnection(QString);
protected:
    username* _user;
public:
    account(QString, QString, int,  const legami&);
    ~account();

    virtual username* user() const =0;
    void setuser(QString, QString);

    int type() const;
    void setype(int);

    legami* boss() const;

    QVector<payment*> payments();
    payment* getpayment(const payment&) const;
    virtual void addpayment(const payment&) throw(error);
    payment* getlastpaymentapproved();

    virtual QVector<account*> getconnections() const;
    virtual void addconnection(const account&) throw(error);
    virtual void removeconnection(const account&);

    virtual void newmessage(const account&, const account&, QString, QString);


};

#endif // ACCOUNT_H
