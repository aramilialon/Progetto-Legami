/*
  File: showlistpayments.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef SHOWLISTPAYMENTS_H
#define SHOWLISTPAYMENTS_H

#include "../lib/account.h"

#include <QStandardItemModel>
#include <QTableView>
#include <QWidget>

class showlistpayments : public QWidget
{
    Q_OBJECT

    account* accToShow;

    QTableView* paymentsTable;

    QStandardItemModel* paymentsModel;

    int selected;

public:
    explicit showlistpayments(account*, QWidget *parent = 0);
    int sel();

signals:

public slots:
    void modSelected(QModelIndex);

};

#endif // SHOWLISTPAYMENTS_H
