#ifndef CTIMEDECLENCHEUR_H
#define CTIMEDECLENCHEUR_H

#include "cdeclencheur.h"

class CTimeDeclencheur : public CDeclencheur
{
    private:
        QString m_time ;

    public:
        CTimeDeclencheur();
        void setTime(QString time) ;
        QString texte() ;
        virtual QString type() {return "time";}
};

#endif // CTIMEDECLENCHEUR_H
