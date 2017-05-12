/********************************************************************************
** Form generated from reading UI file 'eventedit_copy.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTEDIT_COPY_H
#define UI_EVENTEDIT_COPY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_eventEdit
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QListView *listView;
    QFrame *frame;
    QFormLayout *formLayout;
    QGroupBox *grpType;
    QFormLayout *formLayout_2;
    QRadioButton *rdbManuel;
    QRadioButton *rdbTime;
    QRadioButton *rdbPos;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout_4;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *lineEdit;
    QSplitter *splitter_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QSplitter *splitter_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;

    void setupUi(QDialog *eventEdit)
    {
        if (eventEdit->objectName().isEmpty())
            eventEdit->setObjectName(QStringLiteral("eventEdit"));
        eventEdit->resize(400, 330);
        gridLayout_2 = new QGridLayout(eventEdit);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame_2 = new QFrame(eventEdit);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listView = new QListView(frame_2);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout->addWidget(listView, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame_2, 3, 0, 1, 2);

        frame = new QFrame(eventEdit);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        grpType = new QGroupBox(frame);
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


        formLayout->setWidget(1, QFormLayout::LabelRole, grpType);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        formLayout_3 = new QFormLayout(groupBox_2);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, lineEdit_3);

        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, lineEdit_4);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, lineEdit_2);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(frame_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        formLayout_4 = new QFormLayout(groupBox);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        splitter->addWidget(label);
        lineEdit = new QLineEdit(splitter);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        splitter->addWidget(lineEdit);

        formLayout_4->setWidget(0, QFormLayout::SpanningRole, splitter);

        splitter_2 = new QSplitter(groupBox);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        radioButton = new QRadioButton(splitter_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        splitter_2->addWidget(radioButton);
        radioButton_2 = new QRadioButton(splitter_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        splitter_2->addWidget(radioButton_2);
        radioButton_3 = new QRadioButton(splitter_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        splitter_2->addWidget(radioButton_3);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, splitter_2);

        splitter_3 = new QSplitter(groupBox);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        radioButton_4 = new QRadioButton(splitter_3);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        splitter_3->addWidget(radioButton_4);
        radioButton_5 = new QRadioButton(splitter_3);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        splitter_3->addWidget(radioButton_5);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, splitter_3);


        verticalLayout->addWidget(groupBox);


        formLayout->setWidget(1, QFormLayout::FieldRole, frame_3);


        gridLayout_2->addWidget(frame, 0, 0, 2, 2);


        retranslateUi(eventEdit);

        QMetaObject::connectSlotsByName(eventEdit);
    } // setupUi

    void retranslateUi(QDialog *eventEdit)
    {
        eventEdit->setWindowTitle(QApplication::translate("eventEdit", "Dialog", Q_NULLPTR));
        grpType->setTitle(QApplication::translate("eventEdit", "Type d'evenement", Q_NULLPTR));
        rdbManuel->setText(QApplication::translate("eventEdit", "Manuel", Q_NULLPTR));
        rdbTime->setText(QApplication::translate("eventEdit", "Temps", Q_NULLPTR));
        rdbPos->setText(QApplication::translate("eventEdit", "Position", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("eventEdit", "Position", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("eventEdit", "Temps :", Q_NULLPTR));
        label->setText(QApplication::translate("eventEdit", "Temps", Q_NULLPTR));
        lineEdit->setInputMask(QApplication::translate("eventEdit", "ddddddddd", Q_NULLPTR));
        radioButton->setText(QApplication::translate("eventEdit", "millisecondes", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("eventEdit", "secondes", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("eventEdit", "minutes", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("eventEdit", "Relatif", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("eventEdit", "Differ\303\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class eventEdit: public Ui_eventEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTEDIT_COPY_H
