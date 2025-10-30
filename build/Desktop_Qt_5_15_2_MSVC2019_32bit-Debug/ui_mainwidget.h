/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <likemusicwi.h>
#include <localwi.h>
#include <musicplayerwi.h>
#include <recommendwi.h>
#include <searchwi.h>
#include <songlistwi.h>
#include <statepushbutton.h>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *head_wi;
    QHBoxLayout *horizontalLayout;
    QWidget *logo_wi;
    QWidget *searchlist_wi;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *back_btn;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *search_lin;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *phone_btn;
    QWidget *user_wi;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *usericon_lb;
    QSpacerItem *horizontalSpacer_5;
    QLabel *username_lb;
    QWidget *headutils_wi;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *message_btn;
    QPushButton *setting_btn;
    QPushButton *dress_btn;
    QPushButton *minimize_btn;
    QPushButton *close_btn;
    QWidget *body_wi;
    QVBoxLayout *verticalLayout_2;
    QWidget *mainbody_wi;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *sidebar_wi;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QWidget *shop_wi;
    QVBoxLayout *verticalLayout_4;
    StatePushbutton *recommend_btn;
    StatePushbutton *featured_btn;
    StatePushbutton *podcast_btn;
    StatePushbutton *explore_btn;
    StatePushbutton *follow_btn;
    QSpacerItem *verticalSpacer_3;
    QFrame *line;
    QWidget *my_wid;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    StatePushbutton *favorite_btn;
    StatePushbutton *recent_btn;
    StatePushbutton *local_btn;
    QWidget *widget_6;
    QStackedWidget *pages_wi;
    Recommendwi *recommend_wi;
    Songlistwi *songlist_wi;
    Searchwi *search_wi;
    Localwi *local_wi;
    Likemusicwi *like_wi;
    Musicplayerwi *playbackControlPanel_wi;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(1584, 1128);
        MainWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        head_wi = new QWidget(MainWidget);
        head_wi->setObjectName(QString::fromUtf8("head_wi"));
        head_wi->setMinimumSize(QSize(0, 90));
        head_wi->setMaximumSize(QSize(16777215, 90));
        horizontalLayout = new QHBoxLayout(head_wi);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        logo_wi = new QWidget(head_wi);
        logo_wi->setObjectName(QString::fromUtf8("logo_wi"));
        logo_wi->setMinimumSize(QSize(305, 0));
        logo_wi->setMaximumSize(QSize(305, 16777215));
        logo_wi->setStyleSheet(QString::fromUtf8("background-color: #f0f3f6;\n"
"background-image: url(:/res/logo.png);\n"
"background-position: center center;\n"
"background-repeat: no-repeat;\n"
"border-top-left-radius: 12px; "));

        horizontalLayout->addWidget(logo_wi);

        searchlist_wi = new QWidget(head_wi);
        searchlist_wi->setObjectName(QString::fromUtf8("searchlist_wi"));
        searchlist_wi->setMinimumSize(QSize(420, 0));
        searchlist_wi->setMaximumSize(QSize(600, 16777215));
        searchlist_wi->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 249, 252);"));
        horizontalLayout_5 = new QHBoxLayout(searchlist_wi);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 20, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        back_btn = new QPushButton(searchlist_wi);
        back_btn->setObjectName(QString::fromUtf8("back_btn"));
        back_btn->setMinimumSize(QSize(40, 54));
        back_btn->setMaximumSize(QSize(40, 54));
        back_btn->setStyleSheet(QString::fromUtf8(" \n"
"QPushButton {\n"
"    border: 1px solid #d0d0d0;\n"
"     border-radius: 8px;\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/res/btn_back1.png);\n"
"  \n"
"}\n"
"QPushButton:hover, \n"
"QPushButton:pressed {\n"
"    background-image: url(:/res/btn_back3.png);\n"
"}"));

        horizontalLayout_5->addWidget(back_btn);

        horizontalSpacer_3 = new QSpacerItem(15, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        search_lin = new QLineEdit(searchlist_wi);
        search_lin->setObjectName(QString::fromUtf8("search_lin"));
        search_lin->setMinimumSize(QSize(385, 54));
        search_lin->setMaximumSize(QSize(385, 54));
        search_lin->setStyleSheet(QString::fromUtf8("    QLineEdit {\n"
"    padding-left: 20px; /*\346\234\200\345\267\246\345\217\257\347\274\226\350\276\221*/\n"
"    border-radius: 10px;\n"
"  border: 1px solid #d0d0d0;\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #dbeafe, stop:1 #fce7f3\n"
"    );\n"
"    color: #4b5563;\n"
"    font-size: 22px;\n"
"}\n"
"\n"
"/* \345\215\240\344\275\215\347\254\246\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"QLineEdit:!focus {\n"
"    color: #9ca3af;/* \346\234\252\350\201\232\347\204\246\346\227\266\357\274\214\350\276\223\345\205\245\346\226\207\345\255\227\347\232\204\351\242\234\350\211\262\345\217\230\344\270\272\346\233\264\346\265\205\347\232\204\347\201\260\350\211\262 */\n"
"}"));

        horizontalLayout_5->addWidget(search_lin);

        horizontalSpacer_2 = new QSpacerItem(15, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        phone_btn = new QPushButton(searchlist_wi);
        phone_btn->setObjectName(QString::fromUtf8("phone_btn"));
        phone_btn->setMinimumSize(QSize(54, 54));
        phone_btn->setMaximumSize(QSize(54, 54));
        phone_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                                      stop:0 #f8f1f8, stop:1 #fbe6ee);\n"
"	\n"
"    border: 1px solid #d0d0d0;\n"
"    border-radius: 12px;\n"
"    padding: 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                                      stop:0 #fcdfea, stop:1 #f8c7e1);\n"
"}"));

        horizontalLayout_5->addWidget(phone_btn);


        horizontalLayout->addWidget(searchlist_wi);

        user_wi = new QWidget(head_wi);
        user_wi->setObjectName(QString::fromUtf8("user_wi"));
        user_wi->setMinimumSize(QSize(200, 0));
        user_wi->setMaximumSize(QSize(310, 16777215));
        user_wi->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 249, 252);"));
        horizontalLayout_6 = new QHBoxLayout(user_wi);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 20, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(15, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        usericon_lb = new QLabel(user_wi);
        usericon_lb->setObjectName(QString::fromUtf8("usericon_lb"));
        usericon_lb->setMinimumSize(QSize(50, 50));
        usericon_lb->setMaximumSize(QSize(50, 50));
        usericon_lb->setStyleSheet(QString::fromUtf8("\n"
"     border: 1px solid #aaa;\n"
"       border-radius: 25px;\n"
"       color: white;\n"
"       padding: 5px;\n"
"  \n"
""));

        horizontalLayout_6->addWidget(usericon_lb);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        username_lb = new QLabel(user_wi);
        username_lb->setObjectName(QString::fromUtf8("username_lb"));
        username_lb->setMinimumSize(QSize(0, 50));
        username_lb->setMaximumSize(QSize(16777215, 50));
        username_lb->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(username_lb);


        horizontalLayout->addWidget(user_wi);

        headutils_wi = new QWidget(head_wi);
        headutils_wi->setObjectName(QString::fromUtf8("headutils_wi"));
        headutils_wi->setMinimumSize(QSize(0, 0));
        headutils_wi->setMaximumSize(QSize(380, 16777215));
        headutils_wi->setStyleSheet(QString::fromUtf8("\n"
"	background-color: rgb(247, 249, 252);\n"
"	border-top-right-radius: 12px; \n"
""));
        horizontalLayout_3 = new QHBoxLayout(headutils_wi);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 20, 0, 0);
        message_btn = new QPushButton(headutils_wi);
        message_btn->setObjectName(QString::fromUtf8("message_btn"));
        message_btn->setMinimumSize(QSize(44, 44));
        message_btn->setMaximumSize(QSize(44, 44));
        message_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/res/btn_messageCenter_50.png);\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover, \n"
