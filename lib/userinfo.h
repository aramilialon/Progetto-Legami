/*
  File: userinfo.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef USERINFO_H
#define USERINFO_H

#include <QString>
#include <QDate>

class userinfo
{
    QString _name;
    QString _surname;
    QDate _birthdate;
    QString _birthplace;
    QString _telnum;
    QString _email;
public:
    userinfo();
    QString name() const;
    QString surname() const;
    QDate birthdate() const;
    QString birthplace() const;
    QString telnum() const;
    QString email() const;
    void setName(QString);
    void setSurname(QString);
    void setDate(const QDate&);
    void setPlace(QString);
    void setNumber(QString);
    void setEmail(QString);
};

#endif // INFO_H
