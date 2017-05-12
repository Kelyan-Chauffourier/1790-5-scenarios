#include "editobject.h"

editObject::editObject(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

editObject::editObject(QWidget *parent, QList<CObject> *list, int index) :
    QDialog(parent),
    listeObjets(list),
    index(index)
{
    if(index != -1) {
        currentObject = new CObject((*list)[index]) ;
        setupUi(this);
        setModal(true);
		qle_chemin->setText(currentObject->getPath());
		qle_Nom->setText(currentObject->getName());
        // Parametrage de l'interface

    }
    else {
        setupUi(this);
        setModal(true);
        // Parametrage de l'interface
    }
}
