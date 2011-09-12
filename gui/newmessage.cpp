#include "../lib/useraccount.h"
#include "../lib/message.h"

#include "newmessage.h"
#include "showcontactsmessage.h"


newmessage::newmessage(account* acc, legami* boss, QWidget *parent) throw(error) :
    QDialog(parent), sender(acc), Boss(boss)
{
    layout= new QGridLayout(this);
    if(dynamic_cast<useraccount*>(sender)){
	int typeAccount= sender->type();
	if(typeAccount==0){
	    throw error(Permission, QString("Basic user account are not allowed to send any message."));
	}
	addresseeLineEdit= new QLineEdit(this);
	if(typeAccount==1){
	    addresseeLineEdit->setReadOnly(true);
	    selectAddressee= new QPushButton(tr("Select addressee"), this);
	    connect(selectAddressee, SIGNAL(clicked()), this, SLOT(changeReceverPressed()));
	}
	else{
	    selectAddressee=0;
	}
	addresseeLabel= new QLabel(tr("Addressee:"));
	layout->addWidget(addresseeLabel, 0, 0);
	layout->addWidget(addresseeLineEdit, 0, 1);
	if(selectAddressee){
	    layout->addWidget(selectAddressee, 0, 2);
	}

	objLabel= new QLabel(tr("Object:"));
	layout->addWidget(objLabel, 3, 0);
	objLineEdit=new QLineEdit(this);
	layout->addWidget(objLineEdit, 3, 1);

	textLabel= new QLabel(tr("Text:"));
	layout->addWidget(textLabel, 4, 0);
	textTextEdit= new QTextEdit(this);
	layout->addWidget(textTextEdit, 5, 0);

	okButton= new QPushButton(tr("Send"), this);
	connect(okButton, SIGNAL(clicked()), this, SLOT(send()));
	layout->addWidget(okButton, 6, 0);

	cancelButton= new QPushButton(tr("Cancel"), this);
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	layout->addWidget(cancelButton, 6, 1);

	setLayout(layout);
    }
}

void newmessage::send(){
    message* temp= new message(*sender, *(Boss->basicSearch(addresseeLineEdit->text())), objLineEdit->text(), textTextEdit->document()->toPlainText());

    Boss->addMessage(*temp);

}

void newmessage::changeReceverPressed(){
    showcontactsmessage* temp= new showcontactsmessage(sender, this);
    connect(temp, SIGNAL(selected(QString)), this, SLOT(changeAddressee(QString)));
    temp->show();
}

void newmessage::changeAddressee(QString newaddr){
    addresseeLineEdit->setText(newaddr);
}
