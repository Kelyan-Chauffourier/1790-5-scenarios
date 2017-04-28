#ifndef CEVENT_H
#define CEVENT_H

#include <QString>
#include <QList>
#include "caction.h"
#include "cdeclencheur.h"

class CAction ;
class CDeclencheur ;

class CEvent
{
    private:
        QString m_name ;
        QString m_description ;
        QList<CAction*> m_listAction ;
        CDeclencheur* m_declencheur ;

    public:
        CEvent() ;
        // m_declencheur étant alloué dynamiquement, un constructeur de copie et un destructeur sont necessaires
        CEvent(const CEvent& copy);
        ~CEvent();
        QString name() ;
        QString description() ;
        QList<CAction*> actions() ;
        CDeclencheur* declencheur() ;
        void setName(QString name) ;
        void setDescription(QString description) ;
        void addAction(CAction* action) ;
        void setDeclencheur(CDeclencheur* declencheur) ;
        QString actionsEvent() ;
};

#endif // CEVENT_H
