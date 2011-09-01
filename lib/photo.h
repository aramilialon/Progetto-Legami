#ifndef PHOTO_H
#define PHOTO_H

#include "account.h"
#include "error.h"

#include <QFile>
#include <QString>

class photo
{
    QString _type;
    QString _name;
    QString _filepath;
    QFile* _filephoto;
    QString _descr;
    account* _ouwner;
public:
    photo(QString, QString, QString, const account&) throw(error);
    ~photo();
    QString type() const;
    QString name() const;
    QString filepath() const;
    QFile* filephoto() const;
    QString descr() const;
    void changeImage(QString) throw(error);
    void setType(QString) throw(error);
    void setDescr(QString);
};

#endif // PHOTO_H