"QPushButton:pressed {\n"
"    background-image: url(:/res/btn_messageCenter_100.png);\n"
"}"));

        horizontalLayout_3->addWidget(message_btn);

        setting_btn = new QPushButton(headutils_wi);
        setting_btn->setObjectName(QString::fromUtf8("setting_btn"));
        setting_btn->setMinimumSize(QSize(44, 44));
        setting_btn->setMaximumSize(QSize(44, 44));
        setting_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/res/btn_settings_50.png);\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover, \n"
"QPushButton:pressed {\n"
"    background-image: url(:/res/btn_settings_100.png);\n"
"}"));

        horizontalLayout_3->addWidget(setting_btn);

        dress_btn = new QPushButton(headutils_wi);
        dress_btn->setObjectName(QString::fromUtf8("dress_btn"));
        dress_btn->setMinimumSize(QSize(44, 44));
        dress_btn->setMaximumSize(QSize(44, 44));
        dress_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/res/btn_dressUp_50.png);\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover, \n"
"QPushButton:pressed {\n"
"    background-image: url(:/res/btn_dressUp_100.png);\n"
"}"));

        horizontalLayout_3->addWidget(dress_btn);

        minimize_btn = new QPushButton(headutils_wi);
        minimize_btn->setObjectName(QString::fromUtf8("minimize_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(44);
        sizePolicy.setVerticalStretch(44);
        sizePolicy.setHeightForWidth(minimize_btn->sizePolicy().hasHeightForWidth());
        minimize_btn->setSizePolicy(sizePolicy);
        minimize_btn->setMaximumSize(QSize(44, 44));
        minimize_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/res/btn_minimize_50.png);\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover, \n"
"QPushButton:pressed {\n"
"    background-image: url(:/res/btn_minimize_100.png);\n"
"}"));

        horizontalLayout_3->addWidget(minimize_btn);

        close_btn = new QPushButton(headutils_wi);
        close_btn->setObjectName(QString::fromUtf8("close_btn"));
        close_btn->setMinimumSize(QSize(44, 44));
        close_btn->setMaximumSize(QSize(44, 44));
        close_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/res/btn_closeMainWindow_50.png);\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover, \n"
