/********************************************************************************
** Form generated from reading UI file 'ModuleRuleEditDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULERULEEDITDETAILWIDGET_H
#define UI_MODULERULEEDITDETAILWIDGET_H

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

class Ui_ModuleRuleEditDetailWidget
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
    QComboBox *cmbxTargetModule;
    QComboBox *cmbxOperationCode;
    QLineEdit *liedtSourceProcess;
    QLineEdit *liedtTargetModule;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *cmbxSysVersion;
    QLabel *label_7;
    QComboBox *cmbxPriority;
    QTextEdit *txtdtRemark;
    QCheckBox *ckbxReportLog;
    QLabel *labError;

    void setupUi(QWidget *ModuleRuleEditDetailWidget)
    {
        if (ModuleRuleEditDetailWidget->objectName().isEmpty())
            ModuleRuleEditDetailWidget->setObjectName(QString::fromUtf8("ModuleRuleEditDetailWidget"));
        ModuleRuleEditDetailWidget->resize(680, 313);
        ModuleRuleEditDetailWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(ModuleRuleEditDetailWidget);
        titleFrame->setObjectName(QString::fromUtf8("titleFrame"));
        titleFrame->setGeometry(QRect(1, 1, 678, 39));
        titleFrame->setStyleSheet(QString::fromUtf8(""));
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Raised);
        btnClose = new QPushButton(titleFrame);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(638, 1, 40, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        btnClose->setFont(font);
        btnClose->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(titleFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 91, 31));
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        btnComfirm = new QPushButton(ModuleRuleEditDetailWidget);
        btnComfirm->setObjectName(QString::fromUtf8("btnComfirm"));
        btnComfirm->setGeometry(QRect(550, 260, 112, 37));
        btnComfirm->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(ModuleRuleEditDetailWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(45, 47, 71, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_3 = new QLabel(ModuleRuleEditDetailWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(25, 77, 91, 31));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_4 = new QLabel(ModuleRuleEditDetailWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(25, 107, 91, 31));
        label_4->setLayoutDirection(Qt::LeftToRight);
        cmbxSourceProcess = new QComboBox(ModuleRuleEditDetailWidget);
        cmbxSourceProcess->setObjectName(QString::fromUtf8("cmbxSourceProcess"));
        cmbxSourceProcess->setGeometry(QRect(115, 50, 180, 26));
        cmbxTargetModule = new QComboBox(ModuleRuleEditDetailWidget);
        cmbxTargetModule->setObjectName(QString::fromUtf8("cmbxTargetModule"));
        cmbxTargetModule->setGeometry(QRect(115, 80, 180, 26));
        cmbxOperationCode = new QComboBox(ModuleRuleEditDetailWidget);
        cmbxOperationCode->setObjectName(QString::fromUtf8("cmbxOperationCode"));
        cmbxOperationCode->setGeometry(QRect(115, 110, 180, 26));
        liedtSourceProcess = new QLineEdit(ModuleRuleEditDetailWidget);
        liedtSourceProcess->setObjectName(QString::fromUtf8("liedtSourceProcess"));
        liedtSourceProcess->setGeometry(QRect(300, 50, 361, 27));
        liedtTargetModule = new QLineEdit(ModuleRuleEditDetailWidget);
        liedtTargetModule->setObjectName(QString::fromUtf8("liedtTargetModule"));
        liedtTargetModule->setGeometry(QRect(300, 80, 361, 27));
        label_5 = new QLabel(ModuleRuleEditDetailWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 137, 51, 31));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_6 = new QLabel(ModuleRuleEditDetailWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(300, 107, 91, 31));
        cmbxSysVersion = new QComboBox(ModuleRuleEditDetailWidget);
        cmbxSysVersion->setObjectName(QString::fromUtf8("cmbxSysVersion"));
        cmbxSysVersion->setGeometry(QRect(390, 110, 131, 26));
        label_7 = new QLabel(ModuleRuleEditDetailWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(520, 107, 91, 31));
        cmbxPriority = new QComboBox(ModuleRuleEditDetailWidget);
        cmbxPriority->setObjectName(QString::fromUtf8("cmbxPriority"));
        cmbxPriority->setGeometry(QRect(619, 110, 41, 26));
        txtdtRemark = new QTextEdit(ModuleRuleEditDetailWidget);
        txtdtRemark->setObjectName(QString::fromUtf8("txtdtRemark"));
        txtdtRemark->setGeometry(QRect(115, 140, 545, 85));
        ckbxReportLog = new QCheckBox(ModuleRuleEditDetailWidget);
        ckbxReportLog->setObjectName(QString::fromUtf8("ckbxReportLog"));
        ckbxReportLog->setGeometry(QRect(110, 240, 151, 24));
        labError = new QLabel(ModuleRuleEditDetailWidget);
        labError->setObjectName(QString::fromUtf8("labError"));
        labError->setGeometry(QRect(25, 280, 421, 21));
        labError->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));

        retranslateUi(ModuleRuleEditDetailWidget);

        QMetaObject::connectSlotsByName(ModuleRuleEditDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *ModuleRuleEditDetailWidget)
    {
        ModuleRuleEditDetailWidget->setWindowTitle(QApplication::translate("ModuleRuleEditDetailWidget", "Form", nullptr));
        btnClose->setText(QApplication::translate("ModuleRuleEditDetailWidget", "X", nullptr));
        label->setText(QApplication::translate("ModuleRuleEditDetailWidget", "\346\250\241\345\235\227\350\247\204\345\210\231", nullptr));
        btnComfirm->setText(QApplication::translate("ModuleRuleEditDetailWidget", "\346\267\273\345\212\240", nullptr));
        label_2->setText(QApplication::translate("ModuleRuleEditDetailWidget", "\346\272\220\350\277\233\347\250\213", nullptr));
        label_3->setText(QApplication::translate("ModuleRuleEditDetailWidget", "\347\233\256\346\240\207\346\250\241\345\235\227", nullptr));
        label_4->setText(QApplication::translate("ModuleRuleEditDetailWidget", "\345\244\204\347\220\206\346\226\271\345\274\217", nullptr));
        label_5->setText(QApplication::translate("ModuleRuleEditDetailWidget", "\345\244\207\346\263\250", nullptr));
        label_6->setText(QApplication::translate("ModuleRuleEditDetailWidget", "\347\224\237\346\225\210\347\263\273\347\273\237", nullptr));
        label_7->setText(QApplication::translate("ModuleRuleEditDetailWidget", "\344\274\230\345\205\210\347\272\247\345\210\253", nullptr));
        ckbxReportLog->setText(QApplication::translate("ModuleRuleEditDetailWidget", "\344\270\212\346\212\245\346\227\245\345\277\227", nullptr));
        labError->setText(QApplication::translate("ModuleRuleEditDetailWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleRuleEditDetailWidget: public Ui_ModuleRuleEditDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULERULEEDITDETAILWIDGET_H
