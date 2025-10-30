/********************************************************************************
** Form generated from reading UI file 'searchwi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWI_H
#define UI_SEARCHWI_H

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

class Ui_Searchwi
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_head;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_head_u;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_searchText;
    QWidget *widget_head_d;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_song_2;
    QPushButton *pushButton_song;
    QPushButton *pushButton_song_3;
    QPushButton *pushButton_song_4;
    QPushButton *pushButton_song_5;
    QPushButton *pushButton_song_6;
    QPushButton *pushButton_song_7;
    QPushButton *pushButton_song_8;
    QPushButton *pushButton_song_9;
    QPushButton *pushButton_song_10;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_playAll;
    QPushButton *pushButton_favoriteAll;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *line;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QListView *m_listView;

    void setupUi(QWidget *Searchwi)
    {
        if (Searchwi->objectName().isEmpty())
            Searchwi->setObjectName(QString::fromUtf8("Searchwi"));
        Searchwi->resize(1259, 898);
        Searchwi->setMinimumSize(QSize(1259, 898));
        Searchwi->setMaximumSize(QSize(1259, 898));
        Searchwi->setStyleSheet(QString::fromUtf8("\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    background-color: #f7f9fc;\n"
""));
        verticalLayout = new QVBoxLayout(Searchwi);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 20, 0, 0);
        widget = new QWidget(Searchwi);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 180));
        widget->setMaximumSize(QSize(16777215, 180));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 180));
        widget_2->setMaximumSize(QSize(16777215, 180));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 10, 0);
        widget_head = new QWidget(widget_2);
        widget_head->setObjectName(QString::fromUtf8("widget_head"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_head->sizePolicy().hasHeightForWidth());
        widget_head->setSizePolicy(sizePolicy);
        widget_head->setMinimumSize(QSize(0, 180));
        widget_head->setMaximumSize(QSize(16777215, 180));
        widget_head->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setBold(false);
        font.setItalic(false);
        widget_head->setFont(font);
        widget_head->setStyleSheet(QString::fromUtf8("background-color: #F7F9FC;"));
        verticalLayout_4 = new QVBoxLayout(widget_head);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_head_u = new QWidget(widget_head);
        widget_head_u->setObjectName(QString::fromUtf8("widget_head_u"));
        widget_head_u->setMinimumSize(QSize(0, 60));
        widget_head_u->setMaximumSize(QSize(16777215, 60));
        verticalLayout_3 = new QVBoxLayout(widget_head_u);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(50, 0, 0, 0);
        label_searchText = new QLabel(widget_head_u);
        label_searchText->setObjectName(QString::fromUtf8("label_searchText"));
        label_searchText->setMinimumSize(QSize(800, 60));
        label_searchText->setMaximumSize(QSize(800, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setBold(true);
        label_searchText->setFont(font1);
        label_searchText->setStyleSheet(QString::fromUtf8(" color: #283270;\n"
"    font-family: \"Microsoft YaHei\";\n"
"    font-size: 30px;  /* \345\267\262\346\267\273\345\212\240\347\232\204\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: bold;  /* \345\255\227\344\275\223\345\212\240\347\262\227 */"));

        verticalLayout_3->addWidget(label_searchText);


        verticalLayout_4->addWidget(widget_head_u);

        widget_head_d = new QWidget(widget_head);
        widget_head_d->setObjectName(QString::fromUtf8("widget_head_d"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_head_d->sizePolicy().hasHeightForWidth());
        widget_head_d->setSizePolicy(sizePolicy1);
        widget_head_d->setMinimumSize(QSize(0, 60));
        widget_head_d->setMaximumSize(QSize(1241212, 60));
        widget_head_d->setStyleSheet(QString::fromUtf8("\n"
"        font-size: 23px;\n"
"       \n"
" font-family: \"Microsoft YaHei\";"));
        horizontalLayout = new QHBoxLayout(widget_head_d);
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(39, 0, 0, 0);
        pushButton_song_2 = new QPushButton(widget_head_d);
        pushButton_song_2->setObjectName(QString::fromUtf8("pushButton_song_2"));
        pushButton_song_2->setMinimumSize(QSize(60, 35));
        pushButton_song_2->setMaximumSize(QSize(60, 35));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setBold(false);
        pushButton_song_2->setFont(font2);
        pushButton_song_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));
        pushButton_song_2->setIconSize(QSize(12, 12));

        horizontalLayout->addWidget(pushButton_song_2);

        pushButton_song = new QPushButton(widget_head_d);
        pushButton_song->setObjectName(QString::fromUtf8("pushButton_song"));
        pushButton_song->setMinimumSize(QSize(60, 35));
        pushButton_song->setMaximumSize(QSize(60, 35));
        pushButton_song->setFont(font1);
        pushButton_song->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));

        horizontalLayout->addWidget(pushButton_song);

        pushButton_song_3 = new QPushButton(widget_head_d);
        pushButton_song_3->setObjectName(QString::fromUtf8("pushButton_song_3"));
        pushButton_song_3->setMinimumSize(QSize(60, 35));
        pushButton_song_3->setMaximumSize(QSize(60, 35));
        pushButton_song_3->setFont(font2);
        pushButton_song_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));

        horizontalLayout->addWidget(pushButton_song_3);

        pushButton_song_4 = new QPushButton(widget_head_d);
        pushButton_song_4->setObjectName(QString::fromUtf8("pushButton_song_4"));
        pushButton_song_4->setMinimumSize(QSize(60, 35));
        pushButton_song_4->setMaximumSize(QSize(60, 35));
        pushButton_song_4->setFont(font2);
        pushButton_song_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));

        horizontalLayout->addWidget(pushButton_song_4);

        pushButton_song_5 = new QPushButton(widget_head_d);
        pushButton_song_5->setObjectName(QString::fromUtf8("pushButton_song_5"));
        pushButton_song_5->setMinimumSize(QSize(60, 35));
        pushButton_song_5->setMaximumSize(QSize(60, 35));
        pushButton_song_5->setFont(font2);
        pushButton_song_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));

        horizontalLayout->addWidget(pushButton_song_5);

        pushButton_song_6 = new QPushButton(widget_head_d);
        pushButton_song_6->setObjectName(QString::fromUtf8("pushButton_song_6"));
        pushButton_song_6->setMinimumSize(QSize(60, 35));
        pushButton_song_6->setMaximumSize(QSize(60, 35));
        pushButton_song_6->setFont(font2);
        pushButton_song_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));

        horizontalLayout->addWidget(pushButton_song_6);

        pushButton_song_7 = new QPushButton(widget_head_d);
        pushButton_song_7->setObjectName(QString::fromUtf8("pushButton_song_7"));
        pushButton_song_7->setMinimumSize(QSize(60, 35));
        pushButton_song_7->setMaximumSize(QSize(60, 35));
        pushButton_song_7->setFont(font2);
        pushButton_song_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));

        horizontalLayout->addWidget(pushButton_song_7);

        pushButton_song_8 = new QPushButton(widget_head_d);
        pushButton_song_8->setObjectName(QString::fromUtf8("pushButton_song_8"));
        pushButton_song_8->setMinimumSize(QSize(60, 35));
        pushButton_song_8->setMaximumSize(QSize(60, 35));
        pushButton_song_8->setFont(font2);
        pushButton_song_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));

        horizontalLayout->addWidget(pushButton_song_8);

        pushButton_song_9 = new QPushButton(widget_head_d);
        pushButton_song_9->setObjectName(QString::fromUtf8("pushButton_song_9"));
        pushButton_song_9->setMinimumSize(QSize(60, 35));
        pushButton_song_9->setMaximumSize(QSize(60, 35));
        pushButton_song_9->setFont(font2);
        pushButton_song_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));

        horizontalLayout->addWidget(pushButton_song_9);

        pushButton_song_10 = new QPushButton(widget_head_d);
        pushButton_song_10->setObjectName(QString::fromUtf8("pushButton_song_10"));
        pushButton_song_10->setMinimumSize(QSize(60, 35));
        pushButton_song_10->setMaximumSize(QSize(60, 35));
        pushButton_song_10->setFont(font2);
        pushButton_song_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));

        horizontalLayout->addWidget(pushButton_song_10);

        horizontalSpacer = new QSpacerItem(657, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_playAll = new QPushButton(widget_head_d);
        pushButton_playAll->setObjectName(QString::fromUtf8("pushButton_playAll"));
        pushButton_playAll->setMinimumSize(QSize(140, 55));
        pushButton_playAll->setMaximumSize(QSize(140, 55));
        pushButton_playAll->setFont(font1);
        pushButton_playAll->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: #FC3B59;\n"
"	border-radius: 15px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #E33742;\n"
"}"));

        horizontalLayout->addWidget(pushButton_playAll);

        pushButton_favoriteAll = new QPushButton(widget_head_d);
        pushButton_favoriteAll->setObjectName(QString::fromUtf8("pushButton_favoriteAll"));
        pushButton_favoriteAll->setMinimumSize(QSize(140, 55));
        pushButton_favoriteAll->setMaximumSize(QSize(140, 55));
        pushButton_favoriteAll->setFont(font1);
        pushButton_favoriteAll->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #3B4357;\n"
