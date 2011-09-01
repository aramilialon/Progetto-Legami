/*
  File: legamilogin.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#ifndef LEGAMILOGIN_H
#define LEGAMILOGIN_H

#include "../lib/legami.h"

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>
#include <QString>

class legamilogin : public QDialog
{
    Q_OBJECT

    legami* boss;

    QLabel* upperLabel;

    QLabel* usernLabel;
    QLineEdit* usernLineEdit;

    QLabel* passwLabel;
    QLineEdit* passwLineEdit;

    QPushButton* loginButton;
    QPushButton* cancelButton;

    QGridLayout* layout;

public:
    explicit legamilogin(legami*, QWidget* parent = 0);

signals:
    void logged(bool);

public slots:
    void tryLogin();

};

#endif // LEGAMILOGIN_H
