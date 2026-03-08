/********************************************************************************
** Form generated from reading UI file 'FileRuleEditDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILERULEEDITDETAILWIDGET_H
#define UI_FILERULEEDITDETAILWIDGET_H

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

class Ui_FileRuleEditDetailWidget
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
    QComboBox *cmbxTargetFile;
    QComboBox *cmbxOperationCode;
    QLineEdit *liedtSourceProcess;
    QLineEdit *liedtTargetFile;
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
    QCheckBox *ckbxPrivilegeCreate;
    QCheckBox *ckbxPrivilegeOpen;
    QCheckBox *ckbxPrivilegeDelete;
    QCheckBox *ckbxPrivilegeQuery;
    QCheckBox *ckbxPrivilegeRename;
    QLabel *labError;

    void setupUi(QWidget *FileRuleEditDetailWidget)
    {
        if (FileRuleEditDetailWidget->objectName().isEmpty())
            FileRuleEditDetailWidget->setObjectName(QString::fromUtf8("FileRuleEditDetailWidget"));
        FileRuleEditDetailWidget->resize(679, 314);
        FileRuleEditDetailWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(FileRuleEditDetailWidget);
        titleFrame->setObjectName(QString::fromUtf8("titleFrame"));
        titleFrame->setGeometry(QRect(1, 1, 677, 39));
        titleFrame->setStyleSheet(QString::fromUtf8(""));
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Raised);
        btnClose = new QPushButton(titleFrame);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(637, 1, 40, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        btnClose->setFont(font);
        btnClose->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(titleFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 91, 31));
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        btnComfirm = new QPushButton(FileRuleEditDetailWidget);
        btnComfirm->setObjectName(QString::fromUtf8("btnComfirm"));
        btnComfirm->setGeometry(QRect(550, 260, 112, 37));
        btnComfirm->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(FileRuleEditDetailWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 47, 71, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_3 = new QLabel(FileRuleEditDetailWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 77, 91, 31));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_4 = new QLabel(FileRuleEditDetailWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 107, 91, 31));
        label_4->setLayoutDirection(Qt::LeftToRight);
        cmbxSourceProcess = new QComboBox(FileRuleEditDetailWidget);
        cmbxSourceProcess->setObjectName(QString::fromUtf8("cmbxSourceProcess"));
        cmbxSourceProcess->setGeometry(QRect(110, 50, 200, 26));
        cmbxTargetFile = new QComboBox(FileRuleEditDetailWidget);
        cmbxTargetFile->setObjectName(QString::fromUtf8("cmbxTargetFile"));
        cmbxTargetFile->setGeometry(QRect(110, 80, 200, 26));
        cmbxOperationCode = new QComboBox(FileRuleEditDetailWidget);
        cmbxOperationCode->setObjectName(QString::fromUtf8("cmbxOperationCode"));
        cmbxOperationCode->setGeometry(QRect(110, 110, 200, 26));
        liedtSourceProcess = new QLineEdit(FileRuleEditDetailWidget);
        liedtSourceProcess->setObjectName(QString::fromUtf8("liedtSourceProcess"));
        liedtSourceProcess->setGeometry(QRect(311, 50, 351, 27));
        liedtTargetFile = new QLineEdit(FileRuleEditDetailWidget);
        liedtTargetFile->setObjectName(QString::fromUtf8("liedtTargetFile"));
        liedtTargetFile->setGeometry(QRect(311, 80, 351, 27));
        label_5 = new QLabel(FileRuleEditDetailWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(45, 170, 51, 31));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_6 = new QLabel(FileRuleEditDetailWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(315, 107, 91, 31));
        cmbxSysVersion = new QComboBox(FileRuleEditDetailWidget);
        cmbxSysVersion->setObjectName(QString::fromUtf8("cmbxSysVersion"));
        cmbxSysVersion->setGeometry(QRect(409, 110, 111, 26));
        label_7 = new QLabel(FileRuleEditDetailWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(520, 107, 91, 31));
        cmbxPriority = new QComboBox(FileRuleEditDetailWidget);
        cmbxPriority->setObjectName(QString::fromUtf8("cmbxPriority"));
        cmbxPriority->setGeometry(QRect(610, 110, 51, 26));
        txtdtRemark = new QTextEdit(FileRuleEditDetailWidget);
        txtdtRemark->setObjectName(QString::fromUtf8("txtdtRemark"));
        txtdtRemark->setGeometry(QRect(110, 180, 515, 51));
        ckbxReportLog = new QCheckBox(FileRuleEditDetailWidget);
        ckbxReportLog->setObjectName(QString::fromUtf8("ckbxReportLog"));
        ckbxReportLog->setGeometry(QRect(110, 250, 151, 24));
        label_8 = new QLabel(FileRuleEditDetailWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 145, 91, 31));
        label_8->setLayoutDirection(Qt::LeftToRight);
        ckbxPrivilegeRead = new QCheckBox(FileRuleEditDetailWidget);
        ckbxPrivilegeRead->setObjectName(QString::fromUtf8("ckbxPrivilegeRead"));
        ckbxPrivilegeRead->setGeometry(QRect(110, 150, 65, 20));
        ckbxPrivilegeWrite = new QCheckBox(FileRuleEditDetailWidget);
        ckbxPrivilegeWrite->setObjectName(QString::fromUtf8("ckbxPrivilegeWrite"));
        ckbxPrivilegeWrite->setGeometry(QRect(175, 150, 65, 20));
        ckbxPrivilegeCreate = new QCheckBox(FileRuleEditDetailWidget);
        ckbxPrivilegeCreate->setObjectName(QString::fromUtf8("ckbxPrivilegeCreate"));
        ckbxPrivilegeCreate->setGeometry(QRect(240, 150, 65, 20));
        ckbxPrivilegeOpen = new QCheckBox(FileRuleEditDetailWidget);
        ckbxPrivilegeOpen->setObjectName(QString::fromUtf8("ckbxPrivilegeOpen"));
        ckbxPrivilegeOpen->setGeometry(QRect(305, 150, 65, 20));
        ckbxPrivilegeDelete = new QCheckBox(FileRuleEditDetailWidget);
        ckbxPrivilegeDelete->setObjectName(QString::fromUtf8("ckbxPrivilegeDelete"));
        ckbxPrivilegeDelete->setGeometry(QRect(370, 150, 65, 20));
        ckbxPrivilegeQuery = new QCheckBox(FileRuleEditDetailWidget);
        ckbxPrivilegeQuery->setObjectName(QString::fromUtf8("ckbxPrivilegeQuery"));
        ckbxPrivilegeQuery->setGeometry(QRect(435, 150, 65, 20));
        ckbxPrivilegeRename = new QCheckBox(FileRuleEditDetailWidget);
        ckbxPrivilegeRename->setObjectName(QString::fromUtf8("ckbxPrivilegeRename"));
        ckbxPrivilegeRename->setGeometry(QRect(500, 150, 65, 20));
        labError = new QLabel(FileRuleEditDetailWidget);
        labError->setObjectName(QString::fromUtf8("labError"));
        labError->setGeometry(QRect(20, 287, 421, 21));
        labError->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));

        retranslateUi(FileRuleEditDetailWidget);

        QMetaObject::connectSlotsByName(FileRuleEditDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *FileRuleEditDetailWidget)
    {
        FileRuleEditDetailWidget->setWindowTitle(QApplication::translate("FileRuleEditDetailWidget", "Form", nullptr));
        btnClose->setText(QApplication::translate("FileRuleEditDetailWidget", "X", nullptr));
        label->setText(QApplication::translate("FileRuleEditDetailWidget", "\346\226\207\344\273\266\350\247\204\345\210\231", nullptr));
        btnComfirm->setText(QApplication::translate("FileRuleEditDetailWidget", "\346\267\273\345\212\240", nullptr));
        label_2->setText(QApplication::translate("FileRuleEditDetailWidget", "\346\272\220\350\277\233\347\250\213", nullptr));
        label_3->setText(QApplication::translate("FileRuleEditDetailWidget", "\347\233\256\346\240\207\346\226\207\344\273\266", nullptr));
        label_4->setText(QApplication::translate("FileRuleEditDetailWidget", "\345\244\204\347\220\206\346\226\271\345\274\217", nullptr));
        label_5->setText(QApplication::translate("FileRuleEditDetailWidget", "\345\244\207\346\263\250", nullptr));
        label_6->setText(QApplication::translate("FileRuleEditDetailWidget", "\347\224\237\346\225\210\347\263\273\347\273\237", nullptr));
        label_7->setText(QApplication::translate("FileRuleEditDetailWidget", "\344\274\230\345\205\210\347\272\247\345\210\253", nullptr));
        ckbxReportLog->setText(QApplication::translate("FileRuleEditDetailWidget", "\344\270\212\346\212\245\346\227\245\345\277\227", nullptr));
        label_8->setText(QApplication::translate("FileRuleEditDetailWidget", "\347\246\201\346\255\242\346\235\203\351\231\220", nullptr));
        ckbxPrivilegeRead->setText(QApplication::translate("FileRuleEditDetailWidget", "\350\257\273\345\217\226", nullptr));
        ckbxPrivilegeWrite->setText(QApplication::translate("FileRuleEditDetailWidget", "\345\206\231\345\205\245", nullptr));
        ckbxPrivilegeCreate->setText(QApplication::translate("FileRuleEditDetailWidget", "\345\210\233\345\273\272", nullptr));
        ckbxPrivilegeOpen->setText(QApplication::translate("FileRuleEditDetailWidget", "\346\211\223\345\274\200", nullptr));
        ckbxPrivilegeDelete->setText(QApplication::translate("FileRuleEditDetailWidget", "\345\210\240\351\231\244", nullptr));
        ckbxPrivilegeQuery->setText(QApplication::translate("FileRuleEditDetailWidget", "\346\237\245\350\257\242", nullptr));
        ckbxPrivilegeRename->setText(QApplication::translate("FileRuleEditDetailWidget", "\346\224\271\345\220\215", nullptr));
        labError->setText(QApplication::translate("FileRuleEditDetailWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileRuleEditDetailWidget: public Ui_FileRuleEditDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILERULEEDITDETAILWIDGET_H
