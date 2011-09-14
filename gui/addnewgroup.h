/*
  File: addnewgroup.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/
#ifndef ADDNEWGROUP_H
#define ADDNEWGROUP_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>

class addnewgroup : public QDialog
{
    Q_OBJECT

    account* Creator;
    legami* Boss;

    QLineEdit* nameLineEdit;
    QLineEdit* descrLineEdit;

    QPushButton* okButton;
    QPushButton* cancelButton;

    QGridLayout* layout;

public:
    explicit addnewgroup(account*, legami*, QWidget *parent = 0);

signals:
    void created();

public slots:
    void create();

};

#endif // ADDNEWGROUP_H
