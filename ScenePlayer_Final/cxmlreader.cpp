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
	m_listObject.clear();

//	while ( !node.isNull() ) {
//		QDomElement event = node.toElement() ;

//		if ( event.tagName() == "event" ) {
//			std::cerr << "event detecter" << std::endl ;
//			m_listEvent.push_back(CEvent());
//			QDomNodeList eventNodes = event.childNodes() ;

//			for ( int i = 0 ; i < eventNodes.size() ; ++i ) {
//				QDomNode n = eventNodes.item(i) ;

//				if ( n.toElement().tagName() == "name") {
//					// TODO stocker nom
//					std::cerr << "\tname detecter" << std::endl ;
//					m_listEvent.last().setName(n.firstChild().toText().data());
//				}
//				else if (n.toElement().tagName() == "description") {
//					std::cerr << "\tdescription detecter" << std::endl ;
//					m_listEvent.last().setDescription(n.firstChild().toText().data());
//				}

//				else if ( n.toElement().tagName() == "actions" ) {
//					std::cerr << "\tactions detecter" << std::endl ;
//					QDomNodeList actionsNodes = n.childNodes() ;

//					for (int i = 0 ; i < actionsNodes.size() ; ++i) {
//						QDomNode n = actionsNodes.item(i) ;
//						QDomElement item = n.toElement() ;

//						if (item.tagName() == "action") {
//							std::cerr << "\t\taction " << i << " detecter" << std::endl ;
//							//TODO différent élément action
//							m_listEvent.last().addAction(new CAction());
//							QDomNodeList actionNodes = n.childNodes() ;

//							for (int i = 0 ; i < actionNodes.size() ; ++i) {
//								QDomNode n = actionNodes.item(i) ;
//								QDomElement item = n.toElement() ;
//								QString data = n.firstChild().toText().data() ;

//								if (item.tagName() == "type") {
//									m_listEvent.last().actions().last()->setType(data);
//								}
//								else if (item.tagName() == "latitude") {
//									m_listEvent.last().actions().last()->setLatitude(data);
//								}
//								else if (item.tagName() == "longitude") {
//									m_listEvent.last().actions().last()->setLongitude(data);
//								}
//								else if (item.tagName() == "orientation") {
//									m_listEvent.last().actions().last()->setOrientation(data);
//								}
//							}
//						}
//					}
//				}
//				else if ( n.toElement().tagName() == "declencheur" ) {
//					// TODO extraire les infos
//					std::cerr << "\tdeclencheur detecter" << std::endl ;
//					QDomNodeList declencheurNodes = n.childNodes() ;
//					QString type ;

//					for (int i = 0 ; i < declencheurNodes.size() ; ++i) {
//						QDomNode n = declencheurNodes.item(i) ;
//						QDomElement item = n.toElement() ;

