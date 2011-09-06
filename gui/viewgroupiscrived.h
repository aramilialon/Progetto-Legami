#ifndef VIEWGROUPISCRIVED_H
#define VIEWGROUPISCRIVED_H

#include "../lib/account.h"
#include "../lib/group.h"
#include "../lib/legami.h"

#include "showgroup.h"

#include <QAction>
#include <QListView>
#include <QModelIndex>
#include <QVector>
#include <QGridLayout>
#include <QScrollArea>
#include <QWidget>

class viewGroupIscrived : public QWidget
{
    Q_OBJECT

    account* accToShow;
    legami* Boss;
    QGridLayout* layout;
    QVector<group*> groupList;
    QListView* groupsListView;
    QScrollArea* scrollRightArea;


public:
    explicit viewGroupIscrived(account*, legami*,  QWidget *parent = 0);

signals:

public slots:

private slots:
    void showGroup(const QModelIndex);

};

#endif // VIEWGROUPISCRIVED_H
