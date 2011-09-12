#ifndef ADDNEWCONTACT_H
#define ADDNEWCONTACT_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>

class addnewcontact : public QDialog
{
    Q_OBJECT
    account* accToModify;
    legami* Boss;

    QFormLayout* layout;

    QLineEdit* newuserLineEdit;

    QPushButton* okButton;
    QPushButton* cancelButton;

public:
    explicit addnewcontact(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void addContact();
};

#endif // ADDNEWCONTACT_H
