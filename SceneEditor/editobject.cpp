#include "editobject.h"

EditObject::EditObject(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

EditObject::EditObject(QWidget *parent, QList<CObject> *list, int index) :
    QDialog(parent),
    listeObjets(list),
    index(index)
{
    if(index != -1) {
        currentObject = new CObject((*list)[index]) ;
        setupUi(this);
        setModal(true);
		// Parametrage de l'interface
		qle_chemin->setText(currentObject->getPath().toLatin1());
		qle_Nom->setText(currentObject->getName().toLatin1());

    }
    else {
        setupUi(this);
        setModal(true);
        // Parametrage de l'interface
	}
}

void EditObject::on_pbu_Valider_clicked()
{
	if(index != -1) {

	}
	else {

	}
	close();
}
