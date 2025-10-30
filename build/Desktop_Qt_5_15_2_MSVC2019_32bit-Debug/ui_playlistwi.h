/********************************************************************************
** Form generated from reading UI file 'playlistwi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTWI_H
#define UI_PLAYLISTWI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playlistwi
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *clear_btn;
    QWidget *container_wi;

    void setupUi(QDialog *playlistwi)
    {
        if (playlistwi->objectName().isEmpty())
            playlistwi->setObjectName(QString::fromUtf8("playlistwi"));
        playlistwi->resize(575, 878);
        playlistwi->setMinimumSize(QSize(575, 878));
        playlistwi->setMaximumSize(QSize(575, 878));
        playlistwi->setStyleSheet(QString::fromUtf8("border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */"));
        verticalLayout = new QVBoxLayout(playlistwi);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 0, 10);
        scrollArea = new QScrollArea(playlistwi);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"\n"
"    background-color: #f7f9fc;\n"
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
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    background-"
                        "color: #f0f3f6; /* \351\232\220\350\227\217\346\273\232\345\212\250\346\235\241\344\270\212\344\270\213\347\256\255\345\244\264 */\n"
"}\n"
"QScrollBar:horizontal {\n"
"    height: 0px; /* \345\205\263\351\224\256\357\274\232\345\260\206\351\253\230\345\272\246\350\256\276\344\270\272 0\357\274\214\344\275\277\346\260\264\345\271\263\346\273\232\345\212\250\346\235\241\344\270\215\345\217\257\350\247\201\344\270\224\344\270\215\345\215\240\347\251\272\351\227\264 */\n"
"    background-color: transparent; /* \345\217\257\351\200\211\357\274\232\350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"}\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 565, 858));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 100));
        widget->setMaximumSize(QSize(16777215, 100));
        widget->setStyleSheet(QString::fromUtf8("background-color: #fafafa;\n"
"/* \345\267\246\344\270\212\350\247\222\345\234\206\350\247\222 12px */\n"
"border-top-left-radius: 12px;\n"
"/* \344\270\212\350\276\271\346\241\206\357\274\2321px \345\256\236\347\272\277\357\274\214\351\242\234\350\211\262\346\257\224\345\246\202 #cccccc */\n"
"border-top: 1px solid #cccccc;\n"
"\n"
"/* \345\267\246\350\276\271\346\241\206\357\274\2321px \345\256\236\347\272\277\357\274\214\351\242\234\350\211\262\346\257\224\345\246\202 #cccccc */\n"
"border-left: 1px solid #cccccc;\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(150, 55));
        label->setMaximumSize(QSize(150, 55));
        label->setStyleSheet(QString::fromUtf8("color: #283248;\n"
"        font-size: 25px;\n"
" border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;\n"
"font-weight: bold;        \n"
"border-top:none;         "));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(240, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clear_btn = new QPushButton(widget);
        clear_btn->setObjectName(QString::fromUtf8("clear_btn"));
        clear_btn->setMinimumSize(QSize(80, 45));
        clear_btn->setMaximumSize(QSize(80, 45));
        clear_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/res/viewswitch/listclear.png);\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));

        horizontalLayout->addWidget(clear_btn);


        verticalLayout_2->addWidget(widget);

        container_wi = new QWidget(scrollAreaWidgetContents);
        container_wi->setObjectName(QString::fromUtf8("container_wi"));
        container_wi->setStyleSheet(QString::fromUtf8("#container_wi{\n"
"background-color: #fafafa;\n"
"background-color: #fafafa;\n"
"border-bottom-left-radius: 12px; \n"
"/* \345\267\246\350\276\271\346\241\206\357\274\2321px \345\256\236\347\272\277\357\274\214\351\242\234\350\211\262\346\257\224\345\246\202 #cccccc */\n"
"border-left: 1px solid #cccccc;\n"
"/* \344\270\213\350\276\271\346\241\206\357\274\2321px \345\256\236\347\272\277\357\274\214\351\242\234\350\211\262\346\257\224\345\246\202 #cccccc */\n"
"border-bottom: 1px solid #cccccc;\n"
"}"));

        verticalLayout_2->addWidget(container_wi);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(playlistwi);

        QMetaObject::connectSlotsByName(playlistwi);
    } // setupUi

    void retranslateUi(QDialog *playlistwi)
    {
        playlistwi->setWindowTitle(QCoreApplication::translate("playlistwi", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("playlistwi", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        clear_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class playlistwi: public Ui_playlistwi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTWI_H
