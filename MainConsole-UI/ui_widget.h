/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *topWidget;
    QToolButton *tbHome;
    QToolButton *tbAgentMan;
    QToolButton *tbInnerRule;
    QToolButton *tbCustomRule;
    QToolButton *tbRunApp;
    QToolButton *tbSetting;
    QToolButton *tbAbout;
    QWidget *titleWidget;
    QPushButton *closePushButton;
    QPushButton *minPushButton;
    QPushButton *titlePushButton;
    QPushButton *titleUpdate;
    QLabel *titlelabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1150, 725);
        Widget->setMaximumSize(QSize(16777215, 16777215));
        Widget->setBaseSize(QSize(920, 580));
        topWidget = new QWidget(Widget);
        topWidget->setObjectName(QString::fromUtf8("topWidget"));
        topWidget->setGeometry(QRect(0, 0, 1151, 140));
        tbHome = new QToolButton(topWidget);
        tbHome->setObjectName(QString::fromUtf8("tbHome"));
        tbHome->setGeometry(QRect(32, 60, 142, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(10);
        tbHome->setFont(font);
        tbAgentMan = new QToolButton(topWidget);
        tbAgentMan->setObjectName(QString::fromUtf8("tbAgentMan"));
        tbAgentMan->setGeometry(QRect(174, 60, 142, 80));
        tbAgentMan->setFont(font);
        tbInnerRule = new QToolButton(topWidget);
        tbInnerRule->setObjectName(QString::fromUtf8("tbInnerRule"));
        tbInnerRule->setGeometry(QRect(316, 60, 142, 80));
        tbInnerRule->setFont(font);
        tbCustomRule = new QToolButton(topWidget);
        tbCustomRule->setObjectName(QString::fromUtf8("tbCustomRule"));
        tbCustomRule->setGeometry(QRect(458, 60, 142, 80));
        tbCustomRule->setFont(font);
        tbRunApp = new QToolButton(topWidget);
        tbRunApp->setObjectName(QString::fromUtf8("tbRunApp"));
        tbRunApp->setGeometry(QRect(600, 60, 142, 80));
        tbRunApp->setFont(font);
        tbSetting = new QToolButton(topWidget);
        tbSetting->setObjectName(QString::fromUtf8("tbSetting"));
        tbSetting->setGeometry(QRect(742, 60, 142, 80));
        tbSetting->setFont(font);
        tbAbout = new QToolButton(topWidget);
        tbAbout->setObjectName(QString::fromUtf8("tbAbout"));
        tbAbout->setGeometry(QRect(884, 60, 142, 80));
        tbAbout->setFont(font);
        titleWidget = new QWidget(topWidget);
        titleWidget->setObjectName(QString::fromUtf8("titleWidget"));
        titleWidget->setGeometry(QRect(0, 0, 1151, 41));
        closePushButton = new QPushButton(titleWidget);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setGeometry(QRect(1119, 0, 28, 28));
        minPushButton = new QPushButton(titleWidget);
        minPushButton->setObjectName(QString::fromUtf8("minPushButton"));
        minPushButton->setGeometry(QRect(1087, 0, 28, 28));
        titlePushButton = new QPushButton(titleWidget);
        titlePushButton->setObjectName(QString::fromUtf8("titlePushButton"));
        titlePushButton->setGeometry(QRect(10, 6, 31, 30));
        titleUpdate = new QPushButton(titleWidget);
        titleUpdate->setObjectName(QString::fromUtf8("titleUpdate"));
        titleUpdate->setGeometry(QRect(290, 12, 16, 16));
        QFont font1;
        font1.setPointSize(9);
        titleUpdate->setFont(font1);
        titlelabel = new QLabel(titleWidget);
        titlelabel->setObjectName(QString::fromUtf8("titlelabel"));
        titlelabel->setGeometry(QRect(39, 0, 241, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(9);
        titlelabel->setFont(font2);
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 140, 1151, 591));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        tbHome->setText(QApplication::translate("Widget", "...", nullptr));
        tbAgentMan->setText(QApplication::translate("Widget", "...", nullptr));
        tbInnerRule->setText(QApplication::translate("Widget", "...", nullptr));
        tbCustomRule->setText(QApplication::translate("Widget", "...", nullptr));
        tbRunApp->setText(QApplication::translate("Widget", "...", nullptr));
        tbSetting->setText(QApplication::translate("Widget", "...", nullptr));
        tbAbout->setText(QApplication::translate("Widget", "...", nullptr));
        closePushButton->setText(QString());
        minPushButton->setText(QString());
        titlePushButton->setText(QString());
        titleUpdate->setText(QString());
        titlelabel->setText(QApplication::translate("Widget", "XXXYYY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
