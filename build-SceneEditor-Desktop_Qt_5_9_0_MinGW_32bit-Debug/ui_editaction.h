/********************************************************************************
** Form generated from reading UI file 'editaction.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITACTION_H
#define UI_EDITACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_editAction
{
public:
    QGridLayout *gridLayout_6;
    QGroupBox *grb_Pos;
    QGridLayout *gridLayout_3;
    QHBoxLayout *qhl_Altitude;
    QLabel *lbl_Altitude;
    QLineEdit *qle_Altitude;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_Longitude;
    QLineEdit *qle_Longitude;
    QCheckBox *chkOnGround;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_Latitude;
    QLineEdit *qle_Latitude;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QCheckBox *chk_Smoke;
    QVBoxLayout *verticalLayout;
    QSlider *qhs_Smoke;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_Smoke_1;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lbl_Smoke_2;
    QGridLayout *gridLayout_5;
    QGroupBox *grpType;
    QGridLayout *gridLayout_2;
    QRadioButton *rdbApparition;
    QRadioButton *rdbDeplacement;
    QRadioButton *rdbDisparition;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_Name;
    QLineEdit *qle_Name;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_Id;
    QLineEdit *qle_Id;
    QSplitter *splitter_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_Psi;
    QLineEdit *qle_Psi;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_Theta;
    QLineEdit *qle_Theta;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lbl_Phi;
    QLineEdit *qle_Phi;

    void setupUi(QDialog *editAction)
    {
        if (editAction->objectName().isEmpty())
            editAction->setObjectName(QStringLiteral("editAction"));
        editAction->resize(335, 486);
        QFont font;
        font.setFamily(QStringLiteral("Liberation Mono"));
        editAction->setFont(font);
        gridLayout_6 = new QGridLayout(editAction);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        grb_Pos = new QGroupBox(editAction);
        grb_Pos->setObjectName(QStringLiteral("grb_Pos"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grb_Pos->sizePolicy().hasHeightForWidth());
        grb_Pos->setSizePolicy(sizePolicy);
        grb_Pos->setCheckable(false);
        gridLayout_3 = new QGridLayout(grb_Pos);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        qhl_Altitude = new QHBoxLayout();
        qhl_Altitude->setObjectName(QStringLiteral("qhl_Altitude"));
        lbl_Altitude = new QLabel(grb_Pos);
        lbl_Altitude->setObjectName(QStringLiteral("lbl_Altitude"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbl_Altitude->sizePolicy().hasHeightForWidth());
        lbl_Altitude->setSizePolicy(sizePolicy1);

        qhl_Altitude->addWidget(lbl_Altitude);

        qle_Altitude = new QLineEdit(grb_Pos);
        qle_Altitude->setObjectName(QStringLiteral("qle_Altitude"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(qle_Altitude->sizePolicy().hasHeightForWidth());
        qle_Altitude->setSizePolicy(sizePolicy2);

        qhl_Altitude->addWidget(qle_Altitude);


        gridLayout_3->addLayout(qhl_Altitude, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lbl_Longitude = new QLabel(grb_Pos);
        lbl_Longitude->setObjectName(QStringLiteral("lbl_Longitude"));
        sizePolicy1.setHeightForWidth(lbl_Longitude->sizePolicy().hasHeightForWidth());
        lbl_Longitude->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("Liberation Mono"));
        font1.setPointSize(8);
        lbl_Longitude->setFont(font1);

        horizontalLayout_4->addWidget(lbl_Longitude);

        qle_Longitude = new QLineEdit(grb_Pos);
        qle_Longitude->setObjectName(QStringLiteral("qle_Longitude"));
        qle_Longitude->setEnabled(true);
        sizePolicy2.setHeightForWidth(qle_Longitude->sizePolicy().hasHeightForWidth());
        qle_Longitude->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(qle_Longitude);


        gridLayout_3->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        chkOnGround = new QCheckBox(grb_Pos);
        chkOnGround->setObjectName(QStringLiteral("chkOnGround"));
        chkOnGround->setChecked(true);

        gridLayout_3->addWidget(chkOnGround, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lbl_Latitude = new QLabel(grb_Pos);
        lbl_Latitude->setObjectName(QStringLiteral("lbl_Latitude"));
        sizePolicy1.setHeightForWidth(lbl_Latitude->sizePolicy().hasHeightForWidth());
        lbl_Latitude->setSizePolicy(sizePolicy1);
        lbl_Latitude->setFont(font);

        horizontalLayout_5->addWidget(lbl_Latitude);

        qle_Latitude = new QLineEdit(grb_Pos);
        qle_Latitude->setObjectName(QStringLiteral("qle_Latitude"));
        sizePolicy2.setHeightForWidth(qle_Latitude->sizePolicy().hasHeightForWidth());
        qle_Latitude->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(qle_Latitude);


        gridLayout_3->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        gridLayout_6->addWidget(grb_Pos, 1, 0, 1, 2);

        frame = new QFrame(editAction);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy3);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        chk_Smoke = new QCheckBox(frame);
        chk_Smoke->setObjectName(QStringLiteral("chk_Smoke"));

        gridLayout_4->addWidget(chk_Smoke, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        qhs_Smoke = new QSlider(frame);
        qhs_Smoke->setObjectName(QStringLiteral("qhs_Smoke"));
        qhs_Smoke->setMinimum(1);
        qhs_Smoke->setMaximum(500);
        qhs_Smoke->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(qhs_Smoke);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbl_Smoke_1 = new QLabel(frame);
        lbl_Smoke_1->setObjectName(QStringLiteral("lbl_Smoke_1"));

        horizontalLayout_2->addWidget(lbl_Smoke_1);

        horizontalSpacer_3 = new QSpacerItem(88, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        lbl_Smoke_2 = new QLabel(frame);
        lbl_Smoke_2->setObjectName(QStringLiteral("lbl_Smoke_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lbl_Smoke_2->sizePolicy().hasHeightForWidth());
        lbl_Smoke_2->setSizePolicy(sizePolicy4);

        horizontalLayout_2->addWidget(lbl_Smoke_2);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_4->addLayout(verticalLayout, 1, 0, 1, 1);


        gridLayout_6->addWidget(frame, 3, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        grpType = new QGroupBox(editAction);
        grpType->setObjectName(QStringLiteral("grpType"));
        gridLayout_2 = new QGridLayout(grpType);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        rdbApparition = new QRadioButton(grpType);
        rdbApparition->setObjectName(QStringLiteral("rdbApparition"));

        gridLayout_2->addWidget(rdbApparition, 0, 0, 1, 1);

        rdbDeplacement = new QRadioButton(grpType);
        rdbDeplacement->setObjectName(QStringLiteral("rdbDeplacement"));

        gridLayout_2->addWidget(rdbDeplacement, 1, 0, 1, 1);

        rdbDisparition = new QRadioButton(grpType);
        rdbDisparition->setObjectName(QStringLiteral("rdbDisparition"));

        gridLayout_2->addWidget(rdbDisparition, 2, 0, 1, 1);


        gridLayout_5->addWidget(grpType, 0, 0, 1, 1);

        groupBox = new QGroupBox(editAction);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbl_Name = new QLabel(groupBox);
        lbl_Name->setObjectName(QStringLiteral("lbl_Name"));

        horizontalLayout->addWidget(lbl_Name);

        qle_Name = new QLineEdit(groupBox);
        qle_Name->setObjectName(QStringLiteral("qle_Name"));

        horizontalLayout->addWidget(qle_Name);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy5);
        pushButton->setMinimumSize(QSize(30, 0));
        pushButton->setMaximumSize(QSize(30, 16777215));
        pushButton->setSizeIncrement(QSize(0, 0));
        pushButton->setBaseSize(QSize(30, 0));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbl_Id = new QLabel(groupBox);
        lbl_Id->setObjectName(QStringLiteral("lbl_Id"));

        horizontalLayout_3->addWidget(lbl_Id);

        qle_Id = new QLineEdit(groupBox);
        qle_Id->setObjectName(QStringLiteral("qle_Id"));

        horizontalLayout_3->addWidget(qle_Id);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 2);

        splitter_3 = new QSplitter(editAction);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(splitter_3->sizePolicy().hasHeightForWidth());
        splitter_3->setSizePolicy(sizePolicy6);
        splitter_3->setOrientation(Qt::Horizontal);
        pushButton_2 = new QPushButton(splitter_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        splitter_3->addWidget(pushButton_2);
        pushButton_3 = new QPushButton(splitter_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        splitter_3->addWidget(pushButton_3);

        gridLayout_6->addWidget(splitter_3, 4, 0, 1, 2);

        groupBox_2 = new QGroupBox(editAction);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_7 = new QGridLayout(groupBox_2);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lbl_Psi = new QLabel(groupBox_2);
        lbl_Psi->setObjectName(QStringLiteral("lbl_Psi"));

        horizontalLayout_6->addWidget(lbl_Psi);

        qle_Psi = new QLineEdit(groupBox_2);
        qle_Psi->setObjectName(QStringLiteral("qle_Psi"));

        horizontalLayout_6->addWidget(qle_Psi);


        gridLayout_7->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lbl_Theta = new QLabel(groupBox_2);
        lbl_Theta->setObjectName(QStringLiteral("lbl_Theta"));

        horizontalLayout_7->addWidget(lbl_Theta);

        qle_Theta = new QLineEdit(groupBox_2);
        qle_Theta->setObjectName(QStringLiteral("qle_Theta"));

        horizontalLayout_7->addWidget(qle_Theta);


        gridLayout_7->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        lbl_Phi = new QLabel(groupBox_2);
        lbl_Phi->setObjectName(QStringLiteral("lbl_Phi"));

        horizontalLayout_8->addWidget(lbl_Phi);

        qle_Phi = new QLineEdit(groupBox_2);
        qle_Phi->setObjectName(QStringLiteral("qle_Phi"));

        horizontalLayout_8->addWidget(qle_Phi);


        gridLayout_7->addLayout(horizontalLayout_8, 2, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 2, 0, 1, 1);


        retranslateUi(editAction);
        QObject::connect(chkOnGround, SIGNAL(toggled(bool)), qle_Altitude, SLOT(setHidden(bool)));
        QObject::connect(chkOnGround, SIGNAL(toggled(bool)), lbl_Altitude, SLOT(setHidden(bool)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), editAction, SLOT(reject()));
        QObject::connect(chk_Smoke, SIGNAL(toggled(bool)), qhs_Smoke, SLOT(setVisible(bool)));
        QObject::connect(chk_Smoke, SIGNAL(toggled(bool)), lbl_Smoke_1, SLOT(setVisible(bool)));
        QObject::connect(chk_Smoke, SIGNAL(toggled(bool)), lbl_Smoke_2, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(editAction);
    } // setupUi

    void retranslateUi(QDialog *editAction)
    {
        editAction->setWindowTitle(QApplication::translate("editAction", "Dialog", Q_NULLPTR));
        grb_Pos->setTitle(QApplication::translate("editAction", "Position", Q_NULLPTR));
        lbl_Altitude->setText(QApplication::translate("editAction", "Altitude  :", Q_NULLPTR));
        lbl_Longitude->setText(QApplication::translate("editAction", "Longitude :", Q_NULLPTR));
        chkOnGround->setText(QApplication::translate("editAction", "Au sol", Q_NULLPTR));
        lbl_Latitude->setText(QApplication::translate("editAction", "Latitude  :", Q_NULLPTR));
        chk_Smoke->setText(QApplication::translate("editAction", "Fum\303\251e", Q_NULLPTR));
        lbl_Smoke_1->setText(QApplication::translate("editAction", "Peu de fum\303\251e", Q_NULLPTR));
        lbl_Smoke_2->setText(QApplication::translate("editAction", "Fum\303\251e abondante", Q_NULLPTR));
        grpType->setTitle(QApplication::translate("editAction", "Type d'action", Q_NULLPTR));
        rdbApparition->setText(QApplication::translate("editAction", "Apparition", Q_NULLPTR));
        rdbDeplacement->setText(QApplication::translate("editAction", "D\303\251placement", Q_NULLPTR));
        rdbDisparition->setText(QApplication::translate("editAction", "Disparition", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("editAction", "Objet", Q_NULLPTR));
        lbl_Name->setText(QApplication::translate("editAction", "Nom :", Q_NULLPTR));
        pushButton->setText(QApplication::translate("editAction", "...", Q_NULLPTR));
        lbl_Id->setText(QApplication::translate("editAction", "Identifiant :", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("editAction", "Annuler", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("editAction", "Valider", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("editAction", "Rotation", Q_NULLPTR));
        lbl_Psi->setText(QApplication::translate("editAction", "Psi   :", Q_NULLPTR));
        lbl_Theta->setText(QApplication::translate("editAction", "Theta :", Q_NULLPTR));
        lbl_Phi->setText(QApplication::translate("editAction", "Phi   :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class editAction: public Ui_editAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITACTION_H
