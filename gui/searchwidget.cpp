#include "../lib/companyaccount.h"
#include "../lib/useraccount.h"

#include "searchwidget.h"

#include <QLabel>
#include <QMessageBox>
#include <QVector>

searchwidget::searchwidget(account* acc, legami* boss, QWidget *parent) :
    QWidget(parent), Boss(boss), Searcher(acc)
{
    if((dynamic_cast<companyaccount*>(Searcher) && dynamic_cast<companyaccount*>(Searcher)->type()!=0) || dynamic_cast<useraccount*>(Searcher)){
        layout= new QGridLayout(this);

        QLabel* upperText= new QLabel(this);

        usernsearchBox=new QGroupBox(tr("Username Search"), this);
        usernsearchBox->setCheckable(true);
        QGridLayout* usernsearchLayout= new QGridLayout(usernsearchBox);
        QLabel* usernLabel= new QLabel(tr("Username:"), usernsearchBox);
        usernLineEdit= new QLineEdit(usernsearchBox);
        usernLabel->setBuddy(usernLineEdit);
        usernsearchLayout->addWidget(usernLabel, 0, 0);
        usernsearchLayout->addWidget(usernLineEdit, 0, 1);
        usernsearchBox->setLayout(usernsearchLayout);

        experienceBox= new QGroupBox(tr("Experience Search"));
        experienceBox->setCheckable(true);
        QGridLayout* experienceLayout= new QGridLayout(experienceBox);
        QLabel* nameLabel= new QLabel(tr("Name:"), experienceBox);
        nameLineEdit= new QLineEdit(experienceBox);
        nameLabel->setBuddy(nameLineEdit);
        QLabel* descrLabel= new QLabel(tr("Description:"), experienceBox);
        descrLineEdit= new QLineEdit(experienceBox);
        descrLabel->setBuddy(descrLineEdit);
        experienceLayout->addWidget(nameLabel, 0, 0);
        experienceLayout->addWidget(nameLineEdit, 0, 1);
        experienceLayout->addWidget(descrLabel, 1, 0);
        experienceLayout->addWidget(descrLineEdit, 1, 1);
        experienceBox->setLayout(experienceLayout);

        searchButton= new QPushButton(tr("Search"), this);
        connect(searchButton, SIGNAL(clicked()), this, SLOT(search()));
        resetButton= new QPushButton(tr("Reset"), this);

        if((dynamic_cast<companyaccount*>(Searcher) && dynamic_cast<companyaccount*>(Searcher)->type()==2) || dynamic_cast<useraccount*>(Searcher)){
            layout->addWidget(experienceBox, 2, 0);
        }
        layout->addWidget(upperText, 0, 0);
        layout->addWidget(usernsearchBox, 1, 0);

        layout->addWidget(searchButton, 3, 0);
        layout->addWidget(resetButton, 3, 1);

        setLayout(layout);
    }
    else QMessageBox::warning(this, tr("Error"), tr("Company basic account are not allowed to perform any search."), QMessageBox::Ok, QMessageBox::Ok);
}

void searchwidget::search(){
    QVector<account*> resultVector;
    if(dynamic_cast<companyaccount*>(Searcher) && Searcher->type()==1){
        QString userTemp= usernLineEdit->text();
        account* temp=dynamic_cast<companyaccount*>(Searcher)->businessSearch(userTemp);
        resultVector.push_back(temp);
    }
    else{

    }

    usersListView= new QListView(this);

    usersModel= new QStandardItemModel(this);
    QStandardItem* usersRootItem= usersModel->invisibleRootItem();

    QVector<account*>::iterator it=resultVector.begin();
    for(;it<resultVector.end();++it){
        QStandardItem* userTemp= new QStandardItem((*it)->user()->user());
        usersRootItem->appendRow(userTemp);
    }
    usersListView->setModel(usersModel);
    connect(usersListView, SIGNAL(clicked(QModelIndex)), this, SLOT(modifySelected(QModelIndex)));

    layout->addWidget(usersListView, 4, 0);

    showButton= new QPushButton(tr("Show profile selected"), this);
    connect(showButton, SIGNAL(clicked()), this, SLOT(showSelected()));
    layout->addWidget(showButton, 5, 0);

    resize(parentWidget()->size());
}

void searchwidget::reset(){}

void searchwidget::modifySelected(QModelIndex ind){
    QStandardItem* temp= usersModel->item(ind.row());
    userSelected= temp->text();
}

void searchwidget::showSelected(){

}
