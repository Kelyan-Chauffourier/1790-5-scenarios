#include "cdeclencheur.h"

CDeclencheur::CDeclencheur():
    m_description("Description")
{

}

void CDeclencheur::setDescription(QString description)
{
    m_description = description ;
}

QString CDeclencheur::description()
{
    return m_description ;
}
