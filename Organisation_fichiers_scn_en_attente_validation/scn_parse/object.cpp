#include "object.h"

Object::Object(QList<QString> args) : name(""), path("")
{
    std::cerr << "CREATING OBJECT" << std::endl ;
    if(args.size() > 0) {
        for(int i = 0 ; i<args.size();i++) {
            for(int j = 0 ; j < args[i].size() ; j++) {
                if(args[i][j] == '=') {
                    updateValue(args[i], j) ;
                }
            }
        }
    }
    std::cerr << "OBJECT CREATED" << std::endl ;
}

void Object::setName(QString &name)
{
    this->name = name ;
}

void Object::setPath(QString &path)
{
    this->path = path ;
}

void Object::updateValue(const QString &line, int separator)
{
    QString key ;
    QString value ;
    for(int i=0;i<separator-1;i++) {
        key += line[i] ;
    }
    for(int i=separator+2;i<line.size()-2;i++) {
        value += line[i] ;
    }
    if(key=="name") {
        setName(value);

        //debug
        std::cerr << "key name set to value " << value.toStdString() << std::endl ;
    }
    else if(key=="path") {
        setPath(value);

        //debug
        std::cerr << "key path set to value" << value.toStdString() << std::endl ;
    }

}
