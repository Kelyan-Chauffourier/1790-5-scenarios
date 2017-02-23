#include "action.h"

Action::Action(QList<QString> args)
{
    std::cerr << "CREATING ACTION" << std::endl ;
    if(args.size() > 0) {
        for(int i = 0 ; i<args.size();i++) {
            for(int j = 0 ; j < args[i].size() ; j++) {
                if(args[i][j] == '=') {
                    updateValue(args[i], j) ;
                }
            }
        }
    }
    std::cerr << "ACTION CREATED" << std::endl ;
}

void Action::setType(const QString &_type)
{
    type = _type ;
}

void Action::setName(const QString &_name)
{
    name = _name ;
}

void Action::setObject(const QString &_object)
{
    object = _object ;
}

void Action::updateValue(const QString &line, int separator)
{
    QString key ;
    QString value ;
    for(int i=0;i<separator-1;i++) {
        key += line[i] ;
    }
    for(int i=separator+2;i<line.size()-2;i++) {
        value += line[i] ;
    }
    if(key == "type") {
        setType(value);

        //debug
        std::cerr << "key type set to value " << value.toStdString() << std::endl ;
    }
    else if(key=="name") {
        setName(value);

        //debug
        std::cerr << "key name set to value " << value.toStdString() << std::endl ;
    }
    else if(key=="object") {
        setObject(value);

        //debug
        std::cerr << "key object set to value" << value.toStdString() << std::endl ;
    }
}
