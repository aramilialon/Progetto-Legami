/*
  File: viewotheruser.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef VIEWOTHERUSER_H
#define VIEWOTHERUSER_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QDialog>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

class viewotheruser : public QDialog
{
    Q_OBJECT

    account* accToShow;
    legami* Boss;

    QWidget* MainWidget;
    QScrollArea* scrollArea;
    QPushButton* okButton;

    QVBoxLayout* layout;

public:
    explicit viewotheruser(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void ok();

};

#endif // VIEWOTHERUSER_H
