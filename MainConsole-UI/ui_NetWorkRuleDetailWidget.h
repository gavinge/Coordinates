/********************************************************************************
** Form generated from reading UI file 'NetWorkRuleDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKRULEDETAILWIDGET_H
#define UI_NETWORKRULEDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetWorkRuleDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *NetWorkRuleDetailWidget)
    {
        if (NetWorkRuleDetailWidget->objectName().isEmpty())
            NetWorkRuleDetailWidget->setObjectName(QString::fromUtf8("NetWorkRuleDetailWidget"));
        NetWorkRuleDetailWidget->resize(583, 261);
        verticalLayout = new QVBoxLayout(NetWorkRuleDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        tableWidget = new QTableWidget(NetWorkRuleDetailWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(NetWorkRuleDetailWidget);

        QMetaObject::connectSlotsByName(NetWorkRuleDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *NetWorkRuleDetailWidget)
    {
        NetWorkRuleDetailWidget->setWindowTitle(QApplication::translate("NetWorkRuleDetailWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetWorkRuleDetailWidget: public Ui_NetWorkRuleDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKRULEDETAILWIDGET_H
