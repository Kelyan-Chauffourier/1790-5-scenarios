#include "caction.h"

CAction::CAction():
	m_type("?"),
	m_position(CPosition()),
	m_orientation("0")
{

}

void CAction::setType(QString type)
{
	m_type = type ;
}

void CAction::setLatitude(QString latitude)
{
	m_position.setLatitude(latitude) ;
}

void CAction::setLongitude(QString longitude)
{
	m_position.setLongitude(longitude);
}

void CAction::setOrientation(QString orientation)
{
	m_orientation = orientation ;
}

QString CAction::parametre()
{
	QString s ;
	s = "\n\nType : " + m_type + "\n" ;
	s += m_position.position() ;
	s += "\nOrientation : " + m_orientation ;
	return s ;
}
