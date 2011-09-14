/*
  File: admingroups.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef ADMINGROUPS_H
#define ADMINGROUPS_H

#include "../lib/group.h"
#include "../lib/legami.h"

#include <QGridLayout>
#include <QListView>
#include <QPushButton>
#include <QStandardItemModel>
#include <QWidget>

class admingroups : public QWidget
{
    Q_OBJECT

    legami* Boss;

    QListView* groupsListView;
    QStandardItemModel* groupModel;

    QPushButton* modifyButton;

    QGridLayout* layout;

    /*Stringa che serve per sapere sempre quale elemento è stato selezionato all'interno di groupsListView*/
    QString groupSelected;

public:
    explicit admingroups(legami*, QWidget *parent = 0);

signals:

public slots:
    void setGroup(const QModelIndex);
    void modifyGroup();
    void groupdeleted();
    void modified();
};

#endif // ADMINGROUPS_H
