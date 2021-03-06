/*
  File: group.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "account.h"
#include "group.h"
#include "username.h"

#include <QString>
#include <QVector>

group::group(QString name, QString descr=" "): _name(name), _descr(descr){}

group::~group(){
    _admins.erase(_admins.begin(),_admins.end());
    _members.erase(_members.begin(), _members.end());
}

QVector<account*> group::members() const{
    return _members;
}

QString group::name() const{
    return _name;
}

QString group::descr() const{
    return _descr;
}

QVector<account*> group::admins() const{
    return _admins;
}

account* group::getmember(QString username) const{
    QVector<account*>::const_iterator it=_members.begin();
    for(;it!=_members.end();++it){
        if((*it)->user()->user()==username) return (*it);
    }
    return 0;
}

account* group::getmember(const account & self) const{
    account* temp=const_cast<account*>(&self);
    QVector<account*>::const_iterator it=_members.begin();
    for(;it!=_members.end();++it){
        if((*it)==temp) return (*it);
    }
    return 0;
}

account* group::getadmin(QString username) const{
    QVector<account*>::const_iterator it=_admins.begin();
    for(;it!=_admins.end();++it){
        if((*it)->user()->user()==username) return (*it);
    }
    return 0;
}

account* group::getadmin(const account & self) const{
    account* temp=const_cast<account*>(&self);
    QVector<account*>::const_iterator it=_admins.begin();
    for(;it!=_admins.end();++it){
        if((*it)==temp) return (*it);
    }
    return 0;
}

void group::addmember(const account& newacc){
    account* temp=getmember(newacc);
    if(!temp) _members.push_back(const_cast<account*>(&newacc));
}

void group::setname(QString name){
    _name=name;
}

void group::setdescr(QString newdescr){
    _descr=newdescr;
}

void group::addadmin(QString newadmin){
    account* temp=_members[0]->boss()->basicSearch(newadmin);
    _admins.push_back(const_cast<account*>(temp));
}

void group::removemember(QString user){
    account* temp= _members[0]->boss()->basicSearch(user);

    QVector<account*>::iterator it=_admins.begin();
    for(;it<_admins.end();++it){
        if(*it==temp) _admins.erase(it);
    }

    it= _members.begin();
    for(;it<_members.end();++it){
        account* temp1= (*it);
        if(temp1==temp) _members.erase(it);
    }
}

void group::removeadmin(QString toberemoved){
    account* temp= _members[0]->boss()->basicSearch(toberemoved);
    QVector<account*>::iterator it=_admins.begin();
    for(;it<_admins.end();++it){
        if((*it)==temp) _admins.erase(it);
    }
}
