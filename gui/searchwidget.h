#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QCheckBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QStandardItemModel>
#include <QString>
#include <QWidget>

class searchwidget : public QWidget
{
    Q_OBJECT
    legami* Boss;
    account* Searcher;

    QGridLayout* layout;

    QGroupBox* usernsearchBox;
    QLineEdit* usernLineEdit;

    QGroupBox* experienceBox;
    QCheckBox* formativeSearchCheck;
    QCheckBox* workingSeachCheck;
    QLineEdit* nameLineEdit;
    QLineEdit* descrLineEdit;

    QPushButton* searchButton;
    QPushButton* resetButton;
    QPushButton* showButton;

    QListView* usersListView;
    QStandardItemModel* usersModel;

    QString userSelected;

public:
    explicit searchwidget(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void search();
    void reset();
    void modifySelected(QModelIndex);
    void showSelected();
};

#endif // SEARCHWIDGET_H
