/*
  File: addnewcontact.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef ADDNEWCONTACT_H
#define ADDNEWCONTACT_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>

class addnewcontact : public QDialog
{
    Q_OBJECT

    account* accToModify;
    legami* Boss;

    QPushButton* okButton;
    QPushButton* cancelButton;

    QLineEdit* newuserLineEdit;

    QFormLayout* layout;

public:
    explicit addnewcontact(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void addContact();
};

#endif // ADDNEWCONTACT_H
