/********************************************************************************
** Form generated from reading UI file 'likemusicwi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIKEMUSICWI_H
#define UI_LIKEMUSICWI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Likemusicwi
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *icon_lb;
    QWidget *widget_2;
    QLabel *label;
    QPushButton *playall_btn;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QFrame *line;
    QListView *m_listView;

    void setupUi(QWidget *Likemusicwi)
    {
        if (Likemusicwi->objectName().isEmpty())
            Likemusicwi->setObjectName(QString::fromUtf8("Likemusicwi"));
        Likemusicwi->resize(1259, 898);
        Likemusicwi->setMinimumSize(QSize(1259, 898));
        Likemusicwi->setMaximumSize(QSize(1259, 898));
        Likemusicwi->setStyleSheet(QString::fromUtf8("background-color: #F7F9FC;"));
        verticalLayout = new QVBoxLayout(Likemusicwi);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Likemusicwi);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 340));
        widget->setMaximumSize(QSize(16777215, 340));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        icon_lb = new QLabel(widget);
        icon_lb->setObjectName(QString::fromUtf8("icon_lb"));
        icon_lb->setMinimumSize(QSize(250, 250));
        icon_lb->setMaximumSize(QSize(250, 250));
        icon_lb->setStyleSheet(QString::fromUtf8("border-image: url(:/res/head_2.jpg);\n"
"  border: none;\n"
"   border-radius: 20px;\n"
"    background-color: transparent;"));

        horizontalLayout->addWidget(icon_lb);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 50, 250, 50));
        label->setMinimumSize(QSize(250, 50));
        label->setMaximumSize(QSize(250, 50));
        label->setStyleSheet(QString::fromUtf8("color: #283248;\n"
"        font-size: 33px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;\n"
"font-weight: bold;                 "));
        playall_btn = new QPushButton(widget_2);
        playall_btn->setObjectName(QString::fromUtf8("playall_btn"));
        playall_btn->setGeometry(QRect(60, 220, 140, 55));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        playall_btn->setFont(font);
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

        horizontalLayout->addWidget(widget_2);


        verticalLayout->addWidget(widget);

        widget_4 = new QWidget(Likemusicwi);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(200, 280));
        label_6->setMaximumSize(QSize(200, 280));
        label_6->setStyleSheet(QString::fromUtf8("border-image: url(:/res/viewswitch/kong2.png);\n"
"  border: none;\n"
" \n"
"    background-color: transparent;"));

        horizontalLayout_2->addWidget(label_6);


        verticalLayout->addWidget(widget_4);

        scrollArea = new QScrollArea(Likemusicwi);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1259, 278));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 50));
        widget_3->setMaximumSize(QSize(16777215, 50));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: #F7F9FC;"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 0, 40, 40));
        label_2->setMinimumSize(QSize(0, 40));
        label_2->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;\n"
"            "));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(135, 0, 60, 40));
        label_3->setMinimumSize(QSize(60, 40));
        label_3->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(640, 0, 60, 40));
        label_4->setMinimumSize(QSize(60, 40));
        label_4->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1110, 0, 60, 40));
        label_5->setMinimumSize(QSize(60, 40));
        label_5->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));
        line = new QFrame(widget_3);
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

        verticalLayout_2->addWidget(widget_3);

        m_listView = new QListView(scrollAreaWidgetContents);
        m_listView->setObjectName(QString::fromUtf8("m_listView"));
        m_listView->setStyleSheet(QString::fromUtf8(" border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    background-color: #F7F9FC;\n"
""));

        verticalLayout_2->addWidget(m_listView);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Likemusicwi);

        QMetaObject::connectSlotsByName(Likemusicwi);
    } // setupUi

    void retranslateUi(QWidget *Likemusicwi)
    {
        Likemusicwi->setWindowTitle(QCoreApplication::translate("Likemusicwi", "Form", nullptr));
        icon_lb->setText(QString());
        label->setText(QCoreApplication::translate("Likemusicwi", "\346\210\221\345\226\234\346\254\242\347\232\204\351\237\263\344\271\220", nullptr));
        playall_btn->setText(QString());
        label_6->setText(QString());
        label_2->setText(QCoreApplication::translate("Likemusicwi", "#", nullptr));
        label_3->setText(QCoreApplication::translate("Likemusicwi", "\346\240\207\351\242\230", nullptr));
        label_4->setText(QCoreApplication::translate("Likemusicwi", "\344\270\223\350\276\221", nullptr));
        label_5->setText(QCoreApplication::translate("Likemusicwi", "\346\227\266\351\225\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Likemusicwi: public Ui_Likemusicwi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIKEMUSICWI_H
