/********************************************************************************
** Form generated from reading UI file 'musicplayerwi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICPLAYERWI_H
#define UI_MUSICPLAYERWI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <recordwi.h>
#include <statepushbutton.h>

QT_BEGIN_NAMESPACE

class Ui_Musicplayerwi
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    RecordWi *record_wi;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QLabel *songinfo_lb;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *collect_btn;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *barcontrol_wi;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *love_btn;
    QPushButton *forward_btn;
    StatePushbutton *pause_btn;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *retreat_btn;
    QPushButton *order_btn;
    QSpacerItem *horizontalSpacer_2;
    QWidget *progressbar_wi;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lefttime_lb;
    QSpacerItem *horizontalSpacer_8;
    QSlider *bar_sl;
    QSpacerItem *horizontalSpacer_9;
    QLabel *righttime_lb;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *volume_btn;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *list_btn;

    void setupUi(QWidget *Musicplayerwi)
    {
        if (Musicplayerwi->objectName().isEmpty())
            Musicplayerwi->setObjectName(QString::fromUtf8("Musicplayerwi"));
        Musicplayerwi->resize(1564, 120);
        Musicplayerwi->setStyleSheet(QString::fromUtf8("border-top: 1px solid #e0e0e0;     /* \344\270\212\350\276\271\346\241\206\357\274\232\346\265\205\347\201\260\350\211\262\357\274\2141\345\203\217\347\264\240\345\256\236\347\272\277 */\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(Musicplayerwi);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Musicplayerwi);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(540, 0));
        widget->setMaximumSize(QSize(540, 16777215));
        widget->setStyleSheet(QString::fromUtf8("background-color: #fafafa;\n"
"border-bottom-left-radius: 12px; \n"
"border-top: 1px solid #e0e0e0;     /* \344\270\212\350\276\271\346\241\206\357\274\232\346\265\205\347\201\260\350\211\262\357\274\2141\345\203\217\347\264\240\345\256\236\347\272\277 */\n"
""));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        record_wi = new RecordWi(widget);
        record_wi->setObjectName(QString::fromUtf8("record_wi"));
        record_wi->setMinimumSize(QSize(100, 100));
        record_wi->setMaximumSize(QSize(100, 100));
        record_wi->setStyleSheet(QString::fromUtf8("border-top:none;"));

        horizontalLayout_6->addWidget(record_wi);

        widget_7 = new QWidget(widget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(widget_7);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        widget_8 = new QWidget(widget_7);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMaximumSize(QSize(16777215, 45));
        widget_8->setStyleSheet(QString::fromUtf8("border-top:none;"));
        horizontalLayout_7 = new QHBoxLayout(widget_8);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        songinfo_lb = new QLabel(widget_8);
        songinfo_lb->setObjectName(QString::fromUtf8("songinfo_lb"));
        songinfo_lb->setMinimumSize(QSize(0, 40));
        songinfo_lb->setMaximumSize(QSize(16777215, 40));
        songinfo_lb->setStyleSheet(QString::fromUtf8("border-top:none;\n"
"color: #283248;\n"
"        font-size: 24px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));

        horizontalLayout_7->addWidget(songinfo_lb);


        verticalLayout_2->addWidget(widget_8);

        widget_9 = new QWidget(widget_7);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setMaximumSize(QSize(16777215, 50));
        widget_9->setStyleSheet(QString::fromUtf8("border-top:none;"));
        horizontalLayout_8 = new QHBoxLayout(widget_9);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        collect_btn = new QPushButton(widget_9);
        collect_btn->setObjectName(QString::fromUtf8("collect_btn"));
        collect_btn->setMinimumSize(QSize(40, 40));
        collect_btn->setMaximumSize(QSize(40, 40));
        collect_btn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"	background-image: url(:/res/viewswitch/collect1.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:hover {\n"
"  	background-image: url(:/res/viewswitch/collect2.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:pressed {\n"
" 	background-image: url(:/res/viewswitch/collect3.png);  \n"
"    background-position: center center;\n"
"}"));

        horizontalLayout_8->addWidget(collect_btn);

        horizontalSpacer_6 = new QSpacerItem(300, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        verticalLayout_2->addWidget(widget_9);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_6->addWidget(widget_7);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(Musicplayerwi);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(600, 0));
        widget_2->setMaximumSize(QSize(600, 16777215));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: #fafafa;\n"
"\n"
"border-top: 1px solid #e0e0e0;     /* \344\270\212\350\276\271\346\241\206\357\274\232\346\265\205\347\201\260\350\211\262\357\274\2141\345\203\217\347\264\240\345\256\236\347\272\277 */\n"
""));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        barcontrol_wi = new QWidget(widget_2);
        barcontrol_wi->setObjectName(QString::fromUtf8("barcontrol_wi"));
        barcontrol_wi->setMinimumSize(QSize(0, 80));
        barcontrol_wi->setMaximumSize(QSize(16777215, 80));
        barcontrol_wi->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(barcontrol_wi);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(110, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget_4 = new QWidget(barcontrol_wi);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("border-top:none;\n"
""));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 15, 0, 0);
        love_btn = new QPushButton(widget_4);
        love_btn->setObjectName(QString::fromUtf8("love_btn"));
        love_btn->setMinimumSize(QSize(40, 40));
        love_btn->setMaximumSize(QSize(40, 40));
        love_btn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"	background-image: url(:/res/viewswitch/love1.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:hover {\n"