"	background-color: #EAEDF1;\n"
"	border-radius: 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #E2E5E9;\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_favoriteAll);


        verticalLayout_4->addWidget(widget_head_d);

        frame = new QFrame(widget_head);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(frame);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 50));
        widget_3->setMaximumSize(QSize(16777215, 50));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: #F7F9FC;"));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 0, 40, 40));
        label->setMinimumSize(QSize(0, 40));
        label->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;\n"
"            "));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(135, 0, 60, 40));
        label_2->setMinimumSize(QSize(60, 40));
        label_2->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(640, 0, 60, 40));
        label_3->setMinimumSize(QSize(60, 40));
        label_3->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
"        font-size: 20px;\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-weight: normal;\n"
"        background-color: transparent;"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1110, 0, 60, 40));
        label_4->setMinimumSize(QSize(60, 40));
        label_4->setStyleSheet(QString::fromUtf8("color: #8b949e;\n"
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

        horizontalLayout_3->addWidget(widget_3);


        verticalLayout_4->addWidget(frame);


        horizontalLayout_2->addWidget(widget_head);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_5->addWidget(widget_2);


        verticalLayout->addWidget(widget);

        widget_4 = new QWidget(Searchwi);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 0));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(300, 270));
        label_5->setMaximumSize(QSize(300, 270));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/res/viewswitch/kong1.png);\n"
