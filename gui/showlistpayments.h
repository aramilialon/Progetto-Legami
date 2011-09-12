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



public:
    explicit showlistpayments(QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWLISTPAYMENTS_H
