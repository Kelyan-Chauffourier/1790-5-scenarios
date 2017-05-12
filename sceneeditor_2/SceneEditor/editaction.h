#ifndef EDITACTION_H
#define EDITACTION_H

#include "ui_editaction.h"
#include "caction.h"

class editAction : public QDialog, private Ui::editAction
{
    Q_OBJECT

	QList<CAction *> *listeActions;
	int index;

public:
    explicit editAction(QWidget *parent = 0);
	editAction(QWidget *parent, QList<CAction *> *list, int index = -1);
};

#endif // EDITACTION_H
