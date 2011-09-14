/*
  File: showmessage.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef SHOWMESSAGE_H
#define SHOWMESSAGE_H

#include "../lib/message.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

class showMessage : public QGroupBox
{
    Q_OBJECT

    message* messToShow;

    QLineEdit* senderLineEdit;
    QLineEdit* receverLineEdit;
    QLineEdit* objLineEdit;

    QTextEdit* messageTextEdit;

    QFormLayout* layout;

public:
    explicit showMessage(message*, QWidget *parent = 0);

signals:

public slots:

};

#endif // SHOWMESSAGE_H
