/*
  File: companyaccount.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "account.h"
#include "companyaccount.h"
#include "companyinfo.h"
#include "legami.h"

#include <QString>
#include <QVector>

companyaccount::companyaccount(QString user, QString pass, int type, const legami& boss): account(user, pass, type, boss)
{
    _info=new companyinfo();
}

companyaccount::~companyaccount(){
    delete _info;
}

username* companyaccount::user() const{
    return _user;
}

account* companyaccount::businessSearch(QString usern) const{
    return account::boss()->basicSearch(usern);
}

companyinfo* companyaccount::information() const{
    return _info;
}

QVector<account*> companyaccount::getconnections() const{
    return account::getconnections();
}

void companyaccount::setInfo(QString name, QString address, QString cotype){
    delete _info;
    _info=new companyinfo();
    _info->setName(name);
    _info->setAddress(address);
    _info->setType(cotype);
}

void companyaccount::newmessage(const account & sender, const account & recever, QString object, QString text) throw(error){
    if(account::type()!=0) account::newmessage(sender, recever, object, text);
    else throw error(Permission, QString("Basic account cannot send any message"));
}

void companyaccount::setInfo(const companyinfo & x){
    if(_info) delete _info;
    _info= const_cast<companyinfo*>(&x);
}
