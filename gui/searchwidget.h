/*
  File: searchwidget.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QCheckBox>
#include <QDateEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QRadioButton>
#include <QStandardItemModel>
#include <QString>
#include <QWidget>

class searchwidget : public QWidget
{
    Q_OBJECT

    legami* Boss;
    account* Searcher;

    QGroupBox* usernsearchBox;
    QLineEdit* usernLineEdit;

    QRadioButton* companySearchRadio;
    QRadioButton* userSearchRadio;

    QGroupBox* userInfoBox;
    QLineEdit* nameUserLineEdit;
    QLineEdit* surnameLineEdit;
    QDateEdit* birthDateEdit;
    QLineEdit* placeLineEdit;
    QLineEdit* telnumLineEdit;
    QLineEdit* emailLineEdit;

    QGroupBox* companyInfoBox;
    QLineEdit* nameCompanyLineEdit;
    QLineEdit* addressLineEdit;
    QLineEdit* cotypeLineEdit;

    QGroupBox* experienceBox;
    QCheckBox* formativeSearchCheck;
    QCheckBox* workingSeachCheck;
    QLineEdit* nameLineEdit;
    QLineEdit* descrLineEdit;

    QPushButton* searchButton;
    QPushButton* showButton;

    QListView* usersListView;
    QStandardItemModel* usersModel;


    QString userSelected;

    QGridLayout* layout;

public:
    explicit searchwidget(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void search();
    void modifySelected(QModelIndex);
    void showSelected();
    void companySearch();
    void userSearch();
};

#endif // SEARCHWIDGET_H
