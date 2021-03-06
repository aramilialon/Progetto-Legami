/*
  File: useraccount.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "account.h"
#include "legami.h"
#include "useraccount.h"
#include "userinfo.h"

#include <QString>
#include <QVector>

useraccount::useraccount(QString a, QString b, int c, const legami& d) : account(a,b,c,d)
{
    _info=new userinfo();
}

useraccount::~useraccount(){
    for(QVector<experience*>::iterator it=_experiences.begin();it!=_experiences.end();++it){
        delete *it;
    }
    _experiences.erase(_experiences.begin(), _experiences.end());
}

void useraccount::addconnection(const account& a) throw(error) {
    try{
        account::addconnection(a);
    }
    catch(error er1){
        throw error(er1.type(), er1.comment());
    }
}

void useraccount::setinfo(QString a, QString b, int c, int d, int e, QString f, QString g, QString h){
    if(_info) delete _info;
    _info=new userinfo();
    _info->setName(a);
    _info->setSurname(b);
    _info->setDate(QDate(c,d,e));
    _info->setPlace(f);
    _info->setNumber(g);
    _info->setEmail(h);
}

username* useraccount::user() const{
    return _user;
}

userinfo* useraccount::information() const{
    return _info;
}

void useraccount::addexperience(const experience &x){
    _experiences.push_back(const_cast<experience*>(&x));
}

void useraccount::setinfo(const userinfo & x){
    if(_info) delete _info;
    _info=const_cast<userinfo*>(&x);
}

QVector<experience*> useraccount::getexperiences() const{
    return _experiences;
}

QVector<account*> useraccount::getconnections() const{
    return account::getconnections();
}

QVector<account*> useraccount::search(QString x, userinfo* infosearch = 0, experience* expsearch = 0) const{
    QVector<account*> temp;
    QVector<account*> temp1=account::boss()->Search(x);
    if(infosearch){
        QVector<account*> temp2=account::boss()->userInfoSearch(infosearch->name(), infosearch->surname(), infosearch->birthdate(), infosearch->birthplace(), infosearch->telnum(), infosearch->email());
        QVector<account*>::iterator it1=temp1.begin();
        QVector<account*>::iterator it2=temp2.begin();
        for(;it1!=temp1.end();++it1){
            for(;it2!=temp2.end();++it2){
                if((*it1)==(*it2)){
                    temp2.erase(it2);
                }
            }
        }
        temp=temp1+temp2;
    }
    else{
        temp=temp1;
    }
    if(expsearch){
        QVector<account*> temp3=account::boss()->experienceSearch(expsearch->type(), expsearch->espname(), expsearch->descr());
        QVector<account*>::iterator it1=temp.begin();
        QVector<account*>::iterator it2=temp3.begin();
        for(;it1!=temp.end();++it1){
            for(;it2!=temp3.end();++it2){
                if((*it1)==(*it2)){
                    temp3.erase(it2);
                }
            }
        }
        temp=temp+temp3;
    }
    return temp;
}

void useraccount::setadmin(int admin){
    _admin=admin;
}

int useraccount::getadmin() const{
    return _admin;
}

void useraccount::removeconnection(const account& acc){
    account::removeconnection(acc);
}
void useraccount::removeexperience(const experience & olexp){
    for(QVector<experience*>::iterator it=_experiences.begin();it!=_experiences.end();++it){
        if(*it==&olexp){
            delete *it;
            _experiences.erase(it);
            return;
        }
    }
}