"QPushButton:pressed {\n"
"    background-image: url(:/res/btn_closeMainWindow_100.png);\n"
"}"));

        horizontalLayout_3->addWidget(close_btn);


        horizontalLayout->addWidget(headutils_wi);


        verticalLayout->addWidget(head_wi);

        body_wi = new QWidget(MainWidget);
        body_wi->setObjectName(QString::fromUtf8("body_wi"));
        verticalLayout_2 = new QVBoxLayout(body_wi);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        mainbody_wi = new QWidget(body_wi);
        mainbody_wi->setObjectName(QString::fromUtf8("mainbody_wi"));
        horizontalLayout_2 = new QHBoxLayout(mainbody_wi);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        sidebar_wi = new QScrollArea(mainbody_wi);
        sidebar_wi->setObjectName(QString::fromUtf8("sidebar_wi"));
        sidebar_wi->setMinimumSize(QSize(305, 0));
        sidebar_wi->setMaximumSize(QSize(305, 16777215));
        sidebar_wi->setStyleSheet(QString::fromUtf8("background-color: #f0f3f6;\n"
" border: none;\n"
"\n"
"\n"
"\n"
""));
        sidebar_wi->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 305, 898));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        shop_wi = new QWidget(scrollAreaWidgetContents);
        shop_wi->setObjectName(QString::fromUtf8("shop_wi"));
        shop_wi->setMinimumSize(QSize(0, 350));
        shop_wi->setMaximumSize(QSize(16777215, 350));
        shop_wi->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout_4 = new QVBoxLayout(shop_wi);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(33, 0, 0, 0);
        recommend_btn = new StatePushbutton(shop_wi);
        recommend_btn->setObjectName(QString::fromUtf8("recommend_btn"));
        recommend_btn->setMinimumSize(QSize(250, 54));
        recommend_btn->setMaximumSize(QSize(250, 54));
        recommend_btn->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-image: url(:/res/viewswitch/recommend_w.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"  \n"
"}\n"
"QPushButton:checked {\n"
"    background-image: url(:/res/viewswitch/recommend.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"  \n"
"}"));

        verticalLayout_4->addWidget(recommend_btn);

        featured_btn = new StatePushbutton(shop_wi);
        featured_btn->setObjectName(QString::fromUtf8("featured_btn"));
        featured_btn->setMinimumSize(QSize(250, 54));
        featured_btn->setMaximumSize(QSize(250, 54));
        featured_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-image: url(:/res/viewswitch/featured_w.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"  \n"
"}\n"
"QPushButton:checked {\n"
"    background-image: url(:/res/viewswitch/featured.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"  \n"
"}"));

        verticalLayout_4->addWidget(featured_btn);

        podcast_btn = new StatePushbutton(shop_wi);
        podcast_btn->setObjectName(QString::fromUtf8("podcast_btn"));
        podcast_btn->setMinimumSize(QSize(250, 54));
        podcast_btn->setMaximumSize(QSize(250, 54));
        podcast_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-image: url(:/res/viewswitch/podcast_w.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"  \n"
"}\n"
"QPushButton:checked {\n"
"    background-image: url(:/res/viewswitch/podcast.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"  \n"
"}"));

        verticalLayout_4->addWidget(podcast_btn);

        explore_btn = new StatePushbutton(shop_wi);
        explore_btn->setObjectName(QString::fromUtf8("explore_btn"));
        explore_btn->setMinimumSize(QSize(250, 54));
        explore_btn->setMaximumSize(QSize(250, 54));
        explore_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-image: url(:/res/viewswitch/explore_w.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"  \n"
"}\n"
"QPushButton:checked {\n"
"    background-image: url(:/res/viewswitch/explore.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"  \n"
"}"));

        verticalLayout_4->addWidget(explore_btn);

        follow_btn = new StatePushbutton(shop_wi);
        follow_btn->setObjectName(QString::fromUtf8("follow_btn"));
        follow_btn->setMinimumSize(QSize(250, 54));
        follow_btn->setMaximumSize(QSize(250, 54));
        follow_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-image: url(:/res/viewswitch/follow_w.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"  \n"
"}\n"
"QPushButton:checked {\n"
"    background-image: url(:/res/viewswitch/follow.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"  \n"
"}"));

        verticalLayout_4->addWidget(follow_btn);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_3);

        line = new QFrame(shop_wi);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(150, 0));
        line->setMaximumSize(QSize(230, 1));
        line->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #dbdfe4;\n"
