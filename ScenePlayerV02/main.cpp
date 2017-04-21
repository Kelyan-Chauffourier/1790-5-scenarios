/* -----------------------------------------------------------------------------
 *	Nom			:	main.cpp
 *	Type		:	APPLICATION
 *	Sujet		:	ScenePlayer
 *
 *	Auteur		:	DELION Quentin
 *	Version		:	0.1
 *	Création	:	02/02/2017
 *	Der. Modif.	:	01/03/2017
 *	------------------------------------------------------------------------- */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "cxmlreader.h"
#include <QtQml>

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	CXmlReader cxmlreader ;

	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty("xmlreader", &cxmlreader);
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}
