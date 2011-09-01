#ifndef SHOWCOMPANYINFO_H
#define SHOWCOMPANYINFO_H

#include "../lib/account.h"
#include "../lib/companyaccount.h"

#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>

class showcompanyinfo : public QWidget
{
    Q_OBJECT

	companyaccount* accToShow;

	QLineEdit* nameLineEdit;
	QLineEdit* addressLineEdit;
	QLineEdit* cotypeLineEdit;

	QFormLayout* layout;
public:
	explicit showcompanyinfo(const account&, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWCOMPANYINFO_H
