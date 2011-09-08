#ifndef SHOWMESSAGE_H
#define SHOWMESSAGE_H

#include "../lib/message.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QTextEdit>

class showMessage : public QGroupBox
{
    Q_OBJECT

    message* messToShow;

    QFormLayout* layout;

    QLineEdit* senderLineEdit;
    QLineEdit* receverLineEdit;
    QLineEdit* objLineEdit;

    QTextEdit* messageTextEdit;

public:
    explicit showMessage(message*, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWMESSAGE_H
