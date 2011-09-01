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
        QVBoxLayout* layout;

        showusern* userns;
        showuserinfo* infos;
        showuserexperieces* exps;

public:
        explicit showuserprofile(const account &, legami*, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWUSERPROFILE_H
