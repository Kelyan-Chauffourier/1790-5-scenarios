#include "eventedit.h"

eventEdit::eventEdit(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    setModal(true);
    grb_Pos->setHidden(true);
    grb_Time->setHidden(true);
    spl_Altitude->setHidden(true);
}

eventEdit::eventEdit(QWidget *parent, CEvent &current) :
    QDialog(parent)
{
    currentEvent = new CEvent(current) ;
    setupUi(this);
    setModal(true);
    spl_Altitude->setHidden(true);
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
