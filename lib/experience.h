/*
  File: experience.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <QDate>
#include <QString>

class experience
{
    int _type;
    QString _espname;
    QDate _espdate;
    QString _descr;
public:
    experience();
    experience(int, QString=QString(""), QDate=QDate(), QString=QString(""));
    int type() const;
    QString espname() const;
    QDate espdate() const;
    QString descr() const;
    void set_type(int);
    void set_namesp(QString);
    void set_datesp(int, int, int);
    void set_descr(QString);
};
#endif // EXPERIENCE_H
