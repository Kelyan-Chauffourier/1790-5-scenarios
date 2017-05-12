#ifndef EDITOBJECT_H
#define EDITOBJECT_H

#include "ui_editobject.h"
#include "cobject.h"

class editObject : public QDialog, private Ui::editObject
{
    Q_OBJECT

    CObject *currentObject;
    QList<CObject> *listeObjets;
    int index;

public:
    explicit editObject(QWidget *parent = 0);
    editObject(QWidget *parent, QList<CObject> *list, int index = -1);
};

#endif // EDITOBJECT_H
