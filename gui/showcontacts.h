#ifndef SHOWCONTACTS_H
#define SHOWCONTACTS_H

#include "../lib/account.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QListView>
#include <QStandardItemModel>
#include <QString>

class showcontacts : public QWidget
{
    Q_OBJECT

    account* accToShow;

    QGridLayout* layout;

    QLabel* contactsLabel;

    QListView* contactsView;
    QStandardItemModel* contactsModel;

    QString selection;
public:
    explicit showcontacts(account*, QWidget *parent = 0);
    QString sel();
signals:

public slots:
    void select(QModelIndex);
};

#endif // SHOWCONTACTS_H
