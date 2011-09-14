/*
  File: adminusers.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef ADMINUSERS_H
#define ADMINUSERS_H

#include "../lib/legami.h"

#include "showuserlist.h"

#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

class adminusers : public QWidget
{
    Q_OBJECT

    legami* Boss;
    showuserlist* userList;

    QPushButton* modifyButton;

    QGridLayout* layout;

public:
    explicit adminusers(legami*, QWidget *parent = 0);

signals:

public slots:
    void modify();
};

#endif // ADMINUSERS_H
