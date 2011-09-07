#ifndef MODIFYGROUP_H
#define MODIFYGROUP_H

#include "../lib/account.h"
#include "../lib/error.h"
#include "../lib/group.h"
#include "../lib/legami.h"

#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QVector>


class modifygroup : public QDialog
{
    Q_OBJECT

    legami* Boss;

    int removeuserRow;
    int removeadminRow;
    int newadminRow;

    group* groupToModify;

    QVector<account*> userVector;
    QVector<account*> adminVector;

    QLineEdit* newuserLineEdit;
    QLineEdit* nameLineEdit;
    QLineEdit* descrLineEdit;

    QListView* userremoveList;
    QListView* adminremoveList;
    QListView* newadminList;

    QPushButton* okButton;
    QPushButton* cancelButton;

    QGridLayout* layout;

public:
    explicit modifygroup(group*, legami*, QWidget *parent = 0);

signals:
    void modified(group*);
public slots:
    void setRemoveUser(const QModelIndex);
    void setRemoveAdmin(const QModelIndex);
    void setNewAdmin(const QModelIndex);
    void modify() throw(error);
};

#endif // MODIFYGROUP_H
