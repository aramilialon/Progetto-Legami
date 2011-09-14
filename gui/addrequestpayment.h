/*
  File: addrequestpayment.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef ADDREQUESTPAYMENT_H
#define ADDREQUESTPAYMENT_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

class addrequestpayment : public QDialog
{
    Q_OBJECT

    account* accToModify;
    legami* Boss;

    QLabel* supLabel;

    QLabel* businessLabel;
    QLabel* businessdescrLabel;

    QLabel* executiveLabel;
    QLabel* executivedescrLabel;

    QPushButton* businessButton;
    QPushButton* executiveButton;
    QPushButton* cancelButton;

    QGridLayout* layout;

public:
    explicit addrequestpayment(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void createBusiness();
    void createExecutive();
};

#endif // ADDREQUESTPAYMENT_H
