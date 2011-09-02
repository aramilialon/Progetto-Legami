#ifndef MODIFYUSEREXPERIENCE_H
#define MODIFYUSEREXPERIENCE_H

#include "../lib/experience.h"

#include <QDateEdit>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>

class modifyuserexperience : public QGroupBox
{
    Q_OBJECT

    experience* expToModify;


    QFormLayout* layout;

public:
    explicit modifyuserexperience(experience* , QWidget *parent = 0);

signals:

public slots:
    void modifyExp();
};

#endif // MODIFYUSEREXPERIENCE_H
