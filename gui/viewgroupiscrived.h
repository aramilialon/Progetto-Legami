/*
  File: viewgroupiscrived.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef VIEWGROUPISCRIVED_H
#define VIEWGROUPISCRIVED_H

#include "../lib/account.h"
#include "../lib/group.h"
#include "../lib/legami.h"

#include "showgroup.h"

#include <QAction>
#include <QGridLayout>
#include <QListView>
#include <QModelIndex>
#include <QScrollArea>
#include <QVector>
#include <QWidget>

class viewGroupIscrived : public QWidget
{
    Q_OBJECT

    account* accToShow;
    legami* Boss;

    QVector<group*> groupList;
    QListView* groupsListView;

    QScrollArea* scrollRightArea;
    showgroup* showGr;

    QGridLayout* layout;

public:
    explicit viewGroupIscrived(account*, legami*,  QWidget *parent = 0);

signals:
    void resized();

private slots:
    void showGroup(const QModelIndex);
    void adminGroup(group*);
    void groupModified(group*);
    void groupDeleted();

};

#endif // VIEWGROUPISCRIVED_H
