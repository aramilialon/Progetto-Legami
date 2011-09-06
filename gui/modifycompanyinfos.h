#ifndef MODIFYCOMPANYINFOS_H
#define MODIFYCOMPANYINFOS_H

#include "../lib/companyaccount.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>

class modifycompanyinfos : public QGroupBox
{
    Q_OBJECT

    companyaccount* accToModify;

    QLineEdit* nameLineEdit;
    QLineEdit* addressLineEdit;
    QLineEdit* cotypeLineEdit;

    QFormLayout* layout;

    QPushButton* okButton;
    QPushButton* cancelButton;

public:
    explicit modifycompanyinfos(companyaccount *, QWidget *parent = 0);

signals:
    void modified(bool);

public slots:
    void modify();
    void reset();

};

#endif // MODIFYCOMPANYINFOS_H
