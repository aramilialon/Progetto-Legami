#include "../lib/companyaccount.h"
#include "../lib/useraccount.h"

#include "searchwidget.h"
#include "viewotheruser.h"

#include <QDate>
#include <QLabel>
#include <QMessageBox>
#include <QSize>
#include <QVector>

searchwidget::searchwidget(account* acc, legami* boss, QWidget *parent) :
    QWidget(parent), Boss(boss), Searcher(acc)
{
    userInfoBox=0;
    companyInfoBox=0;
    experienceBox=0;
    usersListView=0;
    showButton=0;

    if((dynamic_cast<companyaccount*>(Searcher) && dynamic_cast<companyaccount*>(Searcher)->type()!=0) || dynamic_cast<useraccount*>(Searcher)){
        layout= new QGridLayout(this);

        usernsearchBox=new QGroupBox(tr("Username Search"), this);
        if((dynamic_cast<companyaccount*>(Searcher) && dynamic_cast<companyaccount*>(Searcher)->type()==2) || dynamic_cast<useraccount*>(Searcher)) usernsearchBox->setCheckable(true);
        QGridLayout* usernsearchLayout= new QGridLayout(usernsearchBox);
        QLabel* usernLabel= new QLabel(tr("Username:"), usernsearchBox);
        usernLineEdit= new QLineEdit(usernsearchBox);
        usernLabel->setBuddy(usernLineEdit);
        usernsearchLayout->addWidget(usernLabel, 0, 0);
        usernsearchLayout->addWidget(usernLineEdit, 0, 1);
        usernsearchBox->setLayout(usernsearchLayout);

        if((dynamic_cast<companyaccount*>(Searcher) && dynamic_cast<companyaccount*>(Searcher)->type()==2) || dynamic_cast<useraccount*>(Searcher)){
            companySearchRadio= new QRadioButton(tr("Company Search"), this);
            connect(companySearchRadio, SIGNAL(clicked()), this, SLOT(companySearch()));
            userSearchRadio= new QRadioButton(tr("User Search"), this);
            connect(userSearchRadio, SIGNAL(clicked()), this, SLOT(userSearch()));

            layout->addWidget(companySearchRadio, 1, 1);
            layout->addWidget(userSearchRadio, 1, 0);
        }

        searchButton= new QPushButton(tr("Search"), this);
        connect(searchButton, SIGNAL(clicked()), this, SLOT(search()));
        layout->addWidget(usernsearchBox, 0, 0);

        layout->addWidget(searchButton, 2, 0);

        setLayout(layout);
    }
    else QMessageBox::warning(this, tr("Error"), tr("Company basic account are not allowed to perform any search."), QMessageBox::Ok, QMessageBox::Ok);
}

void searchwidget::search(){
    QVector<account*> resultVector;
    if(dynamic_cast<companyaccount*>(Searcher) && Searcher->type()==1){
        QString userTemp= usernLineEdit->text();
        account* temp=dynamic_cast<companyaccount*>(Searcher)->businessSearch(userTemp);
        if(temp) resultVector.push_back(temp);
    }
    else{
        if(userSearchRadio->isChecked()){
            if(usernsearchBox->isChecked()){
                QString userTemp= usernLineEdit->text();
                account* temp=Boss->basicSearch(userTemp);
                if(temp) resultVector.push_back(temp);
            }
            if(userInfoBox->isChecked()){
                QVector<account*> resTemp=Boss->userInfoSearch(nameUserLineEdit->text(), surnameLineEdit->text(), birthDateEdit->date(), placeLineEdit->text(), telnumLineEdit->text(), emailLineEdit->text());
                if(!resTemp.isEmpty()) resultVector+=resTemp;
            }
            if(experienceBox->isChecked()){
                QString nameTemp= nameLineEdit->text(),
                        descrTemp= descrLineEdit->text();
                if(workingSeachCheck->isChecked()){
                    QVector<account*> resTemp= Boss->experienceSearch(0, nameTemp, descrTemp);
                    if(!resTemp.isEmpty()) resultVector+=resTemp;
                }
                if(formativeSearchCheck->isChecked()){
                    QVector<account*> resTemp= Boss->experienceSearch(1, nameTemp, descrTemp);
                    if(!resTemp.isEmpty()) resultVector+=resTemp;
                }
            }
        }
        else if(companySearchRadio->isChecked()){
            if(usernsearchBox->isChecked()){
                QString userTemp= usernLineEdit->text();
                account* temp=Boss->basicSearch(userTemp);
                if(temp) resultVector.push_back(temp);
            }
            if(companyInfoBox->isChecked()){
                QVector<account*> resTemp= Boss->companyInfoSearch(nameCompanyLineEdit->text(), addressLineEdit->text(), cotypeLineEdit->text());
                if(!resTemp.isEmpty()) resultVector+=resTemp;
            }
        }
    }

    usersListView= new QListView(this);

    usersModel= new QStandardItemModel(this);
    QStandardItem* usersRootItem= usersModel->invisibleRootItem();
    if(!resultVector.isEmpty()){
        QVector<account*>::iterator it=resultVector.begin();
        for(;it<resultVector.end();++it){
            account* temp= (*it);
            QStandardItem* userTemp= new QStandardItem(temp->user()->user());
            usersRootItem->appendRow(userTemp);
        }
    }
    usersListView->setModel(usersModel);
    connect(usersListView, SIGNAL(clicked(QModelIndex)), this, SLOT(modifySelected(QModelIndex)));

    layout->addWidget(usersListView, 5, 0);

    showButton= new QPushButton(tr("Show profile selected"), this);
    connect(showButton, SIGNAL(clicked()), this, SLOT(showSelected()));
    layout->addWidget(showButton, 6, 0);

    resize(parentWidget()->size());
}

