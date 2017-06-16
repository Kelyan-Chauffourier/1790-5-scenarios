#include "editobject.h"
#include <QFileDialog>

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
		qle_chemin->setText(currentObject->getPath()/*.toLatin1()*/);
		qle_Nom->setText(currentObject->getName()/*.toLatin1()*/);

    }
    else {
        currentObject = new CObject();
        setupUi(this);
        setModal(true);
        // Parametrage de l'interface
	}
}

void EditObject::on_pbu_Valider_clicked()
{
	if(index != -1) {
		CObject obj = listeObjets->at(index) ;
		if(obj.getName() != currentObject->getName()) {
			emit obj_name_changed(obj.getName(), currentObject->getName());
		}
		listeObjets->replace(index, *currentObject);
	}
	else {
		listeObjets->push_back(*currentObject);
	}
	close();
}

void EditObject::on_pbu_chemin_clicked()
{
	QFileDialog dialog ;
	QString openFile = dialog.getOpenFileName(
		this,
		QString("sélection du chemin"),
		QDir::homePath(),
		QString("*"),
		nullptr,
		QFileDialog::DontResolveSymlinks);
	if(openFile == "") {
		return ;
	}
	qle_chemin->setText(openFile);
	currentObject->setPath(openFile);
}

void EditObject::on_qle_chemin_textChanged(const QString &arg1)
{
	currentObject->setPath(qle_chemin->text());
}

void EditObject::on_qle_Nom_textChanged(const QString &arg1)
{
	currentObject->setName(qle_Nom->text());
}
