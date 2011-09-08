#ifndef SUBSCRIBEGROUP_H
#define SUBSCRIBEGROUP_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QListView>
#include <QPushButton>
#include <QStandardItemModel>
#include <QString>

class subscribegroup : public QDialog
{
    Q_OBJECT

    account* accToAdd;
    legami* Boss;

    QGridLayout* layout;

    QLabel* textLabel;

    QListView* groupsListView;
    QStandardItemModel* groupModel;

    QPushButton* okButton;
    QPushButton* cancelButton;

    QString groupSelected;


public:
    explicit subscribegroup(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void subscribe();
    void setGroup(const QModelIndex);
};

#endif // SUBSCRIBEGROUP_H
