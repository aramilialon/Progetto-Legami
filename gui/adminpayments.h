/*
  File: adminpayments.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef ADMINPAYMENTS_H
#define ADMINPAYMENTS_H

#include "../lib/legami.h"
#include "../lib/payment.h"

#include <QGridLayout>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTableView>
#include <QVector>
#include <QWidget>

class adminpayments : public QWidget
{
    Q_OBJECT

    legami* Boss;

    QVector<payment*> payVector;

    QTableView* payTable;
    QStandardItemModel* payModel;

    QPushButton* acceptButton;
    QPushButton* rejectButton;

    QGridLayout* layout;

    /*Intero che indica quale riga è stata elezionata all'interno di payTable*/
    int paySelected;

public:
    explicit adminpayments(legami*, QWidget *parent = 0);

signals:

public slots:
    void modSelected(QModelIndex);
    void acceptPay();
    void rejectPay();
};

#endif // ADMINPAYMENTS_H
