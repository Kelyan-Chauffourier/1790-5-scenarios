/* -----------------------------------------------------------------------------
 *	Nom			:	main.cpp
 *	Type		:	APPLICATION
 *	Sujet		:	ScenePlayer
 *
 *	Auteur		:	DELION Quentin
 *	Version		:	0.1
 *	Création	:	02/02/2017
 *	Der. Modif.	:	02/02/2017
 *	------------------------------------------------------------------------- */

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	engine.load(QUrl(QLatin1String("qrc:/main.qml")));

	return app.exec();
}
