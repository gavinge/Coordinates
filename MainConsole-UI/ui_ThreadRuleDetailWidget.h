/********************************************************************************
** Form generated from reading UI file 'ThreadRuleDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREADRULEDETAILWIDGET_H
#define UI_THREADRULEDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThreadRuleDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ThreadRuleDetailWidget)
    {
        if (ThreadRuleDetailWidget->objectName().isEmpty())
            ThreadRuleDetailWidget->setObjectName(QString::fromUtf8("ThreadRuleDetailWidget"));
        ThreadRuleDetailWidget->resize(583, 261);
        verticalLayout = new QVBoxLayout(ThreadRuleDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        tableWidget = new QTableWidget(ThreadRuleDetailWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ThreadRuleDetailWidget);

        QMetaObject::connectSlotsByName(ThreadRuleDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *ThreadRuleDetailWidget)
    {
        ThreadRuleDetailWidget->setWindowTitle(QApplication::translate("ThreadRuleDetailWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThreadRuleDetailWidget: public Ui_ThreadRuleDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREADRULEDETAILWIDGET_H
