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
#include <QStandardItem>
#include <QStandardItemModel>
#include <QVector>


class modifygroup : public QDialog
{
    Q_OBJECT

    legami* Boss;

    QString removeuserRow;
    QString removeadminRow;
    QString newadminRow;

    group* groupToModify;

    QVector<account*> userVector;
    QVector<account*> adminVector;

    QLineEdit* newuserLineEdit;
    QLineEdit* nameLineEdit;
    QLineEdit* descrLineEdit;

    QListView* userremoveList;
    QListView* adminremoveList;
    QListView* newadminList;
    QStandardItemModel* userremoveModel;
    QStandardItemModel* newadminModel;
    QStandardItemModel* adminremoveModel;

    QPushButton* okButton;
    QPushButton* deleteButton;
    QPushButton* cancelButton;

    QGridLayout* layout;

public:
    explicit modifygroup(group*, legami*, QWidget *parent = 0);

signals:
    void modified(group*);
    void deletethisgroup();
public slots:
    void setRemoveUser(const QModelIndex);
    void setRemoveAdmin(const QModelIndex);
    void setNewAdmin(const QModelIndex);
    void modify() throw(error);
    void deletegroup();
};

#endif // MODIFYGROUP_H
