#ifndef CACTION_H
#define CACTION_H

#include <QString>
#include <QList>

class CAction
{
	private:
		QString type ;
		QString name ;
		QString object ;

	public:
		CAction(QList<QString> args);
		void setType(const QString& _type) ;
		void setName(const QString& _name) ;
		void setObject(const QString& _object) ;
		void updateValue(const QString& line, int separator) ;
};

#endif // CACTION_H
