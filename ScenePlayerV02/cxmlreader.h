#ifndef CXMLREADER_H
#define CXMLREADER_H

#include <QObject>
#include <QString>
#include <QList>
#include "cevent.h"

class CEvent ;

class CXmlReader : public QObject
{
	Q_OBJECT

	private:
		QList<CEvent> m_listEvent ;

	public:
		CXmlReader(QObject* parent = 0);
		Q_INVOKABLE void readData(const QUrl& xml) ;
		Q_INVOKABLE int numberEvents() ;
		Q_INVOKABLE QString eventName(int i) ;
		Q_INVOKABLE QString eventActions(int i) ;
		Q_INVOKABLE QString eventDeclencheur(int i) ;
};

#endif // CXMLREADER_H
