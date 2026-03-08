/********************************************************************************
** Form generated from reading UI file 'ModuleRuleDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULERULEDETAILWIDGET_H
#define UI_MODULERULEDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModuleRuleDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ModuleRuleDetailWidget)
    {
        if (ModuleRuleDetailWidget->objectName().isEmpty())
            ModuleRuleDetailWidget->setObjectName(QString::fromUtf8("ModuleRuleDetailWidget"));
        ModuleRuleDetailWidget->resize(583, 261);
        verticalLayout = new QVBoxLayout(ModuleRuleDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        tableWidget = new QTableWidget(ModuleRuleDetailWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ModuleRuleDetailWidget);

        QMetaObject::connectSlotsByName(ModuleRuleDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *ModuleRuleDetailWidget)
    {
        ModuleRuleDetailWidget->setWindowTitle(QApplication::translate("ModuleRuleDetailWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleRuleDetailWidget: public Ui_ModuleRuleDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULERULEDETAILWIDGET_H
