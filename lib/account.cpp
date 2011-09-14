/*
  File: account.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "account.h"
#include "error.h"
#include "experience.h"
#include "legami.h"
#include "message.h"
#include "payment.h"
#include "username.h"

#include <QString>
#include <QVector>

account::account(QString a, QString b, int c,  const legami& d): _type(c),  _boss(const_cast<legami*>(&d)), _user(new username(a,b)){}

account::~account() {
    delete _user;
    _connection.erase(_connection.begin(), _connection.end());
}

username* account::user() const{
    return _user;
}

int account::type() const{
    return _type;
}

legami* account::boss() const{
    return _boss;
}

void account::setuser(QString a, QString b){
    if(_user) delete _user;
    _user=new username(a,b);
}

void account::setype(int a){
    _type=a;
}

QVector<account*> account::getconnections() const{
    return _connection;
}

void account::addconnection (const account& a) throw(error){
    account* temp=const_cast<account*>(&a);
    if(!getconnection(temp->user()->user())){
        _connection.push_back(temp);
    }
    else throw error(Connection, QString("You are already connected with this user"));

}

void account::removeconnection(const account& a){
    account* temp=const_cast<account*>(&a);
    QVector<account*>::iterator it=_connection.begin();
    bool finish=false;
    for(;it!=_connection.end()&&!finish;++it){
        if(*it==temp){
            _connection.erase(it);
            finish=true;
        }
    }
}

void account::newmessage(const account& sender, const account& rec, QString obj, QString text) {
    message* mess=new message(sender, rec, obj, text);
    _boss->addMessage(*mess);
}

QVector<payment*> account::payments(){
    return _payments;
}

payment* account::getpayment(const payment & paytemp) const{
    for(QVector<payment*>::const_iterator it=_payments.begin(); it!=_payments.end();++it){
        if((*it)->request()==paytemp.request() && (*it)->date()==paytemp.date() && (*it)->approved()==paytemp.approved()) return *it;
    }
    return 0;
}

void account::addpayment(const payment & newpay) throw(error){
    for(QVector<payment*>::const_iterator it=_payments.begin(); it!=_payments.end();++it){
        if((*it)->request()==newpay.request() && (*it)->approved()==0){
            throw error(Payment, QString("Another payment of the same type has been already requested"));
        }
    }
    _payments.push_back(const_cast<payment*>(&newpay));
}

account* account::getconnection(QString usern){
    QVector<account*>::iterator it=_connection.begin();
    account* temp=_boss->basicSearch(usern);
    for(;it<_connection.end();++it){
        if((*it)==temp) return (*it);
    }
    return 0;
}

payment* account::getlastpaymentapproved(){
    QVector<payment*>::iterator it=_payments.begin();
    QDate temp=QDate();
    payment* payTemp=0;
    for(;it<_payments.end();++it){
        if(((*it)->date())>temp && (*it)->approved()==1){
            payTemp=*it;
            temp=(*it)->date();
        }
    }
    return payTemp;
}
