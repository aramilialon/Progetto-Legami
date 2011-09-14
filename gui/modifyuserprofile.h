/*
  File: modifyuserprofile.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef MODIFYUSERPROFILE_H
#define MODIFYUSERPROFILE_H

#include "../lib/legami.h"
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
    legami* Boss;

    modifyusern* usernModify;
    modifyuserinfos* infosModify;
    modifyuserexperiences* expsModify;

    QVBoxLayout* layout;

public:
    explicit modifyuserprofile(const useraccount &, legami*, QWidget *parent = 0);

signals:
    void modified();
    void modifiedlist();

public slots:
    void modified(bool);
    void modexp();
};

#endif // MODIFYUSERPROFILE_H
