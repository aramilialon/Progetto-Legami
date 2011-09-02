#ifndef MODIFYUSERPROFILE_H
#define MODIFYUSERPROFILE_H

#include "../lib/useraccount.h"

#include "modifyuserexperiences.h"
#include "modifyuserinfos.h"
#include "modifyusern.h"

#include <QVBoxLayout>
#include <QWidget>

class modifyuserprofile : public QWidget
{
    Q_OBJECT

    useraccount* accToModify;

    QVBoxLayout* layout;
    modifyusern* usernModify;
    modifyuserinfos* infosModify;
    modifyuserexperiences* expsModify;


public:
    explicit modifyuserprofile(const useraccount &, QWidget *parent = 0);

signals:

public slots:
    void modified(bool);
    void modexp();
};

#endif // MODIFYUSERPROFILE_H
