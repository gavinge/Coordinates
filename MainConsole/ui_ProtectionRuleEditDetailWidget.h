/********************************************************************************
** Form generated from reading UI file 'ProtectionRuleEditDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTECTIONRULEEDITDETAILWIDGET_H
#define UI_PROTECTIONRULEEDITDETAILWIDGET_H

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

class Ui_ProtectionRuleEditDetailWidget
{
public:
    QFrame *titleFrame;
    QPushButton *btnClose;
    QLabel *label;
    QPushButton *btnComfirm;
    QLabel *label_2;
    QLabel *label_4;
    QComboBox *cmbxSourceProcess;
    QComboBox *cmbxProtectProcess;
    QComboBox *cmbxOperationCode;
    QLineEdit *liedtSourceProcess;
    QLineEdit *liedtProtectProcess;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *cmbxSysVersion;
    QLabel *label_7;
    QComboBox *cmbxPriority;
    QTextEdit *txtdtRemark;
    QCheckBox *ckbxReportLog;
    QLabel *label_8;
    QComboBox *cmbxProtectType;
    QLabel *label_9;
    QLabel *labError;

    void setupUi(QWidget *ProtectionRuleEditDetailWidget)
    {
        if (ProtectionRuleEditDetailWidget->objectName().isEmpty())
            ProtectionRuleEditDetailWidget->setObjectName(QString::fromUtf8("ProtectionRuleEditDetailWidget"));
        ProtectionRuleEditDetailWidget->resize(650, 336);
        ProtectionRuleEditDetailWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(ProtectionRuleEditDetailWidget);
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
        btnComfirm = new QPushButton(ProtectionRuleEditDetailWidget);
        btnComfirm->setObjectName(QString::fromUtf8("btnComfirm"));
        btnComfirm->setGeometry(QRect(530, 290, 112, 37));
        btnComfirm->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(ProtectionRuleEditDetailWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 47, 71, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_4 = new QLabel(ProtectionRuleEditDetailWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 147, 91, 31));
        label_4->setLayoutDirection(Qt::LeftToRight);
        cmbxSourceProcess = new QComboBox(ProtectionRuleEditDetailWidget);
        cmbxSourceProcess->setObjectName(QString::fromUtf8("cmbxSourceProcess"));
        cmbxSourceProcess->setGeometry(QRect(110, 50, 160, 26));
        cmbxProtectProcess = new QComboBox(ProtectionRuleEditDetailWidget);
        cmbxProtectProcess->setObjectName(QString::fromUtf8("cmbxProtectProcess"));
        cmbxProtectProcess->setGeometry(QRect(110, 80, 160, 26));
        cmbxOperationCode = new QComboBox(ProtectionRuleEditDetailWidget);
        cmbxOperationCode->setObjectName(QString::fromUtf8("cmbxOperationCode"));
        cmbxOperationCode->setGeometry(QRect(110, 150, 160, 26));
        liedtSourceProcess = new QLineEdit(ProtectionRuleEditDetailWidget);
        liedtSourceProcess->setObjectName(QString::fromUtf8("liedtSourceProcess"));
        liedtSourceProcess->setGeometry(QRect(275, 50, 351, 27));
        liedtProtectProcess = new QLineEdit(ProtectionRuleEditDetailWidget);
        liedtProtectProcess->setObjectName(QString::fromUtf8("liedtProtectProcess"));
        liedtProtectProcess->setGeometry(QRect(275, 80, 351, 27));
        label_5 = new QLabel(ProtectionRuleEditDetailWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(55, 177, 51, 31));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_6 = new QLabel(ProtectionRuleEditDetailWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(275, 147, 91, 31));
        cmbxSysVersion = new QComboBox(ProtectionRuleEditDetailWidget);
        cmbxSysVersion->setObjectName(QString::fromUtf8("cmbxSysVersion"));
        cmbxSysVersion->setGeometry(QRect(369, 150, 121, 26));
        label_7 = new QLabel(ProtectionRuleEditDetailWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(500, 147, 91, 31));
        cmbxPriority = new QComboBox(ProtectionRuleEditDetailWidget);
        cmbxPriority->setObjectName(QString::fromUtf8("cmbxPriority"));
        cmbxPriority->setGeometry(QRect(594, 150, 31, 26));
        txtdtRemark = new QTextEdit(ProtectionRuleEditDetailWidget);
        txtdtRemark->setObjectName(QString::fromUtf8("txtdtRemark"));
        txtdtRemark->setGeometry(QRect(110, 180, 515, 85));
        ckbxReportLog = new QCheckBox(ProtectionRuleEditDetailWidget);
        ckbxReportLog->setObjectName(QString::fromUtf8("ckbxReportLog"));
        ckbxReportLog->setGeometry(QRect(105, 270, 151, 24));
        label_8 = new QLabel(ProtectionRuleEditDetailWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 80, 91, 31));
        label_8->setLayoutDirection(Qt::LeftToRight);
        cmbxProtectType = new QComboBox(ProtectionRuleEditDetailWidget);
        cmbxProtectType->setObjectName(QString::fromUtf8("cmbxProtectType"));
        cmbxProtectType->setGeometry(QRect(110, 115, 160, 26));
        label_9 = new QLabel(ProtectionRuleEditDetailWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 115, 91, 31));
        label_9->setLayoutDirection(Qt::LeftToRight);
        labError = new QLabel(ProtectionRuleEditDetailWidget);
        labError->setObjectName(QString::fromUtf8("labError"));
        labError->setGeometry(QRect(20, 300, 431, 31));
        labError->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));

        retranslateUi(ProtectionRuleEditDetailWidget);

        QMetaObject::connectSlotsByName(ProtectionRuleEditDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *ProtectionRuleEditDetailWidget)
    {
        ProtectionRuleEditDetailWidget->setWindowTitle(QApplication::translate("ProtectionRuleEditDetailWidget", "Form", nullptr));
        btnClose->setText(QApplication::translate("ProtectionRuleEditDetailWidget", "X", nullptr));
        label->setText(QApplication::translate("ProtectionRuleEditDetailWidget", " \344\277\235\346\212\244\350\247\204\345\210\231", nullptr));
        btnComfirm->setText(QApplication::translate("ProtectionRuleEditDetailWidget", "\346\267\273\345\212\240", nullptr));
        label_2->setText(QApplication::translate("ProtectionRuleEditDetailWidget", "\346\272\220\350\277\233\347\250\213", nullptr));
        label_4->setText(QApplication::translate("ProtectionRuleEditDetailWidget", "\345\244\204\347\220\206\346\226\271\345\274\217", nullptr));
        label_5->setText(QApplication::translate("ProtectionRuleEditDetailWidget", "\345\244\207\346\263\250", nullptr));
        label_6->setText(QApplication::translate("ProtectionRuleEditDetailWidget", "\347\224\237\346\225\210\347\263\273\347\273\237", nullptr));
        label_7->setText(QApplication::translate("ProtectionRuleEditDetailWidget", "\344\274\230\345\205\210\347\272\247\345\210\253", nullptr));
        ckbxReportLog->setText(QApplication::translate("ProtectionRuleEditDetailWidget", "\344\270\212\346\212\245\346\227\245\345\277\227", nullptr));
        label_8->setText(QApplication::translate("ProtectionRuleEditDetailWidget", "\344\277\235\346\212\244\350\277\233\347\250\213", nullptr));
        label_9->setText(QApplication::translate("ProtectionRuleEditDetailWidget", "\344\277\235\346\212\244\347\261\273\345\236\213", nullptr));
        labError->setText(QApplication::translate("ProtectionRuleEditDetailWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProtectionRuleEditDetailWidget: public Ui_ProtectionRuleEditDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTECTIONRULEEDITDETAILWIDGET_H
