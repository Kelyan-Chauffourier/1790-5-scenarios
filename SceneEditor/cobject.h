#ifndef OBJECT_H
#define OBJECT_H

#include <QList>
#include <iostream>
#include <string>

class CObject
{
public:
	CObject() {}
    CObject(QList<QString> args);
    QString getName();
    void setName(QString & name);
    QString getPath();
    void setPath(QString& path);
    void updateValue(const QString& line, int separator) ;
private:
    QString name ;
    QString path ;
private slots:
	void on_pbu_Valider_clicked();
};

#endif // OBJECT_H