//						if (item.tagName() == "type") {
//							type = n.firstChild().toText().data() ;
//							if (type == "manuel") {
//								m_listEvent.last().setDeclencheur(new CManualDeclencheur());
//							}
//							else if (type == "time") {
//								m_listEvent.last().setDeclencheur(new CTimeDeclencheur());
//							}
//							else if (type == "position") {
//								m_listEvent.last().setDeclencheur(new CPositionDeclencheur());
//							}
//						}
//						else if (item.tagName() == "latitude") {
//							CPositionDeclencheur* tmp = (CPositionDeclencheur*)(m_listEvent.last().declencheur());
//							tmp->setLatitude(n.firstChild().toText().data());
//						}
//						else if (item.tagName() == "longitude") {
//							CPositionDeclencheur* tmp = (CPositionDeclencheur*)(m_listEvent.last().declencheur()) ;
//							tmp->setLongitude(n.firstChild().toText().data());
//						}
//						else if (item.tagName() == "rayon") {
//							CPositionDeclencheur* tmp = (CPositionDeclencheur*)(m_listEvent.last().declencheur());
//							tmp->setRayon(n.firstChild().toText().data());
//						}
//						else if (item.tagName() == "time") {
//							CTimeDeclencheur* tmp = (CTimeDeclencheur*)(m_listEvent.last().declencheur());
//							tmp->setTime(n.firstChild().toText().data());
//						}
//						else if (item.tagName() == "description") {
//							m_listEvent.last().declencheur()->setDescription(n.firstChild().toText().data());
//						}
//					}
//				}
//			}
//		}
//		node = node.nextSibling() ;
//		std::cerr << "noeud suivant" << std::endl ;
//	}

	while ( !node.isNull() ) {
		QDomElement event = node.toElement() ;
		if (event.tagName() == "object") {
			std::cerr << "object detecter" << std::endl ;
			OBJ7 object ;
			object.OBJname = event.attribute("name") ;
			object.OBJpath = event.attribute("path") ;
			m_listObject.push_back(object);
		}
		else if ( event.tagName() == "event" ) {
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
							QString type_action = item.attribute("type");
							QDomNodeList actionNodes = n.childNodes() ;

							for (int i = 0 ; i < actionNodes.size() ; ++i) {
								QDomNode n = actionNodes.item(i) ;
								QDomElement item = n.toElement() ;

								if (item.tagName() == "object") {
									int obj_id = item.attribute("id").toInt() ;
									QString obj_path = OBJ7nameToObject3Dpath(item.attribute("name")) ;
									Object3D obj(obj_id, obj_path, item.attribute("name")) ;

									QDomNodeList actionNodes = n.childNodes() ;

									for (int i = 0 ; i < actionNodes.size() ; ++i) {
										QDomNode n = actionNodes.item(i) ;
										QDomElement item = n.toElement() ;

										if (item.tagName() == "position") {
											obj.setPosition(item.attribute("latitude").toDouble(),
												item.attribute("longitude").toDouble(),
												item.attribute("elevation").toDouble()) ;
										}
										else if (item.tagName() == "vrotations") {
											obj.setAttitude(item.attribute("psi").toFloat(),
												item.attribute("the").toFloat(),
												item.attribute("phi").toFloat());
										}
										else if (item.tagName() == "divers") {
											obj.setOnGround(item.attribute("ground").toInt());
											obj.setSmokeSize(item.attribute("smoke").toFloat());
										}
									}
									m_listEvent.last().addAction(new CAction(type_action, obj));
								}
							}
						}
					}
				}
				else if ( n.toElement().tagName() == "declencheur" ) {
					// TODO extraire les infos
					std::cerr << "\tdeclencheur detecter" << std::endl ;
					if (n.toElement().attribute("type") == "manuel") {
						m_listEvent.last().setDeclencheur(new CManualDeclencheur());
					}
					else if (n.toElement().attribute("type") == "time") {
						m_listEvent.last().setDeclencheur(new CTimeDeclencheur());
					}
					else if (n.toElement().attribute("type") == "position") {
						m_listEvent.last().setDeclencheur(new CPositionDeclencheur());
					}
					QDomNodeList declencheurNodes = n.childNodes() ;

					for (int i = 0 ; i < declencheurNodes.size() ; ++i) {
						QDomNode n = declencheurNodes.item(i) ;
						QDomElement item = n.toElement() ;

						if (item.tagName() == "latitude") {
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

QString CXmlReader::OBJ7nameToObject3Dpath(QString name)
{
	for (int i = 0 ; m_listObject.size() ; ++i) {
		if (name == m_listObject.at(i).OBJname) {
			return m_listObject.at(i).OBJpath ;
		}
	}
	return name ;
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

void CXmlReader::runEvent(int i)
{
	QString udpHost ;
	udpHost = "192.168.0.1" ;
	m_udpWorker = new XPlaneUdpWorker(udpHost, 49000, 49001, 250 ) ;
	int nbActions = m_listEvent[i].actions().size() ;
	for (int j = 0 ; j < nbActions ; j++) {
		m_udpWorker->send(m_listEvent[i].actions().at(j)->object().xplaneObjectLoadRequest()) ;
		QThread::msleep(10) ;
		m_udpWorker->send(m_listEvent[i].actions().at(j)->object().xplaneObjectPlaceRequest() ) ;
		QThread::msleep(10) ;
	}
}
