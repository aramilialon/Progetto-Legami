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
#include "photo.h"
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
    QVector<photo*> _photos;
    QVector<payment*> _payments;

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

    QVector<payment*> payments() const;
	payment* getpayment(const payment&) const;
	virtual void addpayment(const payment&) throw(error);

	virtual QVector<photo*> getphotos() const;
    virtual QVector<photo*> getphotobytag(QString) const;
    virtual photo* getphotobyname(QString, QString) const;
	virtual void addphoto(const photo&);
	virtual void removephoto(const photo&);

    virtual QVector<account*> getconnections() const;
    virtual void addconnection(const account&);
	virtual void removeconnection(const account&);

    virtual void newmessage(const account&, const account&, QString, QString);


};

#endif // ACCOUNT_H