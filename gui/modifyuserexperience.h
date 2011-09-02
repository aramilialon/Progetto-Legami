#ifndef MODIFYUSEREXPERIENCE_H
#define MODIFYUSEREXPERIENCE_H

#include "../lib/experience.h"

#include <QDateEdit>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>

class modifyuserexperience : public QGroupBox
{
    Q_OBJECT

    experience* expToModify;

    QLineEdit* nameLineEdit;
    QDateEdit* dateDateEdit;
    QLineEdit* descrLineEdit;

    QFormLayout* layoutEdit;
    QGridLayout* layout;

    QPushButton* modifyButton;
    QPushButton* cancelButton;
public:
    explicit modifyuserexperience(experience* , QWidget *parent = 0);

signals:
    void modifiedExp();
public slots:
    void modifyExp();
    void cancel();
};

#endif // MODIFYUSEREXPERIENCE_H
