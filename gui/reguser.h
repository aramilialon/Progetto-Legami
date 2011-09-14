/*
  File: reguser.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef REGUSER_H
#define REGUSER_H

#include "../lib/legami.h"

#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QDialog>

class reguser : public QDialog
{
    Q_OBJECT

    legami* Boss;

    QLineEdit* usernLineEdit;
    QLineEdit* passwLineEdit;

    QRadioButton* userRadio;
    QRadioButton* companyRadio;

    QPushButton* okButton;
    QPushButton* cancelButton;

    QFormLayout* layout;

public:
    explicit reguser(legami*, QWidget *parent = 0);

signals:
    void login();
    void registered(bool);

public slots:
    void reginto();

};

#endif // REGUSER_H
