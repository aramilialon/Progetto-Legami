#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QWidget>

class searchwidget : public QWidget
{
    Q_OBJECT
    legami* Boss;


public:
    explicit searchwidget(legami*, QWidget *parent = 0);

signals:

public slots:

};

#endif // SEARCHWIDGET_H
