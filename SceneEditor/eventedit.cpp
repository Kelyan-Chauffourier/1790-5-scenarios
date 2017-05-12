#include "eventedit.h"
#include "editaction.h"

eventEdit::eventEdit(QWidget *parent) :
    QDialog(parent)
{
	setupUi(this);
	setModal(true);
	grb_Pos->setHidden(true);
	grb_Time->setHidden(true);
}

eventEdit::eventEdit(QWidget *parent, QList<CEvent> *list, int index) :
	QDialog(parent),
	index(index),
	listeEvents(list)
{
	if(index != -1) {
		currentEvent = new CEvent((*list)[index]) ;
		setupUi(this);
		setModal(true);
		// Parametrage de l'interface
		if(currentEvent->declencheur()->type()=="manual") {
			rdbManuel->setChecked(true);
			grb_Pos->setHidden(true);
			grb_Time->setHidden(true);
		}
		else if(currentEvent->declencheur()->type()=="time") {
			rdbTime->setChecked(true);
			grb_Pos->setHidden(true);
		}
		else if(currentEvent->declencheur()->type()=="position") {
			rdbPos->setChecked(true);
			grb_Time->setHidden(true);
		}
	}
	else {
		setupUi(this);
		setModal(true);
		grb_Pos->setHidden(true);
		grb_Time->setHidden(true);
	}
}

void eventEdit::on_pbuAddAction_clicked()
{
	editAction* edit = new editAction(this,&(currentEvent->actions()));
	edit->show();
}