"  border: none;\n"
" \n"
"    background-color: transparent;"));

        horizontalLayout_4->addWidget(label_5);


        verticalLayout->addWidget(widget_4);

        scrollArea = new QScrollArea(Searchwi);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1259, 416));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        m_listView = new QListView(scrollAreaWidgetContents);
        m_listView->setObjectName(QString::fromUtf8("m_listView"));
        m_listView->setStyleSheet(QString::fromUtf8(" border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    background-color: #f0f3f6;\n"
""));

        verticalLayout_2->addWidget(m_listView);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Searchwi);

        QMetaObject::connectSlotsByName(Searchwi);
    } // setupUi

    void retranslateUi(QWidget *Searchwi)
    {
        Searchwi->setWindowTitle(QCoreApplication::translate("Searchwi", "Form", nullptr));
        label_searchText->setText(QCoreApplication::translate("Searchwi", "\346\240\207\351\242\230", nullptr));
        pushButton_song_2->setText(QCoreApplication::translate("Searchwi", "\347\273\274\345\220\210", nullptr));
        pushButton_song->setText(QCoreApplication::translate("Searchwi", "\345\215\225\346\233\262", nullptr));
        pushButton_song_3->setText(QCoreApplication::translate("Searchwi", "\346\255\214\345\215\225", nullptr));
        pushButton_song_4->setText(QCoreApplication::translate("Searchwi", "\346\255\214\346\211\213", nullptr));
        pushButton_song_5->setText(QCoreApplication::translate("Searchwi", "\345\243\260\351\237\263", nullptr));
        pushButton_song_6->setText(QCoreApplication::translate("Searchwi", "\346\222\255\345\256\242", nullptr));
        pushButton_song_7->setText(QCoreApplication::translate("Searchwi", "\346\255\214\350\257\215", nullptr));
        pushButton_song_8->setText(QCoreApplication::translate("Searchwi", "\344\270\223\350\276\221", nullptr));
        pushButton_song_9->setText(QCoreApplication::translate("Searchwi", "MV", nullptr));
        pushButton_song_10->setText(QCoreApplication::translate("Searchwi", "\347\224\250\346\210\267", nullptr));
        pushButton_playAll->setText(QCoreApplication::translate("Searchwi", "\346\222\255\346\224\276\345\205\250\351\203\250", nullptr));
        pushButton_favoriteAll->setText(QCoreApplication::translate("Searchwi", "\346\224\266\350\227\217\345\205\250\351\203\250", nullptr));
        label->setText(QCoreApplication::translate("Searchwi", "#", nullptr));
        label_2->setText(QCoreApplication::translate("Searchwi", "\346\240\207\351\242\230", nullptr));
        label_3->setText(QCoreApplication::translate("Searchwi", "\344\270\223\350\276\221", nullptr));
        label_4->setText(QCoreApplication::translate("Searchwi", "\346\227\266\351\225\277", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Searchwi: public Ui_Searchwi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWI_H
