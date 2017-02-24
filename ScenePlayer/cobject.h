#ifndef COBJECT_H
#define COBJECT_H

#include <QList>
#include <QString>
#include <string>

class CObject
{
	private:
		QString name ;
		QString path ;

	public:
		CObject(QList<QString> args);
		QString getName();
		void setName(QString & name);
		QString getPath();
		void setPath(QString& path);
		void updateValue(const QString& line, int separator) ;
};

#endif // COBJECT_H
