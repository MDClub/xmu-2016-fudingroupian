/********************************************************************************
** Form generated from reading UI file 'processface.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSFACE_H
#define UI_PROCESSFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessFaceClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *startButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *KathonButton;
    QPushButton *pushButton_4;
    QPushButton *endButton;
    QLabel *labelOriImage;
    QLabel *labelResultImage;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonSketch;
    QPushButton *pushButtonCartoon;
    QPushButton *pushButtonBeautifyFace;
    QPushButton *pushButtonMaxFrame;
    QPushButton *pushButtonMinFrame;
    QPushButton *pushButtonEyesZoom;
    QPushButton *pushButtonAddHat;
    QPushButton *pushButtonAddWig;
    QPushButton *pushButtonEnd;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProcessFaceClass)
    {
        if (ProcessFaceClass->objectName().isEmpty())
            ProcessFaceClass->setObjectName(QStringLiteral("ProcessFaceClass"));
        ProcessFaceClass->resize(1493, 565);
        centralWidget = new QWidget(ProcessFaceClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1820, 280, 81, 471));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(verticalLayoutWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        verticalLayout->addWidget(startButton);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        KathonButton = new QPushButton(verticalLayoutWidget);
        KathonButton->setObjectName(QStringLiteral("KathonButton"));

        verticalLayout->addWidget(KathonButton);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        endButton = new QPushButton(verticalLayoutWidget);
        endButton->setObjectName(QStringLiteral("endButton"));

        verticalLayout->addWidget(endButton);

        labelOriImage = new QLabel(centralWidget);
        labelOriImage->setObjectName(QStringLiteral("labelOriImage"));
        labelOriImage->setGeometry(QRect(20, 10, 641, 481));
        labelResultImage = new QLabel(centralWidget);
        labelResultImage->setObjectName(QStringLiteral("labelResultImage"));
        labelResultImage->setGeometry(QRect(730, 20, 641, 481));
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(1383, 30, 101, 441));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonStart = new QPushButton(verticalLayoutWidget_2);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));

        verticalLayout_2->addWidget(pushButtonStart);

        pushButtonSketch = new QPushButton(verticalLayoutWidget_2);
        pushButtonSketch->setObjectName(QStringLiteral("pushButtonSketch"));

        verticalLayout_2->addWidget(pushButtonSketch);

        pushButtonCartoon = new QPushButton(verticalLayoutWidget_2);
        pushButtonCartoon->setObjectName(QStringLiteral("pushButtonCartoon"));

        verticalLayout_2->addWidget(pushButtonCartoon);

        pushButtonBeautifyFace = new QPushButton(verticalLayoutWidget_2);
        pushButtonBeautifyFace->setObjectName(QStringLiteral("pushButtonBeautifyFace"));

        verticalLayout_2->addWidget(pushButtonBeautifyFace);

        pushButtonMaxFrame = new QPushButton(verticalLayoutWidget_2);
        pushButtonMaxFrame->setObjectName(QStringLiteral("pushButtonMaxFrame"));

        verticalLayout_2->addWidget(pushButtonMaxFrame);

        pushButtonMinFrame = new QPushButton(verticalLayoutWidget_2);
        pushButtonMinFrame->setObjectName(QStringLiteral("pushButtonMinFrame"));

        verticalLayout_2->addWidget(pushButtonMinFrame);

        pushButtonEyesZoom = new QPushButton(verticalLayoutWidget_2);
        pushButtonEyesZoom->setObjectName(QStringLiteral("pushButtonEyesZoom"));

        verticalLayout_2->addWidget(pushButtonEyesZoom);

        pushButtonAddHat = new QPushButton(verticalLayoutWidget_2);
        pushButtonAddHat->setObjectName(QStringLiteral("pushButtonAddHat"));

        verticalLayout_2->addWidget(pushButtonAddHat);

        pushButtonAddWig = new QPushButton(verticalLayoutWidget_2);
        pushButtonAddWig->setObjectName(QStringLiteral("pushButtonAddWig"));

        verticalLayout_2->addWidget(pushButtonAddWig);

        pushButtonEnd = new QPushButton(verticalLayoutWidget_2);
        pushButtonEnd->setObjectName(QStringLiteral("pushButtonEnd"));

        verticalLayout_2->addWidget(pushButtonEnd);

        ProcessFaceClass->setCentralWidget(centralWidget);
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        labelOriImage->raise();
        labelResultImage->raise();
        menuBar = new QMenuBar(ProcessFaceClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1493, 23));
        ProcessFaceClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProcessFaceClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProcessFaceClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProcessFaceClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProcessFaceClass->setStatusBar(statusBar);

        retranslateUi(ProcessFaceClass);
        QObject::connect(pushButtonStart, SIGNAL(clicked()), ProcessFaceClass, SLOT(startClicked()));
        QObject::connect(pushButtonSketch, SIGNAL(clicked()), ProcessFaceClass, SLOT(sketchClicked()));
        QObject::connect(pushButtonEnd, SIGNAL(clicked()), ProcessFaceClass, SLOT(closeClicked()));
        QObject::connect(pushButtonCartoon, SIGNAL(clicked()), ProcessFaceClass, SLOT(cartoonClicked()));
        QObject::connect(pushButtonAddHat, SIGNAL(clicked()), ProcessFaceClass, SLOT(addHatClicked()));
        QObject::connect(pushButtonAddWig, SIGNAL(clicked()), ProcessFaceClass, SLOT(addWigClicked()));
        QObject::connect(pushButtonBeautifyFace, SIGNAL(clicked()), ProcessFaceClass, SLOT(beautifyFaceClicked()));
        QObject::connect(pushButtonMaxFrame, SIGNAL(clicked()), ProcessFaceClass, SLOT(maxFrameClicked()));
        QObject::connect(pushButtonMinFrame, SIGNAL(clicked()), ProcessFaceClass, SLOT(minFrameClicked()));
        QObject::connect(pushButtonEyesZoom, SIGNAL(clicked()), ProcessFaceClass, SLOT(eyesZoomClicked()));

        QMetaObject::connectSlotsByName(ProcessFaceClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProcessFaceClass)
    {
        ProcessFaceClass->setWindowTitle(QApplication::translate("ProcessFaceClass", "ProcessFace", 0));
        startButton->setText(QApplication::translate("ProcessFaceClass", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", 0));
        pushButton_5->setText(QApplication::translate("ProcessFaceClass", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("ProcessFaceClass", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("ProcessFaceClass", "PushButton", 0));
        KathonButton->setText(QApplication::translate("ProcessFaceClass", "\345\212\250\346\274\253\346\225\210\346\236\234", 0));
        pushButton_4->setText(QApplication::translate("ProcessFaceClass", "PushButton", 0));
        endButton->setText(QApplication::translate("ProcessFaceClass", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", 0));
        labelOriImage->setText(QString());
        labelResultImage->setText(QString());
        pushButtonStart->setText(QApplication::translate("ProcessFaceClass", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", 0));
        pushButtonSketch->setText(QApplication::translate("ProcessFaceClass", "\347\264\240\346\217\217\346\225\210\346\236\234", 0));
        pushButtonCartoon->setText(QApplication::translate("ProcessFaceClass", "\345\215\241\351\200\232\346\225\210\346\236\234", 0));
        pushButtonBeautifyFace->setText(QApplication::translate("ProcessFaceClass", "\344\272\272\350\204\270\347\276\216\345\256\271\346\225\210\346\236\234", 0));
        pushButtonMaxFrame->setText(QApplication::translate("ProcessFaceClass", "\345\207\270\351\200\217\351\225\234\346\225\210\346\236\234", 0));
        pushButtonMinFrame->setText(QApplication::translate("ProcessFaceClass", "\345\207\271\351\200\217\351\225\234\346\225\210\346\236\234", 0));
        pushButtonEyesZoom->setText(QApplication::translate("ProcessFaceClass", "\345\217\214\347\234\274\345\206\222\346\241\203\345\277\203\346\225\210\346\236\234", 0));
        pushButtonAddHat->setText(QApplication::translate("ProcessFaceClass", "\346\210\264\345\270\275\345\255\220\346\225\210\346\236\234", 0));
        pushButtonAddWig->setText(QApplication::translate("ProcessFaceClass", "\346\210\264\345\201\207\345\217\221\346\225\210\346\236\234", 0));
        pushButtonEnd->setText(QApplication::translate("ProcessFaceClass", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", 0));
    } // retranslateUi

};

namespace Ui {
    class ProcessFaceClass: public Ui_ProcessFaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSFACE_H
