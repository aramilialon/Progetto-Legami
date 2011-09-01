#ifndef SHOWUSERN_H
#define SHOWUSERN_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QFormLayout>
#include <QLineEdit>
#include <QGroupBox>


class showusern : public QGroupBox
{
    Q_OBJECT

	username* usernToShow;
	QLineEdit* usernLineEdit;
	QLineEdit* passwLineEdit;
        QFormLayout* layout;

	legami* boss;

public:
	explicit showusern(account*, legami*, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWUSERN_H
