#ifndef EVENT_H
#define EVENT_H

#include "action.h"

class Event
{
public:
    Event(const QList<QString> &list, const QList<QList<QString>> &actions);
    void updateValue(const QString& line, int separator) ;
private:
    QList<Action> actions ;
    QString name ;
    QString type ;
    int time ;
    bool active ;
};

#endif // EVENT_H
