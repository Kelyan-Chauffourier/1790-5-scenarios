#include "ctimedeclencheur.h"

CTimeDeclencheur::CTimeDeclencheur():
    CDeclencheur(),
    m_time("0")
{

}

void CTimeDeclencheur::setTime(QString time)
{
    m_time = time ;
}

QString CTimeDeclencheur::texte()
{
    QString s ;
    s = description();
    s += "\n\nType : déclenchement en fonction du temps \n" ;
    s += "Temps : " + m_time ;
    return s ;
}
