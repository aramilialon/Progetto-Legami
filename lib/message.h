/*
  File: message.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef MESSAGE_H
#define MESSAGE_H

#include "account.h"

#include <QString>

class account;

class message
{
    account* _sender;
    account* _recever;
    QString _object;
    QString _text;
    bool _read;
public:
    message(const account&, const account&, const QString&, const QString&, bool=false);
    account* sender() const;
    account* recever() const;
    QString object() const;
    QString text() const;
    bool read() const;
    void setobject(QString);
    void settext(QString);
    void readed();
};

#endif // MESSAGE_H
