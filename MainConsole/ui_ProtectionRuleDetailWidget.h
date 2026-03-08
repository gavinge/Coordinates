/********************************************************************************
** Form generated from reading UI file 'ProtectionRuleDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTECTIONRULEDETAILWIDGET_H
#define UI_PROTECTIONRULEDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProtectionRuleDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ProtectionRuleDetailWidget)
    {
        if (ProtectionRuleDetailWidget->objectName().isEmpty())
            ProtectionRuleDetailWidget->setObjectName(QString::fromUtf8("ProtectionRuleDetailWidget"));
        ProtectionRuleDetailWidget->resize(583, 261);
        verticalLayout = new QVBoxLayout(ProtectionRuleDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        tableWidget = new QTableWidget(ProtectionRuleDetailWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ProtectionRuleDetailWidget);

        QMetaObject::connectSlotsByName(ProtectionRuleDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *ProtectionRuleDetailWidget)
    {
        ProtectionRuleDetailWidget->setWindowTitle(QApplication::translate("ProtectionRuleDetailWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProtectionRuleDetailWidget: public Ui_ProtectionRuleDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTECTIONRULEDETAILWIDGET_H
