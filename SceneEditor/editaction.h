#ifndef EDITACTION_H
#define EDITACTION_H

#include "ui_editaction.h"
#include "caction.h"

class editAction : public QDialog, private Ui::editAction
{
    Q_OBJECT

	QList<CAction *> *listeActions;
	CAction * currentAction;
	int index;

public:
    explicit editAction(QWidget *parent = 0);
	editAction(QWidget *parent, QList<CAction *> *list, int index = -1);
private slots:
	void on_qle_Name_textChanged(const QString &arg1);
	void on_qle_Id_textChanged(const QString &arg1);
	void on_rdbApparition_toggled(bool checked);
	void on_rdbDeplacement_toggled(bool checked);
	void on_rdbDisparition_toggled(bool checked);
	void on_chkOnGround_toggled(bool checked);
	void on_qhs_Smoke_valueChanged(int value);
	void on_chk_Smoke_toggled(bool checked);
	void on_pbu_Valider_clicked();
};

#endif // EDITACTION_H
