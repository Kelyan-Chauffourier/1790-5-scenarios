#ifndef CXMLREADER_H
#define CXMLREADER_H

#include <QObject>
#include <QString>
#include <QList>
#include "cevent.h"
#include "object3d.h"

class CEvent ;

typedef struct {
	QString OBJname ;
	QString OBJpath ;
} OBJ7 ;

class CXmlReader : public QObject
{
    Q_OBJECT

    private:
        QList<CEvent> m_listEvent ;
		QList<OBJ7> m_listObject ;

    public:
        CXmlReader(QObject* parent = 0);
		QString OBJ7nameToObject3Dpath(QString name) ;
        Q_INVOKABLE void readData(const QString& xml) ;
        Q_INVOKABLE int numberEvents() ;
        Q_INVOKABLE QString eventName(int i) ;
        Q_INVOKABLE QString eventActions(int i) ;
        Q_INVOKABLE QString eventDeclencheur(int i) ;
		QList<OBJ7> listObject() {return m_listObject;}
		QList<CEvent> listEvent() {return m_listEvent;}
};

#endif // CXMLREADER_H
