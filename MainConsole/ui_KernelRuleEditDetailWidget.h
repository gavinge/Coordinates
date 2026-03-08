/********************************************************************************
** Form generated from reading UI file 'KernelRuleEditDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KERNELRULEEDITDETAILWIDGET_H
#define UI_KERNELRULEEDITDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KernelRuleEditDetailWidget
{
public:
    QFrame *titleFrame;
    QPushButton *btnClose;
    QLabel *label;
    QPushButton *btnComfirm;
    QLabel *label_2;
    QComboBox *cmbxKerneInfo;
    QLineEdit *liedtKernelInfo;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *cmbxSysVersion;
    QLabel *label_7;
    QComboBox *cmbxPriority;
    QTextEdit *txtdtRemark;
    QCheckBox *ckbxReportLog;
    QComboBox *cmbxOperationCode;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *cmbxCallBackType;
    QLabel *labError;

    void setupUi(QWidget *KernelRuleEditDetailWidget)
    {
        if (KernelRuleEditDetailWidget->objectName().isEmpty())
            KernelRuleEditDetailWidget->setObjectName(QString::fromUtf8("KernelRuleEditDetailWidget"));
        KernelRuleEditDetailWidget->resize(650, 300);
        KernelRuleEditDetailWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(KernelRuleEditDetailWidget);
        titleFrame->setObjectName(QString::fromUtf8("titleFrame"));
        titleFrame->setGeometry(QRect(1, 1, 648, 39));
        titleFrame->setStyleSheet(QString::fromUtf8(""));
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Raised);
        btnClose = new QPushButton(titleFrame);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(608, 1, 40, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        btnClose->setFont(font);
        btnClose->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(titleFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 91, 31));
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        btnComfirm = new QPushButton(KernelRuleEditDetailWidget);
        btnComfirm->setObjectName(QString::fromUtf8("btnComfirm"));
        btnComfirm->setGeometry(QRect(530, 250, 112, 37));
        btnComfirm->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(KernelRuleEditDetailWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(25, 47, 91, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        cmbxKerneInfo = new QComboBox(KernelRuleEditDetailWidget);
        cmbxKerneInfo->setObjectName(QString::fromUtf8("cmbxKerneInfo"));
        cmbxKerneInfo->setGeometry(QRect(115, 50, 161, 26));
        liedtKernelInfo = new QLineEdit(KernelRuleEditDetailWidget);
        liedtKernelInfo->setObjectName(QString::fromUtf8("liedtKernelInfo"));
        liedtKernelInfo->setGeometry(QRect(280, 50, 351, 27));
        label_5 = new QLabel(KernelRuleEditDetailWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 137, 51, 31));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_6 = new QLabel(KernelRuleEditDetailWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(25, 110, 91, 31));
        cmbxSysVersion = new QComboBox(KernelRuleEditDetailWidget);
        cmbxSysVersion->setObjectName(QString::fromUtf8("cmbxSysVersion"));
        cmbxSysVersion->setGeometry(QRect(115, 110, 161, 26));
        label_7 = new QLabel(KernelRuleEditDetailWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(280, 110, 91, 31));
        cmbxPriority = new QComboBox(KernelRuleEditDetailWidget);
        cmbxPriority->setObjectName(QString::fromUtf8("cmbxPriority"));
        cmbxPriority->setGeometry(QRect(370, 110, 180, 26));
        txtdtRemark = new QTextEdit(KernelRuleEditDetailWidget);
        txtdtRemark->setObjectName(QString::fromUtf8("txtdtRemark"));
        txtdtRemark->setGeometry(QRect(115, 140, 515, 85));
        ckbxReportLog = new QCheckBox(KernelRuleEditDetailWidget);
        ckbxReportLog->setObjectName(QString::fromUtf8("ckbxReportLog"));
        ckbxReportLog->setGeometry(QRect(110, 240, 151, 24));
        cmbxOperationCode = new QComboBox(KernelRuleEditDetailWidget);
        cmbxOperationCode->setObjectName(QString::fromUtf8("cmbxOperationCode"));
        cmbxOperationCode->setGeometry(QRect(115, 80, 161, 26));
        label_8 = new QLabel(KernelRuleEditDetailWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(25, 77, 91, 31));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_9 = new QLabel(KernelRuleEditDetailWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(280, 80, 91, 31));
        cmbxCallBackType = new QComboBox(KernelRuleEditDetailWidget);
        cmbxCallBackType->setObjectName(QString::fromUtf8("cmbxCallBackType"));
        cmbxCallBackType->setGeometry(QRect(370, 80, 180, 26));
        labError = new QLabel(KernelRuleEditDetailWidget);
        labError->setObjectName(QString::fromUtf8("labError"));
        labError->setGeometry(QRect(25, 270, 421, 21));
        labError->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));

        retranslateUi(KernelRuleEditDetailWidget);

        QMetaObject::connectSlotsByName(KernelRuleEditDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *KernelRuleEditDetailWidget)
    {
        KernelRuleEditDetailWidget->setWindowTitle(QApplication::translate("KernelRuleEditDetailWidget", "Form", nullptr));
        btnClose->setText(QApplication::translate("KernelRuleEditDetailWidget", "X", nullptr));
        label->setText(QApplication::translate("KernelRuleEditDetailWidget", "\351\251\261\345\212\250\350\247\204\345\210\231", nullptr));
        btnComfirm->setText(QApplication::translate("KernelRuleEditDetailWidget", "\346\267\273\345\212\240", nullptr));
        label_2->setText(QApplication::translate("KernelRuleEditDetailWidget", "\351\251\261\345\212\250\344\277\241\346\201\257", nullptr));
        label_5->setText(QApplication::translate("KernelRuleEditDetailWidget", "\345\244\207\346\263\250", nullptr));
        label_6->setText(QApplication::translate("KernelRuleEditDetailWidget", "\347\224\237\346\225\210\347\263\273\347\273\237", nullptr));
        label_7->setText(QApplication::translate("KernelRuleEditDetailWidget", "\344\274\230\345\205\210\347\272\247\345\210\253", nullptr));
        ckbxReportLog->setText(QApplication::translate("KernelRuleEditDetailWidget", "\344\270\212\346\212\245\346\227\245\345\277\227", nullptr));
        label_8->setText(QApplication::translate("KernelRuleEditDetailWidget", "\345\244\204\347\220\206\346\226\271\345\274\217", nullptr));
        label_9->setText(QApplication::translate("KernelRuleEditDetailWidget", "\345\233\236\350\260\203\347\261\273\345\236\213", nullptr));
        labError->setText(QApplication::translate("KernelRuleEditDetailWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KernelRuleEditDetailWidget: public Ui_KernelRuleEditDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KERNELRULEEDITDETAILWIDGET_H
