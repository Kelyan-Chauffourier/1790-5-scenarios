#include "cmanualdeclencheur.h"

CManualDeclencheur::CManualDeclencheur():
    CDeclencheur()
{

}

QString CManualDeclencheur::texte()
{
    QString s = description() ;
    s += "\n\nType : déclenchement manuel" ;
    return s ;
}
