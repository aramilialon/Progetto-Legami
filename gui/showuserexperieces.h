#ifndef SHOWUSEREXPERIECES_H
#define SHOWUSEREXPERIECES_H

#include "../lib/useraccount.h"
#include "showuserexperience.h"

#include <QVBoxLayout>
#include <QVector>
#include <QGroupBox>

class showuserexperieces : public QGroupBox
{
    Q_OBJECT

	QVector<showuserexperience*> exps;
	useraccount* accToShow;

	QVBoxLayout* layout;


public:
	explicit showuserexperieces(const account &, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWUSEREXPERIECES_H
