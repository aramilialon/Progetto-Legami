/*
  File: companyinfo.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef COMPANYINFO_H
#define COMPANYINFO_H

#include <QString>

class companyinfo
{
    QString _name;
    QString _address;
    QString _cotype;
public:
    companyinfo();
    companyinfo(QString, QString, QString);
    QString name() const;
    QString address() const;
    QString cotype() const;
    void setName(QString);
    void setAddress(QString);
    void setType(QString);
};

#endif // COMPANYINFO_H
