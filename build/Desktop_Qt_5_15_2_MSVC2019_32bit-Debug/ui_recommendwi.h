/********************************************************************************
** Form generated from reading UI file 'recommendwi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOMMENDWI_H
#define UI_RECOMMENDWI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <coverflowwi.h>

QT_BEGIN_NAMESPACE

class Ui_Recommendwi
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    CoverFlowwi *coverFlowwi;
    QWidget *songlistwi;
    QVBoxLayout *verticalLayout_3;
    QWidget *songlbwi;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QWidget *songwi;
    QWidget *widget_4;

    void setupUi(QWidget *Recommendwi)
    {
        if (Recommendwi->objectName().isEmpty())
            Recommendwi->setObjectName(QString::fromUtf8("Recommendwi"));
        Recommendwi->resize(1259, 898);
        Recommendwi->setMinimumSize(QSize(1259, 898));
        Recommendwi->setMaximumSize(QSize(1259, 898));
        Recommendwi->setStyleSheet(QString::fromUtf8("background-color: #F7F9FC;"));
        verticalLayout = new QVBoxLayout(Recommendwi);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(Recommendwi);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    background-color: #f0f3f6;\n"
"}\n"
"\n"
"QScrollArea::corner {\n"
"    background-color: #f0f3f6;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background-color: #f0f3f6; /* \346\273\232\345\212\250\346\235\241\350\203\214\346\231\257 */\n"
"    width: 9px; /* \346\273\232\345\212\250\346\235\241\345\256\275\345\272\246 */\n"
"    margin: 0px 0px 0px 0px; /* \346\216\247\345\210\266\346\273\232\345\212\250\346\235\241\347\232\204\351\227\264\350\267\235 */\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #dcdfe4; /* \346\273\232\345\212\250\346\235\241\346\273\221\345\235\227\351\242\234\350\211\262 */\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background-color: #bec3ca; /* \346\273\232\345\212\250\346\235\241\346\273\221\345\235\227\346\202\254\345\201\234\346\227\266\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QScrollBar"
                        "::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    background-color: #f0f3f6; /* \351\232\220\350\227\217\346\273\232\345\212\250\346\235\241\344\270\212\344\270\213\347\256\255\345\244\264 */\n"
"}\n"
"QScrollBar:horizontal {\n"
"    height: 0px; /* \345\205\263\351\224\256\357\274\232\345\260\206\351\253\230\345\272\246\350\256\276\344\270\272 0\357\274\214\344\275\277\346\260\264\345\271\263\346\273\232\345\212\250\346\235\241\344\270\215\345\217\257\350\247\201\344\270\224\344\270\215\345\215\240\347\251\272\351\227\264 */\n"
"    background-color: transparent; /* \345\217\257\351\200\211\357\274\232\350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"}\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1250, 1300));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(50, 0, 50, 0);
        coverFlowwi = new CoverFlowwi(scrollAreaWidgetContents);
        coverFlowwi->setObjectName(QString::fromUtf8("coverFlowwi"));
        coverFlowwi->setMinimumSize(QSize(0, 400));
        coverFlowwi->setMaximumSize(QSize(16777215, 400));
        coverFlowwi->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(coverFlowwi);

        songlistwi = new QWidget(scrollAreaWidgetContents);
        songlistwi->setObjectName(QString::fromUtf8("songlistwi"));
        verticalLayout_3 = new QVBoxLayout(songlistwi);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        songlbwi = new QWidget(songlistwi);
        songlbwi->setObjectName(QString::fromUtf8("songlbwi"));
        songlbwi->setMinimumSize(QSize(0, 80));
        songlbwi->setMaximumSize(QSize(16777215, 80));
        horizontalLayout = new QHBoxLayout(songlbwi);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(songlbwi);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(200, 50));
        label->setMaximumSize(QSize(200, 50));
        label->setStyleSheet(QString::fromUtf8("color: #283248;\n"
"        font-size: 28px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;\n"
"font-weight: bold;                 "));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(songlbwi);

        songwi = new QWidget(songlistwi);
        songwi->setObjectName(QString::fromUtf8("songwi"));
        songwi->setMinimumSize(QSize(0, 320));
        songwi->setMaximumSize(QSize(16777215, 320));

        verticalLayout_3->addWidget(songwi);


        verticalLayout_2->addWidget(songlistwi);

        widget_4 = new QWidget(scrollAreaWidgetContents);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 500));

        verticalLayout_2->addWidget(widget_4);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Recommendwi);

        QMetaObject::connectSlotsByName(Recommendwi);
    } // setupUi

    void retranslateUi(QWidget *Recommendwi)
    {
        Recommendwi->setWindowTitle(QCoreApplication::translate("Recommendwi", "Form", nullptr));
        label->setText(QCoreApplication::translate("Recommendwi", "\346\216\250\350\215\220\346\255\214\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Recommendwi: public Ui_Recommendwi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOMMENDWI_H
