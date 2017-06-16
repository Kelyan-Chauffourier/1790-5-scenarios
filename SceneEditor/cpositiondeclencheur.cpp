#include "cpositiondeclencheur.h"

CPositionDeclencheur::CPositionDeclencheur():
    CDeclencheur(),
    m_rayon("0")
{

}

void CPositionDeclencheur::setLatitude(QString latitude)
{
    m_position.setLatitude(latitude) ;
}

void CPositionDeclencheur::setLongitude(QString longitude)
{
    m_position.setLongitude(longitude);
}

void CPositionDeclencheur::setRayon(QString rayon)
{
    m_rayon = rayon ;
}

QString CPositionDeclencheur::parametre()
{
    QString s ;
    s = m_position.position() ;
    s += "\nRayon : " + m_rayon ;
    return s ;
}

QString CPositionDeclencheur::texte()
{
    QString s ;
    s = description();
    s += "\n\nType : déclenchement sur zone \n" ;
    s += parametre();
    return s ;
}
