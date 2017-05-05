#include "qscenariodir.h"

QScenarioDir::QScenarioDir()
{

}

QList<QScenarioFile*> QScenarioDir::getDir() const
{
    return fileInDir;
}

void QScenarioDir::addFile(QScenarioFile *file)
{
    fileInDir.append(file);
}

void QScenarioDir::setDir(QList<QScenarioFile*> containDir)
{
    containDir = fileInDir;
}

void QScenarioDir::list(QPlainTextEdit &text_edit, int index)
{
    QScenarioFile::list(text_edit, index);
    for(int i=0;i<fileInDir.size();i++) {
        fileInDir[i]->list(text_edit, index+1);
    }
}
