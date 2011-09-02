#ifndef MODIFYUSERINFOS_H
#define MODIFYUSERINFOS_H

#include "../lib/useraccount.h"

#include <QDateEdit>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>

class modifyuserinfos : public QGroupBox
{
    Q_OBJECT

    QFormLayout* layout;

    useraccount* accToModify;

    QLineEdit* nameLineEdit;
    QLineEdit* surnameLineEdit;
    QDateEdit* dateDateEdit;
    QLineEdit* placeLineEdit;
    QLineEdit* telnumLineEdit;
    QLineEdit* emailLineEdit;

    QPushButton* okButton;
    QPushButton* cancelButton;

public:
    explicit modifyuserinfos(const useraccount &, QWidget *parent = 0);

signals:
    void modified(bool);

public slots:
    void modify();
    void reset();
};

#endif // MODIFYUSERINFOS_H
