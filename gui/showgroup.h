#ifndef SHOWGROUP_H
#define SHOWGROUP_H

#include "../lib/account.h"
#include "../lib/group.h"
#include "../lib/legami.h"

#include <QGridLayout>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QVector>
#include <QWidget>

class showgroup : public QWidget
{
    Q_OBJECT

    legami* Boss;

    group* groupToShow;
    account* accShown;

    QLineEdit* nameLineEdit;
    QLineEdit* descrLineEdit;

    QVector<account*> userVector;
    QVector<account*> adminVector;

    QGridLayout* layout;

    QPushButton* adminButton;

    QListView* usersList;
    QListView* adminList;

public:
    explicit showgroup(account*, group*, legami*,  QWidget *parent = 0);

signals:
    void adminGr(group*);
public slots:
    void adminGroup();
};

#endif // SHOWGROUP_H
