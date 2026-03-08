/********************************************************************************
** Form generated from reading UI file 'settingwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWIDGET_H
#define UI_SETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWidget
{
public:

    void setupUi(QWidget *SettingWidget)
    {
        if (SettingWidget->objectName().isEmpty())
            SettingWidget->setObjectName(QString::fromUtf8("SettingWidget"));
        SettingWidget->resize(400, 300);

        retranslateUi(SettingWidget);

        QMetaObject::connectSlotsByName(SettingWidget);
    } // setupUi

    void retranslateUi(QWidget *SettingWidget)
    {
        SettingWidget->setWindowTitle(QApplication::translate("SettingWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWidget: public Ui_SettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWIDGET_H
