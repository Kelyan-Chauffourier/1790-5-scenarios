#include "cxmlreader.h"
#include <QtXml>
#include <iostream>
#include <QDomDocument>
#include <QTextStream>
#include <QFile>
#include "cmanualdeclencheur.h"
#include "cpositiondeclencheur.h"
#include "ctimedeclencheur.h"
#include "cevent.h"

CXmlReader::CXmlReader(QObject* parent):
	QObject(parent)
{
}

void CXmlReader::readData(const QUrl& xml)
{
	QFile xmlFile(xml.toString(QUrl::PreferLocalFile)) ;
	if (!xmlFile.open(QIODevice::ReadOnly | QIODevice::Text))
		return ;
	QTextStream stream(&xmlFile) ;
	QDomDocument dom ;
	dom.setContent(stream.readAll()) ;
	QDomElement root = dom.documentElement() ;
	QDomNode node = root.firstChild() ;

	m_listEvent.clear();

	while ( !node.isNull() ) {
		QDomElement event = node.toElement() ;

		if ( event.tagName() == "event" ) {
			std::cerr << "event detecter" << std::endl ;
			m_listEvent.push_back(CEvent());
			QDomNodeList eventNodes = event.childNodes() ;

			for ( int i = 0 ; i < eventNodes.size() ; ++i ) {
				QDomNode n = eventNodes.item(i) ;

				if ( n.toElement().tagName() == "name") {
					// TODO stocker nom
					std::cerr << "\tname detecter" << std::endl ;
					m_listEvent.last().setName(n.firstChild().toText().data());
				}
				else if (n.toElement().tagName() == "description") {
					std::cerr << "\tdescription detecter" << std::endl ;
					m_listEvent.last().setDescription(n.firstChild().toText().data());
				}

				else if ( n.toElement().tagName() == "actions" ) {
					std::cerr << "\tactions detecter" << std::endl ;
					QDomNodeList actionsNodes = n.childNodes() ;

					for (int i = 0 ; i < actionsNodes.size() ; ++i) {
						QDomNode n = actionsNodes.item(i) ;
						QDomElement item = n.toElement() ;

						if (item.tagName() == "action") {
							std::cerr << "\t\taction " << i << " detecter" << std::endl ;
							//TODO différent élément action
							m_listEvent.last().addAction(new CAction());
							QDomNodeList actionNodes = n.childNodes() ;

							for (int i = 0 ; i < actionNodes.size() ; ++i) {
								QDomNode n = actionNodes.item(i) ;
								QDomElement item = n.toElement() ;
								QString data = n.firstChild().toText().data() ;

								if (item.tagName() == "type") {
									m_listEvent.last().actions().last()->setType(data);
								}
								else if (item.tagName() == "latitude") {
									m_listEvent.last().actions().last()->setLatitude(data);
								}
								else if (item.tagName() == "longitude") {
									m_listEvent.last().actions().last()->setLongitude(data);
								}
								else if (item.tagName() == "orientation") {
									m_listEvent.last().actions().last()->setOrientation(data);
								}
							}
						}
					}
				}
				else if ( n.toElement().tagName() == "declencheur" ) {
					// TODO extraire les infos
					std::cerr << "\tdeclencheur detecter" << std::endl ;
					QDomNodeList declencheurNodes = n.childNodes() ;
					QString type ;

					for (int i = 0 ; i < declencheurNodes.size() ; ++i) {
						QDomNode n = declencheurNodes.item(i) ;
						QDomElement item = n.toElement() ;

						if (item.tagName() == "type") {
							type = n.firstChild().toText().data() ;
							if (type == "manual") {
								m_listEvent.last().setDeclencheur(new CManualDeclencheur());
							}
							else if (type == "time") {
								m_listEvent.last().setDeclencheur(new CTimeDeclencheur());
							}
							else if (type == "position") {
								m_listEvent.last().setDeclencheur(new CPositionDeclencheur());
							}
						}
						else if (item.tagName() == "latitude") {
							CPositionDeclencheur* tmp = (CPositionDeclencheur*)(m_listEvent.last().declencheur());
							tmp->setLatitude(n.firstChild().toText().data());
						}
						else if (item.tagName() == "longitude") {
							CPositionDeclencheur* tmp = (CPositionDeclencheur*)(m_listEvent.last().declencheur()) ;
							tmp->setLongitude(n.firstChild().toText().data());
						}
						else if (item.tagName() == "rayon") {
							CPositionDeclencheur* tmp = (CPositionDeclencheur*)(m_listEvent.last().declencheur());
							tmp->setRayon(n.firstChild().toText().data());
						}
						else if (item.tagName() == "time") {
							CTimeDeclencheur* tmp = (CTimeDeclencheur*)(m_listEvent.last().declencheur());
							tmp->setTime(n.firstChild().toText().data());
						}
						else if (item.tagName() == "description") {
							m_listEvent.last().declencheur()->setDescription(n.firstChild().toText().data());
						}
					}
				}
			}
		}
		node = node.nextSibling() ;
		std::cerr << "noeud suivant" << std::endl ;
	}
}

int CXmlReader::numberEvents()
{
	return m_listEvent.size() ;
}

QString CXmlReader::eventName(int i)
{
	std::cerr << m_listEvent[i].name().toStdString() << std::endl ;
	return m_listEvent[i].name() ;
}

QString CXmlReader::eventActions(int i)
{
	std::cerr << m_listEvent[i].actionsEvent().toStdString() << std::endl ;
	return m_listEvent[i].actionsEvent() ;
}

QString CXmlReader::eventDeclencheur(int i)
{
	std::cerr << m_listEvent[i].declencheur()->texte().toStdString() << std::endl ;
	return m_listEvent[i].declencheur()->texte() ;
}
