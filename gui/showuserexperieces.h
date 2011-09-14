/*
  File: showuserexperieces.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef SHOWUSEREXPERIECES_H
#define SHOWUSEREXPERIECES_H

#include "../lib/useraccount.h"

#include "showuserexperience.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QVector>

class showuserexperieces : public QGroupBox
{
    Q_OBJECT

    QVector<showuserexperience*> exps;
    useraccount* accToShow;

    QVBoxLayout* layout;

public:
    explicit showuserexperieces(const account &, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWUSEREXPERIECES_H
