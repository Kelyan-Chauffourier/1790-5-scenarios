#ifndef CPOSITIONDECLENCHEUR_H
#define CPOSITIONDECLENCHEUR_H

#include "cdeclencheur.h"
#include "cposition.h"

class CPositionDeclencheur : public CDeclencheur
{
    private:
        CPosition m_position ;
        QString m_rayon ;

    public:
        CPositionDeclencheur();
        virtual void setLatitude(QString latitude) ;
        virtual void setLongitude(QString longitude) ;
        void setRayon(QString rayon) ;
        QString texte() ;
        QString parametre() ;
        virtual QString type() {return "position";}
};

#endif // CPOSITIONDECLENCHEUR_H
