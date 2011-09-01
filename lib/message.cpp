/*
  File: message.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "account.h"
#include "message.h"

#include "QString"

message::message(const account& sender, const account& recever, const QString& object, const  QString& text, bool read): _sender(const_cast<account*>(&sender)), _recever(const_cast<account*>(&recever)), _object(object), _text(text), _read(read){}

account* message::sender() const{
    return _sender;
}

account* message::recever() const{
    return _recever;
}

QString message::object() const{
    return _object;
}

QString message::text() const{
    return _text;
}

bool message::read() const{
    return _read;
}

void message::setobject(QString obj){
    _object=obj;
}

void message::settext(QString text){
    _text=text;
}

void message::readed(){
    _read=true;
}
