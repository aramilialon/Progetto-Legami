/*
  File: companyinfo.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "companyinfo.h"

#include <QString>

companyinfo::companyinfo(){}

void companyinfo::setName(QString x=""){
    _name=x;
}

void companyinfo::setAddress(QString x=""){
    _address=x;
}

void companyinfo::setType(QString x=""){
    _cotype=x;
}

QString companyinfo::name() const{
    if(!_name.isEmpty()) return _name;
    else return QString("");
}

QString companyinfo::address() const{
    if(!_address.isEmpty()) return _address;
    else return QString("");
}

QString companyinfo::cotype() const{
    if(!_cotype.isEmpty()) return _cotype;
    else return QString("");
}
