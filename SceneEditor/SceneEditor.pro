#-------------------------------------------------
#
# Project created by QtCreator 2017-02-28T08:53:51
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SceneEditor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        sceneeditor.cpp \
    caction.cpp \
    cobject.cpp \
    cevent.cpp \
    cposition.cpp \
    cdeclencheur.cpp \
    cmanualdeclencheur.cpp \
    cpositiondeclencheur.cpp \
    ctimedeclencheur.cpp \
    cxmlreader.cpp \
    eventedit.cpp

HEADERS  += sceneeditor.h \
    caction.h \
    cevent.h \
    cobject.h \
    cposition.h \
    cdeclencheur.h \
    cmanualdeclencheur.h \
    cpositiondeclencheur.h \
    ctimedeclencheur.h \
    cxmlreader.h \
    eventedit.h

FORMS    += sceneeditor.ui \
    eventedit_copy.ui \
    eventedit.ui
