/*
  File: showcontacts.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef SHOWCONTACTS_H
#define SHOWCONTACTS_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QGridLayout>
#include <QLabel>
#include <QListView>
#include <QPushButton>
#include <QStandardItemModel>
#include <QString>
#include <QWidget>

class showcontacts : public QWidget
{
    Q_OBJECT

    account* accToShow;
    legami* Boss;

    QLabel* contactsLabel;

    QListView* contactsView;
    QStandardItemModel* contactsModel;

    QString selection;

    QPushButton* showButton;

    QGridLayout* layout;

public:
    explicit showcontacts(account*, legami*, QWidget *parent = 0);
    QString sel();

signals:

public slots:
    void select(QModelIndex);
    void showuser();

};

#endif // SHOWCONTACTS_H
