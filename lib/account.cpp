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
#include "photo.h"
#include "username.h"

#include <QString>
#include <QVector>

account::account(QString a, QString b, int c,  const legami& d): _type(c),  _boss(const_cast<legami*>(&d)), _user(new username(a,b)){}

account::~account() {
    delete _user;
    _connection.erase(_connection.begin(), _connection.end());
    _photos.erase(_photos.begin(), _photos.end());
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

void account::addconnection (const account& a){
    account* temp=const_cast<account*>(&a);
    _connection.push_back(temp);
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

void account::addphoto(const photo& newphoto){
    if(_type!=0)
    _photos.push_back(const_cast<photo*>(&newphoto));
}

void account::removephoto(const photo & oldphoto){
    bool erased=false;
    for(QVector<photo*>::iterator it=_photos.begin();it!=_photos.end();++it){
        if(*it==&oldphoto){
            delete *it;
            _photos.erase(it);
            erased=true;
        }
    }
}

QVector<photo*> account::getphotos() const{
    return _photos;
}

QVector<photo*> account::getphotobytag(QString tag) const{
    QVector<photo*> temp;
    for(QVector<photo*>::const_iterator it=_photos.begin(); it!=_photos.end();++it){
        if((*it)->type()==tag) temp.push_back(*it);;
    }
    return temp;
}

photo* account::getphotobyname(QString tag, QString name) const{
    for(QVector<photo*>::const_iterator it=_photos.begin(); it!=_photos.end();++it){
        if((*it)->type()==tag && (*it)->name()==name) return *it;
    }
    return 0;
}

QVector<payment*> account::payments() const{
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
