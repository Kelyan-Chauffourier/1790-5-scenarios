#ifndef EDITOBJECT_H
#define EDITOBJECT_H

#include "ui_editobject.h"
#include "cobject.h"

class EditObject : public QDialog, private Ui::editObject
{
    Q_OBJECT

    CObject *currentObject;
    QList<CObject> *listeObjets;
    int index;

public:
	explicit EditObject(QWidget *parent = 0);
	EditObject(QWidget *parent, QList<CObject> *list, int index = -1);

private slots:
	void on_pbu_Valider_clicked();
};

#endif // EDITOBJECT_H
