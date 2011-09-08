#ifndef INBOXMESSAGES_H
#define INBOXMESSAGES_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include "showmessage.h"

#include <QTableView>
#include <QStandardItemModel>
#include <QString>
#include <QVBoxLayout>
#include <QVector>
#include <QWidget>

class inboxMessages : public QWidget
{
    Q_OBJECT

    account* accToShow;
    legami* Boss;

    QVector<message*> messVector;

    showMessage* showMess;

    QTableView* inboxList;

    QStandardItemModel* inboxModel;

    QVBoxLayout* layout;


public:
    explicit inboxMessages(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void selected(const QModelIndex);
};

#endif // INBOXMESSAGES_H
