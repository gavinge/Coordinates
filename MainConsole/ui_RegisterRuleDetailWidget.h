/********************************************************************************
** Form generated from reading UI file 'RegisterRuleDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERRULEDETAILWIDGET_H
#define UI_REGISTERRULEDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterRuleDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *RegisterRuleDetailWidget)
    {
        if (RegisterRuleDetailWidget->objectName().isEmpty())
            RegisterRuleDetailWidget->setObjectName(QString::fromUtf8("RegisterRuleDetailWidget"));
        RegisterRuleDetailWidget->resize(583, 261);
        verticalLayout = new QVBoxLayout(RegisterRuleDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        tableWidget = new QTableWidget(RegisterRuleDetailWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(RegisterRuleDetailWidget);

        QMetaObject::connectSlotsByName(RegisterRuleDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *RegisterRuleDetailWidget)
    {
        RegisterRuleDetailWidget->setWindowTitle(QApplication::translate("RegisterRuleDetailWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterRuleDetailWidget: public Ui_RegisterRuleDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERRULEDETAILWIDGET_H
