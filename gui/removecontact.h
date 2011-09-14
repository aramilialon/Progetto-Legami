/*
  File: removecontact.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef REMOVECONTACT_H
#define REMOVECONTACT_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include "showcontacts.h"

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

class removecontact : public QDialog
{
    Q_OBJECT

    account* accToModify;
    legami* Boss;

    QLabel* textLabel;

    showcontacts* showList;

    QPushButton* okButton;
    QPushButton* cancelButton;

    QGridLayout* layout;

public:
    explicit removecontact(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void modify();

};

#endif // REMOVECONTACT_H
