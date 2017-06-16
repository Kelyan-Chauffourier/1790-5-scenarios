#ifndef CPOSITION_H
#define CPOSITION_H

#include <QString>

class CPosition
{
    private:
        QString m_latitude ;
        QString m_longitude ;

    public:
        CPosition();
        QString latitude() ;
        QString longitude() ;
        QString position() ;
        virtual void setLatitude(QString latitude) ;
        virtual void setLongitude(QString longitude) ;
};

#endif // CPOSITION_H
