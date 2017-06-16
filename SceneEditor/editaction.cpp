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
		currentAction = new CAction(*current);
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
		qle_Name->setText(current->object().name());
		qle_Id->setText(QString(std::to_string(current->object().id()).c_str()));
		if(current->object().smokeSize() !=0) {
			chk_Smoke->setChecked(true);
			qhs_Smoke->setValue(current->object().smokeSize() * 10);
		}
		if(current->type()=="apparition") {
			rdbApparition->setChecked(true);
		}
		else if(current->type()=="déplacement/changement d'état") {
			rdbDeplacement->setChecked(true);
		}
		else if(current->type()=="disparition") {
			rdbDisparition->setChecked(true);
		}
	}
	else {
		setupUi(this);
		setModal(true);
		//parametrage de l'interface
		//TODO
		currentAction = new CAction("manuel", Object3D(0,"",""));
		rdbApparition->setChecked(true);
		lbl_Altitude->setHidden(true);
		qle_Altitude->setHidden(true);
		qhs_Smoke->setHidden(true);
		lbl_Smoke_1->setHidden(true);
		lbl_Smoke_2->setHidden(true);
	}
}

void editAction::on_qle_Name_textChanged(const QString &arg1)
{
	currentAction->object().setName(qle_Name->text());
}

void editAction::on_qle_Id_textChanged(const QString &arg1)
{
	currentAction->object().setId(qle_Id->text().toInt());
}

void editAction::on_rdbApparition_toggled(bool checked)
{
	if(checked == true) {
		currentAction->setType("apparition");
	}
}

void editAction::on_rdbDeplacement_toggled(bool checked)
{
	if(checked == true) {
		currentAction->setType(QString("déplacement/changement d'état"));
	}
}

void editAction::on_rdbDisparition_toggled(bool checked)
{
	if(checked == true) {
		currentAction->setType("disparition");
	}
}

void editAction::on_chkOnGround_toggled(bool checked)
{
	currentAction->object().setOnGround(checked);
}

void editAction::on_qhs_Smoke_valueChanged(int value)
{
	currentAction->object().setSmokeSize(value/10);
}

void editAction::on_chk_Smoke_toggled(bool checked)
{
	if(checked) {
		currentAction->object().setSmokeSize(0);
	}
	else {
		currentAction->object().setSmokeSize(qhs_Smoke->value()/10);
	}
}

void editAction::on_pbu_Valider_clicked()
{
	if(index == -1) {
		listeActions->append(currentAction);
		listeActions->last()->object().setPosition(qle_Latitude->text().replace(',', '.').toDouble(), qle_Longitude->text().replace(',', '.').toDouble(), qle_Altitude->text().replace(',', '.').toDouble());
		listeActions->last()->object().setAttitude(qle_Psi->text().replace(',', '.').toDouble(), qle_Phi->text().replace(',', '.').toDouble(), qle_Theta->text().replace(',', '.').toDouble());
        listeActions->last()->object().setOnGround(chkOnGround->isChecked());
    }
	else {
		listeActions->replace(index, currentAction);
		listeActions->at(index)->object().setPosition(qle_Latitude->text().replace(',', '.').toDouble(), qle_Longitude->text().replace(',', '.').toDouble(), qle_Altitude->text().replace(',', '.').toDouble());
		listeActions->at(index)->object().setAttitude(qle_Psi->text().replace(',', '.').toDouble(), qle_Phi->text().replace(',', '.').toDouble(), qle_Theta->text().replace(',', '.').toDouble());
        listeActions->last()->object().setOnGround(chkOnGround->isChecked());
    }
	close();
}
