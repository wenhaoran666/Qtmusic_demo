/********************************************************************************
** Form generated from reading UI file 'listmusicitemwi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTMUSICITEMWI_H
#define UI_LISTMUSICITEMWI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Listmusicitemwi
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widgetMusicItem_wi;
    QPushButton *index_btn;
    QLabel *icon_lb;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *songname_lb;
    QLabel *composer_lb;
    QLabel *duration_lb;

    void setupUi(QWidget *Listmusicitemwi)
    {
        if (Listmusicitemwi->objectName().isEmpty())
            Listmusicitemwi->setObjectName(QString::fromUtf8("Listmusicitemwi"));
        Listmusicitemwi->resize(575, 90);
        Listmusicitemwi->setMinimumSize(QSize(563, 90));
        Listmusicitemwi->setMaximumSize(QSize(575, 92));
        horizontalLayout = new QHBoxLayout(Listmusicitemwi);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 0, 0, 0);
        widgetMusicItem_wi = new QWidget(Listmusicitemwi);
        widgetMusicItem_wi->setObjectName(QString::fromUtf8("widgetMusicItem_wi"));
        widgetMusicItem_wi->setMinimumSize(QSize(563, 90));
        widgetMusicItem_wi->setMaximumSize(QSize(563, 90));
        widgetMusicItem_wi->setStyleSheet(QString::fromUtf8("#widgetMusicItem_wi {\n"
"	border-radius: 15px;\n"
"}\n"
"#widgetMusicItem_wi:hover{\n"
"	background-color: #ffffff;\n"
" border: 1px solid #cccccc;       /* \346\267\273\345\212\240 1px \347\201\260\350\211\262\345\256\236\347\272\277\350\276\271\346\241\206 */\n"
"}"));
        index_btn = new QPushButton(widgetMusicItem_wi);
        index_btn->setObjectName(QString::fromUtf8("index_btn"));
        index_btn->setGeometry(QRect(17, 25, 40, 40));
        index_btn->setMinimumSize(QSize(40, 40));
        index_btn->setMaximumSize(QSize(40, 40));
        index_btn->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"         font-weight: 500;\n"
"        background-color: transparent;"));
        icon_lb = new QLabel(widgetMusicItem_wi);
        icon_lb->setObjectName(QString::fromUtf8("icon_lb"));
        icon_lb->setGeometry(QRect(80, 10, 70, 70));
        icon_lb->setMinimumSize(QSize(70, 70));
        icon_lb->setMaximumSize(QSize(70, 70));
        icon_lb->setStyleSheet(QString::fromUtf8("border: none;\n"
"   border-radius: 20px;\n"
"    background-color: transparent;"));
        widget = new QWidget(widgetMusicItem_wi);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(173, 15, 270, 60));
        widget->setMinimumSize(QSize(270, 60));
        widget->setMaximumSize(QSize(270, 60));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        songname_lb = new QLabel(widget);
        songname_lb->setObjectName(QString::fromUtf8("songname_lb"));
        songname_lb->setStyleSheet(QString::fromUtf8("color: #283248;\n"
"        font-size: 21px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));

        verticalLayout->addWidget(songname_lb);

        composer_lb = new QLabel(widget);
        composer_lb->setObjectName(QString::fromUtf8("composer_lb"));
        composer_lb->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));

        verticalLayout->addWidget(composer_lb);

        duration_lb = new QLabel(widgetMusicItem_wi);
        duration_lb->setObjectName(QString::fromUtf8("duration_lb"));
        duration_lb->setGeometry(QRect(471, 25, 60, 40));
        duration_lb->setMinimumSize(QSize(60, 40));
        duration_lb->setMaximumSize(QSize(60, 40));
        duration_lb->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"     font-weight: 500;\n"
"        background-color: transparent;"));

        horizontalLayout->addWidget(widgetMusicItem_wi);


        retranslateUi(Listmusicitemwi);

        QMetaObject::connectSlotsByName(Listmusicitemwi);
    } // setupUi

    void retranslateUi(QWidget *Listmusicitemwi)
    {
        Listmusicitemwi->setWindowTitle(QCoreApplication::translate("Listmusicitemwi", "Form", nullptr));
        index_btn->setText(QString());
        icon_lb->setText(QCoreApplication::translate("Listmusicitemwi", "TextLabel", nullptr));
        songname_lb->setText(QCoreApplication::translate("Listmusicitemwi", "\346\255\214\346\233\262\345\220\215", nullptr));
        composer_lb->setText(QCoreApplication::translate("Listmusicitemwi", "\344\275\234\350\200\205", nullptr));
        duration_lb->setText(QCoreApplication::translate("Listmusicitemwi", "\346\227\266\351\225\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Listmusicitemwi: public Ui_Listmusicitemwi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTMUSICITEMWI_H
