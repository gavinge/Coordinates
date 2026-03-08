/********************************************************************************
** Form generated from reading UI file 'WindowRuleDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWRULEDETAILWIDGET_H
#define UI_WINDOWRULEDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowRuleDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *WindowRuleDetailWidget)
    {
        if (WindowRuleDetailWidget->objectName().isEmpty())
            WindowRuleDetailWidget->setObjectName(QString::fromUtf8("WindowRuleDetailWidget"));
        WindowRuleDetailWidget->resize(583, 261);
        verticalLayout = new QVBoxLayout(WindowRuleDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        tableWidget = new QTableWidget(WindowRuleDetailWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(WindowRuleDetailWidget);

        QMetaObject::connectSlotsByName(WindowRuleDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *WindowRuleDetailWidget)
    {
        WindowRuleDetailWidget->setWindowTitle(QApplication::translate("WindowRuleDetailWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowRuleDetailWidget: public Ui_WindowRuleDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWRULEDETAILWIDGET_H
