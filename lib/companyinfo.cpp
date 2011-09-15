/*
  File: companyinfo.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "companyinfo.h"

#include <QString>

companyinfo::companyinfo(){}

companyinfo::companyinfo(QString a, QString b, QString c){
    _name=a;
    _address=b;
    _cotype=c;
}

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
    return _name;
}

QString companyinfo::address() const{
    return _address;
}

QString companyinfo::cotype() const{
    return _cotype;
}
