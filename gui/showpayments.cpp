#include "showpayments.h"

showpayments::showpayments(account* acc, QWidget *parent) :
    QWidget(parent), accToShow(acc)
{
    layout= new QGridLayout(this);

    payList= new showlistpayments(accToShow, this);
    layout->addWidget(payList);

    setLayout(layout);
}
