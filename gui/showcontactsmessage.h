#ifndef SHOWCONTACTSMESSAGE_H
#define SHOWCONTACTSMESSAGE_H

#include "../lib/account.h"
#include "../lib/legami.h"
#include "showcontacts.h"

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>

class showcontactsmessage : public QDialog
{
    Q_OBJECT

    account* accToShow;
    legami* Boss;

    QGridLayout* layout;

    showcontacts* contactsShown;

    QPushButton* okButton;
    QPushButton* cancelButton;

public:
    explicit showcontactsmessage(account*, legami*, QWidget *parent = 0);

signals:
    void selected(QString);
public slots:
    void okPressed();
};

#endif // SHOWCONTACTSMESSAGE_H
