#ifndef OUTBOXMESSAGES_H
#define OUTBOXMESSAGES_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include "showmessage.h"

#include <QTableView>
#include <QStandardItemModel>
#include <QString>
#include <QVBoxLayout>
#include <QVector>
#include <QWidget>

class outboxMessages : public QWidget
{
    Q_OBJECT

    account* accToShow;
    legami* Boss;

    QVector<message*> messVector;

    showMessage* showMess;

    QTableView* outboxList;

    QStandardItemModel* outboxModel;

    QVBoxLayout* layout;


public:
    explicit outboxMessages(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void selected(const QModelIndex);
};

#endif // OUTBOXMESSAGES_H
