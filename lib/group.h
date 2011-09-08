#ifndef GROUP_H
#define GROUP_H

#include "account.h"

#include <QString>
#include <QVector>

class account;

class group
{
    QVector<account*> _members;
    QString _name;
    QString _descr;
    QVector<account*> _admins;
public:
    group(QString, QString);
    ~group();
    QVector<account*> members() const;
    QString name() const;
    QString descr() const;
    QVector<account*> admins() const;
    account* getmember(QString) const;
    account* getmember(const account&)const;
    account* getadmin(QString)const;
    account* getadmin(const account&)const;
    void addmember(const account&);
    void setname(QString);
    void setdescr(QString);
    void addadmin(QString);
    void removemember(QString);
    void removeadmin(QString);
};

#endif // GROUP_H
