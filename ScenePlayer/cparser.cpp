#include "cparser.h"
#include <iostream>
#include "cobject.h"
#include "cevent.h"
#include <QtCore/QUrl>
#include <QFile>

CParser::CParser(QObject* parent) :
	QObject(parent)
{
}

void CParser::parse(const QUrl &filePath)
{
	objects.clear();
	events.clear();
	QString currentLine ;
	QString buf ;
	QFile scnfile(filePath.toString(QUrl::PreferLocalFile)) ;
	if (!scnfile.open(QIODevice::ReadOnly | QIODevice::Text))
			  return;

	QTextStream stream(&scnfile) ;
	while(!stream.atEnd()) {
		currentLine = stream.readLine();
		if(currentLine.endsWith(":")) {
			std::cerr << ": detected" << std::endl ;
			buf.clear();
			for(int j=0;j<currentLine.size()-2;j++) {
				buf += currentLine[j] ;
			}
			std::cerr << "buf : " << buf.toStdString() << std::endl ;
			if(buf == "object") {
				QList<QString> list ;
				currentLine = stream.readLine() ;
				std::cerr << currentLine.toStdString() << std::endl ;
				while(currentLine.endsWith(";")) {
					list.push_back(currentLine.simplified());
					currentLine = stream.readLine() ;
				}
				objects.push_back(CObject(list));
			}
			else if(buf == "event") {
				QList<QString> list ;
				QList<QList<QString>> actions ;
				currentLine = stream.readLine() ;
				while (currentLine.simplified().size()!=0) {
					if(currentLine.endsWith(";")) {
						list.push_back(currentLine.simplified());
						currentLine = stream.readLine() ;
					}
					else if(currentLine.endsWith(":"))  {
						buf.clear();
						for(int j=0;j<currentLine.size()-2;j++) {
							buf += currentLine[j] ;
						}
						if(buf.simplified() == "action") {
							actions.push_back(QList<QString>());
							currentLine = stream.readLine() ;
							while(currentLine.endsWith(";")) {
								actions.last().push_back(currentLine.simplified());
								currentLine = stream.readLine() ;
							}
						}
						else {
							currentLine = stream.readLine() ;
						}
					}
					else {
						currentLine = stream.readLine() ;
					}
				}
				std::cerr << "event end detected" << std::endl;
				events.push_back(CEvent(list, actions));
			}
		}
	}
}

//void CParser::selectedFileChanged()
//{
//	QString filePath ;
//	// TODO récuperer le fichier filePath =
//	parse(filePath) ;
//}
