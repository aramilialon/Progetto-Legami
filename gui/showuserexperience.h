#ifndef SHOWUSEREXPERIENCE_H
#define SHOWUSEREXPERIENCE_H

#include "../lib/experience.h"

#include <QFormLayout>
#include <QDateEdit>
#include <QLineEdit>
#include <QGroupBox>

class showuserexperience : public QGroupBox
{
    Q_OBJECT

	experience* expToShow;

	QFormLayout* layout;

	QLineEdit* typeLineEdit;
	QLineEdit* expnameLineEdit;
	QDateEdit* expdateDateEdit;
	QLineEdit* descrLineEdit;


public:
	explicit showuserexperience(experience*, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWUSEREXPERIENCE_H
