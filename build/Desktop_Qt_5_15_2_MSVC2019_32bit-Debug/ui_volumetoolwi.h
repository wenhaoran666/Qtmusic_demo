/********************************************************************************
** Form generated from reading UI file 'volumetoolwi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUMETOOLWI_H
#define UI_VOLUMETOOLWI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VolumeToolwi
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSlider *slider;
    QLabel *volum_lb;

    void setupUi(QWidget *VolumeToolwi)
    {
        if (VolumeToolwi->objectName().isEmpty())
            VolumeToolwi->setObjectName(QString::fromUtf8("VolumeToolwi"));
        VolumeToolwi->resize(80, 200);
        VolumeToolwi->setMinimumSize(QSize(80, 200));
        VolumeToolwi->setMaximumSize(QSize(80, 200));
        verticalLayout = new QVBoxLayout(VolumeToolwi);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        widget = new QWidget(VolumeToolwi);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 200));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 10);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        slider = new QSlider(widget_2);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setMinimumSize(QSize(30, 0));
        slider->setMaximumSize(QSize(30, 16777215));
        slider->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {\n"
"    border: none;\n"
"    width: 10px;\n"
"	background: rgb(252, 61, 81);\n"
"    margin: 0px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: white;\n"
"    border: 2px solid #FC3D4D;\n"
"    border: 1px solid #DADCDF;\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: 0 -6px;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QSlider::sub-page:vertical {\n"
"	background: #DADCDF;\n"
"    border-radius: 5px;\n"
"}\n"
""));
        slider->setMaximum(100);
        slider->setValue(30);
        slider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider);


        verticalLayout_2->addWidget(widget_2);

        volum_lb = new QLabel(widget);
        volum_lb->setObjectName(QString::fromUtf8("volum_lb"));
        volum_lb->setStyleSheet(QString::fromUtf8("border: none;"));
        volum_lb->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(volum_lb);


        verticalLayout->addWidget(widget);


        retranslateUi(VolumeToolwi);

        QMetaObject::connectSlotsByName(VolumeToolwi);
    } // setupUi

    void retranslateUi(QWidget *VolumeToolwi)
    {
        VolumeToolwi->setWindowTitle(QCoreApplication::translate("VolumeToolwi", "Form", nullptr));
        volum_lb->setText(QCoreApplication::translate("VolumeToolwi", "50%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VolumeToolwi: public Ui_VolumeToolwi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMETOOLWI_H
