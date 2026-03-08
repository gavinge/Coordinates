/********************************************************************************
** Form generated from reading UI file 'ProcessRuleDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSRULEDETAILWIDGET_H
#define UI_PROCESSRULEDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessRuleDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ProcessRuleDetailWidget)
    {
        if (ProcessRuleDetailWidget->objectName().isEmpty())
            ProcessRuleDetailWidget->setObjectName(QString::fromUtf8("ProcessRuleDetailWidget"));
        ProcessRuleDetailWidget->resize(583, 261);
        verticalLayout = new QVBoxLayout(ProcessRuleDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        tableWidget = new QTableWidget(ProcessRuleDetailWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ProcessRuleDetailWidget);

        QMetaObject::connectSlotsByName(ProcessRuleDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *ProcessRuleDetailWidget)
    {
        ProcessRuleDetailWidget->setWindowTitle(QApplication::translate("ProcessRuleDetailWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProcessRuleDetailWidget: public Ui_ProcessRuleDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSRULEDETAILWIDGET_H
