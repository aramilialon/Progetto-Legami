/*
  File: loader.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef LOADER_H
#define LOADER_H

#include "error.h"
#include "legami.h"

#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>

class legami;
class account;

class loader
{
    legami* _boss;
    QString _db;

	void loadcompanyinfo(QDomNode, account*);
	void writecompanyinfo(const account&, QDomNode&, QDomDocument);

	void loadconnections(QDomNode);
	void writeconnections(QDomNode&, QDomDocument);

	void loadgroups(QDomNode);
	void writegroups(QDomNode&, QDomDocument);

	void loadmessages(QDomNode);
	void writemessages(QDomNode&, QDomDocument);

	void loadpayments(QDomNode);
	void writepayments(const account&, QDomNode&, QDomDocument);

	void loadphotos(QDomNode);
	void writephotos(const account&, QDomNode&, QDomDocument);

	void loaduser(QDomNode);
	void loaduserexperiences(QDomNode, account*);
	void writeuserexp(const account&, QDomNode&, QDomDocument);

	void loaduserinfo(QDomNode, account*);
	void writeusers(QDomNode&, QDomDocument);

	void writeuserinfo(const account&, QDomNode&, QDomDocument);

	void writeaccdata(const account&, QString, QDomNode&, QDomDocument);

public:
    loader(QString, const legami&);
    QString db() const;
    void setdb(QString);
    void loaddb() throw(error);
    void writedb() throw(error);
};

#endif // LOADER_H
