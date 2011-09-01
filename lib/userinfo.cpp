/*
  File: userinfo.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "userinfo.h"

#include <QDate>
#include <QString>

userinfo::userinfo(){}

void userinfo::setDate(const QDate& x=QDate()){
    _birthdate=x;
}

void userinfo::setEmail(QString x=""){
    _email=x;
}

void userinfo::setName(QString x=""){
    _name=x;
}

void userinfo::setNumber(QString x=""){
    _telnum=x;
}

void userinfo::setPlace(QString x=""){
    _birthplace=x;
}

void userinfo::setSurname(QString x=""){
    _surname=x;
}

QString userinfo::name() const{
    if(!_name.isEmpty()) return _name;
    return QString("");
}

QString userinfo::surname() const{
    if(!_surname.isEmpty()) return _surname;
    return QString("");
}

QDate userinfo::birthdate() const{
    if(!_birthdate.isValid()) return _birthdate;
    return QDate();
}

QString userinfo::birthplace() const{
    if(!_birthplace.isEmpty() && !_birthplace.isNull()) return _birthplace;
    return QString("");
}

QString userinfo::telnum() const{
    if(!_telnum.isEmpty()) return _telnum;
    return QString("");
}

QString userinfo::email() const{
    if(!_email.isEmpty()) return _email;
    return QString("");
}
