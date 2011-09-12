#ifndef NEWMESSAGE_H
#define NEWMESSAGE_H

#include "../lib/account.h"
#include "../lib/error.h"
#include "../lib/legami.h"
#include "../lib/message.h"

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QStandardItemModel>
#include <QString>
#include <QTextEdit>

class newmessage : public QDialog
{
    Q_OBJECT

    account* sender;
    legami* Boss;

    bool listShown;

    QString addresseeTemp;

    QGridLayout* layout;

    QLabel* addresseeLabel;
    QLabel* objLabel;
    QLabel* textLabel;

    QLineEdit* addresseeLineEdit;
    QLineEdit* objLineEdit;
    QTextEdit* textTextEdit;

    QListView* friendList;
    QStandardItemModel* friendModel;

    QPushButton* selectAddressee;
    QPushButton* okButton;
    QPushButton* cancelButton;

public:
    explicit newmessage(account*, legami*, QWidget *parent = 0) throw(error);

signals:

public slots:
    void send();
    void changeReceverPressed();
    void changeAddressee(QString);

};

#endif // NEWMESSAGE_H
