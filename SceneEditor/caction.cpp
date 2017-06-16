#include "caction.h"

CAction::CAction(QString type, Object3D object)
	: m_type(type)
	, m_object(object)
{

}

QString CAction::parametre()
{
	QString s ;
	s = "\n\nType : " + m_type + "\n" ;
	s += m_object.affichageName() ;
	s += m_object.affichagePosition() ;
	s += m_object.affichageAttitude() ;
	s += m_object.affichageOnGround() ;
	s += m_object.affichageSmokeSize() ;
	return s ;
}

Object3D &CAction::object()
{
	return m_object ;
}

CAction::CAction(CAction &copy)
	: m_object(copy.m_object)
{
	m_type = copy.m_type;
	m_object.setPosition(copy.m_object.position().x(),copy.m_object.position().y(),copy.m_object.position().z());
	m_object.setId(copy.m_object.id());
	m_object.setName(copy.m_object.name());
	m_object.setOnGround(copy.m_object.isOnGround());
	m_object.setSmokeSize(copy.m_object.smokeSize());
	m_object.setAttitude(copy.m_object.attitude().x(), copy.m_object.attitude().y(), copy.m_object.attitude().z());
}
