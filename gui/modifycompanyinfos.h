#ifndef MODIFYCOMPANYINFOS_H
#define MODIFYCOMPANYINFOS_H

#include "../lib/companyaccount.h"

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

public:
    explicit modifycompanyinfos(QWidget *parent = 0);

signals:

public slots:

};

#endif // MODIFYCOMPANYINFOS_H
