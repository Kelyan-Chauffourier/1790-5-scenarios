#ifndef CACTION_H
#define CACTION_H

#include <QString>
#include "cposition.h"

class CAction
{
    private:
        QString m_type ;
        CPosition m_position ;
        QString m_orientation ;

    public:
        CAction();
        virtual ~CAction() {}
        void setType(QString type) ;
        virtual void setLatitude(QString latitude) ;
        virtual void setLongitude(QString longitude) ;
        void setOrientation(QString orientation) ;
        QString parametre() ;
};

#endif // CACTION_H
