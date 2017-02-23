#ifndef ACTION_H
#define ACTION_H

#include "object.h"

class Action
{
public:
    Action(QList<QString> args);
    void setType(const QString& _type) ;
    void setName(const QString& _name) ;
    void setObject(const QString& _object) ;
    void updateValue(const QString& line, int separator) ;
private:
    QString type ;
    QString name ;
    QString object ;
};

#endif // ACTION_H
