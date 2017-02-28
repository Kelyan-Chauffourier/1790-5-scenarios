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
		return ;

	QTextStream stream(&scnfile) ;
	while (!stream.atEnd()) {
		currentLine = stream.readLine();
		if (currentLine.endsWith(":")) {
			std::cerr << ": detected" << std::endl ;
			buf.clear();
			for (int j = 0 ; j < currentLine.size() - 2 ; j++) {
				buf += currentLine[j] ;
			}
			std::cerr << "buf : " << buf.toStdString() << std::endl ;
			if (buf == "object") {
				QList<QString> list ;
				currentLine = stream.readLine() ;
				std::cerr << currentLine.toStdString() << std::endl ;
				while (currentLine.endsWith(";")) {
					list.push_back(currentLine.simplified());
					currentLine = stream.readLine() ;
				}
				objects.push_back(CObject(list));
			}
			else if (buf == "event") {
				QList<QString> list ;	// Toutes les lignes de l'évenement
				QList<QList<QString>> actions ;	//Lignes des actions
				currentLine = stream.readLine() ;	// Lit la ligne
				while (currentLine.simplified().size() != 0) { // Tant que pas fin de ligne
					if (currentLine.endsWith(";")) {	// SI fin ligne = ';'
						list.push_back(currentLine.simplified());	//Ajout dans la liste
						currentLine = stream.readLine() ;	//Lecture ligne suivant
					}
					else if (currentLine.endsWith(":"))  {	// Si fin ligne = : (fin evenement)
						buf.clear();
						for (int j = 0 ; j < currentLine.size() - 2 ; j++) {	// Enleve :
							buf += currentLine[j] ;
						}
						if (buf.simplified() == "action") {
							actions.push_back(QList<QString>());	// Ajoute une liste dans la liste
							currentLine = stream.readLine() ;
							while (currentLine.endsWith(";")) {
								actions.last().push_back(currentLine.simplified()); // Ajout dans la liste créée
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

int CParser::getSize()
{
	return events.size() ;
}

QString CParser::getEventName(int index)
{
	return events[index].getName() ;
}

QString CParser::getEventType(int index)
{
	return events[index].getType() ;
}
