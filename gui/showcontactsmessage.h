#ifndef SHOWCONTACTSMESSAGE_H
#define SHOWCONTACTSMESSAGE_H

#include "../lib/account.h"
#include "showcontacts.h"

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>

class showcontactsmessage : public QDialog
{
    Q_OBJECT

    account* accToShow;

    QGridLayout* layout;

    showcontacts* contactsShown;

    QPushButton* okButton;
    QPushButton* cancelButton;

public:
    explicit showcontactsmessage(account*, QWidget *parent = 0);

signals:
    void selected(QString);
public slots:
    void okPressed();
};

#endif // SHOWCONTACTSMESSAGE_H
