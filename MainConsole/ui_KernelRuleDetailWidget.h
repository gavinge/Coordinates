/********************************************************************************
** Form generated from reading UI file 'KernelRuleDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KERNELRULEDETAILWIDGET_H
#define UI_KERNELRULEDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KernelRuleDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *KernelRuleDetailWidget)
    {
        if (KernelRuleDetailWidget->objectName().isEmpty())
            KernelRuleDetailWidget->setObjectName(QString::fromUtf8("KernelRuleDetailWidget"));
        KernelRuleDetailWidget->resize(583, 261);
        verticalLayout = new QVBoxLayout(KernelRuleDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        tableWidget = new QTableWidget(KernelRuleDetailWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(KernelRuleDetailWidget);

        QMetaObject::connectSlotsByName(KernelRuleDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *KernelRuleDetailWidget)
    {
        KernelRuleDetailWidget->setWindowTitle(QApplication::translate("KernelRuleDetailWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KernelRuleDetailWidget: public Ui_KernelRuleDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KERNELRULEDETAILWIDGET_H
