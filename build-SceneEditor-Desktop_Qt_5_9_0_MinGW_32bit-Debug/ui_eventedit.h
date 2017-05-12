/********************************************************************************
** Form generated from reading UI file 'eventedit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTEDIT_H
#define UI_EVENTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_eventEdit
{
public:
    QGridLayout *gridLayout;
    QFrame *frm_EventInfo;
    QFormLayout *formLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_8;
    QGroupBox *grpType;
    QFormLayout *formLayout_2;
    QRadioButton *rdbManuel;
    QRadioButton *rdbTime;
    QRadioButton *rdbPos;
    QFrame *frame_3;
    QGridLayout *gridLayout_3;
    QGroupBox *grb_Time;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QTimeEdit *timeEdit;
    QSpacerItem *horizontalSpacer;
    QSplitter *splitter_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QGroupBox *grb_Pos;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QPlainTextEdit *plainTextEdit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QListView *listView;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QPushButton *pbuAddAction;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;

    void setupUi(QDialog *eventEdit)
    {
        if (eventEdit->objectName().isEmpty())
            eventEdit->setObjectName(QStringLiteral("eventEdit"));
        eventEdit->resize(468, 550);
        QFont font;
        font.setFamily(QStringLiteral("Liberation Mono"));
        eventEdit->setFont(font);
        gridLayout = new QGridLayout(eventEdit);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frm_EventInfo = new QFrame(eventEdit);
        frm_EventInfo->setObjectName(QStringLiteral("frm_EventInfo"));
        frm_EventInfo->setFrameShape(QFrame::StyledPanel);
        frm_EventInfo->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frm_EventInfo);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        frame_2 = new QFrame(frm_EventInfo);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_2);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        grpType = new QGroupBox(frame_2);
        grpType->setObjectName(QStringLiteral("grpType"));
        formLayout_2 = new QFormLayout(grpType);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        rdbManuel = new QRadioButton(grpType);
        rdbManuel->setObjectName(QStringLiteral("rdbManuel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, rdbManuel);

        rdbTime = new QRadioButton(grpType);
        rdbTime->setObjectName(QStringLiteral("rdbTime"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, rdbTime);

        rdbPos = new QRadioButton(grpType);
        rdbPos->setObjectName(QStringLiteral("rdbPos"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, rdbPos);


        gridLayout_8->addWidget(grpType, 0, 0, 1, 1);


        formLayout->setWidget(0, QFormLayout::LabelRole, frame_2);

        frame_3 = new QFrame(frm_EventInfo);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        grb_Time = new QGroupBox(frame_3);
        grb_Time->setObjectName(QStringLiteral("grb_Time"));
        grb_Time->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grb_Time->sizePolicy().hasHeightForWidth());
        grb_Time->setSizePolicy(sizePolicy);
        gridLayout_7 = new QGridLayout(grb_Time);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(grb_Time);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        timeEdit = new QTimeEdit(grb_Time);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        horizontalLayout_4->addWidget(timeEdit);

        horizontalSpacer = new QSpacerItem(27, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        gridLayout_7->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        splitter_3 = new QSplitter(grb_Time);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        radioButton_4 = new QRadioButton(splitter_3);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        splitter_3->addWidget(radioButton_4);
        radioButton_5 = new QRadioButton(splitter_3);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        splitter_3->addWidget(radioButton_5);

        gridLayout_7->addWidget(splitter_3, 1, 0, 1, 1);


        gridLayout_3->addWidget(grb_Time, 2, 1, 1, 1);

        grb_Pos = new QGroupBox(frame_3);
        grb_Pos->setObjectName(QStringLiteral("grb_Pos"));
        grb_Pos->setCheckable(false);
        gridLayout_4 = new QGridLayout(grb_Pos);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(grb_Pos);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("Liberation Mono"));
        font1.setPointSize(8);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        lineEdit_3 = new QLineEdit(grb_Pos);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(lineEdit_3);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(grb_Pos);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        lineEdit_4 = new QLineEdit(grb_Pos);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy2.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(lineEdit_4);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(grb_Pos);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label_4);

        lineEdit_2 = new QLineEdit(grb_Pos);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(lineEdit_2);


        gridLayout_4->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        gridLayout_3->addWidget(grb_Pos, 1, 1, 1, 1);


        formLayout->setWidget(0, QFormLayout::FieldRole, frame_3);


        gridLayout->addWidget(frm_EventInfo, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(eventEdit);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout_5->addWidget(plainTextEdit, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(eventEdit);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        listView = new QListView(groupBox);
        listView->setObjectName(QStringLiteral("listView"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy3);

        gridLayout_6->addWidget(listView, 0, 0, 1, 1);

        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy4);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pbuAddAction = new QPushButton(frame);
        pbuAddAction->setObjectName(QStringLiteral("pbuAddAction"));

        gridLayout_2->addWidget(pbuAddAction, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 2, 0, 1, 1);


        gridLayout_6->addWidget(frame, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_5 = new QPushButton(eventEdit);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_5->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(eventEdit);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_5->addWidget(pushButton_4);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 1);


        retranslateUi(eventEdit);
        QObject::connect(rdbTime, SIGNAL(toggled(bool)), grb_Time, SLOT(setVisible(bool)));
        QObject::connect(rdbPos, SIGNAL(toggled(bool)), grb_Pos, SLOT(setVisible(bool)));
        QObject::connect(pushButton_5, SIGNAL(clicked()), eventEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(eventEdit);
    } // setupUi

    void retranslateUi(QDialog *eventEdit)
    {
        eventEdit->setWindowTitle(QApplication::translate("eventEdit", "Dialog", Q_NULLPTR));
        grpType->setTitle(QApplication::translate("eventEdit", "Type d'evenement", Q_NULLPTR));
        rdbManuel->setText(QApplication::translate("eventEdit", "Manuel", Q_NULLPTR));
        rdbTime->setText(QApplication::translate("eventEdit", "Temps", Q_NULLPTR));
        rdbPos->setText(QApplication::translate("eventEdit", "Position", Q_NULLPTR));
        grb_Time->setTitle(QApplication::translate("eventEdit", "Temps :", Q_NULLPTR));
        label->setText(QApplication::translate("eventEdit", "Temps", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("eventEdit", "Relatif", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("eventEdit", "Differ\303\251", Q_NULLPTR));
        grb_Pos->setTitle(QApplication::translate("eventEdit", "Position", Q_NULLPTR));
        label_2->setText(QApplication::translate("eventEdit", "Longitude :", Q_NULLPTR));
        label_3->setText(QApplication::translate("eventEdit", "Latitude  :", Q_NULLPTR));
        label_4->setText(QApplication::translate("eventEdit", "rayon     :", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("eventEdit", "Description", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("eventEdit", "Actions", Q_NULLPTR));
        pbuAddAction->setText(QApplication::translate("eventEdit", "&Ajouter", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("eventEdit", "&Editer", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("eventEdit", "&Supprimer", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("eventEdit", "Annuler", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("eventEdit", "Valider", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class eventEdit: public Ui_eventEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTEDIT_H