void searchwidget::modifySelected(QModelIndex ind){
    QStandardItem* temp= usersModel->item(ind.row());
    userSelected= temp->text();
}

void searchwidget::showSelected(){
    viewotheruser* temp= new viewotheruser(Boss->basicSearch(userSelected), Boss, this);
    temp->show();
}

void searchwidget::userSearch(){

    layout->removeWidget(usernsearchBox);
    layout->removeWidget(companySearchRadio);
    layout->removeWidget(userSearchRadio);
    layout->removeWidget(searchButton);

    if(usersListView){
        layout->removeWidget(showButton);
        layout->removeWidget(usersListView);
        delete usersListView;
        delete showButton;
        showButton=0;
        usersListView=0;
    }

    if(userInfoBox){
        layout->removeWidget(userInfoBox);
        delete userInfoBox;
        userInfoBox=0;
    }
    if(companyInfoBox){
        layout->removeWidget(companyInfoBox);
        delete companyInfoBox;
        companyInfoBox=0;
    }
    if(experienceBox){
        layout->removeWidget(experienceBox);
        delete experienceBox;
        experienceBox=0;
    }

    userInfoBox= new QGroupBox(tr("User info Search"), this);
    userInfoBox->setCheckable(true);
    QGridLayout* userInfoLayout= new QGridLayout(userInfoBox);
    QLabel* nameUserLabel= new QLabel(tr("Name:"), userInfoBox);
    nameUserLineEdit= new QLineEdit(userInfoBox);
    nameUserLabel->setBuddy(nameUserLineEdit);
    QLabel* surnameLabel= new QLabel(tr("Surname:"), userInfoBox);
    surnameLineEdit= new QLineEdit(userInfoBox);
    surnameLabel->setBuddy(surnameLineEdit);
    QLabel* dateLabel= new QLabel(tr("Birth Date:"), userInfoBox);
    birthDateEdit= new QDateEdit(QDate(), userInfoBox);
    dateLabel->setBuddy(birthDateEdit);
    QLabel* placeLabel= new QLabel(tr("Birth Place:"), userInfoBox);
    placeLineEdit= new QLineEdit(userInfoBox);
    placeLabel->setBuddy(placeLineEdit);
    QLabel* telnumLabel= new QLabel(tr("Tel number:"), userInfoBox);
    telnumLineEdit= new QLineEdit(userInfoBox);
    telnumLabel->setBuddy(telnumLineEdit);
    QLabel* emailLabel= new QLabel(tr("Email:"), userInfoBox);
    emailLineEdit= new QLineEdit(userInfoBox);
    emailLabel->setBuddy(emailLineEdit);
    userInfoLayout->addWidget(nameUserLabel, 0, 0);
    userInfoLayout->addWidget(nameUserLineEdit, 0, 1);
    userInfoLayout->addWidget(surnameLabel, 1, 0);
    userInfoLayout->addWidget(surnameLineEdit, 1, 1);
    userInfoLayout->addWidget(dateLabel, 2, 0);
    userInfoLayout->addWidget(birthDateEdit, 2, 1);
    userInfoLayout->addWidget(placeLabel, 3, 0);
    userInfoLayout->addWidget(placeLineEdit, 3, 1);
    userInfoLayout->addWidget(telnumLabel, 4, 0);
    userInfoLayout->addWidget(telnumLineEdit, 4, 1);
    userInfoLayout->addWidget(emailLabel, 5, 0);
    userInfoLayout->addWidget(emailLineEdit, 5, 1);
    userInfoBox->setLayout(userInfoLayout);

    experienceBox= new QGroupBox(tr("Experience Search"));
    experienceBox->setCheckable(true);
    QGridLayout* experienceLayout= new QGridLayout(experienceBox);
    formativeSearchCheck= new QCheckBox(tr("Formative Experience"), experienceBox);
    workingSeachCheck= new QCheckBox(tr("Working Experience"), experienceBox);
    QLabel* nameLabel= new QLabel(tr("Name:"), experienceBox);
    nameLineEdit= new QLineEdit(experienceBox);
    nameLabel->setBuddy(nameLineEdit);
    QLabel* descrLabel= new QLabel(tr("Description:"), experienceBox);
    descrLineEdit= new QLineEdit(experienceBox);
    descrLabel->setBuddy(descrLineEdit);
    experienceLayout->addWidget(formativeSearchCheck, 0, 0);
    experienceLayout->addWidget(workingSeachCheck, 1, 0);
    experienceLayout->addWidget(nameLabel, 2, 0);
    experienceLayout->addWidget(nameLineEdit, 2, 1);
    experienceLayout->addWidget(descrLabel, 3, 0);
    experienceLayout->addWidget(descrLineEdit, 3, 1);
    experienceBox->setLayout(experienceLayout);

    layout->addWidget(usernsearchBox, 0, 0);
    layout->addWidget(userSearchRadio, 1, 0);
    layout->addWidget(companySearchRadio, 1, 1);
    layout->addWidget(userInfoBox, 2, 0);
    layout->addWidget(experienceBox, 3, 0);
    layout->addWidget(searchButton, 4, 0);
    resize(parentWidget()->size());
}

