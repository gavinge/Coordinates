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
    QPushButton *closeBtn;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox_4;
    QLabel *label_7;
    QComboBox *comboBox_5;
    QTextEdit *textEdit;
    QCheckBox *checkBox;
    QComboBox *comboBox_6;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBox_7;

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
        pushButton = new QPushButton(KernelRuleEditDetailWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(530, 250, 112, 37));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(KernelRuleEditDetailWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(25, 47, 91, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        comboBox = new QComboBox(KernelRuleEditDetailWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(115, 50, 105, 26));
        lineEdit = new QLineEdit(KernelRuleEditDetailWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(225, 50, 405, 27));
        label_5 = new QLabel(KernelRuleEditDetailWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 137, 51, 31));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_6 = new QLabel(KernelRuleEditDetailWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(25, 110, 91, 31));
        comboBox_4 = new QComboBox(KernelRuleEditDetailWidget);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(115, 110, 105, 26));
        label_7 = new QLabel(KernelRuleEditDetailWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(230, 110, 81, 31));
        comboBox_5 = new QComboBox(KernelRuleEditDetailWidget);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(310, 110, 110, 26));
        textEdit = new QTextEdit(KernelRuleEditDetailWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(115, 140, 515, 85));
        checkBox = new QCheckBox(KernelRuleEditDetailWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(110, 250, 151, 24));
        comboBox_6 = new QComboBox(KernelRuleEditDetailWidget);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setGeometry(QRect(115, 80, 105, 26));
        label_8 = new QLabel(KernelRuleEditDetailWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(25, 77, 91, 31));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_9 = new QLabel(KernelRuleEditDetailWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(230, 80, 81, 31));
        comboBox_7 = new QComboBox(KernelRuleEditDetailWidget);
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));
        comboBox_7->setGeometry(QRect(310, 80, 110, 26));

        retranslateUi(KernelRuleEditDetailWidget);

        QMetaObject::connectSlotsByName(KernelRuleEditDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *KernelRuleEditDetailWidget)
    {
        KernelRuleEditDetailWidget->setWindowTitle(QApplication::translate("KernelRuleEditDetailWidget", "Form", nullptr));
        closeBtn->setText(QApplication::translate("KernelRuleEditDetailWidget", "X", nullptr));
        label->setText(QApplication::translate("KernelRuleEditDetailWidget", "\351\251\261\345\212\250\350\247\204\345\210\231", nullptr));
        pushButton->setText(QApplication::translate("KernelRuleEditDetailWidget", "\346\267\273\345\212\240", nullptr));
        label_2->setText(QApplication::translate("KernelRuleEditDetailWidget", "\351\251\261\345\212\250\344\277\241\346\201\257", nullptr));
        label_5->setText(QApplication::translate("KernelRuleEditDetailWidget", "\345\244\207\346\263\250", nullptr));
        label_6->setText(QApplication::translate("KernelRuleEditDetailWidget", "\347\224\237\346\225\210\347\263\273\347\273\237", nullptr));
        label_7->setText(QApplication::translate("KernelRuleEditDetailWidget", "\344\274\230\345\205\210\347\272\247\345\210\253", nullptr));
        checkBox->setText(QApplication::translate("KernelRuleEditDetailWidget", "\344\270\212\346\212\245\346\227\245\345\277\227", nullptr));
        label_8->setText(QApplication::translate("KernelRuleEditDetailWidget", "\345\244\204\347\220\206\346\226\271\345\274\217", nullptr));
        label_9->setText(QApplication::translate("KernelRuleEditDetailWidget", "\345\233\236\350\260\203\347\261\273\345\236\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KernelRuleEditDetailWidget: public Ui_KernelRuleEditDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KERNELRULEEDITDETAILWIDGET_H
