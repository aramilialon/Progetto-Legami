/*
  File: error.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef ERROR_H
#define ERROR_H

#include <QString>

enum typeError{
    IO=0,
    Permission,
    Photography,
	Username,
	Payment,
    Group
};

class error{
    typeError _type;
    QString _comment;
public:
    error(typeError type, QString comm=""): _type(type), _comment(comm){}
    typeError type() const{return _type;}
    QString comment() const{return _comment;}
};

#endif // ERROR_H
