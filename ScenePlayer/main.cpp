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
#include "cparser.h"
#include <QtQml>

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	CParser cparser ;

	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty("parser", &cparser) ;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}