"  	background-image: url(:/res/viewswitch/love2.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:pressed {\n"
" 	background-image: url(:/res/viewswitch/love3.png);  \n"
"    background-position: center center;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(love_btn);

        forward_btn = new QPushButton(widget_4);
        forward_btn->setObjectName(QString::fromUtf8("forward_btn"));
        forward_btn->setMinimumSize(QSize(40, 40));
        forward_btn->setMaximumSize(QSize(40, 40));
        forward_btn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"	background-image: url(:/res/viewswitch/forward1.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:hover {\n"
"  	background-image: url(:/res/viewswitch/forward2.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:pressed {\n"
" 	background-image: url(:/res/viewswitch/forward3.png);  \n"
"    background-position: center center;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(forward_btn);


        horizontalLayout_2->addWidget(widget_4);

        pause_btn = new StatePushbutton(barcontrol_wi);
        pause_btn->setObjectName(QString::fromUtf8("pause_btn"));
        pause_btn->setMinimumSize(QSize(70, 70));
        pause_btn->setMaximumSize(QSize(70, 70));
        pause_btn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"	background-image: url(:/res/viewswitch/pause1.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:hover {\n"
"  	background-image: url(:/res/viewswitch/pause2.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:pressed {\n"
" 	background-image: url(:/res/viewswitch/pause3.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:checked {\n"
"    background-image: url(:/res/viewswitch/continue1.png);\n"
"   background-position: center center;\n"
"}\n"
"QPushButton:checked:hover {\n"
"    background-image: url(:/res/viewswitch/continue2.png);\n"
"   background-position: center center;\n"
"}\n"
"QPushButton:checked:pressed {\n"
"    background-image: url(:/res/viewswitch/continue3.png);\n"
"   background-position: center center;\n"
"}"));

        horizontalLayout_2->addWidget(pause_btn);

        widget_5 = new QWidget(barcontrol_wi);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setStyleSheet(QString::fromUtf8("border-top:none;\n"
""));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 13, 0, 0);
        retreat_btn = new QPushButton(widget_5);
        retreat_btn->setObjectName(QString::fromUtf8("retreat_btn"));
        retreat_btn->setMinimumSize(QSize(40, 40));
        retreat_btn->setMaximumSize(QSize(40, 40));
        retreat_btn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"	background-image: url(:/res/viewswitch/retreat1.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:hover {\n"
"  	background-image: url(:/res/viewswitch/retreat2.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:pressed {\n"
" 	background-image: url(:/res/viewswitch/retreat3.png);  \n"
"    background-position: center center;\n"
"}\n"
""));

        horizontalLayout_4->addWidget(retreat_btn);

        order_btn = new QPushButton(widget_5);
        order_btn->setObjectName(QString::fromUtf8("order_btn"));
        order_btn->setMinimumSize(QSize(40, 40));
        order_btn->setMaximumSize(QSize(40, 40));
        order_btn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"	background-image: url(:/res/viewswitch/order1.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:hover {\n"
