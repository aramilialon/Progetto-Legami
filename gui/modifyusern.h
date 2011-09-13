#ifndef MODIFYUSERN_H
#define MODIFYUSERN_H

#include "../lib/account.h"
#include "../lib/legami.h"
#include "../lib/username.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>

class modifyusern : public QGroupBox
{
    Q_OBJECT

    account* accToModify;
    legami* Boss;

    QFormLayout* layout;

    QLineEdit* usernLineEdit;
    QLineEdit* passwLineEdit;
    QRadioButton* yesadminRadio;
    QRadioButton* noadminRadio;

    QPushButton* okButton;
    QPushButton* cancelButton;

public:
    explicit modifyusern(const account &, legami*, QWidget *parent = 0);

signals:
    void modified(bool);

public slots:
    void modify();
    void reset();

};

#endif // MODIFYUSERN_H
