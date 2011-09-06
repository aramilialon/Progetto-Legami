#ifndef SHOWGROUP_H
#define SHOWGROUP_H

#include "../lib/group.h"

#include <QGridLayout>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QVector>
#include <QWidget>

class showgroup : public QWidget
{
    Q_OBJECT

    group* groupToShow;

    QLineEdit* nameLineEdit;
    QLineEdit* descrLineEdit;

    QVector<account*> userVector;
    QVector<account*> adminVector;

    QGridLayout* layout;

    QPushButton* adminButton;

    QListView* usersList;
    QListView* adminList;

public:
    explicit showgroup(group*, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWGROUP_H
