#ifndef QSCENARIOFILE_H
#define QSCENARIOFILE_H

#include <QString>
#include <QPlainTextEdit>

class QScenarioFile
{

public:
    QScenarioFile();
    QString name;
    QString fullpath;

    void setFilename(QString name);
    void setFullpath(QString fullpath);
    QString getFilename() const ;
    QString getFilefullpath() const;
    virtual QString type() {return "file";}
    virtual void list(QPlainTextEdit& text_edit, int index);
};

#endif // QSCENARIOFILE_H
