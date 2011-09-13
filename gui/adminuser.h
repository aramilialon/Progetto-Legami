#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>

class adminuser : public QDialog
{
    Q_OBJECT

    QWidget* modifyWidget;
    QScrollArea* mainWidget;

    account* accToModify;
    legami* Boss;

    QPushButton* finishButton;

    QGridLayout* layout;

public:
    explicit adminuser(account*, legami*, QWidget *parent = 0);

signals:

public slots:

};

#endif // ADMINUSER_H
