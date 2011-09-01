/*
  File: username.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "username.h"

#include <QString>

username::username(QString a, QString b): _username(a), _password(b){}

QString username::user()const{
    return _username;
}

QString username::pass() const{
    return _password;
}

void username::setusername(QString user){
    _username=user;
}

void username::setpassword(QString pass){
    _password=pass;
}
