#ifndef MODIFYUSEREXPERIENCES_H
#define MODIFYUSEREXPERIENCES_H

#include "../lib/experience.h"
#include "../lib/useraccount.h"
#include "modifyuserexperience.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVector>

class modifyuserexperiences : public QGroupBox
{
    Q_OBJECT

    useraccount* accToModify;
    QVector<modifyuserexperience*> expWidget;

    QVBoxLayout* layout;
    QPushButton* addFormativeExp;
    QPushButton* addWorkingExp;

    void loadExpWidget();

public:
    explicit modifyuserexperiences(const useraccount&, QWidget *parent = 0);

signals:
    void modified();
public slots:
    void pushedForm();
    void pushedWork();
    void modifiedExp();
};

#endif // MODIFYUSEREXPERIENCES_H
