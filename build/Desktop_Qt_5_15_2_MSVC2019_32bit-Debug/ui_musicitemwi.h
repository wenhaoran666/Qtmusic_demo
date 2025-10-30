/********************************************************************************
** Form generated from reading UI file 'musicitemwi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICITEMWI_H
#define UI_MUSICITEMWI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicItemwi
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widgetMusicItem_wi;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *index_btn;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *songname_lb;
    QLabel *composer_lb;
    QSpacerItem *horizontalSpacer_3;
    QLabel *album_lb;
    QSpacerItem *horizontalSpacer_4;
    QLabel *duration_lb;
    QSpacerItem *horizontalSpacer_5;
    QLabel *size_lb;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *MusicItemwi)
    {
        if (MusicItemwi->objectName().isEmpty())
            MusicItemwi->setObjectName(QString::fromUtf8("MusicItemwi"));
        MusicItemwi->resize(1170, 80);
        MusicItemwi->setMinimumSize(QSize(1170, 80));
        MusicItemwi->setMaximumSize(QSize(1170, 80));
        MusicItemwi->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: transparent;\n"
"border-radius: 15px;"));
        horizontalLayout = new QHBoxLayout(MusicItemwi);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widgetMusicItem_wi = new QWidget(MusicItemwi);
        widgetMusicItem_wi->setObjectName(QString::fromUtf8("widgetMusicItem_wi"));
        widgetMusicItem_wi->setMinimumSize(QSize(1150, 80));
        widgetMusicItem_wi->setMaximumSize(QSize(1150, 80));
        widgetMusicItem_wi->setStyleSheet(QString::fromUtf8("#widgetMusicItem_wi {\n"
"	border-radius: 15px;\n"
"}\n"
"#widgetMusicItem_wi:hover{\n"
"	background-color: #FFFFFF;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widgetMusicItem_wi);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_7 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        index_btn = new QPushButton(widgetMusicItem_wi);
        index_btn->setObjectName(QString::fromUtf8("index_btn"));
        index_btn->setMinimumSize(QSize(40, 40));
        index_btn->setMaximumSize(QSize(40, 40));
        index_btn->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"         font-weight: 500;\n"
"        background-color: transparent;"));

        horizontalLayout_2->addWidget(index_btn);

        horizontalSpacer_2 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        widget = new QWidget(widgetMusicItem_wi);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(340, 60));
        widget->setMaximumSize(QSize(340, 60));
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


        horizontalLayout_2->addWidget(widget);

        horizontalSpacer_3 = new QSpacerItem(176, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        album_lb = new QLabel(widgetMusicItem_wi);
        album_lb->setObjectName(QString::fromUtf8("album_lb"));
        album_lb->setMinimumSize(QSize(300, 40));
        album_lb->setMaximumSize(QSize(300, 40));
        album_lb->setStyleSheet(QString::fromUtf8("color: #283248;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));

        horizontalLayout_2->addWidget(album_lb);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        duration_lb = new QLabel(widgetMusicItem_wi);
        duration_lb->setObjectName(QString::fromUtf8("duration_lb"));
        duration_lb->setMinimumSize(QSize(60, 40));
        duration_lb->setMaximumSize(QSize(60, 40));
        duration_lb->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"     font-weight: 500;\n"
"        background-color: transparent;"));

        horizontalLayout_2->addWidget(duration_lb);

        horizontalSpacer_5 = new QSpacerItem(45, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        size_lb = new QLabel(widgetMusicItem_wi);
        size_lb->setObjectName(QString::fromUtf8("size_lb"));
        size_lb->setMinimumSize(QSize(60, 40));
        size_lb->setMaximumSize(QSize(60, 40));
        size_lb->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 19px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));

        horizontalLayout_2->addWidget(size_lb);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        horizontalLayout->addWidget(widgetMusicItem_wi);


        retranslateUi(MusicItemwi);

        QMetaObject::connectSlotsByName(MusicItemwi);
    } // setupUi

    void retranslateUi(QWidget *MusicItemwi)
    {
        MusicItemwi->setWindowTitle(QCoreApplication::translate("MusicItemwi", "Form", nullptr));
        index_btn->setText(QCoreApplication::translate("MusicItemwi", "01", nullptr));
        songname_lb->setText(QCoreApplication::translate("MusicItemwi", "\346\255\214\346\233\262\345\220\215", nullptr));
        composer_lb->setText(QCoreApplication::translate("MusicItemwi", "\344\275\234\350\200\205", nullptr));
        album_lb->setText(QCoreApplication::translate("MusicItemwi", "\344\270\223\350\276\221", nullptr));
        duration_lb->setText(QCoreApplication::translate("MusicItemwi", "\346\227\266\351\225\277", nullptr));
        size_lb->setText(QCoreApplication::translate("MusicItemwi", "\345\244\247\345\260\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicItemwi: public Ui_MusicItemwi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICITEMWI_H
