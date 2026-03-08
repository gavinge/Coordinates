/********************************************************************************
** Form generated from reading UI file 'RegisterRuleEditDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERRULEEDITDETAILWIDGET_H
#define UI_REGISTERRULEEDITDETAILWIDGET_H

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

class Ui_RegisterRuleEditDetailWidget
{
public:
    QFrame *titleFrame;
    QPushButton *btnClose;
    QLabel *label;
    QPushButton *btnComfirm;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *cmbxSourceProcess;
    QComboBox *cmbxOperationCode;
    QLineEdit *liedtSourceProcess;
    QLineEdit *liedtTargetRegisterPath;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *cmbxSysVersion;
    QLabel *label_7;
    QComboBox *cmbxPriority;
    QTextEdit *txtdtRemark;
    QCheckBox *ckbxReportLog;
    QLabel *label_8;
    QCheckBox *ckbxPrivilegeRead;
    QCheckBox *ckbxPrivilegeWrite;
    QCheckBox *ckbxPrivilegeDelete;
    QLabel *labError;

    void setupUi(QWidget *RegisterRuleEditDetailWidget)
    {
        if (RegisterRuleEditDetailWidget->objectName().isEmpty())
            RegisterRuleEditDetailWidget->setObjectName(QString::fromUtf8("RegisterRuleEditDetailWidget"));
        RegisterRuleEditDetailWidget->resize(650, 300);
        RegisterRuleEditDetailWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(RegisterRuleEditDetailWidget);
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
        btnComfirm = new QPushButton(RegisterRuleEditDetailWidget);
        btnComfirm->setObjectName(QString::fromUtf8("btnComfirm"));
        btnComfirm->setGeometry(QRect(530, 250, 112, 37));
        btnComfirm->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(RegisterRuleEditDetailWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 47, 71, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_3 = new QLabel(RegisterRuleEditDetailWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 77, 91, 31));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_4 = new QLabel(RegisterRuleEditDetailWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 107, 91, 31));
        label_4->setLayoutDirection(Qt::LeftToRight);
        cmbxSourceProcess = new QComboBox(RegisterRuleEditDetailWidget);
        cmbxSourceProcess->setObjectName(QString::fromUtf8("cmbxSourceProcess"));
        cmbxSourceProcess->setGeometry(QRect(110, 50, 161, 26));
        cmbxOperationCode = new QComboBox(RegisterRuleEditDetailWidget);
        cmbxOperationCode->setObjectName(QString::fromUtf8("cmbxOperationCode"));
        cmbxOperationCode->setGeometry(QRect(110, 110, 161, 26));
        liedtSourceProcess = new QLineEdit(RegisterRuleEditDetailWidget);
        liedtSourceProcess->setObjectName(QString::fromUtf8("liedtSourceProcess"));
        liedtSourceProcess->setGeometry(QRect(274, 50, 351, 27));
        liedtTargetRegisterPath = new QLineEdit(RegisterRuleEditDetailWidget);
        liedtTargetRegisterPath->setObjectName(QString::fromUtf8("liedtTargetRegisterPath"));
        liedtTargetRegisterPath->setGeometry(QRect(110, 80, 515, 27));
        label_5 = new QLabel(RegisterRuleEditDetailWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(45, 170, 51, 31));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_6 = new QLabel(RegisterRuleEditDetailWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 107, 91, 31));
        cmbxSysVersion = new QComboBox(RegisterRuleEditDetailWidget);
        cmbxSysVersion->setObjectName(QString::fromUtf8("cmbxSysVersion"));
        cmbxSysVersion->setGeometry(QRect(370, 110, 131, 26));
        label_7 = new QLabel(RegisterRuleEditDetailWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(500, 107, 91, 31));
        cmbxPriority = new QComboBox(RegisterRuleEditDetailWidget);
        cmbxPriority->setObjectName(QString::fromUtf8("cmbxPriority"));
        cmbxPriority->setGeometry(QRect(594, 110, 31, 26));
        txtdtRemark = new QTextEdit(RegisterRuleEditDetailWidget);
        txtdtRemark->setObjectName(QString::fromUtf8("txtdtRemark"));
        txtdtRemark->setGeometry(QRect(110, 180, 515, 51));
        ckbxReportLog = new QCheckBox(RegisterRuleEditDetailWidget);
        ckbxReportLog->setObjectName(QString::fromUtf8("ckbxReportLog"));
        ckbxReportLog->setGeometry(QRect(105, 240, 151, 24));
        label_8 = new QLabel(RegisterRuleEditDetailWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 145, 91, 31));
        label_8->setLayoutDirection(Qt::LeftToRight);
        ckbxPrivilegeRead = new QCheckBox(RegisterRuleEditDetailWidget);
        ckbxPrivilegeRead->setObjectName(QString::fromUtf8("ckbxPrivilegeRead"));
        ckbxPrivilegeRead->setGeometry(QRect(110, 150, 65, 20));
        ckbxPrivilegeWrite = new QCheckBox(RegisterRuleEditDetailWidget);
        ckbxPrivilegeWrite->setObjectName(QString::fromUtf8("ckbxPrivilegeWrite"));
        ckbxPrivilegeWrite->setGeometry(QRect(175, 150, 65, 20));
        ckbxPrivilegeDelete = new QCheckBox(RegisterRuleEditDetailWidget);
        ckbxPrivilegeDelete->setObjectName(QString::fromUtf8("ckbxPrivilegeDelete"));
        ckbxPrivilegeDelete->setGeometry(QRect(240, 150, 65, 20));
        labError = new QLabel(RegisterRuleEditDetailWidget);
        labError->setObjectName(QString::fromUtf8("labError"));
        labError->setGeometry(QRect(20, 265, 431, 31));
        labError->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));

        retranslateUi(RegisterRuleEditDetailWidget);

        QMetaObject::connectSlotsByName(RegisterRuleEditDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *RegisterRuleEditDetailWidget)
    {
        RegisterRuleEditDetailWidget->setWindowTitle(QApplication::translate("RegisterRuleEditDetailWidget", "Form", nullptr));
        btnClose->setText(QApplication::translate("RegisterRuleEditDetailWidget", "X", nullptr));
        label->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\346\263\250\345\206\214\350\241\250\350\247\204\345\210\231", nullptr));
        btnComfirm->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\346\267\273\345\212\240", nullptr));
        label_2->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\346\272\220\350\277\233\347\250\213", nullptr));
        label_3->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\345\214\271\351\205\215\350\267\257\345\276\204", nullptr));
        label_4->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\345\244\204\347\220\206\346\226\271\345\274\217", nullptr));
        label_5->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\345\244\207\346\263\250", nullptr));
        label_6->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\347\224\237\346\225\210\347\263\273\347\273\237", nullptr));
        label_7->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\344\274\230\345\205\210\347\272\247\345\210\253", nullptr));
        ckbxReportLog->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\344\270\212\346\212\245\346\227\245\345\277\227", nullptr));
        label_8->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\347\246\201\346\255\242\346\235\203\351\231\220", nullptr));
        ckbxPrivilegeRead->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\350\257\273\345\217\226", nullptr));
        ckbxPrivilegeWrite->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\345\206\231\345\205\245", nullptr));
        ckbxPrivilegeDelete->setText(QApplication::translate("RegisterRuleEditDetailWidget", "\345\210\240\351\231\244", nullptr));
        labError->setText(QApplication::translate("RegisterRuleEditDetailWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterRuleEditDetailWidget: public Ui_RegisterRuleEditDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERRULEEDITDETAILWIDGET_H
