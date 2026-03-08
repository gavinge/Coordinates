/********************************************************************************
** Form generated from reading UI file 'NetWorkRuleEditDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKRULEEDITDETAILWIDGET_H
#define UI_NETWORKRULEEDITDETAILWIDGET_H

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

class Ui_NetWorkRuleEditDetailWidget
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
    QLineEdit *liedtTargetIP;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *cmbxSysVersion;
    QLabel *label_7;
    QComboBox *cmbxPriority;
    QTextEdit *txtdtRemark;
    QCheckBox *ckbxReportLog;
    QLabel *label_8;
    QLineEdit *liedtTargetPort;
    QLabel *labError;

    void setupUi(QWidget *NetWorkRuleEditDetailWidget)
    {
        if (NetWorkRuleEditDetailWidget->objectName().isEmpty())
            NetWorkRuleEditDetailWidget->setObjectName(QString::fromUtf8("NetWorkRuleEditDetailWidget"));
        NetWorkRuleEditDetailWidget->resize(761, 300);
        NetWorkRuleEditDetailWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(NetWorkRuleEditDetailWidget);
        titleFrame->setObjectName(QString::fromUtf8("titleFrame"));
        titleFrame->setGeometry(QRect(1, 1, 761, 39));
        titleFrame->setStyleSheet(QString::fromUtf8(""));
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Raised);
        btnClose = new QPushButton(titleFrame);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(720, 0, 40, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        btnClose->setFont(font);
        btnClose->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(titleFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 91, 31));
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        btnComfirm = new QPushButton(NetWorkRuleEditDetailWidget);
        btnComfirm->setObjectName(QString::fromUtf8("btnComfirm"));
        btnComfirm->setGeometry(QRect(640, 250, 112, 37));
        btnComfirm->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(NetWorkRuleEditDetailWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(45, 47, 71, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_3 = new QLabel(NetWorkRuleEditDetailWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(25, 77, 91, 31));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_4 = new QLabel(NetWorkRuleEditDetailWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(25, 107, 91, 31));
        label_4->setLayoutDirection(Qt::LeftToRight);
        cmbxSourceProcess = new QComboBox(NetWorkRuleEditDetailWidget);
        cmbxSourceProcess->setObjectName(QString::fromUtf8("cmbxSourceProcess"));
        cmbxSourceProcess->setGeometry(QRect(115, 50, 180, 26));
        cmbxOperationCode = new QComboBox(NetWorkRuleEditDetailWidget);
        cmbxOperationCode->setObjectName(QString::fromUtf8("cmbxOperationCode"));
        cmbxOperationCode->setGeometry(QRect(115, 110, 180, 26));
        liedtSourceProcess = new QLineEdit(NetWorkRuleEditDetailWidget);
        liedtSourceProcess->setObjectName(QString::fromUtf8("liedtSourceProcess"));
        liedtSourceProcess->setGeometry(QRect(299, 50, 436, 27));
        liedtTargetIP = new QLineEdit(NetWorkRuleEditDetailWidget);
        liedtTargetIP->setObjectName(QString::fromUtf8("liedtTargetIP"));
        liedtTargetIP->setGeometry(QRect(115, 80, 305, 27));
        label_5 = new QLabel(NetWorkRuleEditDetailWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 137, 51, 31));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_6 = new QLabel(NetWorkRuleEditDetailWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(310, 107, 91, 31));
        cmbxSysVersion = new QComboBox(NetWorkRuleEditDetailWidget);
        cmbxSysVersion->setObjectName(QString::fromUtf8("cmbxSysVersion"));
        cmbxSysVersion->setGeometry(QRect(400, 110, 131, 26));
        label_7 = new QLabel(NetWorkRuleEditDetailWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(570, 107, 91, 31));
        cmbxPriority = new QComboBox(NetWorkRuleEditDetailWidget);
        cmbxPriority->setObjectName(QString::fromUtf8("cmbxPriority"));
        cmbxPriority->setGeometry(QRect(664, 110, 71, 26));
        txtdtRemark = new QTextEdit(NetWorkRuleEditDetailWidget);
        txtdtRemark->setObjectName(QString::fromUtf8("txtdtRemark"));
        txtdtRemark->setGeometry(QRect(115, 140, 621, 85));
        ckbxReportLog = new QCheckBox(NetWorkRuleEditDetailWidget);
        ckbxReportLog->setObjectName(QString::fromUtf8("ckbxReportLog"));
        ckbxReportLog->setGeometry(QRect(110, 240, 151, 24));
        label_8 = new QLabel(NetWorkRuleEditDetailWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(450, 77, 91, 31));
        liedtTargetPort = new QLineEdit(NetWorkRuleEditDetailWidget);
        liedtTargetPort->setObjectName(QString::fromUtf8("liedtTargetPort"));
        liedtTargetPort->setGeometry(QRect(544, 80, 191, 27));
        labError = new QLabel(NetWorkRuleEditDetailWidget);
        labError->setObjectName(QString::fromUtf8("labError"));
        labError->setGeometry(QRect(25, 270, 421, 21));
        labError->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));

        retranslateUi(NetWorkRuleEditDetailWidget);

        QMetaObject::connectSlotsByName(NetWorkRuleEditDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *NetWorkRuleEditDetailWidget)
    {
        NetWorkRuleEditDetailWidget->setWindowTitle(QApplication::translate("NetWorkRuleEditDetailWidget", "Form", nullptr));
        btnClose->setText(QApplication::translate("NetWorkRuleEditDetailWidget", "X", nullptr));
        label->setText(QApplication::translate("NetWorkRuleEditDetailWidget", "\347\275\221\347\273\234\350\247\204\345\210\231", nullptr));
        btnComfirm->setText(QApplication::translate("NetWorkRuleEditDetailWidget", "\346\267\273\345\212\240", nullptr));
        label_2->setText(QApplication::translate("NetWorkRuleEditDetailWidget", "\346\272\220\350\277\233\347\250\213", nullptr));
        label_3->setText(QApplication::translate("NetWorkRuleEditDetailWidget", "\347\233\256\346\240\207\345\234\260\345\235\200", nullptr));
        label_4->setText(QApplication::translate("NetWorkRuleEditDetailWidget", "\345\244\204\347\220\206\346\226\271\345\274\217", nullptr));
        label_5->setText(QApplication::translate("NetWorkRuleEditDetailWidget", "\345\244\207\346\263\250", nullptr));
        label_6->setText(QApplication::translate("NetWorkRuleEditDetailWidget", "\347\224\237\346\225\210\347\263\273\347\273\237", nullptr));
        label_7->setText(QApplication::translate("NetWorkRuleEditDetailWidget", "\344\274\230\345\205\210\347\272\247\345\210\253", nullptr));
        ckbxReportLog->setText(QApplication::translate("NetWorkRuleEditDetailWidget", "\344\270\212\346\212\245\346\227\245\345\277\227", nullptr));
        label_8->setText(QApplication::translate("NetWorkRuleEditDetailWidget", "\347\233\256\346\240\207\347\253\257\345\217\243", nullptr));
        labError->setText(QApplication::translate("NetWorkRuleEditDetailWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetWorkRuleEditDetailWidget: public Ui_NetWorkRuleEditDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKRULEEDITDETAILWIDGET_H
