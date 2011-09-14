/*
  File: modifycompanyinfos.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef MODIFYCOMPANYINFOS_H
#define MODIFYCOMPANYINFOS_H

#include "../lib/companyaccount.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>

class modifycompanyinfos : public QGroupBox
{
    Q_OBJECT

    companyaccount* accToModify;

    QLineEdit* nameLineEdit;
    QLineEdit* addressLineEdit;
    QLineEdit* cotypeLineEdit;

    QPushButton* okButton;
    QPushButton* cancelButton;

    QFormLayout* layout;

public:
    explicit modifycompanyinfos(companyaccount *, QWidget *parent = 0);

signals:
    void modified(bool);

public slots:
    void modify();
    void reset();

};

#endif // MODIFYCOMPANYINFOS_H
