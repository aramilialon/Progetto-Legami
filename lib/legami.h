/*
  File: legami.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/
#ifndef LEGAMI_H
#define LEGAMI_H

#include "account.h"
#include "error.h"
#include "group.h"
#include "loader.h"
#include "message.h"

#include <QDate>
#include <QVector>

class legami
{
    friend class loader;

    QVector<account*> _userdb;
    QVector<message*> _messagedb;
    QVector<group*> _groupdb;
    loader* _loader;
    account* _accountlog;
public:
    legami(QString);
    ~legami();
    account* accountlogged() const;
    account* basicSearch(QString) const;
    account* basicSearchCompany(QString) const;
    loader* getloader() const;
    QVector<account*> Search(QString) const;
    QVector<account*> userInfoSearch(QString, QString, QDate, QString, QString, QString) const;
    QVector<account*> companyInfoSearch(QString, QString, QString) const;
    QVector<account*> experienceSearch(int, QString, QDate, QString) const;

    bool logAccount(QString, QString);
	void logoutAccount();

    void addMessage(const message&);
	void removeMessage(const message&);

    void addAccount(const account&) throw(error);
	void removeUser(const account&);

    void addGroup(const group&);
    void removeGroup(const group&);

};

#endif // LEGAMI_H
