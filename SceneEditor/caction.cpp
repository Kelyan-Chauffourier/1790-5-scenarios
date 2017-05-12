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

Object3D CAction::object()
{
	return m_object ;
}
