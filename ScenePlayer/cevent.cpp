#include "cevent.h"
#include "caction.h"
#include <iostream>

CEvent::CEvent(const QList<QString> &args, const QList<QList<QString>> &actions) :
	name("unnamed"),
	type("manual"),
	time(0),
	active(0)
{
	std::cerr << "CREATING EVENT" << std::endl ;
	if(args.size() > 0) {
		for(int i = 0 ; i<args.size();i++) {
			for(int j = 0 ; j < args[i].size() ; j++) {
				if(args[i][j] == '=') {
					updateValue(args[i], j) ;
				}
			}
		}
	}
	if(actions.size() > 0) {
		for(int i=0;i<actions.size();i++) {
			this->actions.push_back(CAction(actions[i]));
		}
	}
	std::cerr << "EVENT CREATED" << std::endl ;
}

void CEvent::updateValue(const QString &line, int separator)
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
		this->name = value ;

		//debug
		std::cerr << "key name set to value " << value.toStdString() << std::endl ;
	}
	else if(key=="type") {
		this->type = value ;

		//debug
		std::cerr << "key type set to value " << value.toStdString() << std::endl ;
	}
	else if(key=="time") {
		this->time = value.toInt() ;

		//debug
		std::cerr << "key time set to value " << value.toInt() << std::endl ;
	}
	else if(key=="active") {
		this->active = value.toInt() ;

		//debug
		std::cerr << "key active set to value " << (bool)value.toInt() << std::endl ;
	}
}
