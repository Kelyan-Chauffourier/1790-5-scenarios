#include "cevent.h"
#include "caction.h"
#include "cdeclencheur.h"
#include <iostream>

CEvent::CEvent():
	m_name("Nom événement"),
	m_description("Description événement"),
	m_declencheur(NULL)
{

}

void CEvent::setName(QString name)
{
	m_name = name ;
}

void CEvent::setDescription(QString description)
{
	m_description = description ;
}

void CEvent::addAction(CAction* action)
{
	m_listAction.push_back(action);
}

void CEvent::setDeclencheur(CDeclencheur* declencheur)
{
	m_declencheur = declencheur ;
}

QString CEvent::name()
{
	return m_name ;
}

QString CEvent::description()
{
	return m_description ;
}

QList<CAction*> CEvent::actions()
{
	return m_listAction ;
}

CDeclencheur* CEvent::declencheur()
{
	return m_declencheur ;
}

QString CEvent::actionsEvent()
{
	QString s = description() ;
	for (int i = 0 ; i < m_listAction.size() ; i++) {
		s += m_listAction[i]->parametre() ;
	}
	return s ;
}
