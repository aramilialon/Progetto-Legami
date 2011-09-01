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

    QMenu* Groups;
    QAction* ViewGroupsIscrived;
    QAction* ModifyGroupsIscrived;

    QMenu* Messages;
    QAction* Inbox;
    QAction* Outbox;
    QAction* NewMessage;

    QMenu* Admin;
    QAction* AdminUsers;
    QAction* AdminGroups;
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

};

#endif // LEGAMIMAINWINDOW_H
