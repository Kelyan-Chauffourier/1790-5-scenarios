#ifndef QSCENARIODIR_H
#define QSCENARIODIR_H

#include <QList>
#include "qscenariofile.h"

class QScenarioDir : public QScenarioFile
{
public:
    QScenarioDir();
    QList<QScenarioFile*> fileInDir;

    QList<QScenarioFile *> getDir() const;
    void addFile(QScenarioFile * file);
    void setDir(QList<QScenarioFile*> containDir);
    virtual QString type() {return "dir";}
    virtual void list(QPlainTextEdit& text_edit, int index);
};

#endif // QSCENARIODIR_H
