/*
  File: modifyuserinfos.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef MODIFYUSERINFOS_H
#define MODIFYUSERINFOS_H

#include "../lib/legami.h"
#include "../lib/useraccount.h"

#include <QDateEdit>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>

class modifyuserinfos : public QGroupBox
{
    Q_OBJECT

    useraccount* accToModify;
    legami* Boss;

    QLineEdit* nameLineEdit;
    QLineEdit* surnameLineEdit;
    QDateEdit* dateDateEdit;
    QLineEdit* placeLineEdit;
    QLineEdit* telnumLineEdit;
    QLineEdit* emailLineEdit;

    QPushButton* okButton;
    QPushButton* cancelButton;

    QFormLayout* layout;

public:
    explicit modifyuserinfos(const useraccount &, legami*, QWidget *parent = 0);

signals:
    void modified(bool);

public slots:
    void modify();
    void reset();
};

#endif // MODIFYUSERINFOS_H
