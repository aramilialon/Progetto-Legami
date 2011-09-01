#ifndef MODIFYUSERN_H
#define MODIFYUSERN_H

#include "../lib/useraccount.h"
#include "../lib/username.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>

class modifyusern : public QGroupBox
{
    Q_OBJECT

    useraccount* accToModify;

    QFormLayout* layout;
    QLineEdit* usernLineEdit;
    QLineEdit* passwLineEdit;
    QPushButton* okButton;
    QPushButton* cancelButton;

public:
    explicit modifyusern(const useraccount &, QWidget *parent = 0);

signals:
    void modified(bool);

public slots:
    void modify();
    void reset();

};

#endif // MODIFYUSERN_H