void searchwidget::companySearch(){
    layout->removeWidget(usernsearchBox);
    layout->removeWidget(companySearchRadio);
    layout->removeWidget(userSearchRadio);
    layout->removeWidget(searchButton);

    if(usersListView){
        layout->removeWidget(showButton);
        layout->removeWidget(usersListView);
        delete usersListView;
        delete showButton;
        showButton=0;
        usersListView=0;
    }

    if(userInfoBox){
        layout->removeWidget(userInfoBox);
        delete userInfoBox;
        userInfoBox=0;
    }
    if(companyInfoBox){
        layout->removeWidget(companyInfoBox);
        delete companyInfoBox;
        companyInfoBox=0;
    }
    if(experienceBox){
        layout->removeWidget(experienceBox);
        delete experienceBox;
        experienceBox=0;
    }

    companyInfoBox= new QGroupBox(tr("Company info Search"), this);
    companyInfoBox->setCheckable(true);
    QGridLayout* companyInfoLayout= new QGridLayout(companyInfoBox);
    QLabel* nameCompanyLabel= new QLabel(tr("Name:"), companyInfoBox);
    nameCompanyLineEdit= new QLineEdit(companyInfoBox);
    nameCompanyLabel->setBuddy(nameCompanyLineEdit);
    QLabel* addressLabel= new QLabel(tr("Address:"), companyInfoBox);
    addressLineEdit= new QLineEdit(companyInfoBox);
    addressLabel->setBuddy(addressLineEdit);
    QLabel* cotypeLabel= new QLabel(tr("Company types:"), companyInfoBox);
    cotypeLineEdit= new QLineEdit(companyInfoBox);
    cotypeLabel->setBuddy(cotypeLineEdit);
    companyInfoLayout->addWidget(nameCompanyLabel, 0, 0);
    companyInfoLayout->addWidget(nameCompanyLineEdit, 0, 1);
    companyInfoLayout->addWidget(addressLabel, 1, 0);
    companyInfoLayout->addWidget(addressLineEdit, 1, 1);
    companyInfoLayout->addWidget(cotypeLabel, 2, 0);
    companyInfoLayout->addWidget(cotypeLineEdit, 2, 1);
    companyInfoBox->setLayout(companyInfoLayout);

    layout->addWidget(usernsearchBox, 0, 0);
    layout->addWidget(userSearchRadio, 1, 0);
    layout->addWidget(companySearchRadio, 1, 1);
    layout->addWidget(companyInfoBox, 2, 0);
    layout->addWidget(searchButton, 3, 0);

    resize(parentWidget()->size());
}
