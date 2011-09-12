#ifndef MODIFYCOMPANYPROFILE_H
#define MODIFYCOMPANYPROFILE_H

#include "../lib/companyaccount.h"
#include "../lib/legami.h"

#include "modifyusern.h"
#include "modifycompanyinfos.h"

#include <QVBoxLayout>
#include <QWidget>

class modifycompanyprofile : public QWidget
{
    Q_OBJECT

    companyaccount* accToModify;
    legami* Boss;

    modifyusern* usernModify;
    modifycompanyinfos* infosModify;

    QVBoxLayout* layout;


public:
    explicit modifycompanyprofile(companyaccount*, legami*, QWidget *parent = 0);

signals:
    void modified();

public slots:
    void modified(bool);

};

#endif // MODIFYCOMPANYPROFILE_H
