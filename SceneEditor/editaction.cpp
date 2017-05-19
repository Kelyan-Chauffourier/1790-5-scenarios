#include "editaction.h"
#include <iostream>
#include <string>

editAction::editAction(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
	setModal(true);
    lbl_Altitude->setHidden(true);
	qle_Altitude->setHidden(true);
}

editAction::editAction(QWidget *parent, QList<CAction *> *list, int index) :
	QDialog(parent),
	listeActions(list),
	index(index)
{
	if(index != -1) {
		setupUi(this);
		setModal(true);
		// parametrage de l'interface
		//TODO
		CAction * current = list->at(index);
		lbl_Altitude->setHidden(true);
		qle_Altitude->setHidden(true);
		qle_Latitude->setText(QString(std::to_string(current->object().position().x()).c_str()));
		qle_Longitude->setText(QString(std::to_string(current->object().position().y()).c_str()));
		qle_Altitude->setText(QString(std::to_string(current->object().position().z()).c_str()));
		qle_Psi->setText(QString(std::to_string(current->object().attitude().x()).c_str()));
		qle_Theta->setText(QString(std::to_string(current->object().attitude().y()).c_str()));
		qle_Phi->setText(QString(std::to_string(current->object().attitude().z()).c_str()));
		/**/
		qhs_Smoke->setHidden(true);
		lbl_Smoke_1->setHidden(true);
		lbl_Smoke_2->setHidden(true);
		if(current->object().isOnGround()) {
			chkOnGround->setChecked(true);
		}
		qle_Name->setText(current->object().name().toLatin1());
		qle_Id->setText(QString(std::to_string(current->object().id()).c_str()));
		if(current->object().smokeSize() !=0) {
			chk_Smoke->setChecked(true);
			qhs_Smoke->setValue(current->object().smokeSize() * 10);
		}
		if(current->type().toLatin1()=="apparition") {
			rdbApparition->setChecked(true);
		}
		else if(current->type().toLatin1()=="déplacement") {
			rdbDeplacement->setChecked(true);
		}
		else if(current->type().toLatin1()=="disparition") {
			rdbApparition->setChecked(true);
		}
	}
	else {
		setupUi(this);
		setModal(true);
		//parametrage de l'interface
		//TODO
		rdbApparition->setChecked(true);
		lbl_Altitude->setHidden(true);
		qle_Altitude->setHidden(true);
		qhs_Smoke->setHidden(true);
		lbl_Smoke_1->setHidden(true);
		lbl_Smoke_2->setHidden(true);
	}
}
