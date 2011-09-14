/*
  File: showuserprofile.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef SHOWUSERPROFILE_H
#define SHOWUSERPROFILE_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include "showusern.h"
#include "showuserinfo.h"
#include "showuserexperieces.h"

#include <QVBoxLayout>
#include <QWidget>

class showuserprofile : public QWidget
{
    Q_OBJECT

    legami* boss;
    account* accToShow;

    showusern* userns;
    showuserinfo* infos;
    showuserexperieces* exps;

    QVBoxLayout* layout;

public:
    explicit showuserprofile(const account &, legami*, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWUSERPROFILE_H
