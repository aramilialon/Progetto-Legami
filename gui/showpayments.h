/*
  File: showpayments.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef SHOWPAYMENTS_H
#define SHOWPAYMENTS_H

#include "../lib/account.h"
#include "../lib/payment.h"

#include "showlistpayments.h"

#include <QGridLayout>
#include <QWidget>

class showpayments : public QWidget
{
    Q_OBJECT

    account* accToShow;

    showlistpayments* payList;

    QGridLayout* layout;

public:
    explicit showpayments(account*, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWPAYMENTS_H
