/*
  File: useraccount.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include "account.h"
#include "experience.h"
#include "legami.h"
#include "userinfo.h"
#include "username.h"

#include <QString>
#include <QVector>

class useraccount : public account
{
    userinfo* _info;
    QVector<experience*> _experiences;
    int _admin;
public:
    useraccount(QString, QString, int, const legami&);
    ~useraccount();
    username* user() const;
    userinfo* information() const;
    QVector<experience*> getexperiences() const;
    experience* getexperience(int, QString) const;
    QVector<account*> getconnections() const;
    int getadmin() const;
    void setinfo(QString, QString, int, int, int, QString, QString, QString);
    void setadmin(int);
    virtual void addexperience(const experience&);
    void addconnection(const account&);
    void removeconnection(const account&);
    void removeexperience(const experience&);
    void setinfo(const userinfo&);
    QVector<account*> search(QString, userinfo*, experience*) const;
};

#endif // USERACCOUNT_H
