/*
  File: loader.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "companyaccount.h"
#include "companyinfo.h"
#include "error.h"
#include "experience.h"
#include "legami.h"
#include "loader.h"
#include "payment.h"
#include "photo.h"
#include "useraccount.h"
#include "userinfo.h"
#include "username.h"

#include <QDate>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QtXml/QDomElement>
#include <QtXml/QDomNode>
#include <QtXml/QDomText>
#include <QVector>

loader::loader(QString path, const legami& boss): _boss(const_cast<legami*>(&boss)), _db(path){}

void loader::loaddb() throw(error){
    QDomDocument doc(QString("legami_database"));
    QFile db(_db);
    if(!db.open(QIODevice::ReadOnly)){
        throw error(IO, QString("Error opening the database file.\n May it not exists?"));
    }
    if(!doc.setContent(&db)){
        db.close();
        throw error(IO,QString("Error in handling db file"));
    }
    QDomElement filedb=doc.documentElement();
    if(filedb.tagName()!=QString("legami")){
        throw error(IO,QString("Root tree not found"));
    }
    QDomNode x=filedb.firstChild();
    if(x.nodeName()!=QString("users")){
        throw error(IO,QString("Users node not found"));
    }
    loaduser(x);
    x=x.nextSibling();
    if(x.isNull()||x.nodeName()!=QString("connections")){
        throw error(IO,QString("Connections node not found"));
    }
    else loadconnections(x);
    x=x.nextSibling();
    if(x.isNull()||x.nodeName()!=QString("groups")){
        throw error(IO,QString("Groups node not found"));
    }
    else loadgroups(x);
    x=x.nextSibling();
    if(x.isNull()||x.nodeName()!=QString("messages")){
        throw error(IO,QString("Messages node not found"));
    }
    else loadmessages(x);
    x=x.nextSibling();
    if(x.isNull()||x.nodeName()!=QString("photos")){
        throw error(IO, QString("Photos node not found"));
    }
    else loadphotos(x);
    x=x.nextSibling();
    if(x.isNull()||x.nodeName()!=QString("payments")){
        throw error(IO, QString("Payments node not found"));
    }
    else loadpayments(x);
    db.close();
}

void loader::loaduser(QDomNode users){
    QDomNode temp=users.firstChild();
    if(!temp.isNull()&&temp.nodeName()==QString("user")){
        while(!temp.isNull()){
            QDomNode userdata=temp.namedItem(QString("userdata"));
            QString user=userdata.firstChildElement(QString("username")).text(),
                    pass=userdata.firstChildElement(QString("password")).text(),
                    type=userdata.firstChildElement(QString("type")).text(),
                    acctype=userdata.firstChildElement(QString("acctype")).text(),
                    admin=userdata.firstChildElement(QString("admin")).text();
            account* newuser=0;
            if(type.toStdString()=="user"){
                newuser= new useraccount(user, pass, acctype.toInt(), *_boss);
                useraccount* tempuser=dynamic_cast<useraccount*>(newuser);
                tempuser->setadmin(admin.toInt());
                QDomNode infos=temp.namedItem(QString("infos"));
                if(!infos.isNull()){
                    loaduserinfo(infos, newuser);
                }
                QDomNode exps=temp.namedItem(QString("experiences"));
                if(!exps.isNull()){
                    loaduserexperiences(exps, newuser);
                }
            }
            else{
                newuser= new companyaccount(user, pass, acctype.toInt(), *_boss);
                QDomNode infos=temp.namedItem(QString("infos"));
                if(!infos.isNull()){
                    loadcompanyinfo(infos, newuser);
                }
            }
            _boss->addAccount(*newuser);
            temp=temp.nextSibling();
        }
    }
}

void loader::loaduserinfo(QDomNode infos, account* newaccount){
    useraccount* temp=dynamic_cast<useraccount*>(newaccount);
    QString name=infos.firstChildElement(QString("name")).text(),
            surname=infos.firstChildElement(QString("surname")).text(),
            daybirth=infos.firstChildElement(QString("daybirth")).text(),
            monthbirth=infos.firstChildElement(QString("monthbirth")).text(),
            yearbirth=infos.firstChildElement(QString("yearbirth")).text(),
            telnum=infos.firstChildElement(QString("telnum")).text(),
            email=infos.firstChildElement(QString("email")).text();
    userinfo* infotemp=new userinfo();
    if(!name.isEmpty()) infotemp->setName(name);
    if(!surname.isEmpty()) infotemp->setSurname(surname);
    if(!daybirth.isEmpty()&&!monthbirth.isEmpty()&&!yearbirth.isEmpty()) infotemp->setDate(QDate(yearbirth.toInt(), monthbirth.toInt(), daybirth.toInt()));
    if(!telnum.isEmpty()) infotemp->setNumber(telnum);
    if(!email.isEmpty()) infotemp->setEmail(email);
    temp->setinfo(*infotemp);
}

void loader::loaduserexperiences(QDomNode exps, account * newaccount){
    useraccount* temp=dynamic_cast<useraccount*>(newaccount);
    QDomNode x=exps.firstChild();
    if(!x.isNull() && x.nodeName()==QString("experience")){
        while(!x.isNull()){
            QString exptype=x.firstChildElement(QString("exptype")).text(),
                    expname=x.firstChildElement(QString("expname")).text(),
                    dayexp=x.firstChildElement(QString("dayexp")).text(),
                    monthexp=x.firstChildElement(QString("monthexp")).text(),
                    yearexp=x.firstChildElement(QString("yearexp")).text(),
                    expdescr=x.firstChildElement(QString("expdescr")).text();
            experience* exptemp=new experience();
            exptemp->set_type(exptype.toInt());
            exptemp->set_namesp(expname);
            exptemp->set_datesp(yearexp.toInt(),monthexp.toInt(),dayexp.toInt());
            exptemp->set_descr(expdescr);
            temp->addexperience(*exptemp);
            x=x.nextSibling();
        }
    }
}

void loader::loadcompanyinfo(QDomNode infos, account* newaccount){
    companyaccount* temp=dynamic_cast<companyaccount*>(newaccount);
    QString name=infos.firstChildElement(QString("name")).text(),
            address=infos.firstChildElement(QString("address")).text(),
            cotype=infos.firstChildElement(QString("cotype")).text();
    QString nametemp=QString(""), addresstemp=QString(""), cotypetemp=QString("");
    if(!name.isEmpty()) nametemp=name;
    if(!address.isEmpty()) addresstemp=address;
    if(!cotype.isEmpty()) cotypetemp=cotype;
    temp->setInfo(nametemp, addresstemp, cotypetemp);
}

void loader::loadconnections(QDomNode conns){
    QDomNode temp=conns.firstChild();
    if(!temp.isNull()){
        while(!temp.isNull()){
            QString applicant=temp.firstChildElement(QString("applicant")).text(),
                    applied=temp.firstChildElement(QString("applied")).text();
            account* requester=_boss->basicSearch(applicant);
            if(requester){
                account* requested=_boss->basicSearch(applied);
                if(requested) requester->addconnection(*requested);
            }
            temp=temp.nextSibling();
        }
    }
}

void loader::loadpayments(QDomNode payments){
    QDomNode temp=payments.firstChild();
    if(!temp.isNull()){
        while(!temp.isNull()){
            QString requester= temp.firstChildElement(QString("requester")).text();
            account* requestertemp=_boss->basicSearch(requester);
            int typetemp= temp.firstChildElement(QString("typerequested")).text().toInt(),
                    daytemp= temp.firstChildElement(QString("dayrequest")).text().toInt(),
                    monthtemp= temp.firstChildElement(QString("monthrequest")).text().toInt(),
                    yeartemp= temp.firstChildElement(QString("yearrequest")).text().toInt(),
                    approvedtemp= temp.firstChildElement(QString("approved")).text().toInt();
            if(requestertemp){
                payment* paytemp= new payment(requestertemp, typetemp, QDate(yeartemp, monthtemp, daytemp), approvedtemp);
                requestertemp->addpayment(*paytemp);
            }
            temp=temp.nextSibling();
        }
    }
}

void loader::loadphotos(QDomNode photos){
    QDomNode temp=photos.firstChild();
    if(!temp.isNull()){
        while(!temp.isNull()){
            QString type=temp.firstChildElement(QString("type")).text(),
                    name=temp.firstChildElement(QString("name")).text(),
                    filepath=temp.firstChildElement(QString("filepath")).text(),
                    descr=temp.firstChildElement(QString("descr")).text(),
                    ouwner=temp.firstChildElement(QString("ouwner")).text();
            account* acctemp=_boss->basicSearch(ouwner);
            photo* phototemp= new photo(type, name, filepath, *acctemp);
            acctemp->addphoto(*phototemp);
            phototemp->setDescr(descr);
            temp=temp.nextSibling();
        }
    }
}

void loader::loadgroups(QDomNode groups){
    QDomNode temp=groups.firstChild();
    if(!temp.isNull() && temp.nodeName()==QString("group")){
        while(!temp.isNull()){
            QString name=temp.firstChildElement(QString("name")).text(),
                    descr=temp.firstChildElement(QString("descr")).text();
            QVector<QString> userlisttemp;
            QDomElement memberslistnode=temp.namedItem(QString("members")).firstChildElement(QString("member"));
            while(!memberslistnode.isNull()){
                userlisttemp.push_back(memberslistnode.text());
		memberslistnode= memberslistnode.nextSiblingElement(QString("member"));
            }
            QVector<QString>adminlisttemp;
            QDomElement adminslistnode=temp.namedItem(QString("admins")).firstChildElement(QString("admin"));
            while(!adminslistnode.isNull()){
                adminlisttemp.push_back(adminslistnode.text());
		adminslistnode= adminslistnode.nextSiblingElement(QString("admin"));
            }
            QVector<account*> memberslist;
            QVector<account*> adminslist;
            QVector<QString>::const_iterator members=userlisttemp.begin();
            for(;members!=userlisttemp.end();++members){
                account* temp=_boss->basicSearch((*members));
                if(temp) memberslist.push_back(temp);
            }
            QVector<QString>::const_iterator admins=adminlisttemp.begin();
            for(;admins!=adminlisttemp.end();++admins){
                account* temp=_boss->basicSearch((*admins));
                if (temp) adminslist.push_back(temp);
            }
            group* newgroup= new group(name, descr);
	    QVector<account*>::const_iterator temp1=memberslist.begin();
	    for(;temp1!=memberslist.end();++temp1){
		newgroup->addmember((**temp1));
            }
	    temp1=adminslist.begin();
	    for(;temp1!=adminslist.end();++temp1){
		newgroup->addadmin((*temp1)->user()->user());
            }
            _boss->addGroup(*newgroup);
	    temp=temp.nextSibling();
	}
    }
}

void loader::loadmessages(QDomNode mess){
    QDomNode temp=mess.firstChild();
    if(!temp.isNull() && temp.nodeName()==QString("message")){
        while(!temp.isNull()){
            QString sender=temp.firstChildElement(QString("sender")).text(),
                    recever=temp.firstChildElement(QString("recever")).text(),
                    object=temp.firstChildElement(QString("object")).text(),
                    text=temp.firstChildElement(QString("text")).text(),
                    read=temp.firstChildElement(QString("read")).text();
            account* _sender=_boss->basicSearch(sender);
            account* _recever=_boss->basicSearch(recever);
            if(_sender&&_recever){
                message* messtemp=new message(*_sender,*_recever,object,text,bool(read.toInt()));
                _boss->addMessage(*messtemp);
            }
            temp=temp.nextSibling();
        }
    }
}

void loader::writedb() throw(error){
    QFile database(QString("./database.xml"));
    QDomDocument* root=new QDomDocument(QString("legami"));
    QDomNode legami=root->createElement(QString("legami"));
    root->appendChild(legami);
    QDomNode users=root->createElement(QString("users")),
            connections=root->createElement(QString("connections")),
            groups=root->createElement(QString("groups")),
            messages=root->createElement(QString("messages")),
            photos=root->createElement(QString("photos")),
            payments=root->createElement(QString("payments"));
    writeusers(users, *root);
    writeconnections(connections, *root);
    writegroups(groups,*root);
    writemessages(messages, *root);
    QVector<account*>::const_iterator it=_boss->_userdb.begin();
    for(;it!=_boss->_userdb.end();++it){
        writephotos((**it), photos, *root);
        writepayments((**it), payments, *root);
    }
    legami.appendChild(users);
    legami.appendChild(connections);
    legami.appendChild(groups);
    legami.appendChild(messages);
    legami.appendChild(photos);
    legami.appendChild(payments);
    if(!database.open(QIODevice::WriteOnly)){
        throw error(IO,QString("Error opening the database file"));
    }
    QTextStream output(&database);
    output<<*root;
    database.close();
}

void loader::writeusers(QDomNode& users, QDomDocument root){
    QVector<account*> accounts=_boss->_userdb;
    QVector<account*>::iterator it=accounts.begin();
    if(!accounts.isEmpty()){
        for(;it!=accounts.end();++it){
            QDomNode user=root.createElement(QString("user"));
            if(dynamic_cast<useraccount*>(*it)){
                writeaccdata((**it), QString("user"), user, root);
                writeuserinfo((**it), user, root);
                writeuserexp((**it), user, root);
            }
            else{
                writeaccdata((**it), QString("company"), user, root);
                writecompanyinfo((**it), user, root);
            }
            users.appendChild(user);
        }
    }
}

void loader::writeaccdata(const account& acc, QString typeacc, QDomNode& user, QDomDocument root){
    username* usernameacc=acc.user();
    QDomNode userdata=root.createElement(QString("userdata"));
    user.appendChild(userdata);
    QDomNode usern=root.createElement(QString("username")),
            passw=root.createElement(QString("password")),
            typ=root.createElement(QString("type")),
            acctype=root.createElement(QString("acctype"));
    userdata.appendChild(usern);
    userdata.appendChild(passw);
    userdata.appendChild(typ);
    userdata.appendChild(acctype);
    QString _user=usernameacc->user(), _pass=usernameacc->pass(), _acctype;
    _acctype.setNum(acc.type());
    QDomText usertemp=root.createTextNode(_user),
            passtemp=root.createTextNode(_pass),
            typetemp=root.createTextNode(typeacc),
            acctypetemp=root.createTextNode(_acctype);
    usern.appendChild(usertemp);
    passw.appendChild(passtemp);
    typ.appendChild(typetemp);
    acctype.appendChild(acctypetemp);
    if(dynamic_cast<useraccount*>(const_cast<account*>(&acc))){
        QDomNode admin=root.createElement(QString("admin"));
        useraccount* tempacc=dynamic_cast<useraccount*>(const_cast<account*>(&acc));
        QString _admin;
        _admin=_admin.setNum(tempacc->getadmin());
        QDomText admintemp=root.createTextNode(_admin);
        userdata.appendChild(admin);
        admin.appendChild(admintemp);
    }
}

void loader::writeuserinfo(const account & acc, QDomNode & user, QDomDocument root){
    account* useracctemp=const_cast<account*>(&acc);
    useraccount* useracc=dynamic_cast<useraccount*>(useracctemp);
    userinfo* userinf=useracc->information();
    QDomNode infos=root.createElement(QString("infos"));
    user.appendChild(infos);
    if(userinf){
        QDomText nametext=root.createTextNode(userinf->name()),
                surnametext=root.createTextNode(userinf->surname()),
                daybirthtext=root.createTextNode(QString().setNum(userinf->birthdate().day())),
                monthbirthtext=root.createTextNode(QString().setNum(userinf->birthdate().month())),
                yearbirthtext=root.createTextNode(QString().setNum(userinf->birthdate().year())),
                birthplacetext=root.createTextNode(userinf->birthplace()),
                telinfotext=root.createTextNode(userinf->telnum()),
                emailtext=root.createTextNode(userinf->email());
        QDomNode name=root.createElement(QString("name")),
                surname=root.createElement(QString("surname")),
                daybirth=root.createElement(QString("daybirth")),
                monthbirth=root.createElement(QString("monthbirth")),
                yearbirth=root.createElement(QString("yearbirth")),
                telnum=root.createElement(QString("telnum")),
                email=root.createElement(QString("email"));
        infos.appendChild(name);
        infos.appendChild(surname);
        infos.appendChild(daybirth);
        infos.appendChild(monthbirth);
        infos.appendChild(yearbirth);
        infos.appendChild(telnum);
        infos.appendChild(email);
        name.appendChild(nametext);
        surname.appendChild(surnametext);
        daybirth.appendChild(daybirthtext);
        monthbirth.appendChild(monthbirthtext);
        yearbirth.appendChild(yearbirthtext);
        telnum.appendChild(telinfotext);
        email.appendChild(emailtext);
    }
}

void loader::writeuserexp(const account & acc, QDomNode & exps, QDomDocument root) {
    useraccount* useracc=dynamic_cast<useraccount*>(const_cast<account*>(&acc));
    QDomNode experiences=root.createElement(QString("experiences"));
    exps.appendChild(experiences);
    QVector<experience*> expslist=useracc->getexperiences();
    QVector<experience*>::const_iterator it=expslist.begin();
    for(;it!=expslist.end();++it){
        QDomNode experience=root.createElement(QString("experience")),
                esptype=root.createElement(QString("exptype")),
                espname=root.createElement(QString("expname")),
                dayesp=root.createElement(QString("dayexp")),
                monthesp=root.createElement(QString("monthexp")),
                yearesp=root.createElement(QString("yearexp")),
                espdescr=root.createElement(QString("expdescr"));
        experiences.appendChild(experience);
        experience.appendChild(esptype);
        experience.appendChild(espname);
        experience.appendChild(dayesp);
        experience.appendChild(monthesp);
        experience.appendChild(yearesp);
        experience.appendChild(espdescr);
        QString type, day, month, year;
        QDomText esptypetemp=root.createTextNode(type.setNum((*it)->type())),
                espnametemp=root.createTextNode((*it)->espname()),
                dayesptemp=root.createTextNode(day.setNum((*it)->espdate().day())),
                monthesptemp=root.createTextNode(month.setNum((*it)->espdate().month())),
                yearesptemp=root.createTextNode(year.setNum((*it)->espdate().year())),
                espdescrtemp=root.createTextNode((*it)->descr());
        esptype.appendChild(esptypetemp);
        espname.appendChild(espnametemp);
        dayesp.appendChild(dayesptemp);
        monthesp.appendChild(monthesptemp);
        yearesp.appendChild(yearesptemp);
        espdescr.appendChild(espdescrtemp);
    }
}

void loader::writecompanyinfo(const account & acc, QDomNode & user, QDomDocument root){
    companyaccount* coacc=dynamic_cast<companyaccount*>(const_cast<account*>(&acc));
    companyinfo* companyinf=coacc->information();
    QDomNode userdata=root.createElement(QString("userdata"));
    user.appendChild(userdata);
    QDomNode name=root.createElement(QString("name")),
            address=root.createElement(QString("address")),
            cotype=root.createElement(QString("cotype"));
    userdata.appendChild(name);
    userdata.appendChild(address);
    userdata.appendChild(cotype);
    QDomText nametemp=root.createTextNode(companyinf->name()),
            addresstemp=root.createTextNode(companyinf->address()),
            cotypetemp=root.createTextNode(companyinf->cotype());
    name.appendChild(nametemp);
    address.appendChild(addresstemp);
    cotype.appendChild(cotypetemp);
}

void loader::writeconnections(QDomNode& connections, QDomDocument root){
    QVector<account*> userlist=_boss->_userdb;
    QVector<account*>::const_iterator it=userlist.begin();
    if(!userlist.isEmpty()){
	for(;it<userlist.end();++it){
            QString userapplicant=(*it)->user()->user();
            QVector<account*> connlist=(*it)->getconnections();
            QVector<account*>::const_iterator it1=connlist.begin();
	    for(;it1<connlist.end();++it1){
                QDomNode connection=root.createElement(QString("connection"));
                connections.appendChild(connection);
                QDomNode applicant=root.createElement(QString("applicant"));
                QDomText applicanttemp=root.createTextNode(userapplicant);
                applicant.appendChild(applicanttemp);
                connection.appendChild(applicant);
		QDomText userapplied=root.createTextNode((*it1)->user()->user());
                QDomNode applied=root.createElement(QString("applied"));
                applied.appendChild(userapplied);
		connection.appendChild(applied);
            }
        }
    }
}

void loader::writegroups(QDomNode & groups, QDomDocument root){
    QVector<group*> groupslist=_boss->_groupdb;
    QVector<group*>::const_iterator it=groupslist.begin();
    for(;it!=groupslist.end();++it){
        QDomNode group=root.createElement(QString("group"));
        groups.appendChild(group);
        QDomNode name=root.createElement(QString("name")),
                descr=root.createElement(QString("descr")),
                members=root.createElement(QString("members")),
                admins=root.createElement(QString("admins"));
        QDomText nametemp=root.createTextNode((*it)->name()),
                descrtemp=root.createTextNode((*it)->descr());
        name.appendChild(nametemp);
        descr.appendChild(descrtemp);
        QVector<account*> memberslist=(*it)->members();
        QVector<account*>::const_iterator it1=memberslist.begin();
        for(;it1!=memberslist.end();++it1){
            QDomNode member=root.createElement(QString("member"));
            QDomText membertemp=root.createTextNode((*it1)->user()->user());
            member.appendChild(membertemp);
            members.appendChild(member);
        }
        memberslist=(*it)->admins();
        it1=memberslist.begin();
        for(;it1!=memberslist.end();++it1){
            QDomNode admin=root.createElement(QString("admin"));
            QDomText admintemp=root.createTextNode((*it1)->user()->user());
            admins.appendChild(admin);
            admin.appendChild(admintemp);
        }
        group.appendChild(name);
        group.appendChild(descr);
        group.appendChild(members);
        group.appendChild(admins);

    }
}

void loader::writemessages(QDomNode& mess, QDomDocument root){
    QVector<message*> messlist=_boss->_messagedb;
    QVector<message*>::const_iterator it=messlist.begin();
    for(;it!=messlist.end();++it){
        QDomNode message=root.createElement(QString("message"));
        mess.appendChild(message);
        QDomNode sender=root.createElement(QString("sender")),
                recever=root.createElement(QString("recever")),
                object=root.createElement(QString("object")),
                text=root.createElement(QString("text")),
                read=root.createElement(QString("read"));
        message.appendChild(sender);
        message.appendChild(recever);
        message.appendChild(object);
        message.appendChild(text);
        message.appendChild(read);
	QString readed;
        QDomText usersender=root.createTextNode((*it)->sender()->user()->user()),
                userrecever=root.createTextNode((*it)->recever()->user()->user()),
                objecttemp=root.createTextNode((*it)->object()),
                texttemp=root.createTextNode((*it)->text()),
		readtemp=root.createTextNode(readed.setNum((*it)->read()));
        sender.appendChild(usersender);
        recever.appendChild(userrecever);
        object.appendChild(objecttemp);
        text.appendChild(texttemp);
        read.appendChild(readtemp);
    }
}

void loader::writephotos(const account & acc, QDomNode & photos, QDomDocument root){
    QVector<photo*>::const_iterator it=acc.getphotos().begin();
    for(;it!=acc.getphotos().end();++it){
        QDomNode photonode=root.createElement(QString("photo")),
                type=root.createElement(QString("type")),
                name=root.createElement(QString("name")),
                filepath=root.createElement(QString("filepath")),
                descr=root.createElement(QString("descr"));
        QDomText typetemp=root.createTextNode((*it)->type()),
                nametemp=root.createTextNode((*it)->name()),
                filepathtemp=root.createTextNode(QFileInfo(*((*it)->filephoto())).filePath()),
                descrtemp=root.createTextNode((*it)->descr());
        type.appendChild(typetemp);
        name.appendChild(nametemp);
        filepath.appendChild(filepathtemp);
        descr.appendChild(descrtemp);
        photonode.appendChild(type);
        photonode.appendChild(name);
        photonode.appendChild(filepath);
        photonode.appendChild(descr);
        photos.appendChild(photonode);
    }
}

void loader::writepayments(const account & acc, QDomNode & payments, QDomDocument root){
    QVector<payment*> paytemp= acc.payments();
    for(QVector<payment*>::const_iterator it=paytemp.begin(); it!=paytemp.end();++it){
        QDomNode payment= root.createElement(QString("payment"));
        payments.appendChild(payment);

        QString _daytemp, _monthtemp, _yeartemp, _requestedtemp, _approvedtemp;
        _daytemp=_daytemp.setNum((*it)->date().day());
        _monthtemp=_monthtemp.setNum((*it)->date().month());
        _yeartemp=_yeartemp.setNum((*it)->date().year());
        _approvedtemp=_approvedtemp.setNum((*it)->approved());
        _requestedtemp=_requestedtemp.setNum((*it)->request());

        QDomText requestertemp=root.createTextNode(acc.user()->user()),
                requestedtemp=root.createTextNode(_requestedtemp),
                daytemp=root.createTextNode(_daytemp),
                monthtemp=root.createTextNode(_monthtemp),
                yeartemp=root.createTextNode(_yeartemp),
                approvedtemp=root.createTextNode(_approvedtemp);

        QDomNode requester= root.createElement(QString("applicant")),
                requested=root.createElement(QString("typerequested")),
                day=root.createElement(QString("dayrequest")),
                month=root.createElement(QString("monthrequest")),
                year=root.createElement(QString("yearrequest")),
                approved=root.createElement(QString("approved"));
        requester.appendChild(requestertemp);
        requested.appendChild(requestedtemp);
        day.appendChild(daytemp);
        month.appendChild(monthtemp);
        year.appendChild(yeartemp);
        approved.appendChild(approvedtemp);

        payments.appendChild(requester);
        payments.appendChild(requested);
        payments.appendChild(day);
        payments.appendChild(month);
        payments.appendChild(year);
        payments.appendChild(approved);
    }

}

void loader::setdb(QString newpath){
    _db=newpath;
}
