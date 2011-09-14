/*
  File: showusern.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef SHOWUSERN_H
#define SHOWUSERN_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>

class showusern : public QGroupBox
{
    Q_OBJECT

    legami* boss;

    username* usernToShow;
    QLineEdit* usernLineEdit;
    QLineEdit* passwLineEdit;
    QLineEdit* typeLineEdit;

    QFormLayout* layout;

public:
    explicit showusern(account*, legami*, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWUSERN_H
