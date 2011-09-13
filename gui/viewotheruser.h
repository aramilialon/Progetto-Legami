#ifndef VIEWOTHERUSER_H
#define VIEWOTHERUSER_H

#include "../lib/account.h"
#include "../lib/legami.h"

#include <QDialog>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

class viewotheruser : public QDialog
{
    Q_OBJECT

    account* accToShow;

    legami* Boss;

    QVBoxLayout* layout;

    QWidget* MainWidget;

    QScrollArea* scrollArea;

    QPushButton* okButton;

public:
    explicit viewotheruser(account*, legami*, QWidget *parent = 0);

signals:

public slots:
    void ok();

};

#endif // VIEWOTHERUSER_H