"    height: 1px;\n"
"    border: none;\n"
"}\n"
""));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);


        verticalLayout_3->addWidget(shop_wi);

        my_wid = new QWidget(scrollAreaWidgetContents);
        my_wid->setObjectName(QString::fromUtf8("my_wid"));
        my_wid->setMinimumSize(QSize(0, 300));
        my_wid->setMaximumSize(QSize(16777215, 300));
        my_wid->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout_5 = new QVBoxLayout(my_wid);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(33, 0, 0, 0);
        label = new QLabel(my_wid);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(250, 54));
        label->setMaximumSize(QSize(250, 54));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"   background-image: url(:/res/viewswitch/my.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
""));

        verticalLayout_5->addWidget(label);

        favorite_btn = new StatePushbutton(my_wid);
        favorite_btn->setObjectName(QString::fromUtf8("favorite_btn"));
        favorite_btn->setMinimumSize(QSize(250, 54));
        favorite_btn->setMaximumSize(QSize(250, 54));
        favorite_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-image: url(:/res/viewswitch/favorite1.png);  /* \351\273\230\350\256\244\347\212\266\346\200\201\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-image: url(:/res/viewswitch/favorite.png);  /* \351\274\240\346\240\207\346\202\254\346\265\256\346\227\266\346\230\276\347\244\272\347\232\204\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-image: url(:/res/viewswitch/favorite2.png);    /* \351\200\211\344\270\255\347\212\266\346\200\201\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
""));

        verticalLayout_5->addWidget(favorite_btn);

        recent_btn = new StatePushbutton(my_wid);
        recent_btn->setObjectName(QString::fromUtf8("recent_btn"));
        recent_btn->setMinimumSize(QSize(250, 54));
        recent_btn->setMaximumSize(QSize(250, 54));
        recent_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-image: url(:/res/viewswitch/recent1.png);  /* \351\273\230\350\256\244\347\212\266\346\200\201\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-image: url(:/res/viewswitch/recent.png);  /* \351\274\240\346\240\207\346\202\254\346\265\256\346\227\266\346\230\276\347\244\272\347\232\204\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-image: url(:/res/viewswitch/recent2.png);    /* \351\200\211\344\270\255\347\212\266\346\200\201\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
""));

        verticalLayout_5->addWidget(recent_btn);

        local_btn = new StatePushbutton(my_wid);
        local_btn->setObjectName(QString::fromUtf8("local_btn"));
        local_btn->setMinimumSize(QSize(250, 54));
        local_btn->setMaximumSize(QSize(250, 54));
        local_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-image: url(:/res/viewswitch/local1.png);  /* \351\273\230\350\256\244\347\212\266\346\200\201\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-image: url(:/res/viewswitch/local.png);  /* \351\274\240\346\240\207\346\202\254\346\265\256\346\227\266\346\230\276\347\244\272\347\232\204\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-image: url(:/res/viewswitch/local2.png);    /* \351\200\211\344\270\255\347\212\266\346\200\201\345\233\276\347\211\207 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
"\n"
""));

        verticalLayout_5->addWidget(local_btn);


        verticalLayout_3->addWidget(my_wid);

        widget_6 = new QWidget(scrollAreaWidgetContents);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));

        verticalLayout_3->addWidget(widget_6);

        sidebar_wi->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(sidebar_wi);

        pages_wi = new QStackedWidget(mainbody_wi);
        pages_wi->setObjectName(QString::fromUtf8("pages_wi"));
        pages_wi->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 249, 252);"));
        recommend_wi = new Recommendwi();
        recommend_wi->setObjectName(QString::fromUtf8("recommend_wi"));
        pages_wi->addWidget(recommend_wi);
        songlist_wi = new Songlistwi();
        songlist_wi->setObjectName(QString::fromUtf8("songlist_wi"));
        pages_wi->addWidget(songlist_wi);
        search_wi = new Searchwi();
        search_wi->setObjectName(QString::fromUtf8("search_wi"));
        pages_wi->addWidget(search_wi);
        local_wi = new Localwi();
        local_wi->setObjectName(QString::fromUtf8("local_wi"));
        pages_wi->addWidget(local_wi);
        like_wi = new Likemusicwi();
        like_wi->setObjectName(QString::fromUtf8("like_wi"));
        pages_wi->addWidget(like_wi);

        horizontalLayout_2->addWidget(pages_wi);


        verticalLayout_2->addWidget(mainbody_wi);

        playbackControlPanel_wi = new Musicplayerwi(body_wi);
        playbackControlPanel_wi->setObjectName(QString::fromUtf8("playbackControlPanel_wi"));
        playbackControlPanel_wi->setMinimumSize(QSize(0, 120));
        playbackControlPanel_wi->setMaximumSize(QSize(16777215, 120));
        playbackControlPanel_wi->setStyleSheet(QString::fromUtf8("\n"
"background-color: #fafafa;\n"
"\n"
" \n"
" \n"
"  "));

        verticalLayout_2->addWidget(playbackControlPanel_wi);


        verticalLayout->addWidget(body_wi);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "Form", nullptr));
        back_btn->setText(QString());
        phone_btn->setText(QString());
        usericon_lb->setText(QString());
        username_lb->setText(QCoreApplication::translate("MainWidget", "\350\207\252\351\200\202", nullptr));
        message_btn->setText(QString());
        setting_btn->setText(QString());
        dress_btn->setText(QString());
        minimize_btn->setText(QString());
        close_btn->setText(QString());
        recommend_btn->setText(QString());
        featured_btn->setText(QString());
        podcast_btn->setText(QString());
        explore_btn->setText(QString());
        follow_btn->setText(QString());
        label->setText(QString());
        favorite_btn->setText(QString());
        recent_btn->setText(QString());
        local_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
