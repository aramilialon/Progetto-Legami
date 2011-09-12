/*
  File: legamimainwindow.cpp
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "../lib/error.h"
#include "../lib/useraccount.h"

#include "addnewgroup.h"
#include "legamilogin.h"
#include "legamimainwindow.h"
#include "inboxmessages.h"
#include "modifycompanyprofile.h"
#include "modifyuserprofile.h"
#include "newmessage.h"
#include "outboxmessages.h"
#include "reguser.h"
#include "showcompanyprofile.h"
#include "showcontacts.h"
#include "viewgroupiscrived.h"
#include "showuserprofile.h"
#include "subscribegroup.h"

#include <QCloseEvent>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QScrollArea>

legamimainwindow::legamimainwindow(QWidget *parent) :
    QMainWindow(parent)
{
    setMinimumSize(640,480);
    setMaximumSize(1366, 768);
    FileBar=0;
    MainWidget=0;
    scroll=new QScrollArea(this);
    scroll->resize(this->size());
    scroll->setWidget(MainWidget);
    show();
    setCentralWidget(scroll);
    setMenuBarUnregistered();
    Boss= new legami("./database.xml");
    bool loaded=false;
    bool errorReported=false;
    while(!loaded){
	int returned=0;
	try{
	    Boss->getloader()->loaddb();
	}
	catch(error er){
	    if(er.type()==IO){
		errorReported=true;
		QMessageBox msg;
		msg.setIcon(QMessageBox::Warning);
		msg.setText(tr("Database not loaded"));
		msg.setInformativeText(tr("Would you like to try <i>another path</i> "
					  "rather than the normal one or to load the <i>example data?</i>"));
		msg.setDetailedText(er.comment());
		msg.addButton(tr("Another path"), QMessageBox::YesRole);
		msg.addButton(tr("Example data"), QMessageBox::NoRole);
		msg.exec();
		returned= msg.result();
	    }
	    if(returned==0){
		QString newpath= QFileDialog::getOpenFileName(this, "Select database", "./", "Database File (*.xml)");
		if(!newpath.isEmpty()) Boss->getloader()->setdb(newpath);
	    }
	    else{
		useraccount* newadmin= new useraccount("root", "there is no password", 2, *Boss);
		newadmin->setadmin(1);
		newadmin->setype(2);
		bool created=true;
		try{
		    Boss->addAccount(*newadmin);
		    Boss->getloader()->writedb();
		}
		catch(error er2){
		    created=false;
		    QMessageBox::critical(this, tr("Error!"), tr("Is not been possible to create the example account"));
		}
		Boss->getloader()->writedb();
		if(created){
		    QMessageBox::warning(this, tr("Data example created!"), tr("A user account has been created."
									       "These are the login informations:\n"
									       "Username: root\n"
									       "Password: 'there is no password'"),
					 QMessageBox::Yes, QMessageBox::Yes);
		    errorReported=false;
		}
	    }
	}
	if(!errorReported){
	    loaded=true;
	}
	else{
	    errorReported=false;
	}
    }
}

void legamimainwindow::setMenuBarUnregistered(){
    if(!FileBar) FileBar= new QMenuBar(this);
    else{
	File->clear();
	Config->clear();
	Account->clear();
	Contacts->clear();
	Groups->clear();
	Messages->clear();
	if(Admin) Admin->clear();
	About->clear();
	delete File;
	delete Config;
	delete Account;
	delete Contacts;
	delete Groups;
	delete Messages;
	delete Admin;
	delete About;
    }
    if(MainWidget){
	delete MainWidget;
	MainWidget=0;
    }
    delete scroll;
    scroll=new QScrollArea(this);
    File= new QMenu(tr("File"), this);
    Register= new QAction(tr("New User?"), this);
    connect(Register, SIGNAL(triggered()), this, SLOT(registerNewUser()));
    Login= new QAction(tr("Login"), this);
    connect(Login, SIGNAL(triggered()), this, SLOT(login()));
    Exit= new QAction(tr("Exit"), this);
    connect(Exit, SIGNAL(triggered()), this, SLOT(closeAll()));
    File->addAction(Register);
    File->addAction(Login);
    File->addAction(Exit);

    About= new QMenu(tr("About"), this);
    AboutLegami= new QAction(tr("About Legami"), this);
    connect(AboutLegami, SIGNAL(triggered()), this, SLOT(aboutLegami()));
    AboutQt= new QAction(tr("About Qt"), this);
    connect(AboutQt, SIGNAL(triggered()), this, SLOT(aboutQt()));
    About->addAction(AboutLegami);
    About->addAction(AboutQt);

    FileBar->addMenu(File);
    FileBar->addMenu(About);
    setMenuBar(FileBar);
}

void legamimainwindow::registerNewUser(){
    reguser* newreg=new reguser(Boss, this);
    connect(newreg, SIGNAL(registered(bool)), this, SLOT(registered(bool)));
    newreg->show();
}

void legamimainwindow::registered(bool reg){
    if(reg) QMessageBox::information(this, tr("New Account Created"), tr("The new account requested has been created.\n"
									 "Please login with the new username and password"), QMessageBox::Ok, QMessageBox::Ok);
    else QMessageBox::warning(this, tr("Error"), tr("It has not been possible to create a new account. "
						    "Please try again."), QMessageBox::Ok, QMessageBox::Ok);
}

void legamimainwindow::login(){
    legamilogin* newlogin= new legamilogin(Boss, this);
    connect(newlogin, SIGNAL(logged(bool)), this, SLOT(logged(bool)));
    newlogin->exec();
}

void legamimainwindow::aboutLegami(){
    QMessageBox::information(this, tr("About Legami"), tr("Legami is a program made for the class \"Object Programming\""
							  "\nProgrammer name: Giorgio Maggiolo"
							  "\nStudent Code: 610338"
							  "\nEmail: maggiolo.giorgio@gmail.com"), QMessageBox::Ok, QMessageBox::Ok);
}

void legamimainwindow::aboutQt(){
    QMessageBox::aboutQt(this, tr("About Qt"));
}

void legamimainwindow::logged(bool log){
    if(log){
	QMessageBox::information(this, tr("Logged succefully!"), Boss->accountlogged()->user()->user()+tr(" logged in!"), QMessageBox::Ok, QMessageBox::Ok);
	setMenuBarRegistered();
    }
    else{
	QMessageBox::warning(this, tr("Login problem"), tr("You have provided wrong accessing data.\n"
							   "Please check username and password"), QMessageBox::Ok, QMessageBox::Ok);
    }
}

void legamimainwindow::setMenuBarRegistered(){
    File->clear();

    Logout= new QAction(tr("Logout"), this);
    connect(Logout, SIGNAL(triggered()), this, SLOT(logout()));
    Exit= new QAction(tr("Exit"), this);
    connect(Exit, SIGNAL(triggered()), this, SLOT(closeAll()));
    File->addAction(Logout);
    File->addAction(Exit);

    Config= new QMenu(tr("Config"), this);
    ConfigLegami= new QAction(tr("Preferences"), this);
    Config->addAction(ConfigLegami);

    Account= new QMenu(tr("Account"), this);
    ViewProfileSelf= new QAction(tr("View Profile"), this);
    ModifyProfileSelf= new QAction(tr("Modify Profile"), this);
    Account->addAction(ViewProfileSelf);
    Account->addAction(ModifyProfileSelf);
    connect(ViewProfileSelf, SIGNAL(triggered()), this, SLOT(showuser()));
    connect(ModifyProfileSelf, SIGNAL(triggered()), this, SLOT(modifyuser()));

    Contacts= new QMenu(tr("Contacts"), this);
    ShowContacts= new QAction(tr("Show Contacts"), this);
    connect(ShowContacts, SIGNAL(triggered()), this, SLOT(showcontactsself()));
    AddContact= new QAction(tr("Add new contact"), this);
    RemoveContact= new QAction(tr("Delete Contact"), this);
    Contacts->addAction(ShowContacts);
    Contacts->addAction(AddContact);
    Contacts->addAction(RemoveContact);


    Groups= new QMenu(tr("Groups"), this);
    ViewGroupsIscrived= new QAction(tr("View Groups"), this);
    connect(ViewGroupsIscrived, SIGNAL(triggered()), this, SLOT(showgroups()));
    ModifyGroupsIscrived= new QAction(tr("Register new group"), this);
    connect(ModifyGroupsIscrived, SIGNAL(triggered()), this, SLOT(iscrivenewGroup()));
    SubscribeGroup= new QAction(tr("Subscribe Group"), this);
    connect(SubscribeGroup, SIGNAL(triggered()), this, SLOT(subscribeGroup()));
    Groups->addAction(ModifyGroupsIscrived);
    Groups->addAction(ViewGroupsIscrived);
    Groups->addAction(SubscribeGroup);

    Messages= new QMenu(tr("Messages"), this);
    Inbox= new QAction(tr("Inbox"), this);
    connect(Inbox, SIGNAL(triggered()), this, SLOT(inbox()));
    Outbox= new QAction(tr("Outbox"), this);
    connect(Outbox, SIGNAL(triggered()), this, SLOT(outbox()));
    NewMessage= new QAction(tr("New Message"), this);
    connect(NewMessage, SIGNAL(triggered()), this, SLOT(messagenew()));
    Messages->addAction(Inbox);
    Messages->addAction(NewMessage);
    Messages->addAction(Outbox);

    FileBar->clear();

    FileBar->addMenu(File);
    FileBar->addMenu(Account);
    FileBar->addMenu(Contacts);
    FileBar->addMenu(Groups);
    FileBar->addMenu(Messages);

    useraccount* temp= dynamic_cast<useraccount*>(Boss->accountlogged());
    if(temp && temp->getadmin()==1){
	Admin= new QMenu(tr("Administration"), this);
	AdminUsers= new QAction(tr("Admin Users"), this);
	AdminGroups= new QAction(tr("Admin Groups"), this);
	AdminPayments= new QAction(tr("Admin Payments Requested"), this);

	Admin->addAction(AdminUsers);
	Admin->addAction(AdminGroups);
	Admin->addAction(AdminPayments);
	FileBar->addMenu(Admin);
    }
    else{
	Admin=0;
	AdminUsers=0;
	AdminGroups=0;
	AdminPayments=0;
    }

    FileBar->addMenu(Config);
    FileBar->addMenu(About);
}

void legamimainwindow::closeAll(){
    close();
}

void legamimainwindow::logout(){
    Boss->getloader()->writedb();
    setWindowTitle(QString("Legami"));
    QString name= Boss->accountlogged()->user()->user();
    Boss->logoutAccount();
    QMessageBox::information(this, tr("Successfully logged out!"), name+tr(" successfully logged out."), QMessageBox::Ok, QMessageBox::Ok);
    setMenuBarUnregistered();

}

void legamimainwindow::showuser(){
    delete MainWidget;
    if(!scroll){
	scroll=new QScrollArea(this);
	scroll->resize(this->size());
    }
    if(dynamic_cast<useraccount*>(Boss->accountlogged())) MainWidget= new showuserprofile(*(Boss->accountlogged()), Boss, this);
    else MainWidget= new showcompanyprofile(*(Boss->accountlogged()), Boss, this);
    scroll->setWidget(MainWidget);
    MainWidget->adjustSize();
    scroll->setAlignment(Qt::AlignHCenter);
    MainWidget->setMinimumWidth(620);
    setCentralWidget(scroll);
}

void legamimainwindow::modifyuser(){
    delete MainWidget;
    if(!scroll){
	scroll=new QScrollArea(this);
	scroll->resize(this->size());
    }
    if(dynamic_cast<useraccount*>(Boss->accountlogged())){
	MainWidget= new modifyuserprofile(*(dynamic_cast<useraccount*>((Boss->accountlogged()))), this);
	connect(MainWidget, SIGNAL(modifiedlist()), this, SLOT(usermodified()));
	scroll->setWidget(MainWidget);
	MainWidget->adjustSize();
	scroll->setAlignment(Qt::AlignHCenter);
	MainWidget->setMinimumWidth(620);
	setCentralWidget(scroll);
    }
    else if(dynamic_cast<companyaccount*>(Boss->accountlogged())){
	MainWidget= new modifycompanyprofile(dynamic_cast<companyaccount*>(Boss->accountlogged()), this);
	scroll->setWidget(MainWidget);
	MainWidget->adjustSize();
	scroll->setAlignment(Qt::AlignHCenter);
	MainWidget->setMinimumWidth(620);
	setCentralWidget(scroll);
    }
    else QMessageBox::information(this, tr("Error!"), tr(" asdasdasd successfully logged out."), QMessageBox::Ok, QMessageBox::Ok);
}

void legamimainwindow::closeEvent(QCloseEvent* event){
    Boss->getloader()->writedb();
    delete Boss;
    event->accept();
}

void legamimainwindow::usermodified(){
    delete MainWidget;
    if(!scroll){
	scroll=new QScrollArea(this);
	scroll->resize(this->size());
    }
    if(dynamic_cast<useraccount*>(Boss->accountlogged())){
	MainWidget= new modifyuserprofile(*(dynamic_cast<useraccount*>((Boss->accountlogged()))), this);
	connect(MainWidget, SIGNAL(modifiedlist()), this, SLOT(modifyuser()));
	scroll->setWidget(MainWidget);
	MainWidget->adjustSize();
	scroll->setAlignment(Qt::AlignHCenter);
	MainWidget->setMinimumWidth(620);
	setCentralWidget(scroll);
    }
    else if(dynamic_cast<companyaccount*>(Boss->accountlogged())){
	MainWidget= new modifycompanyprofile(dynamic_cast<companyaccount*>(Boss->accountlogged()), this);
	scroll->setWidget(MainWidget);
	MainWidget->adjustSize();
	scroll->setAlignment(Qt::AlignHCenter);
	MainWidget->setMinimumWidth(620);
	setCentralWidget(scroll);
    }
    else QMessageBox::information(this, tr("Error!"), tr(" asdasdasd successfully logged out."), QMessageBox::Ok, QMessageBox::Ok);
}

void legamimainwindow::showgroups(){
    delete MainWidget;
    delete scroll;
    scroll=new QScrollArea(this);
    MainWidget= new viewGroupIscrived(Boss->accountlogged(), Boss, this);
    scroll->setWidget(MainWidget);
    connect(MainWidget, SIGNAL(resized()), this, SLOT(resizewindow()));
    MainWidget->adjustSize();
    scroll->setAlignment(Qt::AlignHCenter);
    MainWidget->setMinimumWidth(620);
    setCentralWidget(scroll);
}

void legamimainwindow::resizewindow(){
    MainWidget->resize(this->size());
    setCentralWidget(scroll);
}

void legamimainwindow::iscrivenewGroup(){
    addnewgroup* newgroup= new addnewgroup(Boss->accountlogged(), Boss, this);
    connect(newgroup, SIGNAL(created()), this, SLOT(groupCreated()));

    newgroup->show();
}

void legamimainwindow::groupCreated(){
    QMessageBox::information(this, tr("Group Created"), tr("The group requested has been created. /n You are the admin."), QMessageBox::Ok, QMessageBox::Ok);
}

void legamimainwindow::subscribeGroup(){
    subscribegroup* temp= new subscribegroup(Boss->accountlogged(), Boss, this);
    connect(temp, SIGNAL(subscrived()), this, SLOT(subscrived()));
    temp->show();
}

void legamimainwindow::subscrived(){
    QMessageBox::information(this, tr("Group Subscrived"), tr("You have been added to the group requested."), QMessageBox::Ok, QMessageBox::Ok);
}


void legamimainwindow::inbox(){
    delete MainWidget;
    if(!scroll){
	scroll=new QScrollArea(this);
	scroll->resize(this->size());
    }
    MainWidget= new inboxMessages(Boss->accountlogged(), Boss, this);
    scroll->setWidget(MainWidget);
    MainWidget->adjustSize();
    scroll->setAlignment(Qt::AlignHCenter);
    MainWidget->setMaximumWidth(620);
    MainWidget->setMaximumWidth(620);
    MainWidget->resize(this->size());
    setCentralWidget(scroll);
}

void legamimainwindow::outbox(){
    delete MainWidget;
    if(!scroll){
	scroll=new QScrollArea(this);
	scroll->resize(this->size());
    }
    MainWidget= new outboxMessages(Boss->accountlogged(), Boss, this);
    scroll->setWidget(MainWidget);
    MainWidget->adjustSize();
    scroll->setAlignment(Qt::AlignHCenter);
    MainWidget->setMaximumWidth(620);
    MainWidget->setMaximumWidth(620);
    MainWidget->resize(this->size());
    setCentralWidget(scroll);
}

void legamimainwindow::messagenew(){
    try{
	newmessage* newmess= new newmessage(Boss->accountlogged(), Boss, this);
	newmess->show();
    }
    catch(error er1){
	QMessageBox::warning(this, tr("Error"), er1.comment(), QMessageBox::Ok, QMessageBox::Ok);
    }
}

void legamimainwindow::showcontactsself(){
    delete MainWidget;
    if(!scroll){
	scroll=new QScrollArea(this);
	scroll->resize(this->size());
    }
    MainWidget= new showcontacts(Boss->accountlogged(), this);
    scroll->setWidget(MainWidget);
    MainWidget->adjustSize();
    scroll->setAlignment(Qt::AlignHCenter);
    MainWidget->setMaximumWidth(620);
    MainWidget->setMaximumWidth(620);
    MainWidget->resize(this->size());
    setCentralWidget(scroll);
}
