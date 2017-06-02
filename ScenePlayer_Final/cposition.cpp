#include "cposition.h"

CPosition::CPosition():
	m_latitude("0"),
	m_longitude("0")
{

}

QString CPosition::latitude()
{
	return m_latitude ;
}

QString CPosition::longitude()
{
	return m_longitude ;
}

QString CPosition::position()
{
	QString s ;
	s = "Latitude : " + latitude() ;
	s += "\nLongitude : " + longitude() ;
	return s ;
}

void CPosition::setLatitude(QString latitude)
{
	m_latitude = latitude ;
}

void CPosition::setLongitude(QString longitude)
{
	m_longitude = longitude ;
}
