/*
  File: companyaccount.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef COMPANYACCOUNT_H
#define COMPANYACCOUNT_H

#include "account.h"
#include "companyinfo.h"
#include "error.h"
#include "photo.h"

#include <QString>
#include <QVector>

class companyaccount : public account
{
    companyinfo* _info;
public:
    companyaccount(QString, QString, int, const legami&);
    ~companyaccount();
    QVector<account*> search(QString) const;
    username* user() const;
    companyinfo* information() const;
    QVector<account*> getconnections() const;
    void setInfo(QString, QString, QString);
    void setInfo(const companyinfo& );
    virtual void addphoto(QString, QString, QString);
    QVector<photo*> getphotos() const;
    void newmessage(const account &, const account &, QString, QString) throw(error);
    void removephoto(const photo&);
};

#endif // COMPANYACCOUNT_H
