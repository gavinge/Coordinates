/********************************************************************************
** Form generated from reading UI file 'DomainRuleEditDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOMAINRULEEDITDETAILWIDGET_H
#define UI_DOMAINRULEEDITDETAILWIDGET_H

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

class Ui_DomainRuleEditDetailWidget
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
    QLineEdit *liedtTargetDomain;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *cmbxSysVersion;
    QLabel *label_7;
    QComboBox *cmbxPriority;
    QTextEdit *txtdtRemark;
    QCheckBox *ckbxReportLog;
    QLabel *labError;

    void setupUi(QWidget *DomainRuleEditDetailWidget)
    {
        if (DomainRuleEditDetailWidget->objectName().isEmpty())
            DomainRuleEditDetailWidget->setObjectName(QString::fromUtf8("DomainRuleEditDetailWidget"));
        DomainRuleEditDetailWidget->resize(740, 300);
        DomainRuleEditDetailWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(DomainRuleEditDetailWidget);
        titleFrame->setObjectName(QString::fromUtf8("titleFrame"));
        titleFrame->setGeometry(QRect(1, 1, 739, 39));
        titleFrame->setStyleSheet(QString::fromUtf8(""));
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Raised);
        btnClose = new QPushButton(titleFrame);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(700, 0, 40, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        btnClose->setFont(font);
        btnClose->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(titleFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 91, 31));
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        btnComfirm = new QPushButton(DomainRuleEditDetailWidget);
        btnComfirm->setObjectName(QString::fromUtf8("btnComfirm"));
        btnComfirm->setGeometry(QRect(620, 250, 112, 37));
        btnComfirm->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(DomainRuleEditDetailWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(35, 47, 71, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_3 = new QLabel(DomainRuleEditDetailWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(15, 77, 91, 31));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_4 = new QLabel(DomainRuleEditDetailWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(15, 107, 91, 31));
        label_4->setLayoutDirection(Qt::LeftToRight);
        cmbxSourceProcess = new QComboBox(DomainRuleEditDetailWidget);
        cmbxSourceProcess->setObjectName(QString::fromUtf8("cmbxSourceProcess"));
        cmbxSourceProcess->setGeometry(QRect(105, 50, 161, 26));
        cmbxOperationCode = new QComboBox(DomainRuleEditDetailWidget);
        cmbxOperationCode->setObjectName(QString::fromUtf8("cmbxOperationCode"));
        cmbxOperationCode->setGeometry(QRect(105, 110, 161, 26));
        liedtSourceProcess = new QLineEdit(DomainRuleEditDetailWidget);
        liedtSourceProcess->setObjectName(QString::fromUtf8("liedtSourceProcess"));
        liedtSourceProcess->setGeometry(QRect(275, 50, 451, 27));
        liedtTargetDomain = new QLineEdit(DomainRuleEditDetailWidget);
        liedtTargetDomain->setObjectName(QString::fromUtf8("liedtTargetDomain"));
        liedtTargetDomain->setGeometry(QRect(105, 80, 621, 27));
        label_5 = new QLabel(DomainRuleEditDetailWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 137, 51, 31));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_6 = new QLabel(DomainRuleEditDetailWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(290, 107, 91, 31));
        cmbxSysVersion = new QComboBox(DomainRuleEditDetailWidget);
        cmbxSysVersion->setObjectName(QString::fromUtf8("cmbxSysVersion"));
        cmbxSysVersion->setGeometry(QRect(380, 110, 151, 26));
        label_7 = new QLabel(DomainRuleEditDetailWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(580, 107, 91, 31));
        cmbxPriority = new QComboBox(DomainRuleEditDetailWidget);
        cmbxPriority->setObjectName(QString::fromUtf8("cmbxPriority"));
        cmbxPriority->setGeometry(QRect(669, 110, 51, 26));
        txtdtRemark = new QTextEdit(DomainRuleEditDetailWidget);
        txtdtRemark->setObjectName(QString::fromUtf8("txtdtRemark"));
        txtdtRemark->setGeometry(QRect(105, 140, 621, 85));
        ckbxReportLog = new QCheckBox(DomainRuleEditDetailWidget);
        ckbxReportLog->setObjectName(QString::fromUtf8("ckbxReportLog"));
        ckbxReportLog->setGeometry(QRect(100, 230, 151, 24));
        labError = new QLabel(DomainRuleEditDetailWidget);
        labError->setObjectName(QString::fromUtf8("labError"));
        labError->setGeometry(QRect(15, 270, 421, 21));
        labError->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));

        retranslateUi(DomainRuleEditDetailWidget);

        QMetaObject::connectSlotsByName(DomainRuleEditDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *DomainRuleEditDetailWidget)
    {
        DomainRuleEditDetailWidget->setWindowTitle(QApplication::translate("DomainRuleEditDetailWidget", "Form", nullptr));
        btnClose->setText(QApplication::translate("DomainRuleEditDetailWidget", "X", nullptr));
        label->setText(QApplication::translate("DomainRuleEditDetailWidget", "\345\237\237\345\220\215\350\247\204\345\210\231", nullptr));
        btnComfirm->setText(QApplication::translate("DomainRuleEditDetailWidget", "\346\267\273\345\212\240", nullptr));
        label_2->setText(QApplication::translate("DomainRuleEditDetailWidget", "\346\272\220\350\277\233\347\250\213", nullptr));
        label_3->setText(QApplication::translate("DomainRuleEditDetailWidget", "\347\275\221\347\253\231\345\237\237\345\220\215", nullptr));
        label_4->setText(QApplication::translate("DomainRuleEditDetailWidget", "\345\244\204\347\220\206\346\226\271\345\274\217", nullptr));
        label_5->setText(QApplication::translate("DomainRuleEditDetailWidget", "\345\244\207\346\263\250", nullptr));
        label_6->setText(QApplication::translate("DomainRuleEditDetailWidget", "\347\224\237\346\225\210\347\263\273\347\273\237", nullptr));
        label_7->setText(QApplication::translate("DomainRuleEditDetailWidget", "\344\274\230\345\205\210\347\272\247\345\210\253", nullptr));
        ckbxReportLog->setText(QApplication::translate("DomainRuleEditDetailWidget", "\344\270\212\346\212\245\346\227\245\345\277\227", nullptr));
        labError->setText(QApplication::translate("DomainRuleEditDetailWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DomainRuleEditDetailWidget: public Ui_DomainRuleEditDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOMAINRULEEDITDETAILWIDGET_H
