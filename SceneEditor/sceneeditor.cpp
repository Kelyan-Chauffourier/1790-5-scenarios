#include "sceneeditor.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <eventedit.h>
#include <cevent.h>

SceneEditor::SceneEditor(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    //connect(actionOuvrir,SIGNAL(triggered(bool)),this,SLOT(on_actionOuvrir_triggered()));
}

void SceneEditor::on_actionOuvrir_triggered()
{
    QFileDialog dialog ;
	QString openFile = dialog.getOpenFileName(
		this,
		QString("open SCN file"),
		QDir::homePath(),
		QString("*.scn"),
		nullptr,
		QFileDialog::DontResolveSymlinks);
    xmlreader.readData(openFile);
}

void SceneEditor::on_pbuAddEvent_clicked()
{
    eventEdit* edit = new eventEdit(this);
    edit->show();
}
/*
void SceneEditor::parse(const QString & filePath)
{
    objects.clear();
    events.clear();
    QString currentLine ;
    QString buf ;
    QFile scnfile(filePath) ;
    if (!scnfile.open(QIODevice::ReadOnly | QIODevice::Text))
              return;
    fileName = filePath ;
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
*/
/*
void SceneEditor::saveFile()
{
    QFile scnfile(fileName) ;
    if (!scnfile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
              return;
    QTextStream stream(&scnfile) ;
    for(int i=0;i<objects.size();i++) {
        stream << "object :" << '\n' ;
        stream << "\tname = " << objects[i].getName() << " ;" << '\n' ;
        stream << "\tpath = " << objects[i].getPath() << " ;" << '\n' ;
        stream << '\n' ;
    }
    for(int i=0;i<events.size();i++) {
        stream << "event :" << '\n' ;
        stream << "\tname = " << events[i].getName() << " ;" << '\n';
        stream << "\ttype = " << events[i].getType() << " ;" << '\n';
        stream << "\tactive = " << events[i].isActive() << " ;" << '\n';
        if(events[i].getType() == "time")
            stream << "\ttime = " << events[i].getTime() << " ;" << '\n';
        for(int j=0;j<events[i].getActions().size();j++) {
            stream << "\taction :" << '\n' ;
            stream << "\t\ttype = " << events[i].getActions()[j].getType() << " ;" << '\n' ;
            if(events[i].getActions()[j].getType() == "addevent")
                stream << "\t\tname = " << events[i].getActions()[j].getName() << " ;" << '\n';
            if(events[i].getActions()[j].getType() == "spawn" || events[i].getActions()[j].getType() == "move") {
                stream << "\t\tobject = " << events[i].getActions()[j].getObject() << " ;" << '\n';
                stream << "\t\tlat = " << events[i].getActions()[j].getLat() << " ;" << '\n';
                stream << "\t\tlon = " << events[i].getActions()[j].getLon() << " ;" << '\n';
                stream << "\t\torientation = " << events[i].getActions()[j].getOrientation() << " ;" << '\n' ;
            }
        }
        stream << '\n' ;

    }
    stream << "end :" ;
}
*/
/*void SceneEditor::saveFile()
{
    //saveFile();
}*/
