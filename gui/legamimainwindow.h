/*
  File: legamimainwindow.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef LEGAMIMAINWINDOW_H
#define LEGAMIMAINWINDOW_H


#include "../lib/legami.h"
#include "../lib/loader.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
#include <QScrollArea>
#include <QString>
#include <QTranslator>
#include <QWidget>

class legamimainwindow : public QMainWindow
{
    Q_OBJECT

    legami* Boss;

    /*Questi puntatori a QTranslator servono per poter modificare il file di traduzione e conseguentemente la lingua di Legami*/
    QTranslator* itaTransl;
    QTranslator* engTransl;

    QMenuBar* FileBar;

    QMenu* File;
    QAction* Register;
    QAction* Login;
    QAction* Logout;
    QAction* Exit;

    QMenu* Language;
    QAction* Italian;
    QAction* English;

    QMenu* Account;
    QAction* ViewProfileSelf;
    QAction* ModifyProfileSelf;

    QMenu* Contacts;
    QAction* ShowContacts;
    QAction* AddContact;
    QAction* RemoveContact;

    QMenu* Groups;
    QAction* ViewGroupsIscrived;
    QAction* SubscribeGroup;
    QAction* ModifyGroupsIscrived;

    QMenu* Messages;
    QAction* Inbox;
    QAction* Outbox;
    QAction* NewMessage;

    QAction* Search;

    QMenu* Payments;
    QAction* RequestPayment;
    QAction* CheckPayment;

    QMenu* Admin;
    QAction* AdminUsers;
    QAction* AdminGroups;
    QAction* AdminMessages;
    QAction* AdminPayments;

    QMenu* About;
    QAction* AboutLegami;
    QAction* AboutQt;

    QScrollArea* scroll;
    QWidget* MainWidget;

    void setMenuBarUnregistered();
    void setMenuBarRegistered();
    bool loginUser(QString, QString);

    /*Funzioni che permettono di riscrivere i testi dei vari pulsanti in modo tale da "rispecchiare" la lingua scelta*/
    void writeNameActionsUnregistered();
    void writeNameActionsRegistered();

public:
    void changeEvent(QEvent *);
    void closeEvent(QCloseEvent *);
    explicit legamimainwindow(QWidget *parent = 0);

signals:

private slots:
    void aboutLegami();
    void aboutQt();
    void addnewcontactself();
    void admingroupsad();
    void adminpaymentsleft();
    void adminusersad();
    void changeenglish();
    void changeitalian();
    void closeAll();
    void groupCreated();
    void inbox();
    void iscrivenewGroup();
    void logged(bool);
    void login();
    void logout();
    void messagenew();
    void modifyuser();
    void outbox();
    void registered(bool);
    void registerNewUser();
    void removecontactself();
    void requestnewpayment();
    void resizewindow();
    void search();
    void shopaymentsself();
    void showcontactsself();
    void showgroups();
    void showuser();
    void subscribeGroup();
    void subscrived();
    void usermodified();

};

#endif // LEGAMIMAINWINDOW_H
