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
#include <QWidget>

class legamimainwindow : public QMainWindow
{
    Q_OBJECT

    legami* Boss;

    QMenuBar* FileBar;

    QMenu* File;
    QAction* Register;
    QAction* Login;
    QAction* Logout;
    QAction* Exit;

    QMenu* Config;
    QAction* ConfigLegami;

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

public:
    explicit legamimainwindow(QWidget *parent = 0);

    void closeEvent(QCloseEvent *);
signals:

private slots:
    void registerNewUser();
    void closeAll();
    void aboutLegami();
    void aboutQt();
    void login();
    void logout();
    void logged(bool);
    void registered(bool);
    void showuser();
    void modifyuser();
    void usermodified();
    void showgroups();
    void resizewindow();
    void iscrivenewGroup();
    void groupCreated();
    void subscribeGroup();
    void subscrived();
    void inbox();
    void outbox();
    void messagenew();
    void showcontactsself();
    void addnewcontactself();
    void removecontactself();
    void requestnewpayment();
    void shopaymentsself();
};

#endif // LEGAMIMAINWINDOW_H
