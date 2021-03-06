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

class group;
class message;

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
    QVector<group*> groupSearchbyUsern(QString);
    QVector<account*> userInfoSearch(QString, QString, QDate, QString, QString, QString) const;
    QVector<account*> companyInfoSearch(QString, QString, QString) const;
    QVector<account*> experienceSearch(int, QString, QString) const;

    QVector<group*> groupDb() const;

    bool logAccount(QString, QString);
    void logoutAccount();

    void addMessage(const message&);
    void removeMessage(const message&);
    QVector<message*> messageReceved(QString);
    QVector<message*> messageSent(QString);
    QVector<message*> searchMessageAccount(QString, QString);

    void addAccount(const account&) throw(error);
    void removeUser(const account&);
    QVector<account*> userDb();

    void addGroup(const group&) throw(error);
    void removeGroup(const group&);

};

#endif // LEGAMI_H
