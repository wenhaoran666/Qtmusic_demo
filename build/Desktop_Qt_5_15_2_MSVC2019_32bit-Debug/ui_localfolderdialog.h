/********************************************************************************
** Form generated from reading UI file 'localfolderdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALFOLDERDIALOG_H
#define UI_LOCALFOLDERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LocalfolderDialog
{
public:
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QWidget *head;
    QPushButton *pushButton_close;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton_selectFolder;
    QPushButton *pushButton_accept;
    QWidget *body;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *container;

    void setupUi(QDialog *LocalfolderDialog)
    {
        if (LocalfolderDialog->objectName().isEmpty())
            LocalfolderDialog->setObjectName(QString::fromUtf8("LocalfolderDialog"));
        LocalfolderDialog->resize(686, 720);
        widget_2 = new QWidget(LocalfolderDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(10, 10, 666, 700));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;"));
        head = new QWidget(widget_3);
        head->setObjectName(QString::fromUtf8("head"));
        head->setGeometry(QRect(0, 0, 666, 161));
        pushButton_close = new QPushButton(head);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(610, 10, 45, 45));
        pushButton_close->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label = new QLabel(head);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 30, 231, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #283248;"));
        label_3 = new QLabel(head);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 100, 431, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(11);
        font1.setBold(false);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: #283248;"));
        pushButton_selectFolder = new QPushButton(widget_3);
        pushButton_selectFolder->setObjectName(QString::fromUtf8("pushButton_selectFolder"));
        pushButton_selectFolder->setGeometry(QRect(50, 620, 260, 60));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font2.setPointSize(13);
        font2.setBold(false);
        pushButton_selectFolder->setFont(font2);
        pushButton_selectFolder->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #3B4357;\n"
"	background-color: #EAEDF1;\n"
"	border-radius: 30px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #E2E5E9;\n"
"}\n"
""));
        pushButton_accept = new QPushButton(widget_3);
        pushButton_accept->setObjectName(QString::fromUtf8("pushButton_accept"));
        pushButton_accept->setGeometry(QRect(350, 620, 260, 60));
        pushButton_accept->setFont(font2);
        pushButton_accept->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: #FC3B59;\n"
"	border-radius: 30px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #E33742;\n"
"}"));
        body = new QWidget(widget_3);
        body->setObjectName(QString::fromUtf8("body"));
        body->setGeometry(QRect(60, 160, 546, 441));
        body->setMinimumSize(QSize(546, 0));
        body->setMaximumSize(QSize(546, 16777215));
        body->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: #ffffff;\n"
"}\n"
"\n"
"QScrollArea {\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QScrollArea::corner {\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background-color: #f0f3f6; /* \346\273\232\345\212\250\346\235\241\350\203\214\346\231\257 */\n"
"    width: 9px; /* \346\273\232\345\212\250\346\235\241\345\256\275\345\272\246 */\n"
"    margin: 0px 0px 0px 0px; /* \346\216\247\345\210\266\346\273\232\345\212\250\346\235\241\347\232\204\351\227\264\350\267\235 */\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #dcdfe4; /* \346\273\232\345\212\250\346\235\241\346\273\221\345\235\227\351\242\234\350\211\262 */\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background-color: #bec3ca; /* \346\273\232\345\212\250\346\235\241\346\273\221\345\235\227\346\202\254\345\201\234"
                        "\346\227\266\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    background-color: #f0f3f6; /* \351\232\220\350\227\217\346\273\232\345\212\250\346\235\241\344\270\212\344\270\213\347\256\255\345\244\264 */\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(body);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(body);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        container = new QWidget();
        container->setObjectName(QString::fromUtf8("container"));
        container->setGeometry(QRect(0, 0, 546, 441));
        container->setMaximumSize(QSize(16777215, 16777215));
        container->setStyleSheet(QString::fromUtf8("#container {\n"
"	margin: 35px 0px 0px 0px;\n"
"	alignment: top;\n"
"}"));
        scrollArea->setWidget(container);

        verticalLayout_3->addWidget(scrollArea);


        verticalLayout_2->addWidget(widget_3);


        retranslateUi(LocalfolderDialog);

        QMetaObject::connectSlotsByName(LocalfolderDialog);
    } // setupUi

    void retranslateUi(QDialog *LocalfolderDialog)
    {
        LocalfolderDialog->setWindowTitle(QCoreApplication::translate("LocalfolderDialog", "Dialog", nullptr));
        pushButton_close->setText(QString());
        label->setText(QCoreApplication::translate("LocalfolderDialog", "\351\200\211\346\213\251\346\234\254\345\234\260\346\226\207\344\273\266\345\244\271", nullptr));
        label_3->setText(QCoreApplication::translate("LocalfolderDialog", "\345\260\206\350\207\252\345\212\250\346\211\253\346\217\217\345\213\276\351\200\211\347\232\204\347\233\256\345\275\225\357\274\214\346\226\207\344\273\266\345\242\236\345\210\240\345\256\236\346\227\266\345\220\214\346\255\245\343\200\202", nullptr));
        pushButton_selectFolder->setText(QCoreApplication::translate("LocalfolderDialog", "\346\267\273\345\212\240\346\226\207\344\273\266\345\244\271", nullptr));
        pushButton_accept->setText(QCoreApplication::translate("LocalfolderDialog", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LocalfolderDialog: public Ui_LocalfolderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALFOLDERDIALOG_H
