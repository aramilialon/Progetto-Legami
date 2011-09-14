/*
  File: showuserinfo.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef SHOWUSERINFO_H
#define SHOWUSERINFO_H

#include "../lib/account.h"
#include "../lib/useraccount.h"

#include <QDateEdit>
#include <QFormLayout>
#include <QLineEdit>
#include <QGroupBox>

class showuserinfo : public QGroupBox
{
    Q_OBJECT

    useraccount* accToShow;

    QLineEdit* nameLineEdit;
    QLineEdit* surnameLineEdit;
    QDateEdit* dateDateEdit;
    QLineEdit* placeLineEdit;
    QLineEdit* telnumLineEdit;
    QLineEdit* emailLineEdit;

    QFormLayout* layout;

public:
    explicit showuserinfo(const account&, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWUSERINFO_H
