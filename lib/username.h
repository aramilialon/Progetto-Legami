/*
  File: username.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef USERNAME_H
#define USERNAME_H

#include <QString>

class username
{
    QString _username;
    QString _password;
public:
    username(QString, QString);
    QString user() const;
    QString pass() const;
    void setusername(QString);
    void setpassword(QString);
};
#endif // USERNAME_H
