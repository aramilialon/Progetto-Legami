#ifndef MODIFYUSEREXPERIENCE_H
#define MODIFYUSEREXPERIENCE_H

#include "../lib/useraccount.h"
#include "../lib/experience.h"

#include <QDateEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class modifyuserexperience : public QGroupBox
{
    Q_OBJECT

    useraccount* ouwner;
    experience* expToModify;

    QLabel* nameLabel;
    QLabel* dateLabel;
    QLabel* descrLabel;

    QLineEdit* nameLineEdit;
    QDateEdit* dateDateEdit;
    QLineEdit* descrLineEdit;

    QGridLayout* layout;

    QPushButton* modifyButton;
    QPushButton* cancelButton;
    QPushButton* deleteButton;

public:
    explicit modifyuserexperience(experience* , useraccount*,  QWidget *parent = 0);

signals:
    void modifiedExp();
public slots:
    void modifyExp();
    void cancel();
    void deleteExp();
};

#endif // MODIFYUSEREXPERIENCE_H
