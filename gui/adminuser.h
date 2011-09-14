/*
  File: adminuser.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>

class adminuser : public QDialog
{
    Q_OBJECT

    account* accToModify;
    legami* Boss;

    QWidget* modifyWidget;
    QScrollArea* mainWidget;

    QPushButton* finishButton;

    QGridLayout* layout;

public:
    explicit adminuser(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void modifiedlist();
};

#endif // ADMINUSER_H
