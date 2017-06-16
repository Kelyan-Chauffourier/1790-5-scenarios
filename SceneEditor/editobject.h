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
	QString baseName ;

public:
	explicit EditObject(QWidget *parent = 0);
	EditObject(QWidget *parent, QList<CObject> *list, int index = -1);

private slots:
	void on_pbu_Valider_clicked();
	void on_pbu_chemin_clicked();
	void on_qle_chemin_textChanged(const QString &arg1);
	void on_qle_Nom_textChanged(const QString &arg1);

signals:
	void obj_name_changed(QString oldName, QString newName);
};

#endif // EDITOBJECT_H
