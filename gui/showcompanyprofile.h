#ifndef SHOWCOMPANYPROFILE_H
#define SHOWCOMPANYPROFILE_H

#include "../lib/account.h"
#include "../lib/legami.h"
#include "showusern.h"
#include "showcompanyinfo.h"

#include <QVBoxLayout>
#include <QWidget>

class showcompanyprofile : public QWidget
{
    Q_OBJECT

	legami* boss;

	account* accToShow;
	QVBoxLayout* layout;

	showusern* usern;
	showcompanyinfo* infos;

public:
	explicit showcompanyprofile(const account &, legami*, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWCOMPANYPROFILE_H
