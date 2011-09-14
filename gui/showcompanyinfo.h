/*
  File: showcompanyinfo.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef SHOWCOMPANYINFO_H
#define SHOWCOMPANYINFO_H

#include "../lib/account.h"
#include "../lib/companyaccount.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QWidget>

class showcompanyinfo : public QGroupBox
{
    Q_OBJECT

    companyaccount* accToShow;

    QLineEdit* nameLineEdit;
    QLineEdit* addressLineEdit;
    QLineEdit* cotypeLineEdit;

    QFormLayout* layout;

public:
    explicit showcompanyinfo(const account&, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWCOMPANYINFO_H
