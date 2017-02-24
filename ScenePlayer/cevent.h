#ifndef CEVENT_H
#define CEVENT_H

#include <QString>
#include <QList>
#include "caction.h"

class CEvent
{
	private:
		QList<CAction> actions ;
		QString name ;
		QString type ;
		int time ;
		bool active ;

	public:
		CEvent(const QList<QString> &list, const QList<QList<QString>> &actions);
		void updateValue(const QString& line, int separator) ;
};

#endif // CEVENT_H
