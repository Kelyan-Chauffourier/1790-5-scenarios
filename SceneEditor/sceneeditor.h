#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include "ui_sceneeditor.h"
#include "cevent.h"
#include "cxmlreader.h"
#include "cobject.h"

class SceneEditor : public QMainWindow, private Ui::SceneEditor
{
    Q_OBJECT

public:
    explicit SceneEditor(QWidget *parent = 0);
    //void parse(const QString& filePath) ;
    //void saveFile() ;
private:
    CXmlReader xmlreader ;
    QList<CObject> objects ;
    QList<CEvent> events ;
    QString fileName ;
private slots:
    void on_actionOuvrir_triggered();
    void on_pbuAddEvent_clicked();
    void on_pbuAddObject_clicked();
	void on_pbuTest_clicked();
    //void saveFile();
public slots:
	void editSomething();
};

#endif // SCENEEDITOR_H
