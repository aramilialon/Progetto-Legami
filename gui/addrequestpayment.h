#ifndef ADDREQUESTPAYMENT_H
#define ADDREQUESTPAYMENT_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>

class addrequestpayment : public QDialog
{
    Q_OBJECT

    account* accToModify;
    legami* Boss;

    QGridLayout* layout;

    QLabel* supLabel;

    QLabel* businessLabel;
    QLabel* businessdescrLabel;

    QLabel* executiveLabel;
    QLabel* executivedescrLabel;

    QPushButton* businessButton;
    QPushButton* executiveButton;
    QPushButton* cancelButton;
public:
    explicit addrequestpayment(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void createBusiness();
    void createExecutive();
};

#endif // ADDREQUESTPAYMENT_H
