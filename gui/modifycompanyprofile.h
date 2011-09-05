#ifndef MODIFYCOMPANYPROFILE_H
#define MODIFYCOMPANYPROFILE_H

#include "../lib/companyaccount.h"
#include "modifyusern.h"

#include <QWidget>

class modifycompanyprofile : public QWidget
{
    Q_OBJECT

    companyaccount* accToModify;

    modifyusern* usernModify;


public:
    explicit modifycompanyprofile(QWidget *parent = 0);

signals:

public slots:

};

#endif // MODIFYCOMPANYPROFILE_H
