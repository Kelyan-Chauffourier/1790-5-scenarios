/********************************************************************************
** Form generated from reading UI file 'editobject.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOBJECT_H
#define UI_EDITOBJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_editObject
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_chemin;
    QLineEdit *qle_chemin;
    QPushButton *pbu_chemin;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_Nom;
    QLineEdit *qle_Nom;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbu_Annuler;
    QPushButton *pbu_Valider;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *editObject)
    {
        if (editObject->objectName().isEmpty())
            editObject->setObjectName(QStringLiteral("editObject"));
        editObject->resize(339, 108);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editObject->sizePolicy().hasHeightForWidth());
        editObject->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Liberation Mono"));
        editObject->setFont(font);
        gridLayout = new QGridLayout(editObject);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbl_chemin = new QLabel(editObject);
        lbl_chemin->setObjectName(QStringLiteral("lbl_chemin"));

        horizontalLayout->addWidget(lbl_chemin);

        qle_chemin = new QLineEdit(editObject);
        qle_chemin->setObjectName(QStringLiteral("qle_chemin"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qle_chemin->sizePolicy().hasHeightForWidth());
        qle_chemin->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(qle_chemin);

        pbu_chemin = new QPushButton(editObject);
        pbu_chemin->setObjectName(QStringLiteral("pbu_chemin"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pbu_chemin->sizePolicy().hasHeightForWidth());
        pbu_chemin->setSizePolicy(sizePolicy2);
        pbu_chemin->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(pbu_chemin);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbl_Nom = new QLabel(editObject);
        lbl_Nom->setObjectName(QStringLiteral("lbl_Nom"));

        horizontalLayout_3->addWidget(lbl_Nom);

        qle_Nom = new QLineEdit(editObject);
        qle_Nom->setObjectName(QStringLiteral("qle_Nom"));

        horizontalLayout_3->addWidget(qle_Nom);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pbu_Annuler = new QPushButton(editObject);
        pbu_Annuler->setObjectName(QStringLiteral("pbu_Annuler"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pbu_Annuler->sizePolicy().hasHeightForWidth());
        pbu_Annuler->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(pbu_Annuler);

        pbu_Valider = new QPushButton(editObject);
        pbu_Valider->setObjectName(QStringLiteral("pbu_Valider"));
        sizePolicy3.setHeightForWidth(pbu_Valider->sizePolicy().hasHeightForWidth());
        pbu_Valider->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(pbu_Valider);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);


        retranslateUi(editObject);
        QObject::connect(pbu_Annuler, SIGNAL(clicked()), editObject, SLOT(reject()));

        QMetaObject::connectSlotsByName(editObject);
    } // setupUi

    void retranslateUi(QDialog *editObject)
    {
        editObject->setWindowTitle(QApplication::translate("editObject", "Dialog", Q_NULLPTR));
        lbl_chemin->setText(QApplication::translate("editObject", "Chemin :", Q_NULLPTR));
        pbu_chemin->setText(QApplication::translate("editObject", "...", Q_NULLPTR));
        lbl_Nom->setText(QApplication::translate("editObject", "Nom    :", Q_NULLPTR));
        pbu_Annuler->setText(QApplication::translate("editObject", "Annuler", Q_NULLPTR));
        pbu_Valider->setText(QApplication::translate("editObject", "Valider", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class editObject: public Ui_editObject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOBJECT_H
