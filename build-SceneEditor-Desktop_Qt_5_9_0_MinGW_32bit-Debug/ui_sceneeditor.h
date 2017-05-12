/********************************************************************************
** Form generated from reading UI file 'sceneeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENEEDITOR_H
#define UI_SCENEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SceneEditor
{
public:
    QAction *actionNouveau;
    QAction *actionOuvrir;
    QAction *actionEnregistrer;
    QAction *actionEnregistrer_sous;
    QAction *actionQuitter;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_objects;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbuAddObject;
    QPushButton *pbuEditObject;
    QPushButton *pbuDeleteObject;
    QListWidget *qlwObjects;
    QWidget *tab_events;
    QVBoxLayout *verticalLayout;
    QTreeWidget *qtwEvents;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbuAddEvent;
    QPushButton *pbuEditEvent;
    QPushButton *pbuDeleteEvent;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SceneEditor)
    {
        if (SceneEditor->objectName().isEmpty())
            SceneEditor->setObjectName(QStringLiteral("SceneEditor"));
        SceneEditor->resize(456, 443);
        QFont font;
        font.setFamily(QStringLiteral("Liberation Mono"));
        SceneEditor->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("../../1790-5-scenarios/SceneEditor/logo_SE.png"), QSize(), QIcon::Normal, QIcon::Off);
        SceneEditor->setWindowIcon(icon);
        actionNouveau = new QAction(SceneEditor);
        actionNouveau->setObjectName(QStringLiteral("actionNouveau"));
        actionOuvrir = new QAction(SceneEditor);
        actionOuvrir->setObjectName(QStringLiteral("actionOuvrir"));
        actionEnregistrer = new QAction(SceneEditor);
        actionEnregistrer->setObjectName(QStringLiteral("actionEnregistrer"));
        actionEnregistrer_sous = new QAction(SceneEditor);
        actionEnregistrer_sous->setObjectName(QStringLiteral("actionEnregistrer_sous"));
        actionQuitter = new QAction(SceneEditor);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(SceneEditor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(9);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab_objects = new QWidget();
        tab_objects->setObjectName(QStringLiteral("tab_objects"));
        gridLayout = new QGridLayout(tab_objects);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pbuAddObject = new QPushButton(tab_objects);
        pbuAddObject->setObjectName(QStringLiteral("pbuAddObject"));

        horizontalLayout->addWidget(pbuAddObject);

        pbuEditObject = new QPushButton(tab_objects);
        pbuEditObject->setObjectName(QStringLiteral("pbuEditObject"));

        horizontalLayout->addWidget(pbuEditObject);

        pbuDeleteObject = new QPushButton(tab_objects);
        pbuDeleteObject->setObjectName(QStringLiteral("pbuDeleteObject"));

        horizontalLayout->addWidget(pbuDeleteObject);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        qlwObjects = new QListWidget(tab_objects);
        new QListWidgetItem(qlwObjects);
        qlwObjects->setObjectName(QStringLiteral("qlwObjects"));

        gridLayout->addWidget(qlwObjects, 1, 0, 1, 1);

        tabWidget->addTab(tab_objects, QString());
        tab_events = new QWidget();
        tab_events->setObjectName(QStringLiteral("tab_events"));
        verticalLayout = new QVBoxLayout(tab_events);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        qtwEvents = new QTreeWidget(tab_events);
        qtwEvents->setObjectName(QStringLiteral("qtwEvents"));

        verticalLayout->addWidget(qtwEvents);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pbuAddEvent = new QPushButton(tab_events);
        pbuAddEvent->setObjectName(QStringLiteral("pbuAddEvent"));

        horizontalLayout_2->addWidget(pbuAddEvent);

        pbuEditEvent = new QPushButton(tab_events);
        pbuEditEvent->setObjectName(QStringLiteral("pbuEditEvent"));

        horizontalLayout_2->addWidget(pbuEditEvent);

        pbuDeleteEvent = new QPushButton(tab_events);
        pbuDeleteEvent->setObjectName(QStringLiteral("pbuDeleteEvent"));

        horizontalLayout_2->addWidget(pbuDeleteEvent);


        verticalLayout->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab_events, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        SceneEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SceneEditor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 456, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        SceneEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SceneEditor);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SceneEditor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SceneEditor);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SceneEditor->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionNouveau);
        menuFichier->addAction(actionOuvrir);
        menuFichier->addSeparator();
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addAction(actionEnregistrer_sous);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);

        retranslateUi(SceneEditor);
        QObject::connect(qtwEvents, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), SceneEditor, SLOT(editSomething()));
        QObject::connect(pbuEditEvent, SIGNAL(clicked()), SceneEditor, SLOT(editSomething()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SceneEditor);
    } // setupUi

    void retranslateUi(QMainWindow *SceneEditor)
    {
        SceneEditor->setWindowTitle(QApplication::translate("SceneEditor", "SceneEditor", Q_NULLPTR));
        actionNouveau->setText(QApplication::translate("SceneEditor", "Nouveau", Q_NULLPTR));
        actionOuvrir->setText(QApplication::translate("SceneEditor", "Ouvrir", Q_NULLPTR));
        actionEnregistrer->setText(QApplication::translate("SceneEditor", "Enregistrer", Q_NULLPTR));
        actionEnregistrer_sous->setText(QApplication::translate("SceneEditor", "Enregistrer sous ...", Q_NULLPTR));
        actionQuitter->setText(QApplication::translate("SceneEditor", "Quitter", Q_NULLPTR));
        pbuAddObject->setText(QApplication::translate("SceneEditor", "Ajouter", Q_NULLPTR));
        pbuEditObject->setText(QApplication::translate("SceneEditor", "\303\211diter", Q_NULLPTR));
        pbuDeleteObject->setText(QApplication::translate("SceneEditor", "Supprimer", Q_NULLPTR));

        const bool __sortingEnabled = qlwObjects->isSortingEnabled();
        qlwObjects->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = qlwObjects->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("SceneEditor", "Objet test", Q_NULLPTR));
        qlwObjects->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab_objects), QApplication::translate("SceneEditor", "Objets 3D", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = qtwEvents->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("SceneEditor", "\303\211v\303\251nements :", Q_NULLPTR));
        pbuAddEvent->setText(QApplication::translate("SceneEditor", "Ajouter", Q_NULLPTR));
        pbuEditEvent->setText(QApplication::translate("SceneEditor", "\303\211diter", Q_NULLPTR));
        pbuDeleteEvent->setText(QApplication::translate("SceneEditor", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_events), QApplication::translate("SceneEditor", "\303\211venements", Q_NULLPTR));
        menuFichier->setTitle(QApplication::translate("SceneEditor", "Fichier", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SceneEditor: public Ui_SceneEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEEDITOR_H
