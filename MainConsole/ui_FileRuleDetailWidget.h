/********************************************************************************
** Form generated from reading UI file 'FileRuleDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILERULEDETAILWIDGET_H
#define UI_FILERULEDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileRuleDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *FileRuleDetailWidget)
    {
        if (FileRuleDetailWidget->objectName().isEmpty())
            FileRuleDetailWidget->setObjectName(QString::fromUtf8("FileRuleDetailWidget"));
        FileRuleDetailWidget->resize(583, 261);
        verticalLayout = new QVBoxLayout(FileRuleDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        tableWidget = new QTableWidget(FileRuleDetailWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(FileRuleDetailWidget);

        QMetaObject::connectSlotsByName(FileRuleDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *FileRuleDetailWidget)
    {
        FileRuleDetailWidget->setWindowTitle(QApplication::translate("FileRuleDetailWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileRuleDetailWidget: public Ui_FileRuleDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILERULEDETAILWIDGET_H
