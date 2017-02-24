#ifndef CPARSER_H
#define CPARSER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include "cevent.h"
#include "cobject.h"

//class CObject ;
//class CEvent ;

class CParser : public QObject
{
		Q_OBJECT

	private:
		QList<CObject> objects ;
		QList<CEvent> events ;

	public:
		CParser(QObject* parent = 0);
		Q_INVOKABLE void parse(const QUrl& filePath) ;
//		void selectedFileChanged();
};

#endif // CPARSER_H