"  	background-image: url(:/res/viewswitch/order2.png);  \n"
"    background-position: center center;\n"
"}\n"
"QPushButton:pressed {\n"
" 	background-image: url(:/res/viewswitch/order3.png);  \n"
"    background-position: center center;\n"
"}\n"
""));

        horizontalLayout_4->addWidget(order_btn);


        horizontalLayout_2->addWidget(widget_5);

        horizontalSpacer_2 = new QSpacerItem(110, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(barcontrol_wi);

        progressbar_wi = new QWidget(widget_2);
        progressbar_wi->setObjectName(QString::fromUtf8("progressbar_wi"));
        progressbar_wi->setMinimumSize(QSize(0, 30));
        progressbar_wi->setMaximumSize(QSize(16777215, 30));
        progressbar_wi->setStyleSheet(QString::fromUtf8("border-top:none;\n"
""));
        horizontalLayout_9 = new QHBoxLayout(progressbar_wi);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        lefttime_lb = new QLabel(progressbar_wi);
        lefttime_lb->setObjectName(QString::fromUtf8("lefttime_lb"));
        lefttime_lb->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 15px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));

        horizontalLayout_9->addWidget(lefttime_lb);

        horizontalSpacer_8 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        bar_sl = new QSlider(progressbar_wi);
        bar_sl->setObjectName(QString::fromUtf8("bar_sl"));
        bar_sl->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: none;\n"
"    height: 6px;\n"
"    background: #DADCDF;\n"
"    margin: 0px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: white;\n"
"    border: 2px solid #FC3D4D;\n"
"	border: 1px solid #DADCDF;\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -6px 0;\n"
"    border-radius: 9px;\n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"    background: #FC3D4D;\n"
"    border-radius: 3px;\n"
"}"));
        bar_sl->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(bar_sl);

        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        righttime_lb = new QLabel(progressbar_wi);
        righttime_lb->setObjectName(QString::fromUtf8("righttime_lb"));
        righttime_lb->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 15px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));

        horizontalLayout_9->addWidget(righttime_lb);


        verticalLayout->addWidget(progressbar_wi);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout->addWidget(widget_2);

        widget_3 = new QWidget(Musicplayerwi);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("\n"
"background-color: #fafafa;\n"
"border-bottom-right-radius: 12px; \n"
"QPushButton {\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(180, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        volume_btn = new QPushButton(widget_3);
        volume_btn->setObjectName(QString::fromUtf8("volume_btn"));
        volume_btn->setMinimumSize(QSize(40, 40));
        volume_btn->setMaximumSize(QSize(40, 40));
        volume_btn->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{	\n"
"	background-image: url(:/res/viewswitch/volume1.png);  \n"
"    background-position: center center;\n"
"border-top:none;\n"
"}\n"
"QPushButton:hover {\n"
"  	background-image: url(:/res/viewswitch/volume2.png);  \n"
"    background-position: center center;\n"
"border-top:none;\n"
"}\n"
"border-top:none;"));

        horizontalLayout_5->addWidget(volume_btn);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        list_btn = new QPushButton(widget_3);
        list_btn->setObjectName(QString::fromUtf8("list_btn"));
        list_btn->setMinimumSize(QSize(40, 40));
        list_btn->setMaximumSize(QSize(40, 40));
        list_btn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"	background-image: url(:/res/viewswitch/list1.png);  \n"
"    background-position: center center;\n"
"border-top:none;\n"
"}\n"
"QPushButton:hover {\n"
"  	background-image: url(:/res/viewswitch/list2.png);  \n"
"    background-position: center center;\n"
"border-top:none;\n"
"}\n"
"QPushButton:pressed {\n"
" 	background-image: url(:/res/viewswitch/list3.png);  \n"
"    background-position: center center;\n"
"border-top:none;\n"
"}\n"
""));

        horizontalLayout_5->addWidget(list_btn);


        horizontalLayout->addWidget(widget_3);


        retranslateUi(Musicplayerwi);

        QMetaObject::connectSlotsByName(Musicplayerwi);
    } // setupUi

    void retranslateUi(QWidget *Musicplayerwi)
    {
        Musicplayerwi->setWindowTitle(QCoreApplication::translate("Musicplayerwi", "Form", nullptr));
        songinfo_lb->setText(QCoreApplication::translate("Musicplayerwi", "TextLabel", nullptr));
        collect_btn->setText(QString());
        love_btn->setText(QString());
        forward_btn->setText(QString());
        pause_btn->setText(QString());
        retreat_btn->setText(QString());
        order_btn->setText(QString());
        lefttime_lb->setText(QCoreApplication::translate("Musicplayerwi", "0:00", nullptr));
        righttime_lb->setText(QCoreApplication::translate("Musicplayerwi", "0:00", nullptr));
        volume_btn->setText(QString());
        list_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Musicplayerwi: public Ui_Musicplayerwi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYERWI_H
