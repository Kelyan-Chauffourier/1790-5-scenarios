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

	CEvent* currentEvent ;
	int index;
	QList<CEvent> *listeEvents;

public:
    explicit eventEdit(QWidget *parent = 0);
	eventEdit(QWidget *parent, QList<CEvent> *list, int index = -1 );

private slots:
    //void changeType();
	void on_pbuAddAction_clicked();
};

#endif // EVENTEDIT_H
