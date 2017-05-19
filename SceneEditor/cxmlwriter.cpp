#include "cxmlwriter.h"
#include <QtXml>
#include <iostream>
#include <QDomDocument>
#include <QTextStream>
#include <QFile>
#include "cmanualdeclencheur.h"
#include "cpositiondeclencheur.h"
#include "ctimedeclencheur.h"
#include "cevent.h"


CXmlWriter::CXmlWriter()
{
}

void CXmlWriter::saveFile(QFile &file, QList<CObject> objects, QList<CEvent> events)
{
	QTextStream stream(&file) ;
	// creation d'un DOM
	QDomDocument dom ;
	//creation de la balise à la racine
	QDomElement root = dom.createElement("scnfile");
	dom.appendChild(root);
	// Ajout des balises pour chaque objet
	for(int i=0;i<objects.size();i++) {
		QDomElement obj = dom.createElement("object");
		obj.setAttribute("path", (QString)objects[i].getPath().toLatin1());
		obj.setAttribute("name",(QString)objects[i].getName().toLatin1());
		root.appendChild(obj);
	}
	//Ajout des evenements
	for(int i=0;i<events.size();i++) {
		QDomElement event = dom.createElement("event");
		// nom de l'événement
		QDomElement name = dom.createElement("name");
		QDomText nom = dom.createTextNode((QString)events[i].name().toLatin1());
		name.appendChild(nom);
		event.appendChild(name);
		// description de l'événement
		QDomElement descr = dom.createElement("description");
		QDomText desc = dom.createTextNode((QString)events[i].description().toLatin1());
		descr.appendChild(desc);
		event.appendChild(descr);
		//Ajout des actions
		QDomElement actions = dom.createElement("actions");
		// parcours de la liste des actions
		for(int j=0;j<events[i].actions().size();j++) {
			QDomElement action = dom.createElement("action");
			QString type = events[i].actions()[j]->type().toLatin1();
			action.setAttribute("type", type);
			// ajout de l'objet concerné
			QDomElement action_obj = dom.createElement("object");
			action_obj.setAttribute("name",(QString)events[i].actions()[j]->object().name().toLatin1());
			action_obj.setAttribute("id", (QString)events[i].actions()[j]->object().id());
			// Position de l'objet
			QDomElement obj_pos = dom.createElement("position");
			obj_pos.setAttribute("latitude", QString::number(events[i].actions()[j]->object().position().x()));
			obj_pos.setAttribute("longitude", QString::number(events[i].actions()[j]->object().position().y()));
			obj_pos.setAttribute("elevation", QString::number(events[i].actions()[j]->object().position().z()));
			// Rotations
			QDomElement obj_rotations = dom.createElement("vrotations");
			obj_rotations.setAttribute("psi",QString::number(events[i].actions()[j]->object().attitude().x()));
			obj_rotations.setAttribute("the",QString::number(events[i].actions()[j]->object().attitude().y()));
			obj_rotations.setAttribute("phi",QString::number(events[i].actions()[j]->object().attitude().z()));
			//divers
			QDomElement obj_divers = dom.createElement("divers");
			obj_divers.setAttribute("ground", QString::number(events[i].actions()[j]->object().isOnGround()));
			obj_divers.setAttribute("smoke", QString::number(events[i].actions()[j]->object().smokeSize()));
			//ajout des elements crées dans le bon ordre
			action_obj.appendChild(obj_pos);
			action_obj.appendChild(obj_rotations);
			action_obj.appendChild(obj_divers);
			action.appendChild(action_obj);
			actions.appendChild(action);
		}
		event.appendChild(actions);
		root.appendChild(event);
	}
	std::cerr << dom.toString().toLatin1().toStdString();
}
