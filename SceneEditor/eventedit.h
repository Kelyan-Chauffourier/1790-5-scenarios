#ifndef EVENTEDIT_H
#define EVENTEDIT_H

#include "ui_eventedit.h"
#include "cevent.h"
#include "cmanualdeclencheur.h"
#include "ctimedeclencheur.h"
#include "cpositiondeclencheur.h"

class eventEdit : public QDialog, private Ui::eventEdit
{
    Q_OBJECT

public:
    explicit eventEdit(QWidget *parent = 0);
    explicit eventEdit(QWidget *parent, CEvent& current );

private:
    CEvent* currentEvent ;

private slots:
    //void changeType();
};

#endif // EVENTEDIT_H
