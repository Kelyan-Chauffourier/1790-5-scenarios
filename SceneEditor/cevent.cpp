#include "cevent.h"
#include "caction.h"
#include "cdeclencheur.h"
#include "cmanualdeclencheur.h"
#include "ctimedeclencheur.h"
#include "cpositiondeclencheur.h"
#include <iostream>

CEvent::CEvent():
    m_name("Nom événement"),
    m_description("Description événement"),
    m_declencheur(NULL)
{

}

CEvent::CEvent(const CEvent &copy):
    m_name(copy.m_name),
    m_description(copy.m_description),
    m_listAction(copy.m_listAction)
{
    if(copy.m_declencheur->type()=="manual") {
        // creer copie declencheur
        CManualDeclencheur* tmp = new CManualDeclencheur(*(CManualDeclencheur*)(copy.m_declencheur));
        setDeclencheur(tmp);
    }
    else if(copy.m_declencheur->type()=="time") {
        // creer copie declencheur
        CTimeDeclencheur* tmp = new CTimeDeclencheur(*(CTimeDeclencheur*)(copy.m_declencheur));
        setDeclencheur(tmp);
    }
    else if(copy.m_declencheur->type()=="position") {
        // creer copie declencheur
        CPositionDeclencheur* tmp = new CPositionDeclencheur(*(CPositionDeclencheur*)(copy.m_declencheur));
        setDeclencheur(tmp);
    }
}

CEvent::~CEvent()
{
    // freeing memory
    delete m_declencheur;
    for(int i=0;i<m_listAction.size();i++)
        delete m_listAction[i];
    // memory freed
}

void CEvent::setName(QString name)
{
    m_name = name ;
}

void CEvent::setDescription(QString description)
{
    m_description = description ;
}

void CEvent::addAction(CAction* action)
{
    m_listAction.push_back(action);
}

void CEvent::setDeclencheur(CDeclencheur* declencheur)
{
    // liberation de la mémoire pour éviter les fuites de mémoire
    delete m_declencheur;
    //
    m_declencheur = declencheur ;
}

QString CEvent::name()
{
    return m_name ;
}

QString CEvent::description()
{
    return m_description ;
}

QList<CAction*> CEvent::actions()
{
    return m_listAction ;
}

CDeclencheur* CEvent::declencheur()
{
    return m_declencheur ;
}

QString CEvent::actionsEvent()
{
    QString s = description() ;
    for (int i = 0 ; i < m_listAction.size() ; i++) {
        s += m_listAction[i]->parametre() ;
    }
    return s ;
}
