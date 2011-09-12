#ifndef SHOWUSERLIST_H
#define SHOWUSERLIST_H

#include "../lib/legami.h"

#include <QListView>
#include <QStandardItemModel>
#include <QString>
#include <QWidget>

class showuserlist : public QWidget
{
    Q_OBJECT

    legami* Boss;

    QListView* usersListView;
    QStandardItemModel* usersModel;

    QString userSelected;
public:
    explicit showuserlist(legami*, QWidget *parent = 0);

    QString selected();
signals:

public slots:
    void modifySelected(QModelIndex);
};

#endif // SHOWUSERLIST_H
