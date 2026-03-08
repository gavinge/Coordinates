/********************************************************************************
** Form generated from reading UI file 'DomainRuleDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOMAINRULEDETAILWIDGET_H
#define UI_DOMAINRULEDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DomainRuleDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *DomainRuleDetailWidget)
    {
        if (DomainRuleDetailWidget->objectName().isEmpty())
            DomainRuleDetailWidget->setObjectName(QString::fromUtf8("DomainRuleDetailWidget"));
        DomainRuleDetailWidget->resize(583, 261);
        verticalLayout = new QVBoxLayout(DomainRuleDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        tableWidget = new QTableWidget(DomainRuleDetailWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(DomainRuleDetailWidget);

        QMetaObject::connectSlotsByName(DomainRuleDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *DomainRuleDetailWidget)
    {
        DomainRuleDetailWidget->setWindowTitle(QApplication::translate("DomainRuleDetailWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DomainRuleDetailWidget: public Ui_DomainRuleDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOMAINRULEDETAILWIDGET_H
