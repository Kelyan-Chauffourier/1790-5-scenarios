#include "qscenariofile.h"

QScenarioFile::QScenarioFile()
{

}

void QScenarioFile::setFilename(QString name)
{
    this->name = name ;
}

void QScenarioFile::setFullpath(QString fullpath)
{
    this->fullpath = fullpath ;
}

QString QScenarioFile::getFilename() const
{
    return name;
}

QString QScenarioFile::getFilefullpath() const
{
    return fullpath;
}

void QScenarioFile::list(QPlainTextEdit &text_edit, int index)
{
    QString text ;
    for(int i=0;i<index;i++) {
        text += "       ";
    }
    text += name ;
    text_edit.appendPlainText(text);
}

