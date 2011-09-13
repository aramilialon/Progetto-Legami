#ifndef ADMINUSERS_H
#define ADMINUSERS_H

#include "../lib/legami.h"

#include "showuserlist.h"

#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

class adminusers : public QWidget
{
    Q_OBJECT

    legami* Boss;
    showuserlist* userList;

    QGridLayout* layout;
    QPushButton* modifyButton;

public:
    explicit adminusers(legami*, QWidget *parent = 0);

signals:

public slots:
    void modify();
};

#endif // ADMINUSERS_H
