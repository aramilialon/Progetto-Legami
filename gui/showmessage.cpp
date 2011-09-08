#include "showmessage.h"

showMessage::showMessage(message* mess, QWidget *parent) :
    QGroupBox(tr("Message"), parent), messToShow(mess)
{
    layout= new QFormLayout(this);

    senderLineEdit= new QLineEdit(messToShow->sender()->user()->user());
    layout->addRow(tr("Sender:"), senderLineEdit);

    receverLineEdit= new QLineEdit(messToShow->recever()->user()->user());
    layout->addRow(tr("Addressee:"), receverLineEdit);

    objLineEdit= new QLineEdit(messToShow->object());
    layout->addRow(tr("Object:"), objLineEdit);

    messageTextEdit= new QTextEdit(messToShow->text());
    layout->addRow(tr("Message:"), messageTextEdit);

    setLayout(layout);
}
