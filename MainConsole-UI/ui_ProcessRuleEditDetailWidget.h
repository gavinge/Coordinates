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
    QPushButton *closeBtn;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox_4;
    QLabel *label_7;
    QComboBox *comboBox_5;
    QTextEdit *textEdit;
    QCheckBox *checkBox;

    void setupUi(QWidget *ProcessRuleEditDetailWidget)
    {
        if (ProcessRuleEditDetailWidget->objectName().isEmpty())
            ProcessRuleEditDetailWidget->setObjectName(QString::fromUtf8("ProcessRuleEditDetailWidget"));
        ProcessRuleEditDetailWidget->resize(650, 300);
        ProcessRuleEditDetailWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(ProcessRuleEditDetailWidget);
        titleFrame->setObjectName(QString::fromUtf8("titleFrame"));
        titleFrame->setGeometry(QRect(1, 1, 648, 39));
        titleFrame->setStyleSheet(QString::fromUtf8(""));
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Raised);
        closeBtn = new QPushButton(titleFrame);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(608, 1, 40, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        closeBtn->setFont(font);
        closeBtn->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(titleFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 91, 31));
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        pushButton = new QPushButton(ProcessRuleEditDetailWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(530, 250, 112, 37));
        pushButton->setStyleSheet(QString::fromUtf8(""));
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
        comboBox = new QComboBox(ProcessRuleEditDetailWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(105, 50, 105, 26));
        comboBox_2 = new QComboBox(ProcessRuleEditDetailWidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(105, 80, 105, 26));
        comboBox_3 = new QComboBox(ProcessRuleEditDetailWidget);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(105, 110, 105, 26));
        lineEdit = new QLineEdit(ProcessRuleEditDetailWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(215, 50, 405, 27));
        lineEdit_2 = new QLineEdit(ProcessRuleEditDetailWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(215, 80, 405, 27));
        label_5 = new QLabel(ProcessRuleEditDetailWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 137, 51, 31));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_6 = new QLabel(ProcessRuleEditDetailWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(220, 107, 81, 31));
        comboBox_4 = new QComboBox(ProcessRuleEditDetailWidget);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(300, 110, 110, 26));
        label_7 = new QLabel(ProcessRuleEditDetailWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(430, 107, 81, 31));
        comboBox_5 = new QComboBox(ProcessRuleEditDetailWidget);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(510, 110, 110, 26));
        textEdit = new QTextEdit(ProcessRuleEditDetailWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(105, 140, 515, 85));
        checkBox = new QCheckBox(ProcessRuleEditDetailWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(100, 250, 151, 24));

        retranslateUi(ProcessRuleEditDetailWidget);

        QMetaObject::connectSlotsByName(ProcessRuleEditDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *ProcessRuleEditDetailWidget)
    {
        ProcessRuleEditDetailWidget->setWindowTitle(QApplication::translate("ProcessRuleEditDetailWidget", "Form", nullptr));
        closeBtn->setText(QApplication::translate("ProcessRuleEditDetailWidget", "X", nullptr));
        label->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\350\277\233\347\250\213\350\247\204\345\210\231", nullptr));
        pushButton->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\346\267\273\345\212\240", nullptr));
        label_2->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\347\210\266\350\277\233\347\250\213", nullptr));
        label_3->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\345\255\220\350\277\233\347\250\213", nullptr));
        label_4->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\345\244\204\347\220\206\346\226\271\345\274\217", nullptr));
        label_5->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\345\244\207\346\263\250", nullptr));
        label_6->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\347\224\237\346\225\210\347\263\273\347\273\237", nullptr));
        label_7->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\344\274\230\345\205\210\347\272\247\345\210\253", nullptr));
        checkBox->setText(QApplication::translate("ProcessRuleEditDetailWidget", "\344\270\212\346\212\245\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProcessRuleEditDetailWidget: public Ui_ProcessRuleEditDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSRULEEDITDETAILWIDGET_H
