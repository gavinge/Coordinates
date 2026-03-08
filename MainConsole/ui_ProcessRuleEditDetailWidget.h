/********************************************************************************
** Form generated from reading UI file 'ProcessRuleEditDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSRULEEDITDETAILWIDGET_H
#define UI_PROCESSRULEEDITDETAILWIDGET_H

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

class Ui_ProcessRuleEditDetailWidget
{
public:
    QFrame *titleFrame;
    QPushButton *btnClose;
    QLabel *label;
    QPushButton *btnComfirm;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *cmbxParentProcess;
    QComboBox *cmbxSonProcess;
    QComboBox *cmbxTreatMod;
    QLineEdit *liedtParentProcess;
    QLineEdit *liedtSonProcess;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *cmbxSysVersion;
    QLabel *label_7;
    QComboBox *cmbxPriority;
    QTextEdit *txtdtRemark;
    QCheckBox *ckbxReportLog;
    QLabel *labError;

    void setupUi(QWidget *ProcessRuleEditDetailWidget)
    {
        if (ProcessRuleEditDetailWidget->objectName().isEmpty())
            ProcessRuleEditDetailWidget->setObjectName(QString::fromUtf8("ProcessRuleEditDetailWidget"));
        ProcessRuleEditDetailWidget->resize(650, 313);
        ProcessRuleEditDetailWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(ProcessRuleEditDetailWidget);
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
        btnComfirm = new QPushButton(ProcessRuleEditDetailWidget);
        btnComfirm->setObjectName(QString::fromUtf8("btnComfirm"));
        btnComfirm->setGeometry(QRect(530, 260, 112, 37));
        btnComfirm->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(ProcessRuleEditDetailWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(35, 47, 71, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_3 = new QLabel(ProcessRuleEditDetailWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(35, 77, 71, 31));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_4 = new QLabel(ProcessRuleEditDetailWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(15, 107, 91, 31));
        label_4->setLayoutDirection(Qt::LeftToRight);
        cmbxParentProcess = new QComboBox(ProcessRuleEditDetailWidget);
        cmbxParentProcess->setObjectName(QString::fromUtf8("cmbxParentProcess"));
        cmbxParentProcess->setGeometry(QRect(105, 50, 161, 26));
        cmbxParentProcess->setMaxVisibleItems(20);
        cmbxSonProcess = new QComboBox(ProcessRuleEditDetailWidget);
        cmbxSonProcess->setObjectName(QString::fromUtf8("cmbxSonProcess"));
        cmbxSonProcess->setGeometry(QRect(105, 80, 161, 26));
        cmbxSonProcess->setMaxVisibleItems(20);
        cmbxTreatMod = new QComboBox(ProcessRuleEditDetailWidget);
        cmbxTreatMod->setObjectName(QString::fromUtf8("cmbxTreatMod"));
        cmbxTreatMod->setGeometry(QRect(105, 110, 161, 26));
        liedtParentProcess = new QLineEdit(ProcessRuleEditDetailWidget);
        liedtParentProcess->setObjectName(QString::fromUtf8("liedtParentProcess"));
        liedtParentProcess->setGeometry(QRect(269, 50, 351, 27));
        liedtSonProcess = new QLineEdit(ProcessRuleEditDetailWidget);
        liedtSonProcess->setObjectName(QString::fromUtf8("liedtSonProcess"));
        liedtSonProcess->setGeometry(QRect(269, 80, 351, 27));
        label_5 = new QLabel(ProcessRuleEditDetailWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 137, 51, 31));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_6 = new QLabel(ProcessRuleEditDetailWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(270, 107, 81, 31));
        cmbxSysVersion = new QComboBox(ProcessRuleEditDetailWidget);
        cmbxSysVersion->setObjectName(QString::fromUtf8("cmbxSysVersion"));
        cmbxSysVersion->setGeometry(QRect(349, 110, 121, 26));
        label_7 = new QLabel(ProcessRuleEditDetailWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(470, 107, 81, 31));
        cmbxPriority = new QComboBox(ProcessRuleEditDetailWidget);
        cmbxPriority->setObjectName(QString::fromUtf8("cmbxPriority"));
        cmbxPriority->setGeometry(QRect(549, 110, 71, 26));
        cmbxPriority->setMaxVisibleItems(20);
        txtdtRemark = new QTextEdit(ProcessRuleEditDetailWidget);
        txtdtRemark->setObjectName(QString::fromUtf8("txtdtRemark"));
        txtdtRemark->setGeometry(QRect(105, 140, 515, 85));
        ckbxReportLog = new QCheckBox(ProcessRuleEditDetailWidget);
        ckbxReportLog->setObjectName(QString::fromUtf8("ckbxReportLog"));
        ckbxReportLog->setGeometry(QRect(100, 250, 151, 24));
        labError = new QLabel(ProcessRuleEditDetailWidget);
        labError->setObjectName(QString::fromUtf8("labError"));
        labError->setGeometry(QRect(20, 280, 391, 31));
        labError->setLayoutDirection(Qt::LeftToRight);
        labError->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));

        retranslateUi(ProcessRuleEditDetailWidget);

        QMetaObject::connectSlotsByName(ProcessRuleEditDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *ProcessRuleEditDetailWidget)
    {
        ProcessRuleEditDetailWidget->setWindowTitle(QApplication::translate("ProcessRuleEditDetailWidget", "Form", nullptr));
        btnClose->setText(QApplication::translate("ProcessRuleEditDetailWidget", "X", nullptr));
        label->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\350\277\233\347\250\213\350\247\204\345\210\231", nullptr));
        btnComfirm->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\346\267\273\345\212\240", nullptr));
        label_2->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\347\210\266\350\277\233\347\250\213", nullptr));
        label_3->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\345\255\220\350\277\233\347\250\213", nullptr));
        label_4->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\345\244\204\347\220\206\346\226\271\345\274\217", nullptr));
        label_5->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\345\244\207\346\263\250", nullptr));
        label_6->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\347\224\237\346\225\210\347\263\273\347\273\237", nullptr));
        label_7->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\344\274\230\345\205\210\347\272\247\345\210\253", nullptr));
        ckbxReportLog->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\344\270\212\346\212\245\346\227\245\345\277\227", nullptr));
        labError->setText(QApplication::translate("ProcessRuleEditDetailWidget", "error", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProcessRuleEditDetailWidget: public Ui_ProcessRuleEditDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSRULEEDITDETAILWIDGET_H
