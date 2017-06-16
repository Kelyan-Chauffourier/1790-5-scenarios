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

signals:
	void dataChanged();

private slots:
    //void changeType();
	void on_pbuAddAction_clicked();
	void on_pbuEditAction_clicked();
	void on_pbuDeleteAction_clicked();
	void reloadList();
	void on_pbuValider_clicked();
	void on_rdbManuel_toggled(bool checked);
	void on_rdbTime_toggled(bool checked);
	void on_qle_Nom_textChanged(const QString &arg1);
	void on_pte_Description_textChanged();
};

#endif // EVENTEDIT_H
