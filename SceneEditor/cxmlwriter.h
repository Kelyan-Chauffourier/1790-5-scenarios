#ifndef CXMLWRITER_H
#define CXMLWRITER_H

#include <QString>
#include <QList>
#include "cobject.h"
#include "cevent.h"

class CXmlWriter
{
public:
	CXmlWriter();
	void saveFile(QFile &file, QList<CObject> objects, QList<CEvent> events);
};

#endif // CXMLWRITER_H
