/*
  File: legami.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "account.h"
#include "companyaccount.h"
#include "companyinfo.h"
#include "error.h"
#include "experience.h"
#include "group.h"
#include "legami.h"
#include "loader.h"
#include "message.h"
#include "useraccount.h"


legami::legami(QString path)
{
    _loader= new loader(path,*this);
}

legami::~legami(){

    _userdb.erase(_userdb.begin(),_userdb.end());
    _messagedb.erase(_messagedb.begin(), _messagedb.end());
}

account* legami::basicSearch(QString usern) const{
    QVector<account*>::const_iterator it=_userdb.begin();
    for(;it!=_userdb.end();++it){
        if((**it).user()->user()==usern){
            return *it;
        }
    }
    return 0;
}

account* legami::basicSearchCompany(QString name) const{
    QVector<account*>::const_iterator it=_userdb.begin();
    for(;it!=_userdb.end();++it){
        if(dynamic_cast<useraccount*>((*it))){
            useraccount* temp=dynamic_cast<useraccount*>(*it);
            QString nametemp=temp->information()->name();
            if(nametemp==name) return (*it);
        }
        else{
            companyaccount* temp=dynamic_cast<companyaccount*>(*it);
            QString nametemp=temp->information()->name();
            if(nametemp==name) return (*it);
        }
    }
    return 0;
}

QVector<account*> legami::Search(QString name) const{
    QVector<account*> templist;
    QVector<account*>::const_iterator it=_userdb.begin();
    for(;it!=_userdb.end();++it){
        if(dynamic_cast<useraccount*>((*it))){
            useraccount* temp=dynamic_cast<useraccount*>(*it);
            QString nametemp=temp->information()->name();
            if(nametemp==name) templist.push_back((*it));
        }
        else{
            companyaccount* temp=dynamic_cast<companyaccount*>(*it);
            QString nametemp=temp->information()->name();
            if(nametemp==name) templist.push_back((*it));
        }
    }
    return templist;
}

void legami::addMessage(const message& a){
    message* temp=const_cast<message*>(&a);
    _messagedb.push_back(temp);
}

void legami::addGroup(const group& newgroup) throw(error){
    QVector<group*>::iterator it=_groupdb.begin();
    if(!_groupdb.isEmpty()){
        for(;it!=_groupdb.end();++it){
            if((*it)->name()==newgroup.name()) throw error(Group, QString("Group with the same name already exists"));
        }
    }
    _groupdb.push_back(const_cast<group*>(&newgroup));
}

void legami::addAccount(const account& acc) throw(error){
    account* temp=const_cast<account*>(&acc);
    for(QVector<account*>::const_iterator it=_userdb.begin(); it!=_userdb.end();++it){
        if(acc.user()->user()==(*it)->user()->user()){
            throw error(Username, "Same username already registered");
        }
    }
    _userdb.push_back(temp);
}

void legami::removeMessage(const message & oldmessage){
    message* temp=const_cast<message*>(&oldmessage);
    QVector<message*>::iterator it=_messagedb.begin();
    for(;it!=_messagedb.end();++it){
        if((*it)==temp){
            delete *it;
            _messagedb.erase(it);
            return;
        }
    }
}

void legami::removeGroup(const group & oldgroup){
    group* temp=const_cast<group*>(&oldgroup);
    QVector<group*>::iterator it=_groupdb.begin();
    for(;it!=_groupdb.end();++it){
        if((*it)==temp){
            delete *it;
            _groupdb.erase(it);
            return;
        }
    }
}

void legami::removeUser(const account& acc){
    account* temp=const_cast<account*>(&acc);
    QVector<group*>::iterator grpIt= _groupdb.begin();
    for(;grpIt!=_groupdb.end();++grpIt){
        if((*grpIt)->getmember(*temp)) (*grpIt)->removemember(temp->user()->user());
    }
    QVector<account*>::iterator it=_userdb.begin();
    for(;it!=_userdb.end();++it){
        if(*it==temp){
            delete *it;
            _userdb.erase(it);
            return;
        }
    }
}

account* legami::accountlogged() const{
    return _accountlog;
}

void legami::logoutAccount(){
    _accountlog=0;
}

bool legami::logAccount(QString usern, QString passw){
    QVector<account*>::const_iterator it=_userdb.begin();
    for(;it!=_userdb.end();++it){
        QString user=(*it)->user()->user();
        QString pass=(*it)->user()->pass();
        if(user==usern && pass==passw){
            _accountlog=(*it);
            return true;
        }
    }
    return false;
}

QVector<account*> legami::companyInfoSearch(QString name, QString address, QString cotype) const{
    bool nameok=false,
            addressok=false,
            cotypeok=false;
    QVector<account*> temp;
    QVector<account*>::const_iterator it=_userdb.begin();
    for(;it!=_userdb.end();++it){
        if(dynamic_cast<companyaccount*>(*it)){
            companyaccount* accounttemp=dynamic_cast<companyaccount*>(*it);
            if(!name.isEmpty()){
                if(accounttemp->information()->name()==name) nameok=true;
            }
            if(!address.isEmpty()){
                if(accounttemp->information()->address()==address) addressok=true;
            }
            if(!cotype.isEmpty()){
                if(accounttemp->information()->cotype()==cotype) cotypeok=true;
            }
            if(nameok || addressok || cotypeok) temp.push_back(*it);
            nameok=addressok=cotypeok=false;
        }
    }
    return temp;
}

QVector<account*> legami::userInfoSearch(QString name, QString surname, QDate date, QString place, QString telnum, QString email) const{
    bool nameok=false,
            surnameok=false,
            dateok=false,
            placeok=false,
            telnumok=false,
            emailok=false;
    QVector<account*> temp;
    QVector<account*>::const_iterator it=_userdb.begin();
    for(;it!=_userdb.end();++it){
        if(dynamic_cast<useraccount*>(*it)){
            useraccount* accounttemp=dynamic_cast<useraccount*>(*it);
            if(!name.isEmpty()){
                if(accounttemp->information()->name()==name) nameok=true;
            }
            if(!surname.isEmpty()){
                if(accounttemp->information()->surname()==surname) surnameok=true;
            }
            if(!date.isNull()&&date.isValid()){
                if(accounttemp->information()->birthdate()==date) dateok=true;
            }
            if(!place.isEmpty()){
                if(accounttemp->information()->birthplace()==place) placeok=true;
            }
            if(!telnum.isEmpty()){
                if(accounttemp->information()->telnum()==telnum) telnumok=true;
            }
            if(!email.isEmpty()){
                if(accounttemp->information()->email()==email) emailok=true;
            }
            if(nameok || surnameok || dateok || placeok || telnumok || emailok) temp.push_back(*it);
            nameok=surnameok=dateok=placeok=telnumok=emailok=false;
        }
    }
    return temp;
}

QVector<account*> legami::experienceSearch(int type, QString name, QString descr) const{
    bool typeok=false,
            nameok=false,
            descrok=false,
            found=false;
    QVector<account*> temp;
    QVector<account*>::const_iterator it=_userdb.begin();
    for(;it!=_userdb.end()&&!found;++it){
        if(dynamic_cast<useraccount*>(*it)){
            useraccount* accounttemp=dynamic_cast<useraccount*>(*it);
            QVector<experience*> expuser=accounttemp->getexperiences();
            QVector<experience*>::const_iterator it1=expuser.begin();
            for(;it1!=expuser.end();++it1){
                if(type==(*it1)->type()) typeok=true;
                if(!name.isEmpty()){
                    if((*it1)->espname()==name) nameok=true;
                }
                if(!descr.isNull()){
                    if((*it1)->descr()==descr) descrok=true;
                }
                if(typeok || nameok || descrok){
                    found=true;
                    temp.push_back(*it);
                }
            }
            typeok=nameok=descrok=false;
        }
    }
    return temp;
}

loader* legami::getloader() const{
    return _loader;
}

QVector<group*> legami::groupSearchbyUsern(QString usern){
    QVector<group*> temp;
    QVector<group*>::iterator it=_groupdb.begin();
    for(;it!=_groupdb.end();++it){
        if((*it)->getmember(usern)) temp.push_back(*it);
    }
    return temp;
}


QVector<group*> legami::groupDb() const{
    return _groupdb;
}

QVector<message*> legami::messageReceved(QString usern){
    QVector<message*> temp;
    QVector<message*>::iterator it=_messagedb.begin();
    for(;it<_messagedb.end();++it){
        if((*it)->recever()->user()->user()==usern) temp.append(*it);
    }
    return temp;
}

QVector<message*> legami::messageSent(QString usern){
    QVector<message*> temp;
    QVector<message*>::iterator it=_messagedb.begin();
    for(;it<_messagedb.end();++it){
        if((*it)->sender()->user()->user()==usern) temp.append(*it);
    }
    return temp;
}

QVector<message*> legami::searchMessageAccount(QString searcher, QString searched){
    QVector<message*> temp;
    QVector<message*>::iterator it=_messagedb.begin();
    for(;it<_messagedb.end();++it){
        if((*it)->sender()->user()->user()==searcher && (*it)->recever()->user()->user()==searched) temp.append(*it);
        else if((*it)->sender()->user()->user()==searched && (*it)->recever()->user()->user()==searcher) temp.append(*it);
    }
    return temp;
}

QVector<account*> legami::userDb(){
    return _userdb;
}
