/********************************************************************************
** Form generated from reading UI file 'CustomRuleCenterWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMRULECENTERWIDGET_H
#define UI_CUSTOMRULECENTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomRuleCenterWidget
{
public:
    QFrame *titleFrame;
    QPushButton *ruleCenterCloseBtn;
    QLabel *label;
    QFrame *tabWidgetFrame;
    QTabWidget *tabWidget;
    QPushButton *addRulePushButton;

    void setupUi(QWidget *CustomRuleCenterWidget)
    {
        if (CustomRuleCenterWidget->objectName().isEmpty())
            CustomRuleCenterWidget->setObjectName(QString::fromUtf8("CustomRuleCenterWidget"));
        CustomRuleCenterWidget->resize(960, 605);
        CustomRuleCenterWidget->setStyleSheet(QString::fromUtf8("background-color: #D7E9F3;"));
        titleFrame = new QFrame(CustomRuleCenterWidget);
        titleFrame->setObjectName(QString::fromUtf8("titleFrame"));
        titleFrame->setGeometry(QRect(1, 1, 958, 37));
        titleFrame->setStyleSheet(QString::fromUtf8(""));
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Raised);
        ruleCenterCloseBtn = new QPushButton(titleFrame);
        ruleCenterCloseBtn->setObjectName(QString::fromUtf8("ruleCenterCloseBtn"));
        ruleCenterCloseBtn->setGeometry(QRect(920, 0, 40, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        ruleCenterCloseBtn->setFont(font);
        ruleCenterCloseBtn->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(titleFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 91, 16));
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        tabWidgetFrame = new QFrame(CustomRuleCenterWidget);
        tabWidgetFrame->setObjectName(QString::fromUtf8("tabWidgetFrame"));
        tabWidgetFrame->setGeometry(QRect(1, 85, 958, 519));
        tabWidgetFrame->setStyleSheet(QString::fromUtf8("background-color: white;"));
        tabWidget = new QTabWidget(tabWidgetFrame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 958, 519));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        addRulePushButton = new QPushButton(CustomRuleCenterWidget);
        addRulePushButton->setObjectName(QString::fromUtf8("addRulePushButton"));
        addRulePushButton->setGeometry(QRect(5, 43, 112, 37));
        addRulePushButton->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(CustomRuleCenterWidget);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(CustomRuleCenterWidget);
    } // setupUi

    void retranslateUi(QWidget *CustomRuleCenterWidget)
    {
        CustomRuleCenterWidget->setWindowTitle(QApplication::translate("CustomRuleCenterWidget", "Form", nullptr));
        ruleCenterCloseBtn->setText(QApplication::translate("CustomRuleCenterWidget", "X", nullptr));
        label->setText(QApplication::translate("CustomRuleCenterWidget", "\350\247\204\345\210\231\344\270\255\345\277\203", nullptr));
#ifndef QT_NO_WHATSTHIS
        tabWidget->setWhatsThis(QApplication::translate("CustomRuleCenterWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        addRulePushButton->setText(QApplication::translate("CustomRuleCenterWidget", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomRuleCenterWidget: public Ui_CustomRuleCenterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMRULECENTERWIDGET_H
