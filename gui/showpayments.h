#ifndef SHOWPAYMENTS_H
#define SHOWPAYMENTS_H

#include "../lib/account.h"
#include "../lib/payment.h"

#include <QTableView>
#include <QStandardItemModel>
#include <QWidget>

class showpayments : public QWidget
{
    Q_OBJECT

    account* accToShow;

    QTa
public:
    explicit showpayments(account*, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWPAYMENTS_H
