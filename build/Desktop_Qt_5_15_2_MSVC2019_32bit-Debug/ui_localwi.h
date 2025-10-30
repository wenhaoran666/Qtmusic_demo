/********************************************************************************
** Form generated from reading UI file 'localwi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALWI_H
#define UI_LOCALWI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Localwi
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *localwihead_wi;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *leftlocalwihead_wi;
    QLabel *label_listName;
    QPushButton *playall_btn;
    QPushButton *reload_btn;
    QPushButton *pushButton_utils;
    QLabel *count_lb;
    QWidget *rightlocalwihead_wi;
    QPushButton *content_btn;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QFrame *line;
    QWidget *container_wi;

    void setupUi(QWidget *Localwi)
    {
        if (Localwi->objectName().isEmpty())
            Localwi->setObjectName(QString::fromUtf8("Localwi"));
        Localwi->resize(1259, 898);
        Localwi->setMinimumSize(QSize(1259, 898));
        Localwi->setMaximumSize(QSize(1259, 898));
        verticalLayout = new QVBoxLayout(Localwi);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 10, 0, 0);
        scrollArea = new QScrollArea(Localwi);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1259, 888));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        localwihead_wi = new QWidget(scrollAreaWidgetContents);
        localwihead_wi->setObjectName(QString::fromUtf8("localwihead_wi"));
        localwihead_wi->setMinimumSize(QSize(0, 180));
        localwihead_wi->setMaximumSize(QSize(16777215, 180));
        localwihead_wi->setStyleSheet(QString::fromUtf8("background-color: #F7F9FC;"));
        horizontalLayout = new QHBoxLayout(localwihead_wi);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        leftlocalwihead_wi = new QWidget(localwihead_wi);
        leftlocalwihead_wi->setObjectName(QString::fromUtf8("leftlocalwihead_wi"));
        leftlocalwihead_wi->setMinimumSize(QSize(570, 0));
        leftlocalwihead_wi->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"       border-radius: 8px;\n"
"      background-color: #f0f3f6;\n"
"      color: black;\n"
"   }\n"
"   QPushButton:hover {\n"
"     background-color: #e4e8ec;\n"
"    }\n"
"  QPushButton:checked {\n"
"    background-color: #fc3c4d;\n"
"    }"));
        label_listName = new QLabel(leftlocalwihead_wi);
        label_listName->setObjectName(QString::fromUtf8("label_listName"));
        label_listName->setGeometry(QRect(0, 0, 135, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setBold(true);
        label_listName->setFont(font);
        label_listName->setStyleSheet(QString::fromUtf8(" color: #283248;\n"
"        font-size: 33px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;\n"
"font-weight: bold;                 "));
        playall_btn = new QPushButton(leftlocalwihead_wi);
        playall_btn->setObjectName(QString::fromUtf8("playall_btn"));
        playall_btn->setGeometry(QRect(0, 70, 140, 55));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        playall_btn->setFont(font1);
        playall_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FC3B59;\n"
"    background-image: url(:/res/viewswitch/playall1.png);  /* \351\273\230\350\256\244\347\212\266\346\200\201\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: #e33550;\n"
"    background-image: url(:/res/viewswitch/playall2.png);  /* \351\274\240\346\240\207\346\202\254\346\265\256\346\227\266\346\230\276\347\244\272\347\232\204\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
" background-color: #eb8491;\n"
"    background-image: url(:/res/viewswitch/playall3.png);    /* \351\200\211\344\270\255\347\212\266\346\200\201\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
""));
        reload_btn = new QPushButton(leftlocalwihead_wi);
        reload_btn->setObjectName(QString::fromUtf8("reload_btn"));
        reload_btn->setGeometry(QRect(160, 70, 55, 55));
        reload_btn->setFont(font1);
        reload_btn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"	background-color: #EAEDF1;\n"
"	background-image: url(:/res/viewswitch/refresh1.png);  /* \351\273\230\350\256\244\347\212\266\346\200\201\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: center center;\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #E2E5E9;\n"
"  background-image: url(:/res/viewswitch/refresh2.png);  /* \351\274\240\346\240\207\346\202\254\346\265\256\346\227\266\346\230\276\347\244\272\347\232\204\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"  background-position: center center;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
" background-color: #eaecf0;\n"
"    background-image: url(:/res/viewswitch/refresh3.png);    /* \351\200\211\344\270\255\347\212\266\346\200\201\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: center center;\n"
"\n"
"}\n"
""));
        pushButton_utils = new QPushButton(leftlocalwihead_wi);
        pushButton_utils->setObjectName(QString::fromUtf8("pushButton_utils"));
        pushButton_utils->setGeometry(QRect(235, 70, 55, 55));
        QFont font2;
        font2.setPointSize(4);
        font2.setBold(true);
        pushButton_utils->setFont(font2);
        pushButton_utils->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #3B4357;\n"
"	background-color: #EAEDF1;\n"
"	border-radius: 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #E2E5E9;\n"
"}\n"
"QPushButton:pressed {\n"
" background-color: #eaecf0;\n"
"}\n"
""));
        count_lb = new QLabel(leftlocalwihead_wi);
        count_lb->setObjectName(QString::fromUtf8("count_lb"));
        count_lb->setGeometry(QRect(145, 20, 70, 22));
        count_lb->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));

        horizontalLayout->addWidget(leftlocalwihead_wi);

        rightlocalwihead_wi = new QWidget(localwihead_wi);
        rightlocalwihead_wi->setObjectName(QString::fromUtf8("rightlocalwihead_wi"));
        rightlocalwihead_wi->setMinimumSize(QSize(590, 0));
        rightlocalwihead_wi->setMaximumSize(QSize(16777215, 16777215));
        content_btn = new QPushButton(rightlocalwihead_wi);
        content_btn->setObjectName(QString::fromUtf8("content_btn"));
        content_btn->setGeometry(QRect(460, 10, 131, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font3.setPointSize(10);
        font3.setBold(true);
        content_btn->setFont(font3);
        content_btn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	color: rgb(54, 93, 178);\n"
"}\n"
"QPushButton{\n"
"	border: none;\n"
" 	color: rgb(89,117,178);\n"
"}"));
        frame = new QFrame(rightlocalwihead_wi);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(280, 80, 300, 41));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: #ffffff;\n"
"	border-radius: 20px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_3 = new QRadioButton(frame);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setMinimumSize(QSize(60, 36));
        radioButton_3->setMaximumSize(QSize(60, 36));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font4.setPointSize(10);
        font4.setBold(false);
        radioButton_3->setFont(font4);
        radioButton_3->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	color : rgb(190,195,202);\n"
"	background-color: #ffffff;\n"
"	border-radius: 18px;\n"
"}\n"
"QRadioButton:checked{\n"
"	color: rgb(120,127,141);\n"
"	background-color: rgb(242,243,244);\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"	width:0px;\n"
"	height:0px;\n"
"	border:none;\n"
"}\n"
""));
        radioButton_3->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_3);

        radioButton_5 = new QRadioButton(frame);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setMinimumSize(QSize(60, 36));
        radioButton_5->setMaximumSize(QSize(60, 36));
        radioButton_5->setFont(font4);
        radioButton_5->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	color : rgb(190,195,202);\n"
"	background-color: #ffffff;\n"
"	border-radius: 18px;\n"
"}\n"
"QRadioButton:checked{\n"
"	color: rgb(120,127,141);\n"
"	background-color: rgb(242,243,244);\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"	width:0px;\n"
"	height:0px;\n"
"	border:none;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(radioButton_5);

        radioButton_4 = new QRadioButton(frame);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setMinimumSize(QSize(60, 36));
        radioButton_4->setMaximumSize(QSize(60, 36));
        radioButton_4->setFont(font4);
        radioButton_4->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	color : rgb(190,195,202);\n"
"	background-color: #ffffff;\n"
"	border-radius: 18px;\n"
"}\n"
"QRadioButton:checked{\n"
"	color: rgb(120,127,141);\n"
"	background-color: rgb(242,243,244);\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"	width:0px;\n"
"	height:0px;\n"
"	border:none;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(radioButton_4);

        radioButton_2 = new QRadioButton(frame);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setMinimumSize(QSize(80, 36));
        radioButton_2->setMaximumSize(QSize(80, 36));
        radioButton_2->setFont(font4);
        radioButton_2->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	color : rgb(190,195,202);\n"
"	background-color: #ffffff;\n"
"	border-radius: 18px;\n"
"}\n"
"QRadioButton:checked{\n"
"	color: rgb(120,127,141);\n"
"	background-color: rgb(242,243,244);\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"	width:0px;\n"
"	height:0px;\n"
"	border:none;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(radioButton_2);


        horizontalLayout->addWidget(rightlocalwihead_wi);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(localwihead_wi);

        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 50));
        widget->setMaximumSize(QSize(16777215, 50));
        widget->setStyleSheet(QString::fromUtf8("background-color: #F7F9FC;"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 0, 40, 40));
        label->setMinimumSize(QSize(0, 40));
        label->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;\n"
"            "));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(135, 0, 60, 40));
        label_2->setMinimumSize(QSize(60, 40));
        label_2->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(660, 0, 60, 40));
        label_3->setMinimumSize(QSize(60, 40));
        label_3->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(990, 0, 60, 40));
        label_4->setMinimumSize(QSize(60, 40));
        label_4->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1105, 0, 60, 40));
        label_5->setMinimumSize(QSize(60, 40));
        label_5->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));
        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(52, 49, 1146, 1));
        line->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #d2d6dc;\n"
"    height: 1px;\n"
"    border: none;\n"
"}\n"
""));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(widget);

        container_wi = new QWidget(scrollAreaWidgetContents);
        container_wi->setObjectName(QString::fromUtf8("container_wi"));
        container_wi->setStyleSheet(QString::fromUtf8("background-color: #F7F9FC;"));

        verticalLayout_2->addWidget(container_wi);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Localwi);

        QMetaObject::connectSlotsByName(Localwi);
    } // setupUi

    void retranslateUi(QWidget *Localwi)
    {
        Localwi->setWindowTitle(QCoreApplication::translate("Localwi", "Form", nullptr));
        label_listName->setText(QCoreApplication::translate("Localwi", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        playall_btn->setText(QString());
        reload_btn->setText(QString());
        pushButton_utils->setText(QCoreApplication::translate("Localwi", "* * *", nullptr));
        count_lb->setText(QCoreApplication::translate("Localwi", "\345\205\26116\351\246\226", nullptr));
        content_btn->setText(QCoreApplication::translate("Localwi", "\351\200\211\346\213\251\347\233\256\345\275\225 >", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Localwi", "\351\273\230\350\256\244", nullptr));
        radioButton_5->setText(QCoreApplication::translate("Localwi", "\346\255\214\346\211\213", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Localwi", "\344\270\223\350\276\221", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Localwi", "\346\226\207\344\273\266\345\244\271", nullptr));
        label->setText(QCoreApplication::translate("Localwi", "#", nullptr));
        label_2->setText(QCoreApplication::translate("Localwi", "\346\240\207\351\242\230", nullptr));
        label_3->setText(QCoreApplication::translate("Localwi", "\344\270\223\350\276\221", nullptr));
        label_4->setText(QCoreApplication::translate("Localwi", "\346\227\266\351\225\277", nullptr));
        label_5->setText(QCoreApplication::translate("Localwi", "\345\244\247\345\260\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Localwi: public Ui_Localwi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALWI_H
