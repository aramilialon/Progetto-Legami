#ifndef REMOVECONTACT_H
#define REMOVECONTACT_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include "showcontacts.h"

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>


class removecontact : public QDialog
{
    Q_OBJECT

    account* accToModify;
    legami* Boss;

    showcontacts* showList;
    QLabel* textLabel;
    QGridLayout* layout;

    QPushButton* okButton;
    QPushButton* cancelButton;

public:
    explicit removecontact(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void modify();
};

#endif // REMOVECONTACT_H
