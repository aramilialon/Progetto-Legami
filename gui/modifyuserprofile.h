#ifndef MODIFYUSERPROFILE_H
#define MODIFYUSERPROFILE_H

#include "../lib/useraccount.h"

#include "modifyusern.h"

#include <QVBoxLayout>
#include <QWidget>

class modifyuserprofile : public QWidget
{
    Q_OBJECT

    useraccount* accToModify;

    QVBoxLayout* layout;
    modifyusern* usernModify;



public:
    explicit modifyuserprofile(const useraccount &, QWidget *parent = 0);

signals:

public slots:

};

#endif // MODIFYUSERPROFILE_H