/*
  File: modifyuserexperiences.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef MODIFYUSEREXPERIENCES_H
#define MODIFYUSEREXPERIENCES_H

#include "../lib/experience.h"
#include "../lib/legami.h"
#include "../lib/useraccount.h"

#include "modifyuserexperience.h"

#include <QGroupBox>
#include <QGridLayout>
#include <QPushButton>
#include <QVector>

class modifyuserexperiences : public QGroupBox
{
    Q_OBJECT

    useraccount* accToModify;
    legami* Boss;

    QVector<modifyuserexperience*> expWidget;

    QPushButton* addFormativeExp;
    QPushButton* addWorkingExp;

    QGridLayout* layout;

    /*memorizza il numero di oggetti di tipo modifyuserexperience*/
    int rows;

    void loadExpWidget();

public:
    explicit modifyuserexperiences(const useraccount&, legami*, QWidget *parent = 0);

signals:
    void modifiedlist();
    void modified(bool);

public slots:
    void pushedForm();
    void pushedWork();
    void modifiedExp();

};

#endif // MODIFYUSEREXPERIENCES_H
