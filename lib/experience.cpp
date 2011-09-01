/*
  File: experience.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "experience.h"

#include <QDate>
#include <QString>

experience::experience(){}

experience::experience(int type, QString name, QDate date, QString descr){
    _type=type;
    _espname=name;
    _espdate=date;
    _descr=descr;
}


int experience::type() const{
    return _type;
}

QString experience::espname() const{
    return _espname;
}

QDate experience::espdate() const{
    return _espdate;
}

QString experience::descr() const{
    return _descr;
}

void experience::set_type(int a){
    _type=a;
}

void experience::set_namesp(QString a){
    _espname=a;
}

void experience::set_datesp(int year, int month, int day){
    _espdate=QDate(year, month, day);
}

void experience::set_descr(QString a){
    _descr=a;
}
